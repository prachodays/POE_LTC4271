#ifndef LTC4271_H
#define LTC4271_H

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
// Miscellaneous
extern uint8_t Bcast_reg;
//extern uint8_t portNo;

extern uint8_t HEX;
extern uint8_t INVBIN[8];
extern uint8_t BIN[8];
extern uint8_t portNo;

// Add at top of header file
#define LTC4271_SUCCESS      0
#define LTC4271_ERR_I2C     1
#define LTC4271_ERR_BIN2HEX 2
#define LTC4271_ERR_INVERT  3
#define LTC4271_ERR_REVSTR  4
#define LTC4271_ERR_SETDATA 5
#define LTC4271_ERR_PORT    8
#define LTC4271_I2C_ADDR 0x5C  // Default I2C address for LTC4271, adjust if different

//ALL functions 
int setPort(int port, int value);
int pdClass(int port, int classType);
int readStatus(int port, uint8_t *status);
int readClass(int port, uint8_t *classType);
int readLimit(int port, uint8_t *limit);
int readDet(int port);
void resetAll(void);

int i2c_read(uint8_t reg, uint8_t *data);
int i2c_write(uint8_t bcast_reg, uint8_t reg, uint8_t value);
void hex2bin(uint8_t hex, uint8_t *bin);
void inverter(uint8_t *bin, uint8_t *invbin);
void revStr(uint8_t *bin);
void bin2hex(uint8_t *bin, uint8_t *hex);
void setdatabits(uint8_t *bin, int len);
int i2c_init(void);
void LTC4271_cleanup(void);

int selectPort(int port, uint8_t *bcastReg, int *portNo);
void initPorts(void);
void initAll(void);
int EDstatus(int port, uint8_t bcast_reg, uint8_t status_reg);
int Cstatus(int port, uint8_t bcast_reg, uint8_t status_reg);
int Lstatus(int port, uint8_t bcast_reg, uint8_t status_reg);
int Dstatus(int port, uint8_t bcast_reg, uint8_t status_reg);

/****************************************************************
 * Section -- Interrupts
 ****************************************************************/

// Register definition: intstat
extern uint8_t intstat;  // Interrupt Status Register, RO
extern uint8_t ord_intstat_supply;  // Supply Interrupt
extern uint8_t msk_intstat_supply;
extern uint8_t ord_intstat_tstart;  // tSTART Interrupt
extern uint8_t msk_intstat_tstart;
extern uint8_t ord_intstat_tcut;    // tCUT Interrupt
extern uint8_t msk_intstat_tcut;
extern uint8_t ord_intstat_class;   // Class Interrupt
extern uint8_t msk_intstat_class;
extern uint8_t ord_intstat_det;     // Detect Interrupt
extern uint8_t msk_intstat_det;
extern uint8_t ord_intstat_dis;     // Disconnect Interrupt
extern uint8_t msk_intstat_dis;
extern uint8_t ord_intstat_pwrgd;   // Power Good Interrupt
extern uint8_t msk_intstat_pwrgd;
extern uint8_t ord_intstat_pwrena;  // Power Enable Interrupt
extern uint8_t msk_intstat_pwrena;

// Register definition: intmask
extern uint8_t intmask;  // Interrupt Mask Register, R/W
extern uint8_t ord_intmask_supply;    // Supply events
extern uint8_t msk_intmask_supply;
extern uint8_t ord_intmask_tstart;    // tSTART events
extern uint8_t msk_intmask_tstart;
extern uint8_t ord_intmask_tcut;      // tCUT events
extern uint8_t msk_intmask_tcut;
extern uint8_t ord_intmask_class;     // Class events
extern uint8_t msk_intmask_class;
extern uint8_t ord_intmask_det;       // Detect events
extern uint8_t msk_intmask_det;
extern uint8_t ord_intmask_dis;       // Disconnect events
extern uint8_t msk_intmask_dis;
extern uint8_t ord_intmask_pwrgd;     // Power Good events
extern uint8_t msk_intmask_pwrgd;
extern uint8_t ord_intmask_pwrena;    // Power Enable events
extern uint8_t msk_intmask_pwrena;

/****************************************************************
 * Section -- Events
 ****************************************************************/

// Register definition: pwrevn
extern uint8_t pwrevn;  // Power Event Register, Read Only
extern uint8_t ord_pwrevn_pwrgd4;     // Port 4 Power Good Change
extern uint8_t msk_pwrevn_pwrgd4;
extern uint8_t ord_pwrevn_pwrgd3;     // Port 3 Power Good Change
extern uint8_t msk_pwrevn_pwrgd3;
extern uint8_t ord_pwrevn_pwrgd2;     // Port 2 Power Good Change
extern uint8_t msk_pwrevn_pwrgd2;
extern uint8_t ord_pwrevn_pwrgd1;     // Port 1 Power Good Change
extern uint8_t msk_pwrevn_pwrgd1;
extern uint8_t ord_pwrevn_pwrena4;    // Port 4 Power Status Change
extern uint8_t msk_pwrevn_pwrena4;
extern uint8_t ord_pwrevn_pwrena3;    // Port 3 Power Status Change
extern uint8_t msk_pwrevn_pwrena3;
extern uint8_t ord_pwrevn_pwrena2;    // Port 2 Power Status Change
extern uint8_t msk_pwrevn_pwrena2;
extern uint8_t ord_pwrevn_pwrena1;    // Port 1 Power Status Change
extern uint8_t msk_pwrevn_pwrena1;

// Register definition: pwrevn_cor
extern uint8_t pwrevn_cor;  // Power Event Register, Clear on Read
extern uint8_t ord_pwrevn_cor_pwrgd4;     // Port 4 Power Good Change
extern uint8_t msk_pwrevn_cor_pwrgd4;
extern uint8_t ord_pwrevn_cor_pwrgd3;     // Port 3 Power Good Change
extern uint8_t msk_pwrevn_cor_pwrgd3;
extern uint8_t ord_pwrevn_cor_pwrgd2;     // Port 2 Power Good Change
extern uint8_t msk_pwrevn_cor_pwrgd2;
extern uint8_t ord_pwrevn_cor_pwrgd1;     // Port 1 Power Good Change
extern uint8_t msk_pwrevn_cor_pwrgd1;
extern uint8_t ord_pwrevn_cor_pwrena4;    // Port 4 Power Status Change
extern uint8_t msk_pwrevn_cor_pwrena4;
extern uint8_t ord_pwrevn_cor_pwrena3;    // Port 3 Power Status Change
extern uint8_t msk_pwrevn_cor_pwrena3;
extern uint8_t ord_pwrevn_cor_pwrena2;    // Port 2 Power Status Change
extern uint8_t msk_pwrevn_cor_pwrena2;
extern uint8_t ord_pwrevn_cor_pwrena1;    // Port 1 Power Status Change
extern uint8_t msk_pwrevn_cor_pwrena1;

