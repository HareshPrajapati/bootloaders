/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _B25Q32_H
#define _B25Q32_H


#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

uint8_t ID;
uint8_t uniqID[8];
uint16_t pageSize;
uint32_t pageCount;
uint32_t sectorSize;
uint32_t sectorCount;
uint32_t blockSize;
uint32_t blockCount;
uint32_t capacityInKiloByte;
uint8_t statusRegister1;
uint8_t statusRegister2;
uint8_t statusRegister3;
uint8_t lock;



#define WRITE_ENABLE        0x06
#define WRITE_DISABLE       0x04
#define READ_DATA           0x03
#define FAST_READ_DATA      0x0B
#define WRITE_DATA          0x02
#define DEV_ID              0x90
#define UINIQE_ID           0x9F
#define DUMMY_ADDR          0x00
#define READ_STATUS_REG1    0x05
#define READ_STATUS_REG2    0x35
#define WRITE_STATUS_REG    0x01
#define ERASE_CHIP          0x60
#define ERASE_SECTOR        0x20
#define ERASE_BLOCK         0xD8
#define DEEP_POWER_DOWN     0xB9
#define WAKE_UP             0xAB

#define ADDR_BMASK2     0xff0000
#define ADDR_BMASK1     0x00ff00
#define ADDR_BMASK0     0x0000ff
 
#define ADDR_BSHIFT2    16
#define ADDR_BSHIFT1    8
#define ADDR_BSHIFT0    0


int writeInc , readInc ;
#define BLOCK 16

uint32_t millis();
void delayMs(uint32_t delay);
void timerCallback();
void chipEnable();
void chipDisable();
void writeEnable();
void writeDisable() ;


bool w25q32aInIt(void);
uint8_t getMID();
void readuniqID(void);
uint8_t readStatusRegister(uint8_t	selectStatusRegister_1_2_3);
void eraseChip(void);
void waitForWriteEnd(void);
void eraseSector(uint32_t sectorAddr);
void eraseBlock(uint32_t blockAddr);
uint32_t pageToSector(uint32_t	pageAddress);
uint32_t pageToBlock(uint32_t	pageAddress);
uint32_t sectorToBlock(uint32_t	sectorAddress);
uint32_t sectorToPage(uint32_t	sectorAddress);
uint32_t blockToPage(uint32_t	blockAddress);
void writeByte(uint32_t addr,uint32_t data);
void writeStream(uint32_t addr, char* buf, uint32_t count);
uint32_t readByte(uint32_t addr);
char *readStream(uint32_t addr, char* buf, uint32_t count);
void readWriteBlock(uint32_t writeAddr , uint32_t readAddr);
void pageWrite(uint32_t addr, uint8_t *buff, size_t len);
void sleepFlash();
void wakeUpFlash();
void writeBlock(uint32_t writeAddr , uint8_t *data);
void readBlock(uint32_t readAddr , uint8_t *data);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //_B25Q32_H

/* *****************************************************************************
 End of File
 */
