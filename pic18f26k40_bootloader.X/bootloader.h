/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_BOOTLODER_H
#define	XC_BOOTLODER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart1.h"
#include "mcc_generated_files/pin_manager.h"

#define     BOOT_KEY        0x10
#define     APP_MODE        0xAA

#define     RD_VERSION          0x00
#define     RD_FLASH            0x01
#define     WR_FLASH            0x02
#define     ER_FLASH            0x03
#define     RD_EEDATA           0x04
#define     WR_EEDATA           0x05
#define     RD_CONFIG           0x06
#define     WR_CONFIG           0x07
#define     RUN_APP             0x08
    
#define     STX                 0x0F
#define     ETX                 0x04
#define     DLE                 0x05

#define     SUCCESS             0xFF
#define     COMMAND_ERROR       0xFE
#define     MARKER_ERROR        0xFD
#define     ADDRESS_ERROR       0xFC
#define     COUNT_ERROR         0xFB
#define     EOF_ERROR           0xFA
#define     EXECUTION_ERROR     0xF9
#define     CRC_ERROR           0xF8

#define     BOOT_VER_MAJOR      0x01
#define     BOOT_VER_MINOR      0x00

#define     DEV_ID1_ADDR        0x3FFFFE
#define     DEV_ID2_ADDR        0x3FFFFF
#define     NEXT                0xEE


#define     BOOTLOADER_MAX_ADDR             0x0FFF      //4K    =   0x1000      <- Always Code Protected
#define     FLASH_MAX_ADDR                  0xFFFF      //64K   =   0x10000

#define     APPLICATION_MIN_ADDR            0x4000
#define     APPLICATION_MAX_ADDR            FLASH_MAX_ADDR
#define     APPLICATION_FLASH_SIZE          APPLICATION_MAX_ADDR - APPLICATION_MIN_ADDR

#define     EEPROM_MAX_ADDR                 0x400       //1K
#define     EEPROM_MIN_ADDR                 0x000

#define     CONFIG_MAX_ADDR                 0x30000D       
#define     CONFIG_MIN_ADDR                 0x300000

#define     APPLICATION_RESET_VECTOR        APPLICATION_MIN_ADDR
#define     APPLICATION_HP_INT_VECTOR       APPLICATION_MIN_ADDR + 0x0008
#define     APPLICATION_LP_INT_VECTOR       APPLICATION_MIN_ADDR + 0x0018

#define     AWAITING_COMMAND                0xBB
#define     EXITING_BACKDOOR                0xCC
#define     BACKDOOR_TIMEOUT                10000

#define     BACKDOOR_IO
//#define     BACKDOOR_TIMED
#define     BOOT_INDICATOR


#define     BLOCK_MASK              0xFFFC0

#define  NEW_INTERRUPT_VECTOR_HIGH   0x4008
#define  NEW_INTERRUPT_VECTOR_LOW    0x4018

#define _str(x)  #x
#define str(x)  _str(x)



uint8_t exit_boot;
uint32_t index;
uint8_t tempDataBuffer[64];

struct MessageHeader
{
    uint8_t command;
    uint32_t address;
    uint8_t marker;
    uint8_t length;
    void (*get)(void);
    uint8_t dataBuffer[64];
    uint16_t crc;
    uint8_t endOfPacket;
};

struct Block
{
    uint32_t startAddress;
    uint32_t endAddress;
    uint8_t data[64];
    uint8_t* dataPtr;
};



uint8_t BOOT_Load(void);
void BOOT_GetHeader(void);
void BOOT_EraseUserFlash(void);
void BOOT_ReadVersion(void);
void BOOT_Write(void);
void BOOT_Read(void);
void BOOT_GetHeader(void);
uint8_t FLASH_AddToBlock(uint32_t writeAddr, uint8_t *flashWrBufPtr, uint8_t count);
uint16_t FLASH_crc16(uint8_t* data_p, uint8_t length);
void FLASH_ClearBlockData(void);


struct MessageHeader Header = {0, 0, 0, 0,BOOT_GetHeader};
struct Block currentBlock;
uint8_t tempBuffer[1] = {};

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_BOOTLODER_H */