// Register definition: detevn
extern uint8_t detevn;  // Detect and Classification Event Register, Read Only
extern uint8_t ord_detevn_class4;    // Port 4 Classification Complete
extern uint8_t msk_detevn_class4;
extern uint8_t ord_detevn_class3;    // Port 3 Classification Complete
extern uint8_t msk_detevn_class3;
extern uint8_t ord_detevn_class2;    // Port 2 Classification Complete
extern uint8_t msk_detevn_class2;
extern uint8_t ord_detevn_class1;    // Port 1 Classification Complete
extern uint8_t msk_detevn_class1;
extern uint8_t ord_detevn_det4;      // Port 4 Detection Complete
extern uint8_t msk_detevn_det4;
extern uint8_t ord_detevn_det3;      // Port 3 Detection Complete
extern uint8_t msk_detevn_det3;
extern uint8_t ord_detevn_det2;      // Port 2 Detection Complete
extern uint8_t msk_detevn_det2;
extern uint8_t ord_detevn_det1;      // Port 1 Detection Complete
extern uint8_t msk_detevn_det1;

// Register definition: detevn_cor
extern uint8_t detevn_cor;  // Detect and Classification Event Register, Clear on Read
extern uint8_t ord_detevn_cor_class4;    // Port 4 Classification Complete
extern uint8_t msk_detevn_cor_class4;
extern uint8_t ord_detevn_cor_class3;    // Port 3 Classification Complete
extern uint8_t msk_detevn_cor_class3;
extern uint8_t ord_detevn_cor_class2;    // Port 2 Classification Complete
extern uint8_t msk_detevn_cor_class2;
extern uint8_t ord_detevn_cor_class1;    // Port 1 Classification Complete
extern uint8_t msk_detevn_cor_class1;
extern uint8_t ord_detevn_cor_det4;      // Port 4 Detection Complete
extern uint8_t msk_detevn_cor_det4;
extern uint8_t ord_detevn_cor_det3;      // Port 3 Detection Complete
extern uint8_t msk_detevn_cor_det3;
extern uint8_t ord_detevn_cor_det2;      // Port 2 Detection Complete
extern uint8_t msk_detevn_cor_det2;
extern uint8_t ord_detevn_cor_det1;      // Port 1 Detection Complete
extern uint8_t msk_detevn_cor_det1;

// Register definition: fltevn
extern uint8_t fltevn;  // Fault Event Register, Read Only
extern uint8_t ord_fltevn_dis4;     // Port 4 disconnect time out (tDIS)
extern uint8_t msk_fltevn_dis4;
extern uint8_t ord_fltevn_dis3;     // Port 3 disconnect time out (tDIS)
extern uint8_t msk_fltevn_dis3;
extern uint8_t ord_fltevn_dis2;     // Port 2 disconnect time out (tDIS)
extern uint8_t msk_fltevn_dis2;
extern uint8_t ord_fltevn_dis1;     // Port 1 disconnect time out (tDIS)
extern uint8_t msk_fltevn_dis1;
extern uint8_t ord_fltevn_tcut4;    // Port 4 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_tcut4;
extern uint8_t ord_fltevn_tcut3;    // Port 3 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_tcut3;
extern uint8_t ord_fltevn_tcut2;    // Port 2 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_tcut2;
extern uint8_t ord_fltevn_tcut1;    // Port 1 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_tcut1;

// Register definition: fltevn_cor
extern uint8_t fltevn_cor;  // Fault Event Register, Clear on Read
extern uint8_t ord_fltevn_cor_dis4;     // Port 4 disconnect time out (tDIS)
extern uint8_t msk_fltevn_cor_dis4;
extern uint8_t ord_fltevn_cor_dis3;     // Port 3 disconnect time out (tDIS)
extern uint8_t msk_fltevn_cor_dis3;
extern uint8_t ord_fltevn_cor_dis2;     // Port 2 disconnect time out (tDIS)
extern uint8_t msk_fltevn_cor_dis2;
extern uint8_t ord_fltevn_cor_dis1;     // Port 1 disconnect time out (tDIS)
extern uint8_t msk_fltevn_cor_dis1;
extern uint8_t ord_fltevn_cor_tcut4;    // Port 4 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_cor_tcut4;
extern uint8_t ord_fltevn_cor_tcut3;    // Port 3 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_cor_tcut3;
extern uint8_t ord_fltevn_cor_tcut2;    // Port 2 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_cor_tcut2;
extern uint8_t ord_fltevn_cor_tcut1;    // Port 1 overcurrent time out (tCUT)
extern uint8_t msk_fltevn_cor_tcut1;

// Register definition: tsevn
extern uint8_t tsevn;  // tSTART Event Register, Read Only
extern uint8_t ord_tsevn_tlim4;    // Port 4 current limit time out
extern uint8_t msk_tsevn_tlim4;
extern uint8_t ord_tsevn_tlim3;    // Port 3 current limit time out
extern uint8_t msk_tsevn_tlim3;
extern uint8_t ord_tsevn_tlim2;    // Port 2 current limit time out
extern uint8_t msk_tsevn_tlim2;
extern uint8_t ord_tsevn_tlim1;    // Port 1 current limit time out
extern uint8_t msk_tsevn_tlim1;
extern uint8_t ord_tsevn_tstart4;    // Port 4 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_tstart4;
extern uint8_t ord_tsevn_tstart3;    // Port 3 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_tstart3;
extern uint8_t ord_tsevn_tstart2;    // Port 2 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_tstart2;
extern uint8_t ord_tsevn_tstart1;    // Port 1 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_tstart1;

// Register definition: tsevn_cor
extern uint8_t tsevn_cor;  // tSTART Event Register, Clear on Read
extern uint8_t ord_tsevn_cor_tlim4;      // Port 4 current limit time out
extern uint8_t msk_tsevn_cor_tlim4;
extern uint8_t ord_tsevn_cor_tlim3;      // Port 3 current limit time out
extern uint8_t msk_tsevn_cor_tlim3;
extern uint8_t ord_tsevn_cor_tlim2;      // Port 2 current limit time out
extern uint8_t msk_tsevn_cor_tlim2;
extern uint8_t ord_tsevn_cor_tlim1;      // Port 1 current limit time out
extern uint8_t msk_tsevn_cor_tlim1;
extern uint8_t ord_tsevn_cor_tstart4;    // Port 4 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_cor_tstart4;
extern uint8_t ord_tsevn_cor_tstart3;    // Port 3 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_cor_tstart3;
extern uint8_t ord_tsevn_cor_tstart2;    // Port 2 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_cor_tstart2;
extern uint8_t ord_tsevn_cor_tstart1;    // Port 1 startup overcurrent time out (tSTART)
extern uint8_t msk_tsevn_cor_tstart1;

