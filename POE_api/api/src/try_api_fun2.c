#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "LTC4271.h"

// Function prototypes
//int i2c_read(uint8_t reg, uint8_t *data);
//int i2c_write(uint8_t bcast_reg, uint8_t reg, uint8_t value);
//void initPorts(void);
//void hex2bin(uint8_t hex, uint8_t *bin);
//void bin2hex(uint8_t *bin, uint8_t *hex);
//int selectPort(int port, uint8_t *bcastReg, int *portNo);

// Global variables
uint8_t BIN[8];
uint8_t INVBIN[8];
uint8_t HEX;
uint8_t Bcast_reg = 0x20;
uint8_t statpwr = 0x01; 
// uint8_t pwrpb = 0x02;  // This conflicts with LTC4271.h definition

int setPort(int port, int value) {
    uint8_t bcastReg;
    int portNo;
    
    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return 1;
    }
    
    if (value == 1) {
        initPorts();
    }
    
    uint8_t data;
    if (i2c_read(bcastReg, &data) != 0) {
        return 1;
    }

    hex2bin(data, BIN);
    setdatabits(BIN, 8);
    
    // Get first 4 bits
    uint8_t firstFour[4];
    memcpy(firstFour, &BIN[4], sizeof(uint8_t) * 4);
    
    // Reverse and modify bit
    revStr(firstFour);
    firstFour[portNo-1] = value;
    revStr(firstFour);
    
    // Create inverted version
    uint8_t inverted[4];
    inverter(firstFour, inverted);
    
    // Combine and convert back to hex
    uint8_t combined[8];
    memcpy(combined, inverted, 4);
    memcpy(&combined[4], firstFour, 4);
    bin2hex(combined, &HEX);
    
    return i2c_write(bcastReg, pwrpb, HEX);
}

int pdClass(int port, int classType) {
    uint8_t bcastReg;
    int portNo;
    uint8_t classification;

    if (classType < 0 || classType > 4) {
        return -1;
    }

    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return -1;
    }

    switch (classType) {
        case 0: classification = 0xD4; break;
        case 1: classification = 0xC4; break;
        case 2: classification = 0xCB; break;
        case 3: classification = 0xD4; break;
        case 4: classification = 0xE2; break;
        default: classification = 0xC4; break;
    }

    if (i2c_write(Bcast_reg, bcastReg, classification) != 0) {
        return -2;
    }

    return 0;
}

int readStatus(int port, uint8_t *status) {
    uint8_t bcastReg;
    int portNo;

    if (port > 8) {
        return -1;
    }

    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return -1;
    }

    if (i2c_read(statpin, status) != 0) {
        return -2;
    }

    return 0;
}

int readClass(int port, uint8_t *classType) {
    uint8_t bcastReg;
    int portNo;

    if (port > 8) {
        return -1;
    }

    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return -1;
    }

    if (i2c_read(statpin, classType) != 0) {
        return -2;
    }

    return 0;
}

int readLimit(int port, uint8_t *limit) {
    uint8_t bcastReg;
    int portNo;

    if (port > 8) {
        return -1;
    }

    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return -1;
    }

    if (i2c_read(bcastReg, limit) != 0) {
        return -2;
    }

    return 0;
}

int readDet(int port) {
    uint8_t bcastReg;
    int portNo;

    // Validate port number is between 1 and 8
    if (port < 1 || port > 8) {
        return 255;
    }

    // Get broadcast register and port number
    if (selectPort(port, &bcastReg, &portNo) != 0) {
        return 255;
    }

    // Read detection status
    uint8_t status;
    if (i2c_read(bcastReg, &status) != 0) {
        return 255;
    }

    // Return detection status
    return (int)status;
}

void resetAll(void) {
    initPorts();
}
