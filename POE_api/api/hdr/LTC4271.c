#include "LTC4271.h"
extern uint8_t Bcast_reg;
// Register definition: intstat
uint8_t intstat = 0x00;  // Interrupt Status Register, RO
uint8_t ord_intstat_supply = 7;  // Supply Interrupt
uint8_t msk_intstat_supply = 0x80;
uint8_t ord_intstat_tstart = 6;  // tSTART Interrupt
uint8_t msk_intstat_tstart = 0x40;
uint8_t ord_intstat_tcut = 5;    // tCUT Interrupt
uint8_t msk_intstat_tcut = 0x20;
uint8_t ord_intstat_class = 4;   // Class Interrupt
uint8_t msk_intstat_class = 0x10;
uint8_t ord_intstat_det = 3;     // Detect Interrupt
uint8_t msk_intstat_det = 0x08;
uint8_t ord_intstat_dis = 2;     // Disconnect Interrupt
uint8_t msk_intstat_dis = 0x04;
uint8_t ord_intstat_pwrgd = 1;   // Power Good Interrupt
uint8_t msk_intstat_pwrgd = 0x02;
uint8_t ord_intstat_pwrena = 0;  // Power Enable Interrupt
uint8_t msk_intstat_pwrena = 0x01;

// Register definition: intmask
uint8_t intmask = 0x01;  // Interrupt Mask Register, R/W
uint8_t ord_intmask_supply = 7;    // Supply events
uint8_t msk_intmask_supply = 0x80;
uint8_t ord_intmask_tstart = 6;    // tSTART events
uint8_t msk_intmask_tstart = 0x40;
uint8_t ord_intmask_tcut = 5;      // tCUT events
uint8_t msk_intmask_tcut = 0x20;
uint8_t ord_intmask_class = 4;     // Class events
uint8_t msk_intmask_class = 0x10;
uint8_t ord_intmask_det = 3;       // Detect events
uint8_t msk_intmask_det = 0x08;
uint8_t ord_intmask_dis = 2;       // Disconnect events
uint8_t msk_intmask_dis = 0x04;
uint8_t ord_intmask_pwrgd = 1;     // Power Good events
uint8_t msk_intmask_pwrgd = 0x02;
uint8_t ord_intmask_pwrena = 0;    // Power Enable events
uint8_t msk_intmask_pwrena = 0x01;

/****************************************************************
 * Section -- Events
 ****************************************************************/

// Register definition: pwrevn
uint8_t pwrevn = 0x02;  // Power Event Register, Read Only
uint8_t ord_pwrevn_pwrgd4 = 7;     // Port 4 Power Good Change
uint8_t msk_pwrevn_pwrgd4 = 0x80;
uint8_t ord_pwrevn_pwrgd3 = 6;     // Port 3 Power Good Change
uint8_t msk_pwrevn_pwrgd3 = 0x40;
uint8_t ord_pwrevn_pwrgd2 = 5;     // Port 2 Power Good Change
uint8_t msk_pwrevn_pwrgd2 = 0x20;
uint8_t ord_pwrevn_pwrgd1 = 4;     // Port 1 Power Good Change
uint8_t msk_pwrevn_pwrgd1 = 0x10;
uint8_t ord_pwrevn_pwrena4 = 3;    // Port 4 Power Status Change
uint8_t msk_pwrevn_pwrena4 = 0x08;
uint8_t ord_pwrevn_pwrena3 = 2;    // Port 3 Power Status Change
uint8_t msk_pwrevn_pwrena3 = 0x04;
uint8_t ord_pwrevn_pwrena2 = 1;    // Port 2 Power Status Change
uint8_t msk_pwrevn_pwrena2 = 0x02;
uint8_t ord_pwrevn_pwrena1 = 0;    // Port 1 Power Status Change
uint8_t msk_pwrevn_pwrena1 = 0x01;

// Register definition: pwrevn_cor
uint8_t pwrevn_cor = 0x03;  // Power Event Register, Clear on Read
uint8_t ord_pwrevn_cor_pwrgd4 = 7;     // Port 4 Power Good Change
uint8_t msk_pwrevn_cor_pwrgd4 = 0x80;
uint8_t ord_pwrevn_cor_pwrgd3 = 6;     // Port 3 Power Good Change
uint8_t msk_pwrevn_cor_pwrgd3 = 0x40;
uint8_t ord_pwrevn_cor_pwrgd2 = 5;     // Port 2 Power Good Change
uint8_t msk_pwrevn_cor_pwrgd2 = 0x20;
uint8_t ord_pwrevn_cor_pwrgd1 = 4;     // Port 1 Power Good Change
uint8_t msk_pwrevn_cor_pwrgd1 = 0x10;
uint8_t ord_pwrevn_cor_pwrena4 = 3;    // Port 4 Power Status Change
uint8_t msk_pwrevn_cor_pwrena4 = 0x08;
uint8_t ord_pwrevn_cor_pwrena3 = 2;    // Port 3 Power Status Change
uint8_t msk_pwrevn_cor_pwrena3 = 0x04;
uint8_t ord_pwrevn_cor_pwrena2 = 1;    // Port 2 Power Status Change
uint8_t msk_pwrevn_cor_pwrena2 = 0x02;
uint8_t ord_pwrevn_cor_pwrena1 = 0;    // Port 1 Power Status Change
uint8_t msk_pwrevn_cor_pwrena1 = 0x01;

// Register definition: detevn
uint8_t detevn = 0x04;  // Detect and Classification Event Register, Read Only
uint8_t ord_detevn_class4 = 7;    // Port 4 Classification Complete
uint8_t msk_detevn_class4 = 0x80;
uint8_t ord_detevn_class3 = 6;    // Port 3 Classification Complete
uint8_t msk_detevn_class3 = 0x40;
uint8_t ord_detevn_class2 = 5;    // Port 2 Classification Complete
uint8_t msk_detevn_class2 = 0x20;
uint8_t ord_detevn_class1 = 4;    // Port 1 Classification Complete
uint8_t msk_detevn_class1 = 0x10;
uint8_t ord_detevn_det4 = 3;      // Port 4 Detection Complete
uint8_t msk_detevn_det4 = 0x08;
uint8_t ord_detevn_det3 = 2;      // Port 3 Detection Complete
uint8_t msk_detevn_det3 = 0x04;
uint8_t ord_detevn_det2 = 1;      // Port 2 Detection Complete
uint8_t msk_detevn_det2 = 0x02;
uint8_t ord_detevn_det1 = 0;      // Port 1 Detection Complete
uint8_t msk_detevn_det1 = 0x01;