// Register definition: supevn
extern uint8_t supevn;  // Supply Event Register, Read Only
extern uint8_t ord_supevn_overtemp;  // Over Temperature
extern uint8_t msk_supevn_overtemp;
extern uint8_t ord_supevn_fetbad;    // External FET failure
extern uint8_t msk_supevn_fetbad;
extern uint8_t ord_supevn_uvlo3;     // Digital Supply (VDD) UVLO
extern uint8_t msk_supevn_uvlo3;
extern uint8_t ord_supevn_uvlo48;    // Analog Supply (VEE) UVLO
extern uint8_t msk_supevn_uvlo48;

// Register definition: supevn_cor
extern uint8_t supevn_cor;  // Supply Event Register, Clear on Read
extern uint8_t ord_supevn_cor_overtemp;    // Over Temperature
extern uint8_t msk_supevn_cor_overtemp;
extern uint8_t ord_supevn_cor_fetbad;      // External FET failure
extern uint8_t msk_supevn_cor_fetbad;
extern uint8_t ord_supevn_cor_uvlo3;       // Digital Supply (VDD) UVLO
extern uint8_t msk_supevn_cor_uvlo3;
extern uint8_t ord_supevn_cor_uvlo48;      // Analog Supply (VEE) UVLO
extern uint8_t msk_supevn_cor_uvlo48;

// Register definition: statp1
extern uint8_t statp1;  // Port 1 Status, Read Only
extern uint8_t ord_statp1_poepp;  // POE++ result
extern uint8_t msk_statp1_poepp;
extern uint8_t ord_statp1_class;   // Classification result
extern uint8_t msk_statp1_class;
extern uint8_t ord_statp1_detect;  // Detection result
extern uint8_t msk_statp1_detect;

// Register definition: statp2
extern uint8_t statp2;  // Port 2 Status, Read Only
extern uint8_t ord_statp2_poepp;  // POE++ result
extern uint8_t msk_statp2_poepp;
extern uint8_t ord_statp2_class;   // Classification result
extern uint8_t msk_statp2_class;
extern uint8_t ord_statp2_detect;  // Detection result
extern uint8_t msk_statp2_detect;

// Register definition: statp3
extern uint8_t statp3;  // Port 3 Status, Read Only
extern uint8_t ord_statp3_poepp;  // POE++ result
extern uint8_t msk_statp3_poepp;
extern uint8_t ord_statp3_class;   // Classification result
extern uint8_t msk_statp3_class;
extern uint8_t ord_statp3_detect;  // Detection result
extern uint8_t msk_statp3_detect;

// Register definition: statp4
extern uint8_t statp4;  // Port 4 Status, Read Only
extern uint8_t ord_statp4_poepp;  // POE++ result
extern uint8_t msk_statp4_poepp;
extern uint8_t ord_statp4_class;   // Classification result
extern uint8_t msk_statp4_class;
extern uint8_t ord_statp4_detect;  // Detection result
extern uint8_t msk_statp4_detect;

// Register definition: statpwr
//uint8_t statpwr = 0x10;  // Power Status, Read Only
extern uint8_t ord_statpwr_pg4;    // Power good on port 4
extern uint8_t msk_statpwr_pg4;
extern uint8_t ord_statpwr_pg3;    // Power good on port 3
extern uint8_t msk_statpwr_pg3;
extern uint8_t ord_statpwr_pg2;    // Power good on port 2
extern uint8_t msk_statpwr_pg2;
extern uint8_t ord_statpwr_pg1;    // Power good on port 1
extern uint8_t msk_statpwr_pg1;
extern uint8_t ord_statpwr_pe4;    // Power enabled on port 4
extern uint8_t msk_statpwr_pe4;
extern uint8_t ord_statpwr_pe3;    // Power enabled on port 3
extern uint8_t msk_statpwr_pe3;
extern uint8_t ord_statpwr_pe2;    // Power enabled on port 2
extern uint8_t msk_statpwr_pe2;
extern uint8_t ord_statpwr_pe1;    // Power enabled on port 1
extern uint8_t msk_statpwr_pe1;

// Register definition: statpin
extern uint8_t statpin;  // Pin Status, Read Only
extern uint8_t ord_statpin_ad6;     // SMBus address 6
extern uint8_t msk_statpin_ad6;
extern uint8_t ord_statpin_ad3;     // SMBus address 3
extern uint8_t msk_statpin_ad3;
extern uint8_t ord_statpin_ad2;     // SMBus address 2
extern uint8_t msk_statpin_ad2;
extern uint8_t ord_statpin_ad1;     // SMBus address 1
extern uint8_t msk_statpin_ad1;
extern uint8_t ord_statpin_ad0;     // SMBus address 0
extern uint8_t msk_statpin_ad0;
extern uint8_t ord_statpin_mid;     // MID pin state
extern uint8_t msk_statpin_mid;
extern uint8_t ord_statpin_auto;    // AUTO pin state
extern uint8_t msk_statpin_auto;

/****************************************************************
 * Section -- Configuration
 ****************************************************************/

// Register definition: opmd
extern uint8_t opmd;  // Operating Mode, R/W
extern uint8_t ord_opmd_opmd4;    // Operating mode, port 4
extern uint8_t msk_opmd_opmd4;
extern uint8_t ord_opmd_opmd3;    // Operating mode, port 3
extern uint8_t msk_opmd_opmd3;
extern uint8_t ord_opmd_opmd2;    // Operating mode, port 2
extern uint8_t msk_opmd_opmd2;
extern uint8_t ord_opmd_opmd1;    // Operating mode, port 1
extern uint8_t msk_opmd_opmd1;

// Register definition: disena
extern uint8_t disena;  // Disconnect Sensing Enable, R/W
extern uint8_t ord_disena_eml_ac4;    // Emulate AC disconnect on port 4
extern uint8_t msk_disena_eml_ac4;
extern uint8_t ord_disena_eml_ac3;    // Emulate AC disconnect on port 3
extern uint8_t msk_disena_eml_ac3;
extern uint8_t ord_disena_eml_ac2;    // Emulate AC disconnect on port 2
extern uint8_t msk_disena_eml_ac2;
extern uint8_t ord_disena_eml_ac1;    // Emulate AC disconnect on port 1
extern uint8_t msk_disena_eml_ac1;
extern uint8_t ord_disena_dc4;        // Enable DC disconnect on port 4
extern uint8_t msk_disena_dc4;
extern uint8_t ord_disena_dc3;        // Enable DC disconnect on port 3
extern uint8_t msk_disena_dc3;
extern uint8_t ord_disena_dc2;        // Enable DC disconnect on port 2
extern uint8_t msk_disena_dc2;
extern uint8_t ord_disena_dc1;        // Enable DC disconnect on port 1
extern uint8_t msk_disena_dc1;

