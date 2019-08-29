/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "evkbimxrt1050_flexspi_nor_config.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_board"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.conf")))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.conf"
#endif

const flexspi_nor_config_t spiflash_config = {
    .memConfig =
        {
            .tag = FLEXSPI_CFG_BLK_TAG,/*��־��FCFB*/
            .version = FLEXSPI_CFG_BLK_VERSION,/*�汾��V1.4.0*/
            .readSampleClkSrc = kFlexSPIReadSampleClk_LoopbackInternally,/*�ڲ�����*/
            .csHoldTime = 3u, /*����ʱ��*/
            .csSetupTime = 3u,/*����ʱ��*/
            .columnAddressWidth = 0u,/*�е�ַ���*/
            .deviceModeCfgEnable = 1u,/*�豸ģʽ����ʹ��*/
            .deviceModeType = 1u,/*Quad ʹ������*/
            .deviceModeSeq.seqNum = 1u,/*LUT���к�*/
            .deviceModeSeq.seqId = 4u, /*LUT��������*/    
            .deviceModeArg = 0x000200,/*���� QE=1��S9��*/
            .deviceType = kFlexSpiDeviceType_SerialNOR,/*�豸����Ϊnor flash*/
            .sflashPadType = kSerialFlash_4Pads,/*�豸��������Ϊ4*/
            .serialClkFreq = kFlexSpiSerialClk_133MHz,/*flash ʱ��*/
            .sflashA1Size = 32u * 1024u * 1024u,      /*flash ��С32MBytes*/
            //.dataValidTime = {16u, 16u},
            .lookupTable =
                {
                    /*���ٶ�������ߣ�*/
                    [0]     = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xEC, RADDR_SDR, FLEXSPI_4PAD, 0x20),
                    [1]     = FLEXSPI_LUT_SEQ(DUMMY_SDR, FLEXSPI_4PAD, 0x06, READ_SDR, FLEXSPI_4PAD, 0x04),
                    

                    /*��״̬����*/
                    [1*4]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x05, READ_SDR, FLEXSPI_1PAD, 0x04),
                    /*дʹ������*/
                    [3*4]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x06, STOP, FLEXSPI_1PAD, 0),      
                    /*������������*/
                    [5*4]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x20, RADDR_SDR, FLEXSPI_1PAD, 0x04),
                    /*ҳ���������ߣ�*/
                    [9*4]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x32, RADDR_SDR, FLEXSPI_1PAD, 0x18),  
                    [9*4+1] = FLEXSPI_LUT_SEQ(WRITE_SDR,FLEXSPI_4PAD , 0x04, STOP, FLEXSPI_1PAD, 0),                  
                    /*��Ƭ����*/
                    [11*4]  = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xc7, STOP, FLEXSPI_1PAD, 0),                  
                },
        },
    .pageSize = 256u,/*ҳ��СΪ256�ֽ�*/
    .sectorSize = 4u * 1024u,/*������СΪ4k�ֽ�*/
};











//const flexspi_nor_config_t hyperflash_config = {
//    .memConfig =
//        {
//            .tag                = FLEXSPI_CFG_BLK_TAG,
//            .version            = FLEXSPI_CFG_BLK_VERSION,
//            .readSampleClkSrc   = kFlexSPIReadSampleClk_ExternalInputFromDqsPad,
//            .csHoldTime         = 3u,
//            .csSetupTime        = 3u,
//            .columnAddressWidth = 3u,
//            // Enable DDR mode, Wordaddassable, Safe configuration, Differential clock
//            .controllerMiscOption =
//                (1u << kFlexSpiMiscOffset_DdrModeEnable) | (1u << kFlexSpiMiscOffset_WordAddressableEnable) |
//                (1u << kFlexSpiMiscOffset_SafeConfigFreqEnable) | (1u << kFlexSpiMiscOffset_DiffClkEnable),
//            .sflashPadType = kSerialFlash_8Pads,
//            .serialClkFreq = kFlexSpiSerialClk_133MHz,
//            .sflashA1Size  = 64u * 1024u * 1024u,
//            .dataValidTime = {16u, 16u},
//            .lookupTable =
//                {
//                    // Read LUTs
//                    FLEXSPI_LUT_SEQ(CMD_DDR, FLEXSPI_8PAD, 0xA0, RADDR_DDR, FLEXSPI_8PAD, 0x18),
//                    FLEXSPI_LUT_SEQ(CADDR_DDR, FLEXSPI_8PAD, 0x10, DUMMY_DDR, FLEXSPI_8PAD, 0x06),
//                    FLEXSPI_LUT_SEQ(READ_DDR, FLEXSPI_8PAD, 0x04, STOP, FLEXSPI_1PAD, 0x0),
//                },
//        },
//    .pageSize           = 512u,
//    .sectorSize         = 256u * 1024u,
//    .blockSize          = 256u * 1024u,
//    .isUniformBlockSize = true,
//};
#endif /* XIP_BOOT_HEADER_ENABLE */
