#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include "LTC4271.h"

#define MAX_PORT_NAME 32
#define NUM_PORTS 8

//uint8_t HEX = 0;
//uint8_t INVBIN[8] = {0};
//uint8_t BIN[8] = {0};
uint8_t portNo = 0;

// Structure to store port settings
typedef struct {
    char name[MAX_PORT_NAME];
    uint8_t status;
    uint8_t class;
    uint8_t power_limit;
} PortSettings;

// Global variables
PortSettings ports[NUM_PORTS];

// Function prototypes
void initializePortNames(void);
void showPortStatus(void);
void selectPortInteractive(void);
void resetPorts(void);
void portSettings(void);

int main(void) {
    int choice;
    
    // Initialize port names with defaults
    initializePortNames();
    
    // Initialize I2C and LTC4271
    if (i2c_init() != 0) {
        printf("Failed to initialize I2C\n");
        return -1;
    }

    // Initialize all ports with default settings
    initAll();

    while (1) {
        printf("\nPoE Port Management\n");
        printf("==================\n");
        printf("0. Exit\n");
        printf("1. See PoE Port Status\n");
        printf("2. Select PoE Port\n");
        printf("3. Reset Ports\n");
        printf("4. Port Settings\n");
        printf("Enter your choice (0-4): ");
        
         if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            exit(EXIT_FAILURE);
        }
        
        switch (choice) {
            case 0:
                LTC4271_cleanup();
                printf("Exiting...\n");
                return 0;
            
            case 1:
                showPortStatus();
                break;
            
            case 2:
                selectPortInteractive();
                break;
            
            case 3:
                resetPorts();
                break;
            
            case 4:
                portSettings();
                break;
            
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}

void showPortStatus(void) {
    printf("\nPort Status\n");
    printf("===========\n");
    printf("Port  Name        Status    Class     Power    Detection\n");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < NUM_PORTS; i++) {
        int port = i + 1;
        uint8_t bcastReg;
        int portNo;
        uint8_t status, classType, detStatus;
        
        if (selectPort(port, &bcastReg, &portNo) == 0) {
            // Read port status
            if (readStatus(port, &status) == 0) {
                // Read class type
                if (readClass(port, &classType) == 0) {
                    // Read detection status
                    detStatus = readDet(port);
                    
                    // Get power limit
                    uint8_t limit;
                    readLimit(port, &limit);
                    
                    printf("%-5d %-11s %-9s Class %-3d %-7dW %s\n",
                        port,
                        ports[i].name,
                        (status & 0x01) ? "Enabled" : "Disabled",
                        classType,
                        (classType == 0) ? 15 :
                        (classType == 1) ? 4 :
                        (classType == 2) ? 7 :
                        (classType == 3) ? 15 : 30,
                        (detStatus == 255) ? "Error" :
                        (detStatus == 0) ? "No PD" : "PD Detected");
                }
            }
        }
    }
}

void selectPortInteractive(void) {
    int port, choice;
    printf("\nSelect Port (1-8): ");
    if (scanf("%d", &port) != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        return;
    }
    
    if (port < 1 || port > 8) {
        printf("Invalid port number!\n");
        return;
    }
    
    printf("\nPort %d Options:\n", port);
    printf("1. Enable Port\n");
    printf("2. Disable Port\n");
    printf("3. Set Power Class\n");
    printf("4. View Detection Status\n");
    printf("Enter choice (1-4): ");
     if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        return;
    }
    
    switch (choice) {
        case 1:
            setPort(port, 1);
            break;
        case 2:
            setPort(port, 0);
            break;
        case 3: {
            int class;
            printf("Enter class (0-4): ");
              if (scanf("%d", &class) != 1) {
                fprintf(stderr, "Invalid input. Please enter a number.\n");
                return;
            }
            if (class >= 0 && class <= 4) {
                pdClass(port, class);
            } else {
                printf("Invalid class value!\n");
            }
            break;
        }
        case 4: {
            int det = readDet(port);
            printf("Detection Status: %s\n", 
                (det == 255) ? "Error" :
                (det == 0) ? "No PD" : "PD Detected");
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
}

void resetPorts(void) {
    printf("Resetting all ports to default configuration...\n");
    
    // Initialize all ports
    initAll();
    
    // Enable high power features on all ports
    uint8_t hpen_value = msk_hpen_hpen4 | msk_hpen_hpen3 | 
                        msk_hpen_hpen2 | msk_hpen_hpen1;
    i2c_write(Bcast_reg, hpen, hpen_value);
    
    printf("Reset complete.\n");
}

void portSettings(void) {
    int port;
    char newName[MAX_PORT_NAME];
    
    printf("\nEnter port number (1-8): ");
     if (scanf("%d", &port) != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        return;
    }
    
    if (port < 1 || port > 8) {
        printf("Invalid port number!\n");
        return;
    }
    
    printf("Enter new name for port %d: ", port);
     if (scanf(" %31[^\n]", newName) != 1) {
        fprintf(stderr, "Invalid input. Please enter a valid name.\n");
        return;
    }
    
    strncpy(ports[port-1].name, newName, MAX_PORT_NAME-1);
    ports[port-1].name[MAX_PORT_NAME-1] = '\0';
    
    printf("Port name updated successfully.\n");
}

void initializePortNames(void) {
    for (int i = 0; i < NUM_PORTS; i++) {
        snprintf(ports[i].name, MAX_PORT_NAME, "Port %d", i + 1);
        ports[i].status = 0;
        ports[i].class = 0;
        ports[i].power_limit = 0;
    }
}