// Register definition: detena
extern uint8_t detena;  // Detect and Class Enable, Read/Write
extern uint8_t ord_detena_cls4;    // Enable classification on port 4
extern uint8_t msk_detena_cls4;
extern uint8_t ord_detena_cls3;    // Enable classification on port 3
extern uint8_t msk_detena_cls3;
extern uint8_t ord_detena_cls2;    // Enable classification on port 2
extern uint8_t msk_detena_cls2;
extern uint8_t ord_detena_cls1;    // Enable classification on port 1
extern uint8_t msk_detena_cls1;
extern uint8_t ord_detena_det4;    // Enable detection on port 4
extern uint8_t msk_detena_det4;
extern uint8_t ord_detena_det3;    // Enable detection on port 3
extern uint8_t msk_detena_det3;
extern uint8_t ord_detena_det2;    // Enable detection on port 2
extern uint8_t msk_detena_det2;
extern uint8_t ord_detena_det1;    // Enable detection on port 1
extern uint8_t msk_detena_det1;

// Register definition: midspan
extern uint8_t midspan;  // Midspan Backoff Enable, R/W
extern uint8_t ord_midspan_midsp4;    // Enable midspan backoff on port 4
extern uint8_t msk_midspan_midsp4;
extern uint8_t ord_midspan_midsp3;    // Enable midspan backoff on port 3
extern uint8_t msk_midspan_midsp3;
extern uint8_t ord_midspan_midsp2;    // Enable midspan backoff on port 2
extern uint8_t msk_midspan_midsp2;
extern uint8_t ord_midspan_midsp1;    // Enable midspan backoff on port 1
extern uint8_t msk_midspan_midsp1;

// Register definition: mconf
extern uint8_t mconf;  // Miscellaneous Configuration, R/W
extern uint8_t ord_mconf_intena;  // Interrupt pin enable
extern uint8_t msk_mconf_intena;
extern uint8_t ord_mconf_detchg;    // Detect change reporting
extern uint8_t msk_mconf_detchg;
extern uint8_t ord_mconf_reserved;  // Reserved
extern uint8_t msk_mconf_reserved;
extern uint8_t ord_mconf_fasti;     // Fast current measurement
extern uint8_t msk_mconf_fasti;
extern uint8_t ord_mconf_msdmsk4;  // MSD mask port 4
extern uint8_t msk_mconf_msdmsk4;
extern uint8_t ord_mconf_msdmsk3;  // MSD mask port 3
extern uint8_t msk_mconf_msdmsk3;
extern uint8_t ord_mconf_msdmsk2;  // MSD mask port 2
extern uint8_t msk_mconf_msdmsk2;
extern uint8_t ord_mconf_msdmsk1;  // MSD mask port 1
extern uint8_t msk_mconf_msdmsk1;

/****************************************************************
 * Section -- Pushbuttons
 ****************************************************************/

// Register definition: detpb
extern uint8_t detpb;  // Detection and Classification Restart Pushbutton
extern uint8_t ord_detpb_cls4;  // Set classification port 4
extern uint8_t msk_detpb_cls4;
extern uint8_t ord_detpb_cls3;  // Set classification port 3
extern uint8_t msk_detpb_cls3;
extern uint8_t ord_detpb_cls2;  // Set classification port 2
extern uint8_t msk_detpb_cls2;
extern uint8_t ord_detpb_cls1;  // Set classification port 1
extern uint8_t msk_detpb_cls1;
extern uint8_t ord_detpb_det4;  // Set detection port 4
extern uint8_t msk_detpb_det4;
extern uint8_t ord_detpb_det3;  // Set detection port 3
extern uint8_t msk_detpb_det3;
extern uint8_t ord_detpb_det2;  // Set detection port 2
extern uint8_t msk_detpb_det2;
extern uint8_t ord_detpb_det1;  // Set detection port 1
extern uint8_t msk_detpb_det1;

// Register definition: pwrpb
extern uint8_t pwrpb;  // Power On/Off Pushbutton
extern uint8_t ord_pwrpb_off4;    // Reset port 4
extern uint8_t msk_pwrpb_off4;
extern uint8_t ord_pwrpb_off3;    // Reset port 3
extern uint8_t msk_pwrpb_off3;
extern uint8_t ord_pwrpb_off2;    // Reset port 2
extern uint8_t msk_pwrpb_off2;
extern uint8_t ord_pwrpb_off1;    // Reset port 1
extern uint8_t msk_pwrpb_off1;
extern uint8_t ord_pwrpb_on4;     // Power on port 4
extern uint8_t msk_pwrpb_on4;
extern uint8_t ord_pwrpb_on3;     // Power on port 3
extern uint8_t msk_pwrpb_on3;
extern uint8_t ord_pwrpb_on2;     // Power on port 2
extern uint8_t msk_pwrpb_on2;
extern uint8_t ord_pwrpb_on1;     // Power on port 1
extern uint8_t msk_pwrpb_on1;

// Register definition: rstpb
extern uint8_t rstpb; // Reset Pushbutton
extern uint8_t ord_rstpb_intclr;    // Clear interrupts
extern uint8_t msk_rstpb_intclr;
extern uint8_t ord_rstpb_pinclr;    // Clear interrupt pin
extern uint8_t msk_rstpb_pinclr;
extern uint8_t ord_rstpb_rstall;    // Reset LTC4266
//uint8_t msk_rstpb_rstall = 0x10;

// the _RESET pin low.
extern uint8_t msk_rstpb_rstall;
extern uint8_t ord_rstpb_rst4;      // Reset port 4.
extern uint8_t msk_rstpb_rst4;   
extern uint8_t ord_rstpb_rst3;      // Reset port 3.
extern uint8_t msk_rstpb_rst3;   
extern uint8_t ord_rstpb_rst2;      // Reset port 2.
extern uint8_t msk_rstpb_rst2;   
extern uint8_t ord_rstpb_rst1;      // Reset port 1.
extern uint8_t msk_rstpb_rst1;   

/****************************************************************
 * Section -- Debug
 ****************************************************************/

// Register definition: id
extern uint8_t id;  // Chip Identification Register, Read Only. LTC4259 compatible,
                // i.e. the device and revision ID are the same as the
                // LTC4259A.
extern uint8_t ord_id_dev;     // Device identification number.
extern uint8_t msk_id_dev;  
extern uint8_t ord_id_rev;     // Revision number.
extern uint8_t msk_id_rev;  

/****************************************************************
 * Section --  Limit Timing
 ****************************************************************/

// Register definition: tlim
extern uint8_t tlim;  // tLIM timer duration for all ports. R/W. The port's tLIM timer
                  // counts up when the port is in current limit and resets when
                  // the port is not in current limit. If the timer expires then
                  // the port turns off and the tLIM bit in register 08h is set.