// Register definition: detevn_cor
uint8_t detevn_cor = 0x05;  // Detect and Classification Event Register, Clear on Read
uint8_t ord_detevn_cor_class4 = 7;    // Port 4 Classification Complete
uint8_t msk_detevn_cor_class4 = 0x80;
uint8_t ord_detevn_cor_class3 = 6;    // Port 3 Classification Complete
uint8_t msk_detevn_cor_class3 = 0x40;
uint8_t ord_detevn_cor_class2 = 5;    // Port 2 Classification Complete
uint8_t msk_detevn_cor_class2 = 0x20;
uint8_t ord_detevn_cor_class1 = 4;    // Port 1 Classification Complete
uint8_t msk_detevn_cor_class1 = 0x10;
uint8_t ord_detevn_cor_det4 = 3;      // Port 4 Detection Complete
uint8_t msk_detevn_cor_det4 = 0x08;
uint8_t ord_detevn_cor_det3 = 2;      // Port 3 Detection Complete
uint8_t msk_detevn_cor_det3 = 0x04;
uint8_t ord_detevn_cor_det2 = 1;      // Port 2 Detection Complete
uint8_t msk_detevn_cor_det2 = 0x02;
uint8_t ord_detevn_cor_det1 = 0;      // Port 1 Detection Complete
uint8_t msk_detevn_cor_det1 = 0x01;

// Register definition: fltevn
uint8_t fltevn = 0x06;  // Fault Event Register, Read Only
uint8_t ord_fltevn_dis4 = 7;     // Port 4 disconnect time out (tDIS)
uint8_t msk_fltevn_dis4 = 0x80;
uint8_t ord_fltevn_dis3 = 6;     // Port 3 disconnect time out (tDIS)
uint8_t msk_fltevn_dis3 = 0x40;
uint8_t ord_fltevn_dis2 = 5;     // Port 2 disconnect time out (tDIS)
uint8_t msk_fltevn_dis2 = 0x20;
uint8_t ord_fltevn_dis1 = 4;     // Port 1 disconnect time out (tDIS)
uint8_t msk_fltevn_dis1 = 0x10;
uint8_t ord_fltevn_tcut4 = 3;    // Port 4 overcurrent time out (tCUT)
uint8_t msk_fltevn_tcut4 = 0x08;
uint8_t ord_fltevn_tcut3 = 2;    // Port 3 overcurrent time out (tCUT)
uint8_t msk_fltevn_tcut3 = 0x04;
uint8_t ord_fltevn_tcut2 = 1;    // Port 2 overcurrent time out (tCUT)
uint8_t msk_fltevn_tcut2 = 0x02;
uint8_t ord_fltevn_tcut1 = 0;    // Port 1 overcurrent time out (tCUT)
uint8_t msk_fltevn_tcut1 = 0x01;

// Register definition: fltevn_cor
uint8_t fltevn_cor = 0x07;  // Fault Event Register, Clear on Read
uint8_t ord_fltevn_cor_dis4 = 7;     // Port 4 disconnect time out (tDIS)
uint8_t msk_fltevn_cor_dis4 = 0x80;
uint8_t ord_fltevn_cor_dis3 = 6;     // Port 3 disconnect time out (tDIS)
uint8_t msk_fltevn_cor_dis3 = 0x40;
uint8_t ord_fltevn_cor_dis2 = 5;     // Port 2 disconnect time out (tDIS)
uint8_t msk_fltevn_cor_dis2 = 0x20;
uint8_t ord_fltevn_cor_dis1 = 4;     // Port 1 disconnect time out (tDIS)
uint8_t msk_fltevn_cor_dis1 = 0x10;
uint8_t ord_fltevn_cor_tcut4 = 3;    // Port 4 overcurrent time out (tCUT)
uint8_t msk_fltevn_cor_tcut4 = 0x08;
uint8_t ord_fltevn_cor_tcut3 = 2;    // Port 3 overcurrent time out (tCUT)
uint8_t msk_fltevn_cor_tcut3 = 0x04;
uint8_t ord_fltevn_cor_tcut2 = 1;    // Port 2 overcurrent time out (tCUT)
uint8_t msk_fltevn_cor_tcut2 = 0x02;
uint8_t ord_fltevn_cor_tcut1 = 0;    // Port 1 overcurrent time out (tCUT)
uint8_t msk_fltevn_cor_tcut1 = 0x01;

// Register definition: tsevn
uint8_t tsevn = 0x08;  // tSTART Event Register, Read Only
uint8_t ord_tsevn_tlim4 = 7;    // Port 4 current limit time out
uint8_t msk_tsevn_tlim4 = 0x80;
uint8_t ord_tsevn_tlim3 = 6;    // Port 3 current limit time out
uint8_t msk_tsevn_tlim3 = 0x40;
uint8_t ord_tsevn_tlim2 = 5;    // Port 2 current limit time out
uint8_t msk_tsevn_tlim2 = 0x20;
uint8_t ord_tsevn_tlim1 = 4;    // Port 1 current limit time out
uint8_t msk_tsevn_tlim1 = 0x10;
uint8_t ord_tsevn_tstart4 = 3;    // Port 4 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_tstart4 = 0x08;
uint8_t ord_tsevn_tstart3 = 2;    // Port 3 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_tstart3 = 0x04;
uint8_t ord_tsevn_tstart2 = 1;    // Port 2 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_tstart2 = 0x02;
uint8_t ord_tsevn_tstart1 = 0;    // Port 1 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_tstart1 = 0x01;

// Register definition: tsevn_cor
uint8_t tsevn_cor = 0x09;  // tSTART Event Register, Clear on Read
uint8_t ord_tsevn_cor_tlim4 = 7;      // Port 4 current limit time out
uint8_t msk_tsevn_cor_tlim4 = 0x80;
uint8_t ord_tsevn_cor_tlim3 = 6;      // Port 3 current limit time out
uint8_t msk_tsevn_cor_tlim3 = 0x40;
uint8_t ord_tsevn_cor_tlim2 = 5;      // Port 2 current limit time out
uint8_t msk_tsevn_cor_tlim2 = 0x20;
uint8_t ord_tsevn_cor_tlim1 = 4;      // Port 1 current limit time out
uint8_t msk_tsevn_cor_tlim1 = 0x10;
uint8_t ord_tsevn_cor_tstart4 = 3;    // Port 4 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_cor_tstart4 = 0x08;
uint8_t ord_tsevn_cor_tstart3 = 2;    // Port 3 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_cor_tstart3 = 0x04;
uint8_t ord_tsevn_cor_tstart2 = 1;    // Port 2 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_cor_tstart2 = 0x02;
uint8_t ord_tsevn_cor_tstart1 = 0;    // Port 1 startup overcurrent time out (tSTART)
uint8_t msk_tsevn_cor_tstart1 = 0x01;

// Register definition: supevn
uint8_t supevn = 0x0A;  // Supply Event Register, Read Only
uint8_t ord_supevn_overtemp = 7;  // Over Temperature
uint8_t msk_supevn_overtemp = 0x80;
uint8_t ord_supevn_fetbad = 6;    // External FET failure
uint8_t msk_supevn_fetbad = 0x40;
uint8_t ord_supevn_uvlo3 = 5;     // Digital Supply (VDD) UVLO
uint8_t msk_supevn_uvlo3 = 0x20;
uint8_t ord_supevn_uvlo48 = 4;    // Analog Supply (VEE) UVLO
uint8_t msk_supevn_uvlo48 = 0x10;

