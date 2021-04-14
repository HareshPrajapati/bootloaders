/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0256GPM064
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include <stdint.h>

#include "mcc_generated_files/system.h"
#include "B25Q32.h"
#include "lfs.h"

lfs_t lfs;
lfs_file_t file;
uint8_t readBuffer[256];
uint8_t writeBuffer[256];
uint8_t lookAheadBuffer[256];

int blockDeviceRead(const struct lfs_config *c,lfs_block_t block,lfs_off_t off,void *buffer,lfs_size_t size){
    readStream((block * c->block_size + off),(char *)buffer,size);
    return 0;
}

int blockDeviceWrite(const struct lfs_config *c,lfs_block_t block,lfs_off_t off,const void *buffer,lfs_size_t size){
     writeStream((block * c->block_size + off),(char *)buffer,size);
     return 0;
}

int blockDeviceErase(const struct lfs_config *c,lfs_block_t block){
     eraseSector((block * c->block_size));
     return 0;
}

int blockDeviceSync(const struct lfs_config *c){
    return 0;
}

//
const struct lfs_config cfg = {
    // block device operations
    .read  = blockDeviceRead,
    .prog  = blockDeviceWrite,
    .erase = blockDeviceErase,
    .sync  = blockDeviceSync,
    // block device configuration
    .read_size = 256,
    .prog_size = 256,
    .block_size = 4096,
    .block_count = 256,
    .cache_size = 256,
    .lookahead_size = 256,
    .block_cycles = 500,
    .read_buffer = readBuffer,
    .prog_buffer = writeBuffer,
    .lookahead_buffer = lookAheadBuffer,
};


int main(void)
{   
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(timerCallback);
    w25q32aInIt();
   // eraseChip();
    printf("start \r\n");
    int err = lfs_mount(&lfs, &cfg);
    printf("mount err = %d \r\n", err);

    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (err) {
        lfs_format(&lfs, &cfg);
        err = lfs_mount(&lfs, &cfg);
        printf("mount err after formate = %d \r\n", err);
    }
    uint8_t boot_count[1024];
    uint8_t boot_count2[1024];
    memset(boot_count,'Z',sizeof(boot_count));
    lfs_file_open(&lfs, &file, "FONT", LFS_O_RDWR | LFS_O_CREAT);
    lfs_file_rewind(&lfs, &file);
    uint8_t index , writeInc = 1 , readInc = 1;
    uint32_t startWrite =  millis();
    if(writeInc == 0){
        lfs_file_write(&lfs, &file, &boot_count, sizeof(boot_count));
    }
    while (writeInc > 0){
    for (index = 0; index <= 63; index++) {
    lfs_file_write(&lfs, &file, &boot_count, sizeof(boot_count));
    }
    writeInc--;
    }
    uint32_t stopWrite =  millis();
    printf("time for write = %u \r\n",(stopWrite-startWrite));
    lfs_file_close(&lfs, &file);
    lfs_unmount(&lfs);
    
    
    err = lfs_mount(&lfs, &cfg);
    printf("mount err after formate = %d \r\n", err);
    lfs_file_open(&lfs, &file, "FONT", LFS_O_RDWR);
    uint32_t startRead = millis();
    if(readInc == 0) {
        lfs_file_read(&lfs, &file, &boot_count2, sizeof(boot_count2));
    }
    while (readInc > 0){
    for (index = 0; index <= 63; index++){
    lfs_file_read(&lfs, &file, &boot_count2, sizeof(boot_count2));
    }
    readInc--;
    }
    uint32_t stopRead = millis();
    printf("time for read = %u \r\n",(stopRead-startRead));
    uint32_t fileSize = lfs_file_size(&lfs,&file);
    printf("File size : %u \r\n",fileSize);
    // remember the storage is not updated until the file is closed successfully
    lfs_file_close(&lfs, &file);
    // release any resources we were using
    lfs_unmount(&lfs);
    // print the boot count
    printf("boot_count: %s\n", boot_count2);
   
   // readWriteBlock(0,0);

    
    while (1)
    {

    }
    return 1; 
}
/**
 End of File
*/