extern uint8_t ord_tlim_tlim4;  // tLIM timer duration on port 4. If this bit is set the timer is
                         // set to 12ms. If this bit is cleared, the timer is disabled.
extern uint8_t msk_tlim_tlim4;
//uint8_t ord_tlim_tlim4 = 3;     // tLIM timer duration on port 4. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
//uint8_t msk_tlim_tlim4 = 0x08;
extern uint8_t ord_tlim_tlim3;     // tLIM timer duration on port 3. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
extern uint8_t msk_tlim_tlim3;
extern uint8_t ord_tlim_tlim2;     // tLIM timer duration on port 2. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
extern uint8_t msk_tlim_tlim2;
extern uint8_t ord_tlim_tlim1;     // tLIM timer duration on port 1. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
extern uint8_t msk_tlim_tlim1;

/****************************************************************
 * Section --  General Purpose IO
 ****************************************************************/

// Register definition: gpiooen
extern uint8_t gpiooen;               // General Purpose IO Output Enable, R/W
extern uint8_t ord_gpiooen_gpiooen2;     // GPIO%b Output Enable%{cr}See bit 0 description.
extern uint8_t msk_gpiooen_gpiooen2;
extern uint8_t ord_gpiooen_gpiooen1;     // GPIO%b Output Enable%{cr}See bit 0 description.
extern uint8_t msk_gpiooen_gpiooen1;
extern uint8_t ord_gpiooen_gpiooen0;     // GPIO%b Output Enable%{cr}When set this output is enabled and
                                  // con be controlled via gpioout bit %b. When cleared this
                                  // output operates in read-only mode. Input status can be read
                                  // from gpioin bit %b.
extern uint8_t msk_gpiooen_gpiooen0;

// Register definition: gpioout
extern uint8_t gpioout;               // General Purpose IO Output Value, R/W
extern uint8_t ord_gpioout_gpioout2;     // GPIO%b Output State
extern uint8_t msk_gpioout_gpioout2;
extern uint8_t ord_gpioout_gpioout1;     // GPIO%b Output State
extern uint8_t msk_gpioout_gpioout1;
extern uint8_t ord_gpioout_gpioout0;     // GPIO%b Output State
extern uint8_t msk_gpioout_gpioout0;

// Register definition: gpioin
extern uint8_t gpioin;              // General Purpose IO Input Value, R/W
extern uint8_t ord_gpioin_gpioin2;     // GPIO%b Input Value
extern uint8_t msk_gpioin_gpioin2;
extern uint8_t ord_gpioin_gpioin1;     // GPIO%b Input Value
extern uint8_t msk_gpioin_gpioin1;
extern uint8_t ord_gpioin_gpioin0;     // GPIO%b Input Value
extern uint8_t msk_gpioin_gpioin0;

// Register definition: portmonconf
extern uint8_t portmonconf;               // Port Monitor Configuration
extern uint8_t ord_portmonconf_filter_type;  // When this bit is set, the reported port currents represent
                                     // only the previous 100ms window. When this bit is clear, the
                                     // reported port currents are updated every 100ms, but
                                     // represent the rolling average of the previous 1sec window.
extern uint8_t msk_portmonconf_filter_type;

// Register definition: veelsb
extern uint8_t veelsb;             // Vee Supply Voltage Measurement LSB, R/W.
extern uint8_t ord_veelsb_veelsb;     // Vee Voltage LSB. 1 LSB =5.845mV
extern uint8_t msk_veelsb_veelsb;

// Register definition: veemsb
extern uint8_t veemsb;             // Vee Supply Voltage Measurement MSB, R/W.
extern uint8_t ord_veemsb_veemsb;     
extern uint8_t msk_veemsb_veemsb;

/****************************************************************
 * Section -- Port Parametric Measurement
 ****************************************************************/

// Register definition: ip1lsb
extern uint8_t ip1lsb;          // Port 1 Current Measurement LSB, Read Only.
extern uint8_t ord_ip1lsb_ip1lsb;  // Port 1 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
extern uint8_t msk_ip1lsb_ip1lsb;

// Register definition: ip1msb
extern uint8_t ip1msb;             // Port 1 Current Measurement MSB, Read Only.
extern uint8_t ord_ip1msb_ip1msb;     // Port 1 Current MSB.
extern uint8_t msk_ip1msb_ip1msb;

// Register definition: vp1lsb
extern uint8_t vp1lsb;             // Port 1 Voltage Measurement LSB, Read Only.
extern uint8_t ord_vp1lsb_vp1lsb;     // Port 1 Voltage LSB. 1 LSB =5.845mV
extern uint8_t msk_vp1lsb_vp1lsb;

// Register definition: vp1msb
extern uint8_t vp1msb;             // Port 1 Voltage Measurement MSB, Read Only.
extern uint8_t ord_vp1msb_vp1msb;     // Port 1 Voltage MSB.
extern uint8_t msk_vp1msb_vp1msb;

// Register definition: ip2lsb
extern uint8_t ip2lsb;          // Port 2 Current Measurement LSB, Read Only.
extern uint8_t ord_ip2lsb_ip2lsb;  // Port 2 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
extern uint8_t msk_ip2lsb_ip2lsb;

// Register definition: ip2msb
extern uint8_t ip2msb;             // Port 2 Current Measurement MSB, Read Only.
extern uint8_t ord_ip2msb_ip2msb;     // Port 2 Current MSB.
extern uint8_t msk_ip2msb_ip2msb;

// Register definition: vp2lsb
extern uint8_t vp2lsb;             // Port 2 Voltage Measurement LSB, Read Only.
extern uint8_t ord_vp2lsb_vp2lsb;     // Port 2 Voltage LSB. 1 LSB =5.845mV
extern uint8_t msk_vp2lsb_vp2lsb;

// Register definition: vp2msb
extern uint8_t vp2msb;             // Port 2 Voltage Measurement MSB, Read Only.
extern uint8_t ord_vp2msb_vp2msb;     // Port 2 Voltage MSB.
extern uint8_t msk_vp2msb_vp2msb;

// Register definition: ip3lsb
extern uint8_t ip3lsb;          // Port 3 Current Measurement LSB, Read Only.
extern uint8_t ord_ip3lsb_ip3lsb;  // Port 3 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
extern uint8_t msk_ip3lsb_ip3lsb;

// Register definition: ip3msb
extern uint8_t ip3msb;             // Port 3 Current Measurement MSB, Read Only.
extern uint8_t ord_ip3msb_ip3msb;     // Port 3 Current MSB.
extern uint8_t msk_ip3msb_ip3msb;

