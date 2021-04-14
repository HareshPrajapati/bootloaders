/*
 * File:   25Q32ASSIG_flashChip.c
 * Author: Haesh_MikoToniks
 *
 * Created on 22 February, 2021, 9:58 AM
 */


#include "xc.h"
#include "25Q32ASSIG_flashChip.h"


uint32_t millis() {
    return ticker;
}

void delayMs(uint32_t delay) {
    uint32_t currentTime = millis();
    while (millis() <= currentTime + delay) {
    }
}


void timerCallback(){
    ticker++;
}


void chipEnable() 
{
    CS_SetLow();
}

void chipDisable() 
{
    CS_SetHigh();
}

void writeEnable() 
{
    chipEnable();
    SPI1_Exchange8bit(WRITE_ENABLE);
    chipDisable();
}
 
void writeDisable() 
{
    chipEnable();
    SPI1_Exchange8bit(WRITE_DISABLE);
    chipDisable();
}  


void w25q32aInIt(void) {
    uint8_t id = getMID();
    printf("W25Q32A chip id is %u \r\n",id);
    blockCount = 64;
    pageSize = 256;
	sectorSize = 0x1000;
    sectorCount = blockCount*16;
    pageCount = (sectorCount*sectorSize)/pageSize;
	blockSize = sectorSize*16;
	capacityInKiloByte = (sectorCount*sectorSize)/1024;
    printf("W25Q32A Capacity(In KB) : %u \r\n",capacityInKiloByte);
    readuniqID();
    readStatusRegister(1);
	readStatusRegister(2);
    readStatusRegister(3);
}


uint8_t getMID() {
    chipEnable();
    SPI1_Exchange8bit(DEV_ID);
    SPI1_Exchange8bit(DUMMY_ADDR);
    SPI1_Exchange8bit(DUMMY_ADDR);
    SPI1_Exchange8bit(DUMMY_ADDR);
    uint8_t MID = SPI1_Exchange8bit(DUMMY_ADDR);
    ID = SPI1_Exchange8bit(DUMMY_ADDR);
    chipDisable();
    return (ID);
}

void readuniqID(void) {
    chipEnable();
    uint8_t i;
    SPI1_Exchange8bit(UINIQE_ID);
    for(i = 0; i < 4; i++) {
        SPI1_Exchange8bit(DUMMY_ADDR);
    }
    for(i = 0; i < 8; i++) {
        uniqID[i] = SPI1_Exchange8bit(DUMMY_ADDR);
    }
    chipDisable();
    printf("unique Id : %u \r\n",uniqID);
}

uint8_t readStatusRegister(uint8_t	selectStatusRegister_1_2_3)
{
	uint8_t	status=0;
    chipEnable();
	if(selectStatusRegister_1_2_3 == 1)
	{
		SPI1_Exchange8bit(READ_STATUS_REG1);
		status=SPI1_Exchange8bit(DUMMY_ADDR);	
		statusRegister1 = status;
	}
	else if(selectStatusRegister_1_2_3 == 2)
	{
		SPI1_Exchange8bit(READ_STATUS_REG2);
		status=SPI1_Exchange8bit(DUMMY_ADDR);	
		statusRegister2 = status;
	}else {
		SPI1_Exchange8bit(0x15);
		status=SPI1_Exchange8bit(DUMMY_ADDR);	
		statusRegister3 = status;
	}
    chipDisable();
	return status;
}
  
void eraseChip(void) {
    writeEnable();
	chipEnable();
    SPI1_Exchange8bit(ERASE_CHIP);
    chipDisable();
    waitForWriteEnd();
    printf("chip erased Succesfully \r\n");
}


void waitForWriteEnd(void) {
	chipEnable();
	SPI1_Exchange8bit(READ_STATUS_REG1);
    do {
    statusRegister1 = SPI1_Exchange8bit(DUMMY_ADDR);
    } while((statusRegister1 & 0x01) == 0x01);
    chipDisable();
}