// Register definition: supevn_cor
uint8_t supevn_cor = 0x0B;  // Supply Event Register, Clear on Read
uint8_t ord_supevn_cor_overtemp = 7;    // Over Temperature
uint8_t msk_supevn_cor_overtemp = 0x80;
uint8_t ord_supevn_cor_fetbad = 6;      // External FET failure
uint8_t msk_supevn_cor_fetbad = 0x40;
uint8_t ord_supevn_cor_uvlo3 = 5;       // Digital Supply (VDD) UVLO
uint8_t msk_supevn_cor_uvlo3 = 0x20;
uint8_t ord_supevn_cor_uvlo48 = 4;      // Analog Supply (VEE) UVLO
uint8_t msk_supevn_cor_uvlo48 = 0x10;

// Register definition: statp1
uint8_t statp1 = 0x0C;  // Port 1 Status, Read Only
uint8_t ord_statp1_poepp = 7;  // POE++ result
uint8_t msk_statp1_poepp = 0x80;
uint8_t ord_statp1_class = 4;   // Classification result
uint8_t msk_statp1_class = 0x70;
uint8_t ord_statp1_detect = 0;  // Detection result
uint8_t msk_statp1_detect = 0x07;

// Register definition: statp2
uint8_t statp2 = 0x0D;  // Port 2 Status, Read Only
uint8_t ord_statp2_poepp = 7;  // POE++ result
uint8_t msk_statp2_poepp = 0x80;
uint8_t ord_statp2_class = 4;   // Classification result
uint8_t msk_statp2_class = 0x70;
uint8_t ord_statp2_detect = 0;  // Detection result
uint8_t msk_statp2_detect = 0x07;

// Register definition: statp3
uint8_t statp3 = 0x0E;  // Port 3 Status, Read Only
uint8_t ord_statp3_poepp = 7;  // POE++ result
uint8_t msk_statp3_poepp = 0x80;
uint8_t ord_statp3_class = 4;   // Classification result
uint8_t msk_statp3_class = 0x70;
uint8_t ord_statp3_detect = 0;  // Detection result
uint8_t msk_statp3_detect = 0x07;

// Register definition: statp4
uint8_t statp4 = 0x0F;  // Port 4 Status, Read Only
uint8_t ord_statp4_poepp = 7;  // POE++ result
uint8_t msk_statp4_poepp = 0x80;
uint8_t ord_statp4_class = 4;   // Classification result
uint8_t msk_statp4_class = 0x70;
uint8_t ord_statp4_detect = 0;  // Detection result
uint8_t msk_statp4_detect = 0x07;

// Register definition: statpwr
//uint8_t statpwr = 0x10;  // Power Status, Read Only
uint8_t ord_statpwr_pg4 = 7;    // Power good on port 4
uint8_t msk_statpwr_pg4 = 0x80;
uint8_t ord_statpwr_pg3 = 6;    // Power good on port 3
uint8_t msk_statpwr_pg3 = 0x40;
uint8_t ord_statpwr_pg2 = 5;    // Power good on port 2
uint8_t msk_statpwr_pg2 = 0x20;
uint8_t ord_statpwr_pg1 = 4;    // Power good on port 1
uint8_t msk_statpwr_pg1 = 0x10;
uint8_t ord_statpwr_pe4 = 3;    // Power enabled on port 4
uint8_t msk_statpwr_pe4 = 0x08;
uint8_t ord_statpwr_pe3 = 2;    // Power enabled on port 3
uint8_t msk_statpwr_pe3 = 0x04;
uint8_t ord_statpwr_pe2 = 1;    // Power enabled on port 2
uint8_t msk_statpwr_pe2 = 0x02;
uint8_t ord_statpwr_pe1 = 0;    // Power enabled on port 1
uint8_t msk_statpwr_pe1 = 0x01;

// Register definition: statpin
uint8_t statpin = 0x11;  // Pin Status, Read Only
uint8_t ord_statpin_ad6 = 6;     // SMBus address 6
uint8_t msk_statpin_ad6 = 0x40;
uint8_t ord_statpin_ad3 = 5;     // SMBus address 3
uint8_t msk_statpin_ad3 = 0x20;
uint8_t ord_statpin_ad2 = 4;     // SMBus address 2
uint8_t msk_statpin_ad2 = 0x10;
uint8_t ord_statpin_ad1 = 3;     // SMBus address 1
uint8_t msk_statpin_ad1 = 0x08;
uint8_t ord_statpin_ad0 = 2;     // SMBus address 0
uint8_t msk_statpin_ad0 = 0x04;
uint8_t ord_statpin_mid = 1;     // MID pin state
uint8_t msk_statpin_mid = 0x02;
uint8_t ord_statpin_auto = 0;    // AUTO pin state
uint8_t msk_statpin_auto = 0x01;

/****************************************************************
 * Section -- Configuration
 ****************************************************************/

// Register definition: opmd
uint8_t opmd = 0x12;  // Operating Mode, R/W
uint8_t ord_opmd_opmd4 = 6;    // Operating mode, port 4
uint8_t msk_opmd_opmd4 = 0xC0;
uint8_t ord_opmd_opmd3 = 4;    // Operating mode, port 3
uint8_t msk_opmd_opmd3 = 0x30;
uint8_t ord_opmd_opmd2 = 2;    // Operating mode, port 2
uint8_t msk_opmd_opmd2 = 0x0C;
uint8_t ord_opmd_opmd1 = 0;    // Operating mode, port 1
uint8_t msk_opmd_opmd1 = 0x03;

// Register definition: disena
uint8_t disena = 0x13;  // Disconnect Sensing Enable, R/W
uint8_t ord_disena_eml_ac4 = 7;    // Emulate AC disconnect on port 4
uint8_t msk_disena_eml_ac4 = 0x80;
uint8_t ord_disena_eml_ac3 = 6;    // Emulate AC disconnect on port 3
uint8_t msk_disena_eml_ac3 = 0x40;
uint8_t ord_disena_eml_ac2 = 5;    // Emulate AC disconnect on port 2
uint8_t msk_disena_eml_ac2 = 0x20;
uint8_t ord_disena_eml_ac1 = 4;    // Emulate AC disconnect on port 1
uint8_t msk_disena_eml_ac1 = 0x10;
uint8_t ord_disena_dc4 = 3;        // Enable DC disconnect on port 4
uint8_t msk_disena_dc4 = 0x08;
uint8_t ord_disena_dc3 = 2;        // Enable DC disconnect on port 3
uint8_t msk_disena_dc3 = 0x04;
uint8_t ord_disena_dc2 = 1;        // Enable DC disconnect on port 2
uint8_t msk_disena_dc2 = 0x02;
uint8_t ord_disena_dc1 = 0;        // Enable DC disconnect on port 1
uint8_t msk_disena_dc1 = 0x01;