// Register definition: vp3lsb
extern uint8_t vp3lsb;             // Port 3 Voltage Measurement LSB, Read Only.
extern uint8_t ord_vp3lsb_vp3lsb;     // Port 3 Voltage LSB. 1 LSB =5.845mV
extern uint8_t msk_vp3lsb_vp3lsb;

// Register definition: vp3msb
extern uint8_t vp3msb;             // Port 3 Voltage Measurement MSB, Read Only.
extern uint8_t ord_vp3msb_vp3msb;     // Port 3 Voltage MSB.
extern uint8_t msk_vp3msb_vp3msb;

// Register definition: ip4lsb
extern uint8_t ip4lsb;          // Port 4 Current Measurement LSB, Read Only.
extern uint8_t ord_ip4lsb_ip4lsb;  // Port 4 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
extern uint8_t msk_ip4lsb_ip4lsb;

// Register definition: ip4msb
extern uint8_t ip4msb;             // Port 4 Current Measurement MSB, Read Only.
extern uint8_t ord_ip4msb_ip4msb;     // Port 4 Current MSB.
extern uint8_t msk_ip4msb_ip4msb;

// Register definition: vp4lsb
extern uint8_t vp4lsb;             // Port 4 Voltage Measurement LSB, Read Only.
extern uint8_t ord_vp4lsb_vp4lsb;     // Port 4 Voltage LSB. 1 LSB =5.845mV
extern uint8_t msk_vp4lsb_vp4lsb;

// Register definition: vp4msb
extern uint8_t vp4msb;            // Port 4 Voltage Measurement MSB, Read Only.
extern uint8_t ord_vp4msb_vp4msb;     // Port 4 Voltage MSB.
extern uint8_t msk_vp4msb_vp4msb;

/****************************************************************
 * Section -- Configuration 1
 ****************************************************************/

// Register definition: firmware
extern uint8_t firmware;          // Firmware Revision Code, Read Only.
extern uint8_t ord_firmware_rev;     // Firmware Revision Code.
extern uint8_t msk_firmware_rev;

// Register definition: wdog
extern uint8_t wdog;  // Watchdog Register, R/W. The LTC4266 monitors activity on the
                  // SCL pin. If the SCL pin does not transition high or low in
                  // 2.5 seconds (typ.) the wdstat bit is set and ports are
                  // reset. Also displays current status of over/under voltage
                  // conditions and thermal shutdown.
extern uint8_t ord_wdog_tsd;  // TSD monitor. This bit is set when the chip is in thermal
                       // shutdown.
extern uint8_t msk_wdog_tsd;
extern uint8_t ord_wdog_ov48;    // OV48 monitor. This bit is set when the 48V supply is above
                          // safe limits.
extern uint8_t msk_wdog_ov48;
extern uint8_t ord_wdog_uv48;     // UV48 monitor. This bit is set when the 48V supply is too low
                           // to meet IEEE 802.3 specifications.
extern uint8_t msk_wdog_uv48;
extern uint8_t ord_wdog_wddis;    // Watchdog disable. When this field is set to 1011b the
                           // watchdog is disabled. Otherwise the SMBus watchdog is
                           // enabled.
extern uint8_t msk_wdog_wddis;
extern uint8_t ord_wdog_wdstat;    // Status of the watchdog. When the watchdog times out, this
                            // bit is set and all ports are reset. This bit must be clear
                            // for ports to be enabled.
extern uint8_t msk_wdog_wdstat;

// Register definition: devid
extern uint8_t devid;               // Device Identification Register, Read Only.
extern uint8_t ord_devid_features;     // Device ID, Read Only.
extern uint8_t msk_devid_features;
extern uint8_t ord_devid_rev;          // Device revision, Read Only.
extern uint8_t msk_devid_rev;       

/****************************************************************
 * Section -- High Power Features, Global
 ****************************************************************/

// Register definition: hpen
extern uint8_t hpen;  // High Power Enable Register, R/W. This register enables the
                  // features in address 46h through 5Fh and disables the use of
                  // overcurrent (ICUT) and current limit (ILIM) settings from
                  // registers 2Ah, 2Bh, and 40h on a per port basis.
extern uint8_t ord_hpen_poeppen4;  // Enable POE++ features on port 4. When this bit is set, a
                            // LTPoE++ physical class will be issued and extended class
                            // information will be posted to the statp4 register.
extern uint8_t msk_hpen_poeppen4;
extern uint8_t ord_hpen_poeppen3;     // Enable POE++ features on port 3. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp3 register.
extern uint8_t msk_hpen_poeppen3;
extern uint8_t ord_hpen_poeppen2;     // Enable POE++ features on port 2. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp2 register.
extern uint8_t msk_hpen_poeppen2;
extern uint8_t ord_hpen_poeppen1;     // Enable POE++ features on port 1. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp1 register.
extern uint8_t msk_hpen_poeppen1;
extern uint8_t ord_hpen_hpen4;        // Enable high power features on port 4. When this bit is
                               // cleared, high power features are disabled and registers 55h
                               // through 58h have no effect.
extern uint8_t msk_hpen_hpen4;
extern uint8_t ord_hpen_hpen3;     // Enable high power features on port 3. When this bit is
                            // cleared, high power features are disabled and registers 50h
                            // through 53h have no effect.
extern uint8_t msk_hpen_hpen3;
extern uint8_t ord_hpen_hpen2;     // Enable high power features on port 2. When this bit is
                            // cleared, high power features are disabled and registers 4Bh
                            // through 4Eh have no effect.
extern uint8_t msk_hpen_hpen2;
extern uint8_t ord_hpen_hpen1;     // Enable high power features on port 1. When this bit is
                            // cleared, high power features are disabled and registers 46h
                            // through 49h have no effect.
extern uint8_t msk_hpen_hpen1;

/****************************************************************
 * Section -- High Power Features, Port 1
 ****************************************************************/

// Register definition: hpmd1
extern uint8_t hpmd1;  // High Power Modes Port 1, Read/Write. Controls high power
                   // modes and features on port 1.
extern uint8_t ord_hpmd1_legen;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 1. When this bit is set a PD with a
                          // large common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp1 register).
extern uint8_t msk_hpmd1_legen;   
extern uint8_t ord_hpmd1_pongen;     // Enable Ping-Pong classification on port 1.
extern uint8_t msk_hpmd1_pongen;

// Register definition: cut1
extern uint8_t cut1;  // Port 1 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
extern uint8_t ord_cut1_rdis;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
extern uint8_t msk_cut1_rdis;    
extern uint8_t ord_cut1_cutrng;     // Adjust overcurrent threshold range on port . See Table IC1
extern uint8_t msk_cut1_cutrng;
extern uint8_t ord_cut1_cut;        // Set threshold of overcurrent comparator on port . See Table
                            // IC1.
extern uint8_t msk_cut1_cut;

// Register definition: lim1
extern uint8_t lim1;  // Current limit and foldback profiles for port 1, R/W. This
                  // register adjusts the current limit on port 1.
