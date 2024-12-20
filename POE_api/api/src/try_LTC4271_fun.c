#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LTC4271.h"

// Select port and set Bcast_reg and portNo accordingly
// Returns 0 on success, 1 on invalid port
int selectPort(int port,uint8_t *bcastReg,int *portNo) {
    if (port > 4 && port < 9) {
        *bcastReg = 0x21;
        *portNo = port - 4;
        return 0;
    }
    else if (port > 0 && port < 5) {
        *bcastReg = 0x20;
        *portNo = port;
        return 0;
    }
    return 1;
}

// Initialize all ports with default values
void initPorts(void) {
    // Set interrupt mask to all disabled since servicing mode is "polled"
    i2c_write(Bcast_reg, intmask, 0x00);

    // Set opmode = semiauto
    i2c_write(Bcast_reg, opmd, 0xAA);

    // Enable DC disconnect
    i2c_write(Bcast_reg, disena, msk_disena_dc4 | msk_disena_dc3 | 
              msk_disena_dc2 | msk_disena_dc1);

    // Enable high Power mode
    i2c_write(Bcast_reg, hpen, msk_hpen_hpen4 | msk_hpen_hpen3 |
              msk_hpen_hpen2 | msk_hpen_hpen1);

    // Require 0.25ohm (0.50ohm deprecated)
    // Port 1
    i2c_write(Bcast_reg, cut1, 0xD4);
    i2c_write(Bcast_reg, lim1, 0x80);
    // Port 2
    i2c_write(Bcast_reg, cut2, 0xD4);
    i2c_write(Bcast_reg, lim2, 0x80);
    // Port 3
    i2c_write(Bcast_reg, cut3, 0xD4);
    i2c_write(Bcast_reg, lim3, 0x80);
    // Port 4
    i2c_write(Bcast_reg, cut4, 0xD4);
    i2c_write(Bcast_reg, lim4, 0x80);

    i2c_write(Bcast_reg, detpb, 0x0F);
}

// Reset chips and initialize all ports
void initAll(void) {
    // Reset chip and interrupts
    i2c_write(Bcast_reg, rstpb, msk_rstpb_intclr | msk_rstpb_rstall);
    initPorts();
}

// Get enable/disable status of port
// Returns 0 for disabled, 1 for enabled
int EDstatus(int port, uint8_t bcast_reg, uint8_t status_reg) {
    uint8_t data;
    uint8_t bin[8];
    
    i2c_read(status_reg, &data);
    hex2bin(data, bin);
    setdatabits(bin, 8);
    revStr(bin);
    
    return bin[port-1];
}

// Get class of port (0-7)
int Cstatus(int port, uint8_t bcast_reg, uint8_t status_reg) {
    uint8_t data;
    uint8_t bin[8];
    uint8_t cls[3] = {0};
    uint8_t hex;
    int j = 0;
    
    i2c_read(status_reg, &data);
    hex2bin(data, bin);
    setdatabits(bin, 8);
    
    for(int i=1; i<4; i++) {
        cls[j++] = bin[i];
    }
    
    bin2hex(cls, &hex);
    return hex;
}

// Get power limit status (1-4)
int Lstatus(int port, uint8_t bcast_reg, uint8_t status_reg) {
    uint8_t data;
    i2c_read(status_reg, &data);
    
    switch(data) {
        case 0xc4: return 1;  // 5.8W
        case 0xcb: return 2;  // 10.7W
        case 0xd4: return 3;  // 19.5W
        case 0xe2: return 4;  // 33.1W
        default: return -1;
    }
}

// Get detect status (0-7)
int Dstatus(int port, uint8_t bcast_reg, uint8_t status_reg) {
    uint8_t data;
    uint8_t bin[8];
    uint8_t det[3] = {0};
    uint8_t hex;
    int j = 0;
    
    i2c_read(status_reg, &data);
    hex2bin(data, bin);
    setdatabits(bin, 8);
    
    for(int i=5; i<8; i++) {
        det[j++] = bin[i];
    }
    
    bin2hex(det, &hex);
    return hex;
}