// Register definition: detena
uint8_t detena = 0x14;  // Detect and Class Enable, Read/Write
uint8_t ord_detena_cls4 = 7;    // Enable classification on port 4
uint8_t msk_detena_cls4 = 0x80;
uint8_t ord_detena_cls3 = 6;    // Enable classification on port 3
uint8_t msk_detena_cls3 = 0x40;
uint8_t ord_detena_cls2 = 5;    // Enable classification on port 2
uint8_t msk_detena_cls2 = 0x20;
uint8_t ord_detena_cls1 = 4;    // Enable classification on port 1
uint8_t msk_detena_cls1 = 0x10;
uint8_t ord_detena_det4 = 3;    // Enable detection on port 4
uint8_t msk_detena_det4 = 0x08;
uint8_t ord_detena_det3 = 2;    // Enable detection on port 3
uint8_t msk_detena_det3 = 0x04;
uint8_t ord_detena_det2 = 1;    // Enable detection on port 2
uint8_t msk_detena_det2 = 0x02;
uint8_t ord_detena_det1 = 0;    // Enable detection on port 1
uint8_t msk_detena_det1 = 0x01;

// Register definition: midspan
uint8_t midspan = 0x15;  // Midspan Backoff Enable, R/W
uint8_t ord_midspan_midsp4 = 3;    // Enable midspan backoff on port 4
uint8_t msk_midspan_midsp4 = 0x08;
uint8_t ord_midspan_midsp3 = 2;    // Enable midspan backoff on port 3
uint8_t msk_midspan_midsp3 = 0x04;
uint8_t ord_midspan_midsp2 = 1;    // Enable midspan backoff on port 2
uint8_t msk_midspan_midsp2 = 0x02;
uint8_t ord_midspan_midsp1 = 0;    // Enable midspan backoff on port 1
uint8_t msk_midspan_midsp1 = 0x01;

// Register definition: mconf
uint8_t mconf = 0x17;  // Miscellaneous Configuration, R/W
uint8_t ord_mconf_intena = 7;  // Interrupt pin enable
uint8_t msk_mconf_intena = 0x80;
uint8_t ord_mconf_detchg = 6;    // Detect change reporting
uint8_t msk_mconf_detchg = 0x40;
uint8_t ord_mconf_reserved = 5;  // Reserved
uint8_t msk_mconf_reserved = 0x20;
uint8_t ord_mconf_fasti = 4;     // Fast current measurement
uint8_t msk_mconf_fasti = 0x10;
uint8_t ord_mconf_msdmsk4 = 3;  // MSD mask port 4
uint8_t msk_mconf_msdmsk4 = 0x08;
uint8_t ord_mconf_msdmsk3 = 2;  // MSD mask port 3
uint8_t msk_mconf_msdmsk3 = 0x04;
uint8_t ord_mconf_msdmsk2 = 1;  // MSD mask port 2
uint8_t msk_mconf_msdmsk2 = 0x02;
uint8_t ord_mconf_msdmsk1 = 0;  // MSD mask port 1
uint8_t msk_mconf_msdmsk1 = 0x01;

/****************************************************************
 * Section -- Pushbuttons
 ****************************************************************/

// Register definition: detpb
uint8_t detpb = 0x18;  // Detection and Classification Restart Pushbutton
uint8_t ord_detpb_cls4 = 7;  // Set classification port 4
uint8_t msk_detpb_cls4 = 0x80;
uint8_t ord_detpb_cls3 = 6;  // Set classification port 3
uint8_t msk_detpb_cls3 = 0x40;
uint8_t ord_detpb_cls2 = 5;  // Set classification port 2
uint8_t msk_detpb_cls2 = 0x20;
uint8_t ord_detpb_cls1 = 4;  // Set classification port 1
uint8_t msk_detpb_cls1 = 0x10;
uint8_t ord_detpb_det4 = 3;  // Set detection port 4
uint8_t msk_detpb_det4 = 0x08;
uint8_t ord_detpb_det3 = 2;  // Set detection port 3
uint8_t msk_detpb_det3 = 0x04;
uint8_t ord_detpb_det2 = 1;  // Set detection port 2
uint8_t msk_detpb_det2 = 0x02;
uint8_t ord_detpb_det1 = 0;  // Set detection port 1
uint8_t msk_detpb_det1 = 0x01;

// Register definition: pwrpb
uint8_t pwrpb = 0x19;  // Power On/Off Pushbutton
uint8_t ord_pwrpb_off4 = 7;    // Reset port 4
uint8_t msk_pwrpb_off4 = 0x80;
uint8_t ord_pwrpb_off3 = 6;    // Reset port 3
uint8_t msk_pwrpb_off3 = 0x40;
uint8_t ord_pwrpb_off2 = 5;    // Reset port 2
uint8_t msk_pwrpb_off2 = 0x20;
uint8_t ord_pwrpb_off1 = 4;    // Reset port 1
uint8_t msk_pwrpb_off1 = 0x10;
uint8_t ord_pwrpb_on4 = 3;     // Power on port 4
uint8_t msk_pwrpb_on4 = 0x08;
uint8_t ord_pwrpb_on3 = 2;     // Power on port 3
uint8_t msk_pwrpb_on3 = 0x04;
uint8_t ord_pwrpb_on2 = 1;     // Power on port 2
uint8_t msk_pwrpb_on2 = 0x02;
uint8_t ord_pwrpb_on1 = 0;     // Power on port 1
uint8_t msk_pwrpb_on1 = 0x01;

// Register definition: rstpb
uint8_t rstpb = 0x1A;  // Reset Pushbutton
uint8_t ord_rstpb_intclr = 7;    // Clear interrupts
uint8_t msk_rstpb_intclr = 0x80;
uint8_t ord_rstpb_pinclr = 6;    // Clear interrupt pin
uint8_t msk_rstpb_pinclr = 0x40;
uint8_t ord_rstpb_rstall = 4;    // Reset LTC4266
//uint8_t msk_rstpb_rstall = 0x10;

// the _RESET pin low.
uint8_t msk_rstpb_rstall = 0x10;
uint8_t ord_rstpb_rst4 = 3;      // Reset port 4.
uint8_t msk_rstpb_rst4 = 0x08;   
uint8_t ord_rstpb_rst3 = 2;      // Reset port 3.
uint8_t msk_rstpb_rst3 = 0x04;   
uint8_t ord_rstpb_rst2 = 1;      // Reset port 2.
uint8_t msk_rstpb_rst2 = 0x02;   
uint8_t ord_rstpb_rst1 = 0;      // Reset port 1.
uint8_t msk_rstpb_rst1 = 0x01;   

/****************************************************************
 * Section -- Debug
 ****************************************************************/

// Register definition: id
uint8_t id = 0x1B;  // Chip Identification Register, Read Only. LTC4259 compatible,
                // i.e. the device and revision ID are the same as the
                // LTC4259A.
uint8_t ord_id_dev = 3;     // Device identification number.
uint8_t msk_id_dev = 0xF8;  
uint8_t ord_id_rev = 0;     // Revision number.
uint8_t msk_id_rev = 0x07;  

/****************************************************************
 * Section --  Limit Timing
 ****************************************************************/

// Register definition: tlim
uint8_t tlim = 0x1E;  // tLIM timer duration for all ports. R/W. The port's tLIM timer
                  // counts up when the port is in current limit and resets when
                  // the port is not in current limit. If the timer expires then
                  // the port turns off and the tLIM bit in register 08h is set.