extern uint8_t ord_lim1_lim;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
extern uint8_t msk_lim1_lim;

// Register definition: hpstat1
extern uint8_t hpstat1;             // Status of Advanced and High Power Features on Port 1, Read Only.
extern uint8_t ord_hpstat1_polavgevn;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
extern uint8_t msk_hpstat1_polavgevn;
extern uint8_t ord_hpstat1_fetbad;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
extern uint8_t msk_hpstat1_fetbad;
extern uint8_t ord_hpstat1_pongpd;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
extern uint8_t msk_hpstat1_pongpd;

/****************************************************************
 * Section -- High Power Features, Port 2
 ****************************************************************/

// Register definition: hpmd2
extern uint8_t hpmd2;  // High Power Modes Port 2, R/W. Controls high power modes and
                   // features on port 2.
extern uint8_t ord_hpmd2_legen;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 2. When this bit is set a PD with a large
                          // common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp2 register).
extern uint8_t msk_hpmd2_legen;   
extern uint8_t ord_hpmd2_pongen;     // Enable Ping-Pong classification on port 2.
extern uint8_t msk_hpmd2_pongen;

// Register definition: cut2
extern uint8_t cut2;  // Port 2 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
extern uint8_t ord_cut2_rdis;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
extern uint8_t msk_cut2_rdis;    
extern uint8_t ord_cut2_cutrng;     // Adjust overcurrent threshold range on port 2. See Table IC1
extern uint8_t msk_cut2_cutrng;
extern uint8_t ord_cut2_cut;        // Set threshold of overcurrent comparator on port 2. See Table
                            // IC1.
extern uint8_t msk_cut2_cut;

// Register definition: lim2
extern uint8_t lim2;  // Current limit and foldback profiles for port 2, R/W. This
                  // register adjusts the current limit on port 2.
extern uint8_t ord_lim2_lim;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
extern uint8_t msk_lim2_lim;

// Register definition: hpstat2
extern uint8_t hpstat2;             // Status of Advanced and High Power Features on Port 2, Read Only.
extern uint8_t ord_hpstat2_polavgevn;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
extern uint8_t msk_hpstat2_polavgevn;
extern uint8_t ord_hpstat2_fetbad;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
extern uint8_t msk_hpstat2_fetbad;
extern uint8_t ord_hpstat2_pongpd;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
extern uint8_t msk_hpstat2_pongpd;

/****************************************************************
 * Section -- High Power Features, Port 3
 ****************************************************************/

// Register definition: hpmd3
extern uint8_t hpmd3;  // High Power Modes Port 3, R/W. Controls high power modes and
                   // features on port 3.
extern uint8_t ord_hpmd3_legen;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port . When this bit is set a PD with a large
                          // common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp3 register).
extern uint8_t msk_hpmd3_legen;   
extern uint8_t ord_hpmd3_pongen;     // Enable Ping-Pong classification on port 3.
extern uint8_t msk_hpmd3_pongen;

// Register definition: cut3
extern uint8_t cut3;  // Port 3 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
extern uint8_t ord_cut3_rdis;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
extern uint8_t msk_cut3_rdis;    
extern uint8_t ord_cut3_cutrng;     // Adjust overcurrent threshold range on port 3. See Table IC1
extern uint8_t msk_cut3_cutrng;
extern uint8_t ord_cut3_cut;        // Set threshold of overcurrent comparator on port 3. See Table
                            // IC1.
extern uint8_t msk_cut3_cut;

// Register definition: lim3
extern uint8_t lim3;  // Current limit and foldback profiles for port 3, R/W. This
                  // register adjusts the current limit on port 3.
extern uint8_t ord_lim3_lim;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
extern uint8_t msk_lim3_lim;

// Register definition: hpstat3
extern uint8_t hpstat3;             // Status of Advanced and High Power Features on Port 3, Read Only.
extern uint8_t ord_hpstat3_polavgevn;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
extern uint8_t msk_hpstat3_polavgevn;
extern uint8_t ord_hpstat3_fetbad;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
extern uint8_t msk_hpstat3_fetbad;
extern uint8_t ord_hpstat3_pongpd;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
extern uint8_t msk_hpstat3_pongpd;

/****************************************************************
 * Section -- High Power Features, Port 4
 ****************************************************************/

// Register definition: hpmd4
extern uint8_t hpmd4;  // High Power Modes Port 4, R/W. Controls high power modes and
                   // features on port 4.
extern uint8_t ord_hpmd4_legen;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 4. When this bit is set a PD with a large
                          // common mode capacitance will be reported as a valid
                          // signature (code 4 in the statp4 register).
extern uint8_t msk_hpmd4_legen;   
extern uint8_t ord_hpmd4_pongen;     // Enable Ping-Pong classification on port 4.
extern uint8_t msk_hpmd4_pongen;

// Register definition: cut4
extern uint8_t cut4;  // Port 4 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
extern uint8_t ord_cut4_rdis;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
extern uint8_t msk_cut4_rdis;    
extern uint8_t ord_cut4_cutrng;     // Adjust overcurrent threshold range on port 4. See Table IC1
extern uint8_t msk_cut4_cutrng;
extern uint8_t ord_cut4_cut;        // Set threshold of overcurrent comparator on port 4. See Table
                            // IC1.
extern uint8_t msk_cut4_cut;

// Register definition: lim4
extern uint8_t lim4;  // Current limit and foldback profiles for port 4, R/W. This
                  // register adjusts the current limit on port 4.
extern uint8_t ord_lim4_lim;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
extern uint8_t msk_lim4_lim;

// Register definition: hpstat4
extern uint8_t hpstat4;             // Status of Advanced and High Power Features on Port 4, Read Only.
extern uint8_t ord_hpstat4_polavgevn;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
extern uint8_t msk_hpstat4_polavgevn;
extern uint8_t ord_hpstat4_fetbad;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
extern uint8_t msk_hpstat4_fetbad;
extern uint8_t ord_hpstat4_pongpd;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
extern uint8_t msk_hpstat4_pongpd;

/****************************************************************
 * Section -- MSD
 ****************************************************************/

// Register definition: msdpinmode
extern uint8_t msdpinmode; // MSD Pin Mode, R/W%{cr}The lowest addressed quad controls the

// operation of all quads in a single 12-port chip.
extern uint8_t ord_msdpinmode_msdpolaritycntrl;  // MSD Polarity Control
                                          // Defines the active state of the MSDb pin. When cleared, MSDb active level is low
                                          // (compatible with legacy Linear PSE devices.) When asserted,
                                          // the MSD pin is active high.
extern uint8_t msk_msdpinmode_msdpolaritycntrl;

