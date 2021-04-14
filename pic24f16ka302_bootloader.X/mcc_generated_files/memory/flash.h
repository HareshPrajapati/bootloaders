/**
  FLASH Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    flash.h

  @Summary
    This is the generated header file for the FLASH driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for FLASH.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24F16KA302
        Driver Version    :  1.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>
#include <stdbool.h>

#define FLASH_WRITE_ROW_SIZE_IN_INSTRUCTIONS 32
#define FLASH_WRITE_ROW_SIZE_IN_PC_UNITS (FLASH_WRITE_ROW_SIZE_IN_INSTRUCTIONS * 2)
#define FLASH_UNLOCK_KEY 0x00AA0055


 
void     FLASH_Unlock(uint32_t  key);
void     FLASH_Lock(void);

/* FLASH_Erase1Row(uint32_t adddress ):  
 *                     Address must be row aligned.  
 */
bool     FLASH_Erase1Row(uint32_t address);

/* FLASH_Erase2Row(uint32_t adddress ):  
 *                     Address must be double row aligned.  
 */
bool     FLASH_Erase2Row(uint32_t address);

/* FLASH_Erase4Row(uint32_t adddress ):  
 *                     Address must be quad row aligned.  
 */
bool     FLASH_Erase4Row(uint32_t address);

/* The address in the Read and Write word functions below must be even */
uint32_t FLASH_ReadWord24(uint32_t address);
uint16_t FLASH_ReadWord16(uint32_t address);

/* Program the flash one row at a time. */

/* FLASH_WriteRow24: Writes a single row of data from the location given in *data to
 *                   the flash location in address.  Since the flash is only 24 bits wide
 *                   all data in the upper 8 bits of the source will be lost .  
 *                   The address in *data must be row aligned.
 *                   returns true if successful */
bool     FLASH_WriteRow24(uint32_t address, uint32_t *data);


/* FLASH_WriteRow16: Writes a single row of data from the location in given in *data to
 *                   to the flash location in address. Each 16 bit source data 
 *                   word is stored in the lower 16 bits of each flash entry and the 
 *                   upper 8 bits of the flash is not programmed. 
 *                   The address in *data must be row aligned.
 *                   returns true if successful */
bool     FLASH_WriteRow16(uint32_t address, uint16_t *data);

uint16_t FLASH_GetErasePageOffset(uint32_t address);
uint32_t FLASH_GetErasePageAddress(uint32_t address);

#endif	/* FLASH_H */