uint8_t ord_tlim_tlim4 = 3;  // tLIM timer duration on port 4. If this bit is set the timer is
                         // set to 12ms. If this bit is cleared, the timer is disabled.
uint8_t msk_tlim_tlim4 = 0x08;
//uint8_t ord_tlim_tlim4 = 3;     // tLIM timer duration on port 4. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
//uint8_t msk_tlim_tlim4 = 0x08;
uint8_t ord_tlim_tlim3 = 2;     // tLIM timer duration on port 3. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
uint8_t msk_tlim_tlim3 = 0x04;
uint8_t ord_tlim_tlim2 = 1;     // tLIM timer duration on port 2. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
uint8_t msk_tlim_tlim2 = 0x02;
uint8_t ord_tlim_tlim1 = 0;     // tLIM timer duration on port 1. If this bit is set the timer is
                            // set to 12ms. If this bit is cleared, the timer is disabled.
uint8_t msk_tlim_tlim1 = 0x01;

/****************************************************************
 * Section --  General Purpose IO
 ****************************************************************/

// Register definition: gpiooen
uint8_t gpiooen = 0x20;               // General Purpose IO Output Enable, R/W
uint8_t ord_gpiooen_gpiooen2 = 2;     // GPIO%b Output Enable%{cr}See bit 0 description.
uint8_t msk_gpiooen_gpiooen2 = 0x04;
uint8_t ord_gpiooen_gpiooen1 = 1;     // GPIO%b Output Enable%{cr}See bit 0 description.
uint8_t msk_gpiooen_gpiooen1 = 0x02;
uint8_t ord_gpiooen_gpiooen0 = 0;     // GPIO%b Output Enable%{cr}When set this output is enabled and
                                  // con be controlled via gpioout bit %b. When cleared this
                                  // output operates in read-only mode. Input status can be read
                                  // from gpioin bit %b.
uint8_t msk_gpiooen_gpiooen0 = 0x01;

// Register definition: gpioout
uint8_t gpioout = 0x21;               // General Purpose IO Output Value, R/W
uint8_t ord_gpioout_gpioout2 = 2;     // GPIO%b Output State
uint8_t msk_gpioout_gpioout2 = 0x04;
uint8_t ord_gpioout_gpioout1 = 1;     // GPIO%b Output State
uint8_t msk_gpioout_gpioout1 = 0x02;
uint8_t ord_gpioout_gpioout0 = 0;     // GPIO%b Output State
uint8_t msk_gpioout_gpioout0 = 0x01;

// Register definition: gpioin
uint8_t gpioin = 0x22;              // General Purpose IO Input Value, R/W
uint8_t ord_gpioin_gpioin2 = 2;     // GPIO%b Input Value
uint8_t msk_gpioin_gpioin2 = 0x04;
uint8_t ord_gpioin_gpioin1 = 1;     // GPIO%b Input Value
uint8_t msk_gpioin_gpioin1 = 0x02;
uint8_t ord_gpioin_gpioin0 = 0;     // GPIO%b Input Value
uint8_t msk_gpioin_gpioin0 = 0x01;

// Register definition: portmonconf
uint8_t portmonconf = 0x2D;               // Port Monitor Configuration
uint8_t ord_portmonconf_filter_type = 1;  // When this bit is set, the reported port currents represent
                                     // only the previous 100ms window. When this bit is clear, the
                                     // reported port currents are updated every 100ms, but
                                     // represent the rolling average of the previous 1sec window.
uint8_t msk_portmonconf_filter_type = 0x02;

// Register definition: veelsb
uint8_t veelsb = 0x2E;             // Vee Supply Voltage Measurement LSB, R/W.
uint8_t ord_veelsb_veelsb = 0;     // Vee Voltage LSB. 1 LSB =5.845mV
uint8_t msk_veelsb_veelsb = 0xFF;

// Register definition: veemsb
uint8_t veemsb = 0x2F;             // Vee Supply Voltage Measurement MSB, R/W.
uint8_t ord_veemsb_veemsb = 0;     
uint8_t msk_veemsb_veemsb = 0x3F;

/****************************************************************
 * Section -- Port Parametric Measurement
 ****************************************************************/

// Register definition: ip1lsb
uint8_t ip1lsb = 0x30;          // Port 1 Current Measurement LSB, Read Only.
uint8_t ord_ip1lsb_ip1lsb = 0;  // Port 1 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
uint8_t msk_ip1lsb_ip1lsb = 0xFF;

// Register definition: ip1msb
uint8_t ip1msb = 0x31;             // Port 1 Current Measurement MSB, Read Only.
uint8_t ord_ip1msb_ip1msb = 0;     // Port 1 Current MSB.
uint8_t msk_ip1msb_ip1msb = 0x3F;

// Register definition: vp1lsb
uint8_t vp1lsb = 0x32;             // Port 1 Voltage Measurement LSB, Read Only.
uint8_t ord_vp1lsb_vp1lsb = 0;     // Port 1 Voltage LSB. 1 LSB =5.845mV
uint8_t msk_vp1lsb_vp1lsb = 0xFF;

// Register definition: vp1msb
uint8_t vp1msb = 0x33;             // Port 1 Voltage Measurement MSB, Read Only.
uint8_t ord_vp1msb_vp1msb = 0;     // Port 1 Voltage MSB.
uint8_t msk_vp1msb_vp1msb = 0x3F;

// Register definition: ip2lsb
uint8_t ip2lsb = 0x34;          // Port 2 Current Measurement LSB, Read Only.
uint8_t ord_ip2lsb_ip2lsb = 0;  // Port 2 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
uint8_t msk_ip2lsb_ip2lsb = 0xFF;

// Register definition: ip2msb
uint8_t ip2msb = 0x35;             // Port 2 Current Measurement MSB, Read Only.
uint8_t ord_ip2msb_ip2msb = 0;     // Port 2 Current MSB.
uint8_t msk_ip2msb_ip2msb = 0x3F;

// Register definition: vp2lsb
uint8_t vp2lsb = 0x36;             // Port 2 Voltage Measurement LSB, Read Only.
uint8_t ord_vp2lsb_vp2lsb = 0;     // Port 2 Voltage LSB. 1 LSB =5.845mV
uint8_t msk_vp2lsb_vp2lsb = 0xFF;

// Register definition: vp2msb
uint8_t vp2msb = 0x37;             // Port 2 Voltage Measurement MSB, Read Only.
uint8_t ord_vp2msb_vp2msb = 0;     // Port 2 Voltage MSB.
uint8_t msk_vp2msb_vp2msb = 0x3F;

// Register definition: ip3lsb
uint8_t ip3lsb = 0x38;          // Port 3 Current Measurement LSB, Read Only.
uint8_t ord_ip3lsb_ip3lsb = 0;  // Port 3 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
uint8_t msk_ip3lsb_ip3lsb = 0xFF;

// Register definition: ip3msb
uint8_t ip3msb = 0x39;             // Port 3 Current Measurement MSB, Read Only.
uint8_t ord_ip3msb_ip3msb = 0;     // Port 3 Current MSB.
uint8_t msk_ip3msb_ip3msb = 0x3F;

