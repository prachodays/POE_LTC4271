#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "LTC4271.h"

static int i2c_fd = -1;  // Global file descriptor
static uint8_t x;        // Global variable to store read value

// I2C read function
int i2c_read(uint8_t reg, uint8_t *data) {
    char filename[20];
    snprintf(filename, sizeof(filename), "/dev/i2c-3");  // Use I2C bus 3
    
    int fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the I2C bus");
        return -1;
    }
    
    // Write the register address we want to read from
    if (write(fd, &reg, 1) != 1) {
        perror("Failed to write to the I2C bus");
        close(fd);
        return -1;
    }
    
    // Read one byte from the specified register
    if (read(fd, &x, 1) != 1) {
        perror("Failed to read from the I2C bus");
        close(fd);
        return -1;
    }
    
    *data = x;  // Store the read value in the provided pointer
    close(fd);
    return 0;  // Success
}

// I2C write function 
int i2c_write(uint8_t bcast_reg, uint8_t reg, uint8_t value) {
    char filename[20];
    snprintf(filename, sizeof(filename), "/dev/i2c-3");  // Use I2C bus 3
    
    int fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the I2C bus");
        return -1;
    }
    
    // Set I2C slave address (broadcast register)
    if (ioctl(fd, I2C_SLAVE, bcast_reg) < 0) {
        perror("Failed to set I2C slave address");
        close(fd);
        return -1;
    }
    
    // Create buffer for register and data
    uint8_t buffer[2];
    buffer[0] = reg;    // Register address
    buffer[1] = value;  // Value to write
    
    // Write both register and data
    if (write(fd, buffer, 2) != 2) {
        perror("Failed to write to the I2C bus");
        close(fd);
        return -1;
    }
    
    // Sleep for 10ms (10000 microseconds)
    usleep(10000);
    
    close(fd);
    return 0;  // Success
}

// Convert hex value to binary array
void hex2bin(uint8_t hex, uint8_t *bin) {
    for(int i = 7; i >= 0; i--) {
        bin[i] = (hex >> (7-i)) & 0x01;
    }
}

// Invert binary array
void inverter(uint8_t *bin, uint8_t *invbin) {
    for(int i = 0; i < 8; i++) {
        invbin[i] = !bin[i];
    }
}

// Reverse binary array
void revStr(uint8_t *bin) {
    uint8_t temp;
    for(int i = 0; i < 4; i++) {
        temp = bin[i];
        bin[i] = bin[7-i];
        bin[7-i] = temp;
    }
}

// Convert binary array to hex
void bin2hex(uint8_t *bin, uint8_t *hex) {
    *hex = 0;
    for(int i = 0; i < 8; i++) {
        *hex |= (bin[i] << (7-i));
    }
}

// Pad binary array to 8 bits
void setdatabits(uint8_t *bin, int len) {
    if(len >= 8) return;
    
    // Shift existing bits right
    for(int i = 7; i >= 8-len; i--) {
        bin[i] = bin[i-(8-len)];
    }
    
    // Pad with zeros
    for(int i = 0; i < 8-len; i++) {
        bin[i] = 0;
    }
}

int i2c_init(void) {
    char filename[20];
    snprintf(filename, sizeof(filename), "/dev/i2c-3");
    
    if ((i2c_fd = open(filename, O_RDWR)) < 0) {
        return -1;
    }
    
    if (ioctl(i2c_fd, I2C_SLAVE, LTC4271_I2C_ADDR) < 0) {
        close(i2c_fd);
        return -1;
    }
    
    return 0;
}

void LTC4271_cleanup(void) {
    if (i2c_fd >= 0) {
        close(i2c_fd);
        i2c_fd = -1;
    }
}