// Register definition: p1_polcurravg
extern uint8_t p1_polcurravg;                // Port 1 Police Average Current, R/W
extern uint8_t ord_p1_polcurravg_p1_polcurravg; // Specifies a port current threshold. If the one second
                                         // averaged port current window meets or exceeds the specified
                                         // threshold, the port will be turned off and a tCUT event
                                         // will be recorded. In addition, the hpstatN register will
                                         // record a pol_evn_avg event. The LSB size is 15.625mA for
                                         // 0.25ohm sense resistors and 7.81mA for 0.5ohm. When this
                                         // register is zero, average policing is disabled for this port.
extern uint8_t msk_p1_polcurravg_p1_polcurravg;

// Register definition: p2_polcurravg  
extern uint8_t p2_polcurravg;                // Port 2 Police Average Current, R/W
extern uint8_t ord_p2_polcurravg_p2_polcurravg; // See p1_polcurravg description
extern uint8_t msk_p2_polcurravg_p2_polcurravg;

// Register definition: p3_polcurravg
extern uint8_t p3_polcurravg;                // Port 3 Police Average Current, R/W  
extern uint8_t ord_p3_polcurravg_p3_polcurravg; // See p1_polcurravg description
extern uint8_t msk_p3_polcurravg_p3_polcurravg;

// Register definition: p4_polcurravg
extern uint8_t p4_polcurravg;                // Port 1 Police Average Current, R/W
extern uint8_t ord_p4_polcurravg_p4_polcurravg; // See p1_polcurravg description
extern uint8_t msk_p4_polcurravg_p4_polcurravg;

/****************************************************************
 * Section -- Microprocessor Program
 ****************************************************************/

// Register definition: upprogctl
extern uint8_t upprogctl;          // Processor code download mailbox control and status
extern uint8_t ord_upprogctl_jumpram; // The user sets this bit after successfully downloading code
                              // to the cRAM. If this bit is set, firmware will execute
                              // code from the lowest address in cRAM instead of
                              // c.main(). This allows a partial code download and
                              // reutilization of existing ROM code. If this bit is
                              // cleared, firmware will execute romMain and will not utilize
                              // cRAM.
extern uint8_t msk_upprogctl_jumpram;
extern uint8_t ord_upprogctl_ramcrcok;   // When set, a proper code download has completed including a
                                 // final CRC-8 check. This bit is valid only during a full
                                 // download sequence after progrdy is cleared by firmware. At
                                 // all other times this bit will read zero.This bit is also
                                 // used to report RAM MemBIST results during production test.
extern uint8_t msk_upprogctl_ramcrcok;
extern uint8_t ord_upprogctl_progwr;      // When set, the cRAM may be written via the code download
                                  // mailbox.
extern uint8_t msk_upprogctl_progwr;
extern uint8_t ord_upprogctl_progrdy;    // Firmware sets this bit upon to grant a progReq code
                                 // download. By setting this bit firmware guarantees not to be
                                 // running from cRAM. After this bit is set by firmware , the
                                 // user may procede with the code down/upload. When
                                 // progreq is cleared by the user, firmware will execute a
                                 // CRC-8 check on cRAM and post the result to ramcrcok.
                                 // Firmware will then loop waiting for a soft or hard reset.
extern uint8_t msk_upprogctl_progrdy;
extern uint8_t ord_upprogctl_progreq;    // The user sets this bit to signal an intention to download
                                 // new firmware. Once set, the user must wait for progrdy to
                                 // be set by firmware before proceeding with down/upload. Upon
                                 // programming completion, the user must clear this request
                                 // bit to trigger a CRC-8 validation.
extern uint8_t msk_upprogctl_progreq;
extern uint8_t ord_upprogctl_bootram;    // The user sets this bit after successfully downloading code
                                 // to the cRAM. If this bit is set, cRAM will appear at
                                 // address 0, starting at the next soft or hard reset
                                 // exit. This allows a full code download and
                                 // replacement. If this bit is cleared, firmware will
                                 // execute romMain and will not utilize cRAM.
extern uint8_t msk_upprogctl_bootram;

// Register definition: upprogaddlsb
extern uint8_t upprogaddlsb;               // uP Program Address LSB, R/W
extern uint8_t ord_upprogaddlsb_upprogaddlsb; // The user sets the LSB of the address to upload or download
                                       // from/to in this register. On every read or write
                                       // (respectively) to the upprogdata register the
                                       // upprogaddmsb/lsb pair will be auto-incremented by one.On a
                                       // RAM BIST failure, address failure information is recorded
                                       // to this register.
extern uint8_t msk_upprogaddlsb_upprogaddlsb;

// Register definition: upprogaddmsb
extern uint8_t upprogaddmsb;             // uP Program Address MSB, R/W
extern uint8_t ord_upprogaddmsb_upprogaddmsb; // This field represents the MSB of the upprogaddlsb/msb pair.
extern uint8_t msk_upprogaddmsb_upprogaddmsb;

// Register definition: upprogdata
extern uint8_t upprogdata;             // uP Program Data Mailbox, R/W
extern uint8_t ord_upprogdata_upprogdata; // The user reads or writes data to be uploaded or downloaded
                                  // in this register. On every read or write (respectively) to
                                  // this register the upprogaddmsb/lsb pair will be
                                  // auto-incremented by one. On a RAM BIST failure, data
                                  // failure information is recorded here. If RAM BIST read does
                                  // match the expected data the corresponding data bit will be
                                  // set in this field. Only the first byte error is recorded.
extern uint8_t msk_upprogdata_upprogdata;

// Add these near the top of the file after the includes
// Global variables that need to be defined
// extern uint8_t Bcast_reg;
// uint8_t portNo;
// extern uint8_t statpwr;
// uint8_t BIN[8], INVBIN[8], HEX;

// Add these register definitions
//uint8_t opmd = 0x10;    // Operation Mode Register
//uint8_t hpen = 0x11;    // High Power Enable Register
//uint8_t disena = 0x12;  // Disconnect Enable Register
//uint8_t detpb = 0x13;   // Detection Pushbutton Register
//uint8_t rstpb = 0x14;   // Reset Pushbutton Register
//uint8_t pwrpb = 0x19;   // Power On/Off Pushbutton Register

// Add these mask definitions if not already present
//uint8_t msk_disena_dc4 = 0x08;
//uint8_t msk_disena_dc3 = 0x04;
//uint8_t msk_disena_dc2 = 0x02;
//uint8_t msk_disena_dc1 = 0x01;

//uint8_t msk_hpen_hpen4 = 0x08;
//uint8_t msk_hpen_hpen3 = 0x04;
//uint8_t msk_hpen_hpen2 = 0x02;
//uint8_t msk_hpen_hpen1 = 0x01;

//uint8_t msk_rstpb_intclr = 0x02;
//uint8_t msk_rstpb_rstall = 0x01;

#endif /* LTC4271_H */