void eraseSector(uint32_t sectorAddr)
{
    
    printf("Block erased from %X \r\n",sectorAddr);
	sectorAddr = sectorAddr * sectorSize;
    writeEnable();
    chipEnable();
    SPI1_Exchange8bit(ERASE_SECTOR);
    SPI1_Exchange8bit((sectorAddr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((sectorAddr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((sectorAddr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    chipDisable();
    waitForWriteEnd();
}

void eraseBlock(uint32_t blockAddr)
{
    printf("Block erased from %X \r\n",blockAddr);
//	blockAddr = blockAddr * sectorSize*16;
    writeEnable();
    chipEnable();
    SPI1_Exchange8bit(ERASE_BLOCK);
    SPI1_Exchange8bit((blockAddr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((blockAddr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((blockAddr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    chipDisable();
    waitForWriteEnd();   
}

uint32_t pageToSector(uint32_t	pageAddress)
{
	return ((pageAddress*pageSize)/sectorSize);
}

uint32_t pageToBlock(uint32_t	pageAddress)
{
	return ((pageAddress*pageSize)/blockSize);
}

uint32_t sectorToBlock(uint32_t	sectorAddress)
{
	return ((sectorAddress*sectorSize)/blockSize);
}

uint32_t sectorToPage(uint32_t	sectorAddress)
{
	return (sectorAddress*sectorSize)/pageSize;
}

uint32_t blockToPage(uint32_t	blockAddress)
{
	return (blockAddress*blockSize)/pageSize;
}


void writeByte(uint32_t addr,uint32_t data) 
{
    writeEnable();
    chipEnable();
    SPI1_Exchange8bit(WRITE_DATA);
    SPI1_Exchange8bit((addr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((addr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((addr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    SPI1_Exchange8bit(data);
    chipDisable();
    waitForWriteEnd();
}

uint32_t readByte(uint32_t addr) 
{
    chipEnable();
    SPI1_Exchange8bit(FAST_READ_DATA);
    SPI1_Exchange8bit((addr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((addr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((addr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    SPI1_Exchange8bit(DUMMY_ADDR);
    uint32_t response = SPI1_Exchange8bit(DUMMY_ADDR);
    chipDisable();
    return response;
}

void writeStream(uint32_t addr, char* buf, uint32_t count) {
    if (count < 1) {
        return;
    }
    writeEnable();
    chipEnable();
    SPI1_Exchange8bit(WRITE_DATA);
    SPI1_Exchange8bit((addr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((addr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((addr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    int i;
    for (i = 0; i < count; i++) {
       uint32_t Font =  SPI1_Exchange8bit(buf[i]);
    }
    chipDisable();
    waitForWriteEnd();
}


char *readStream(uint32_t addr, char* buf, uint32_t count)
{   
    if (count < 1) {
        return;
    }
    chipEnable();
    SPI1_Exchange8bit(FAST_READ_DATA);
    SPI1_Exchange8bit((addr & ADDR_BMASK2) >> ADDR_BSHIFT2);
    SPI1_Exchange8bit((addr & ADDR_BMASK1) >> ADDR_BSHIFT1);
    SPI1_Exchange8bit((addr & ADDR_BMASK0) >> ADDR_BSHIFT0);
    SPI1_Exchange8bit(DUMMY_ADDR);
    int i;
    for (i = 0; i < count; i++) {
        buf[i] =  SPI1_Exchange8bit(DUMMY_ADDR);
    }
    chipDisable();
    return buf;
}

void pageWrite(uint32_t addr, uint8_t *buff, size_t len) {
	uint32_t _addr = addr;
	size_t n;
	uint8_t temp[4], recTemp[4];
    uint8_t recBuff[256];
	for (n = 0; n < len; n += 256) { 
        writeEnable();
		chipEnable();
		temp[0] =  WRITE_DATA;
		temp[1] = (_addr & ADDR_BMASK2) >> ADDR_BSHIFT2;
		temp[2] = (_addr & ADDR_BMASK1) >> ADDR_BSHIFT1;
		temp[3] = (_addr & ADDR_BMASK0) >> ADDR_BSHIFT0;
        SPI1_Exchange8bitBuffer(temp,4,recTemp);
        SPI1_Exchange8bitBuffer(&buff[n],256,recBuff);
		chipDisable();
        waitForWriteEnd();
		_addr += 256;
	}
}

void readWriteBlock(uint32_t writeAddr , uint32_t readAddr ){
    uint8_t data[1024], i;
    memset(data, 'a', 1024);
    uint32_t writeStart = millis();
    if (BLOCK == 0) {
        pageWrite(writeAddr, data, 1024);
    }
    if (BLOCK <= 15) {
        writeInc = BLOCK;
        while (writeInc > 0) {
            for (i = 0; i <= 62; i++) {
                pageWrite(writeAddr, data, 1024);
                writeAddr += 1024;
            }
            writeInc--;
        }
    } else {
         printf("We have only 15 Blocks in the flash chip please select below 15 \r\n");
    }
    
    uint32_t writeStop = millis();
    printf("last write address = %u \r\n", writeAddr);
    printf("writingTime : %u \r\n", (writeStop - writeStart));

    uint8_t data2[1024];
    uint32_t readStart = millis();
    if (BLOCK == 0) {
        readStream(readAddr, data2, 1024);
    }
    if (BLOCK <= 15) {
        readInc = BLOCK;
        while (readInc > 0) {
            for (i = 0; i <= 62; i++) {
                readStream(readAddr, data2, 1024);
                readAddr += 1024;
            }
            readInc--;
        }
    } else {
        printf("We have only 15 Blocks in the flash chip please select below 15 \r\n");
    }
    uint32_t readStop = millis();
    printf("last read address = %u \r\n", readAddr);
    printf("readingTime : %u \r\n", (readStop - readStart));
    printf("%s \r\n", data2);
}

void sleepFlash() {
    waitForWriteEnd();
    chipEnable();
    SPI1_Exchange8bit(DEEP_POWER_DOWN);
    chipDisable();
}

void wakeUpFlash() {
    waitForWriteEnd();
    chipEnable();
    SPI1_Exchange8bit(WAKE_UP);
    chipDisable();
    waitForWriteEnd();
}