// Register definition: vp3lsb
uint8_t vp3lsb = 0x3A;             // Port 3 Voltage Measurement LSB, Read Only.
uint8_t ord_vp3lsb_vp3lsb = 0;     // Port 3 Voltage LSB. 1 LSB =5.845mV
uint8_t msk_vp3lsb_vp3lsb = 0xFF;

// Register definition: vp3msb
uint8_t vp3msb = 0x3B;             // Port 3 Voltage Measurement MSB, Read Only.
uint8_t ord_vp3msb_vp3msb = 0;     // Port 3 Voltage MSB.
uint8_t msk_vp3msb_vp3msb = 0x3F;

// Register definition: ip4lsb
uint8_t ip4lsb = 0x3C;          // Port 4 Current Measurement LSB, Read Only.
uint8_t ord_ip4lsb_ip4lsb = 0;  // Port 4 Current LSB. 1 LSB =61.035uA when Rsense =
                            // 0.5ohm or 122.07uA when Rsense =0.25ohm
uint8_t msk_ip4lsb_ip4lsb = 0xFF;

// Register definition: ip4msb
uint8_t ip4msb = 0x3D;             // Port 4 Current Measurement MSB, Read Only.
uint8_t ord_ip4msb_ip4msb = 0;     // Port 4 Current MSB.
uint8_t msk_ip4msb_ip4msb = 0x3F;

// Register definition: vp4lsb
uint8_t vp4lsb = 0x3E;             // Port 4 Voltage Measurement LSB, Read Only.
uint8_t ord_vp4lsb_vp4lsb = 0;     // Port 4 Voltage LSB. 1 LSB =5.845mV
uint8_t msk_vp4lsb_vp4lsb = 0xFF;

// Register definition: vp4msb
uint8_t vp4msb = 0x3F;             // Port 4 Voltage Measurement MSB, Read Only.
uint8_t ord_vp4msb_vp4msb = 0;     // Port 4 Voltage MSB.
uint8_t msk_vp4msb_vp4msb = 0x3F;

/****************************************************************
 * Section -- Configuration 1
 ****************************************************************/

// Register definition: firmware
uint8_t firmware = 0x41;          // Firmware Revision Code, Read Only.
uint8_t ord_firmware_rev = 0;     // Firmware Revision Code.
uint8_t msk_firmware_rev = 0xFF;

// Register definition: wdog
uint8_t wdog = 0x42;  // Watchdog Register, R/W. The LTC4266 monitors activity on the
                  // SCL pin. If the SCL pin does not transition high or low in
                  // 2.5 seconds (typ.) the wdstat bit is set and ports are
                  // reset. Also displays current status of over/under voltage
                  // conditions and thermal shutdown.
uint8_t ord_wdog_tsd = 7;  // TSD monitor. This bit is set when the chip is in thermal
                       // shutdown.
uint8_t msk_wdog_tsd = 0x80;
uint8_t ord_wdog_ov48 = 6;    // OV48 monitor. This bit is set when the 48V supply is above
                          // safe limits.
uint8_t msk_wdog_ov48 = 0x40;
uint8_t ord_wdog_uv48 = 5;     // UV48 monitor. This bit is set when the 48V supply is too low
                           // to meet IEEE 802.3 specifications.
uint8_t msk_wdog_uv48 = 0x20;
uint8_t ord_wdog_wddis = 1;    // Watchdog disable. When this field is set to 1011b the
                           // watchdog is disabled. Otherwise the SMBus watchdog is
                           // enabled.
uint8_t msk_wdog_wddis = 0x1E;
uint8_t ord_wdog_wdstat = 0;    // Status of the watchdog. When the watchdog times out, this
                            // bit is set and all ports are reset. This bit must be clear
                            // for ports to be enabled.
uint8_t msk_wdog_wdstat = 0x01;

// Register definition: devid
uint8_t devid = 0x43;               // Device Identification Register, Read Only.
uint8_t ord_devid_features = 3;     // Device ID, Read Only.
uint8_t msk_devid_features = 0xF8;
uint8_t ord_devid_rev = 0;          // Device revision, Read Only.
uint8_t msk_devid_rev = 0x07;       

/****************************************************************
 * Section -- High Power Features, Global
 ****************************************************************/

// Register definition: hpen
uint8_t hpen = 0x44;  // High Power Enable Register, R/W. This register enables the
                  // features in address 46h through 5Fh and disables the use of
                  // overcurrent (ICUT) and current limit (ILIM) settings from
                  // registers 2Ah, 2Bh, and 40h on a per port basis.
uint8_t ord_hpen_poeppen4 = 7;  // Enable POE++ features on port 4. When this bit is set, a
                            // LTPoE++ physical class will be issued and extended class
                            // information will be posted to the statp4 register.
uint8_t msk_hpen_poeppen4 = 0x80;
uint8_t ord_hpen_poeppen3 = 6;     // Enable POE++ features on port 3. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp3 register.
uint8_t msk_hpen_poeppen3 = 0x40;
uint8_t ord_hpen_poeppen2 = 5;     // Enable POE++ features on port 2. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp2 register.
uint8_t msk_hpen_poeppen2 = 0x20;
uint8_t ord_hpen_poeppen1 = 4;     // Enable POE++ features on port 1. When this bit is set, a
                               // LTPoE++ physical class will be issued and extended class
                               // information will be posted to the statp1 register.
uint8_t msk_hpen_poeppen1 = 0x10;
uint8_t ord_hpen_hpen4 = 3;        // Enable high power features on port 4. When this bit is
                               // cleared, high power features are disabled and registers 55h
                               // through 58h have no effect.
uint8_t msk_hpen_hpen4 = 0x08;
uint8_t ord_hpen_hpen3 = 2;     // Enable high power features on port 3. When this bit is
                            // cleared, high power features are disabled and registers 50h
                            // through 53h have no effect.
uint8_t msk_hpen_hpen3 = 0x04;
uint8_t ord_hpen_hpen2 = 1;     // Enable high power features on port 2. When this bit is
                            // cleared, high power features are disabled and registers 4Bh
                            // through 4Eh have no effect.
uint8_t msk_hpen_hpen2 = 0x02;
uint8_t ord_hpen_hpen1 = 0;     // Enable high power features on port 1. When this bit is
                            // cleared, high power features are disabled and registers 46h
                            // through 49h have no effect.
uint8_t msk_hpen_hpen1 = 0x01;

/****************************************************************
 * Section -- High Power Features, Port 1
 ****************************************************************/

// Register definition: hpmd1
uint8_t hpmd1 = 0x46;  // High Power Modes Port 1, Read/Write. Controls high power
                   // modes and features on port 1.
uint8_t ord_hpmd1_legen = 1;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 1. When this bit is set a PD with a
                          // large common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp1 register).
uint8_t msk_hpmd1_legen = 0x02;   
uint8_t ord_hpmd1_pongen = 0;     // Enable Ping-Pong classification on port 1.
uint8_t msk_hpmd1_pongen = 0x01;

// Register definition: cut1
uint8_t cut1 = 0x47;  // Port 1 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
uint8_t ord_cut1_rdis = 7;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
uint8_t msk_cut1_rdis = 0x80;    
uint8_t ord_cut1_cutrng = 6;     // Adjust overcurrent threshold range on port . See Table IC1
uint8_t msk_cut1_cutrng = 0x40;
uint8_t ord_cut1_cut = 0;        // Set threshold of overcurrent comparator on port . See Table
                            // IC1.
uint8_t msk_cut1_cut = 0x3F;

// Register definition: lim1
uint8_t lim1 = 0x48;  // Current limit and foldback profiles for port 1, R/W. This
                  // register adjusts the current limit on port 1.
uint8_t ord_lim1_lim = 0;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
uint8_t msk_lim1_lim = 0xFF;

// Register definition: hpstat1
uint8_t hpstat1 = 0x49;             // Status of Advanced and High Power Features on Port 1, Read Only.
uint8_t ord_hpstat1_polavgevn = 2;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
uint8_t msk_hpstat1_polavgevn = 0x04;
uint8_t ord_hpstat1_fetbad = 1;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
uint8_t msk_hpstat1_fetbad = 0x02;
uint8_t ord_hpstat1_pongpd = 0;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
uint8_t msk_hpstat1_pongpd = 0x01;

/****************************************************************
 * Section -- High Power Features, Port 2
 ****************************************************************/

// Register definition: hpmd2
uint8_t hpmd2 = 0x4B;  // High Power Modes Port 2, R/W. Controls high power modes and
                   // features on port 2.
uint8_t ord_hpmd2_legen = 1;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 2. When this bit is set a PD with a large
                          // common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp2 register).
uint8_t msk_hpmd2_legen = 0x02;   
uint8_t ord_hpmd2_pongen = 0;     // Enable Ping-Pong classification on port 2.
uint8_t msk_hpmd2_pongen = 0x01;

// Register definition: cut2
uint8_t cut2 = 0x4C;  // Port 2 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
uint8_t ord_cut2_rdis = 7;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
uint8_t msk_cut2_rdis = 0x80;    
uint8_t ord_cut2_cutrng = 6;     // Adjust overcurrent threshold range on port 2. See Table IC1
uint8_t msk_cut2_cutrng = 0x40;
uint8_t ord_cut2_cut = 0;        // Set threshold of overcurrent comparator on port 2. See Table
                            // IC1.
uint8_t msk_cut2_cut = 0x3F;

// Register definition: lim2
uint8_t lim2 = 0x4D;  // Current limit and foldback profiles for port 2, R/W. This
                  // register adjusts the current limit on port 2.
uint8_t ord_lim2_lim = 0;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
uint8_t msk_lim2_lim = 0xFF;

// Register definition: hpstat2
uint8_t hpstat2 = 0x4E;             // Status of Advanced and High Power Features on Port 2, Read Only.
uint8_t ord_hpstat2_polavgevn = 2;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
uint8_t msk_hpstat2_polavgevn = 0x04;
uint8_t ord_hpstat2_fetbad = 1;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
uint8_t msk_hpstat2_fetbad = 0x02;
uint8_t ord_hpstat2_pongpd = 0;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
uint8_t msk_hpstat2_pongpd = 0x01;

/****************************************************************
 * Section -- High Power Features, Port 3
 ****************************************************************/

// Register definition: hpmd3
uint8_t hpmd3 = 0x50;  // High Power Modes Port 3, R/W. Controls high power modes and
                   // features on port 3.
uint8_t ord_hpmd3_legen = 1;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port . When this bit is set a PD with a large
                          // common mode capacitance will be reported as a vaild
                          // signature (code 4 in the statp3 register).
uint8_t msk_hpmd3_legen = 0x02;   
uint8_t ord_hpmd3_pongen = 0;     // Enable Ping-Pong classification on port 3.
uint8_t msk_hpmd3_pongen = 0x01;

// Register definition: cut3
uint8_t cut3 = 0x51;  // Port 3 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
uint8_t ord_cut3_rdis = 7;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
uint8_t msk_cut3_rdis = 0x80;    
uint8_t ord_cut3_cutrng = 6;     // Adjust overcurrent threshold range on port 3. See Table IC1
uint8_t msk_cut3_cutrng = 0x40;
uint8_t ord_cut3_cut = 0;        // Set threshold of overcurrent comparator on port 3. See Table
                            // IC1.
uint8_t msk_cut3_cut = 0x3F;

// Register definition: lim3
uint8_t lim3 = 0x52;  // Current limit and foldback profiles for port 3, R/W. This
                  // register adjusts the current limit on port 3.
uint8_t ord_lim3_lim = 0;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
uint8_t msk_lim3_lim = 0xFF;

// Register definition: hpstat3
uint8_t hpstat3 = 0x53;             // Status of Advanced and High Power Features on Port 3, Read Only.
uint8_t ord_hpstat3_polavgevn = 2;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
uint8_t msk_hpstat3_polavgevn = 0x04;
uint8_t ord_hpstat3_fetbad = 1;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
uint8_t msk_hpstat3_fetbad = 0x02;
uint8_t ord_hpstat3_pongpd = 0;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
uint8_t msk_hpstat3_pongpd = 0x01;

/****************************************************************
 * Section -- High Power Features, Port 4
 ****************************************************************/

// Register definition: hpmd4
uint8_t hpmd4 = 0x55;  // High Power Modes Port 4, R/W. Controls high power modes and
                   // features on port 4.
uint8_t ord_hpmd4_legen = 1;  // Enable detection of legacy PDs by sensing for large
                          // capacitance on port 4. When this bit is set a PD with a large
                          // common mode capacitance will be reported as a valid
                          // signature (code 4 in the statp4 register).
uint8_t msk_hpmd4_legen = 0x02;   
uint8_t ord_hpmd4_pongen = 0;     // Enable Ping-Pong classification on port 4.
uint8_t msk_hpmd4_pongen = 0x01;

// Register definition: cut4
uint8_t cut4 = 0x56;  // Port 4 Overcurrent Cutoff Level, R/W. This register controls the
                  // overcurrent and DC disconnect thresholds.
uint8_t ord_cut4_rdis = 7;  // Adjust DC disconnect threshold on port for sense resistor
                        // value: 0=0.5ohm, 1=0.25ohm.
uint8_t msk_cut4_rdis = 0x80;    
uint8_t ord_cut4_cutrng = 6;     // Adjust overcurrent threshold range on port 4. See Table IC1
uint8_t msk_cut4_cutrng = 0x40;
uint8_t ord_cut4_cut = 0;        // Set threshold of overcurrent comparator on port 4. See Table
                            // IC1.
uint8_t msk_cut4_cut = 0x3F;

// Register definition: lim4
uint8_t lim4 = 0x57;  // Current limit and foldback profiles for port 4, R/W. This
                  // register adjusts the current limit on port 4.
uint8_t ord_lim4_lim = 0;  // Current Limit Setting. See Table IL1 for information on
                       // configuring ILIM.
uint8_t msk_lim4_lim = 0xFF;

// Register definition: hpstat4
uint8_t hpstat4 = 0x58;             // Status of Advanced and High Power Features on Port 4, Read Only.
uint8_t ord_hpstat4_polavgevn = 2;  // A policing event has detected a 1 second averaged port
                                // current window measurement above the police_curr_avg
                                // threshold.
uint8_t msk_hpstat4_polavgevn = 0x04;
uint8_t ord_hpstat4_fetbad = 1;        // The External FET has likely failed. See the FETBAD section
                                   // for more information.
uint8_t msk_hpstat4_fetbad = 0x02;
uint8_t ord_hpstat4_pongpd = 0;     // This bit is set when class 4 is measured during both events
                                // in a ping-pong classification.
uint8_t msk_hpstat4_pongpd = 0x01;

/****************************************************************
 * Section -- MSD
 ****************************************************************/

// Register definition: msdpinmode
uint8_t msdpinmode = 0x5B;  // MSD Pin Mode, R/W%{cr}The lowest addressed quad controls the

// operation of all quads in a single 12-port chip.
uint8_t ord_msdpinmode_msdpolaritycntrl = 0;  // MSD Polarity Control
                                          // Defines the active state of the MSDb pin. When cleared, MSDb active level is low
                                          // (compatible with legacy Linear PSE devices.) When asserted,
                                          // the MSD pin is active high.
uint8_t msk_msdpinmode_msdpolaritycntrl = 0x01;

// Register definition: p1_polcurravg
uint8_t p1_polcurravg = 0x61;                // Port 1 Police Average Current, R/W
uint8_t ord_p1_polcurravg_p1_polcurravg = 0; // Specifies a port current threshold. If the one second
                                         // averaged port current window meets or exceeds the specified
                                         // threshold, the port will be turned off and a tCUT event
                                         // will be recorded. In addition, the hpstatN register will
                                         // record a pol_evn_avg event. The LSB size is 15.625mA for
                                         // 0.25ohm sense resistors and 7.81mA for 0.5ohm. When this
                                         // register is zero, average policing is disabled for this port.
uint8_t msk_p1_polcurravg_p1_polcurravg = 0xFF;

// Register definition: p2_polcurravg  
uint8_t p2_polcurravg = 0x65;                // Port 2 Police Average Current, R/W
uint8_t ord_p2_polcurravg_p2_polcurravg = 0; // See p1_polcurravg description
uint8_t msk_p2_polcurravg_p2_polcurravg = 0xFF;

// Register definition: p3_polcurravg
uint8_t p3_polcurravg = 0x69;                // Port 3 Police Average Current, R/W  
uint8_t ord_p3_polcurravg_p3_polcurravg = 0; // See p1_polcurravg description
uint8_t msk_p3_polcurravg_p3_polcurravg = 0xFF;

// Register definition: p4_polcurravg
uint8_t p4_polcurravg = 0x6D;                // Port 1 Police Average Current, R/W
uint8_t ord_p4_polcurravg_p4_polcurravg = 0; // See p1_polcurravg description
uint8_t msk_p4_polcurravg_p4_polcurravg = 0xFF;

/****************************************************************
 * Section -- Microprocessor Program
 ****************************************************************/

// Register definition: upprogctl
uint8_t upprogctl = 0xEA;          // Processor code download mailbox control and status
uint8_t ord_upprogctl_jumpram = 5; // The user sets this bit after successfully downloading code
                              // to the cRAM. If this bit is set, firmware will execute
                              // code from the lowest address in cRAM instead of
                              // c.main(). This allows a partial code download and
                              // reutilization of existing ROM code. If this bit is
                              // cleared, firmware will execute romMain and will not utilize
                              // cRAM.
uint8_t msk_upprogctl_jumpram = 0x20;
uint8_t ord_upprogctl_ramcrcok = 4;   // When set, a proper code download has completed including a
                                 // final CRC-8 check. This bit is valid only during a full
                                 // download sequence after progrdy is cleared by firmware. At
                                 // all other times this bit will read zero.This bit is also
                                 // used to report RAM MemBIST results during production test.
uint8_t msk_upprogctl_ramcrcok = 0x10;
uint8_t ord_upprogctl_progwr = 3;      // When set, the cRAM may be written via the code download
                                  // mailbox.
uint8_t msk_upprogctl_progwr = 0x08;
uint8_t ord_upprogctl_progrdy = 2;    // Firmware sets this bit upon to grant a progReq code
                                 // download. By setting this bit firmware guarantees not to be
                                 // running from cRAM. After this bit is set by firmware , the
                                 // user may procede with the code down/upload. When
                                 // progreq is cleared by the user, firmware will execute a
                                 // CRC-8 check on cRAM and post the result to ramcrcok.
                                 // Firmware will then loop waiting for a soft or hard reset.
uint8_t msk_upprogctl_progrdy = 0x04;
uint8_t ord_upprogctl_progreq = 1;    // The user sets this bit to signal an intention to download
                                 // new firmware. Once set, the user must wait for progrdy to
                                 // be set by firmware before proceeding with down/upload. Upon
                                 // programming completion, the user must clear this request
                                 // bit to trigger a CRC-8 validation.
uint8_t msk_upprogctl_progreq = 0x02;
uint8_t ord_upprogctl_bootram = 0;    // The user sets this bit after successfully downloading code
                                 // to the cRAM. If this bit is set, cRAM will appear at
                                 // address 0, starting at the next soft or hard reset
                                 // exit. This allows a full code download and
                                 // replacement. If this bit is cleared, firmware will
                                 // execute romMain and will not utilize cRAM.
uint8_t msk_upprogctl_bootram = 0x01;

// Register definition: upprogaddlsb
uint8_t upprogaddlsb = 0xEB;               // uP Program Address LSB, R/W
uint8_t ord_upprogaddlsb_upprogaddlsb = 0; // The user sets the LSB of the address to upload or download
                                       // from/to in this register. On every read or write
                                       // (respectively) to the upprogdata register the
                                       // upprogaddmsb/lsb pair will be auto-incremented by one.On a
                                       // RAM BIST failure, address failure information is recorded
                                       // to this register.
uint8_t msk_upprogaddlsb_upprogaddlsb = 0xFF;

// Register definition: upprogaddmsb
uint8_t upprogaddmsb = 0xEC;               // uP Program Address MSB, R/W
uint8_t ord_upprogaddmsb_upprogaddmsb = 0; // This field represents the MSB of the upprogaddlsb/msb pair.
uint8_t msk_upprogaddmsb_upprogaddmsb = 0xFF;

// Register definition: upprogdata
uint8_t upprogdata = 0xED;             // uP Program Data Mailbox, R/W
uint8_t ord_upprogdata_upprogdata = 0; // The user reads or writes data to be uploaded or downloaded
                                  // in this register. On every read or write (respectively) to
                                  // this register the upprogaddmsb/lsb pair will be
                                  // auto-incremented by one. On a RAM BIST failure, data
                                  // failure information is recorded here. If RAM BIST read does
                                  // match the expected data the corresponding data bit will be
                                  // set in this field. Only the first byte error is recorded.
uint8_t msk_upprogdata_upprogdata = 0xFF;
