/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
#include "bootloader.h"



uint8_t BOOT_Load(void)
{   
    /* Wait for Start Character */
//    printf("hear \r\n");
    while(EUSART1_Read() != STX);
//    printf("get it \r\n");
    /* Get Header */
    Header.get();
    /* Process Command */
    switch(Header.command)
    {
        case RD_VERSION:
            BOOT_ReadVersion();
            break;
        case ER_FLASH:
            BOOT_EraseUserFlash();
            break;
        case WR_EEDATA:
        case WR_FLASH:
            BOOT_Write();
            break;
        case RD_FLASH:
        case RD_EEDATA:
        case RD_CONFIG:
            BOOT_Read();
            break;
        case WR_CONFIG:
            break;
        case RUN_APP:
            DATAEE_WriteByte(BOOT_KEY, APP_MODE);
            return 0;
        default:
            EUSART1_Write(COMMAND_ERROR);
            break;
    }
    return 1;
}


void BOOT_GetHeader(void)
{
    Header.address = 0;
    Header.command = EUSART1_Read();
    for(int i = 0; i < 4; i++)
    {        
        Header.address |= ((uint32_t)EUSART1_Read()<<(i*8));       
    }
    Header.marker = EUSART1_Read();
    Header.length = EUSART1_Read();
    if (Header.command == WR_FLASH) {
        for (index = 0; index < Header.length; index++) {
            Header.dataBuffer[index] = EUSART1_Read();
        }
        for (index = 0; index < 2; index++) {
            Header.crc |= ((uint16_t) EUSART1_Read() << (index * 8));
        }
    }
    Header.endOfPacket = EUSART1_Read();
}


void BOOT_Read(void)
{
    uint24_t max_address,  min_address;
    uint8_t max_length, min_length;
    
    switch(Header.command)
    {
        case RD_FLASH:
            min_address = APPLICATION_MIN_ADDR;
            max_address = APPLICATION_MAX_ADDR;
            min_length = 0;
            max_length = 0x40;
            break;
        case RD_CONFIG:
            min_address = CONFIG_MIN_ADDR;
            max_address = CONFIG_MAX_ADDR;
            min_length = 0;
            max_length = 0x0E;
            break;
        case RD_EEDATA:
            min_address = EEPROM_MIN_ADDR;
            max_address = EEPROM_MAX_ADDR;
            min_length = 0;
            max_length = 0x40;
            break;
        default:
            return;
    }
    
    if(Header.address < min_address || Header.address > max_address)
    {
        /* Error Response */
        EUSART1_Write(ADDRESS_ERROR);
        return;
    }
    
    /* Check for marker 0x00 */
    if(Header.marker != 0x00)
    {
        /* Error Response */
        EUSART1_Write(MARKER_ERROR);
        return;
    }
    
    /* Receive number of bytes to read */
    if(Header.length < min_length || Header.length > max_length)
    {
        /* Error Response */
        EUSART1_Write(COUNT_ERROR);
        return;
    }
    
    /* Receive the End of Frame Character */
    if(Header.endOfPacket != ETX)
    {
        /* Error Response */
        EUSART1_Write(EOF_ERROR);
        return;
    }
    
    /* Response */
//    EUSART1_Write(STX);
    printf("Reading flash....");
    for(int i = 0; i < Header.length; i++)
    {
        switch(Header.command)
        {
            case RD_FLASH:
            case RD_CONFIG:
//                EUSART1_Write(FLASH_ReadByte(Header.address++));
                break;
            case RD_EEDATA:
//                EUSART1_Write(DATAEE_ReadByte(Header.address++));
                break;
            default:
                EUSART1_Write(EXECUTION_ERROR);
                return;
        }
        
    }
    printf("read complete \r\n");
    EUSART1_Write(NEXT);
}

void BOOT_Write(void)
{
    uint32_t max_address,  min_address;
    uint32_t max_length, min_length;
    uint16_t crc;
    
    switch(Header.command)
    {
        case WR_FLASH:
            min_address = APPLICATION_MIN_ADDR;
            max_address = 0xFFFF;
            min_length = 0;
            max_length = 0x40;
            break;
        case WR_EEDATA:
            min_address = EEPROM_MIN_ADDR;
            max_address = EEPROM_MAX_ADDR;
            min_length = 0;
            max_length = 0x40;
            break;
        default:
            return;
    }    
    if(Header.address < min_address || Header.address > max_address)
    {
        /* Error Response */
        EUSART1_Write(ADDRESS_ERROR);
        printf("address error \r\n");
        return;
    }
    /* Check for marker 0x00 */
    if(Header.marker != 0x00)
    {
        /* Error Response */
        EUSART1_Write(MARKER_ERROR);
        printf("marker error \r\n");
        return;
    }   
    /* Receive number of bytes to write */
    if(Header.length < min_length || Header.length > max_length)
    {
        /* Error Response */
        EUSART1_Write(COUNT_ERROR);
        return;
    }  
    /* Cyclical Redundancy Check */
    if (Header.length != 0) {

        if (Header.crc != FLASH_crc16(Header.dataBuffer, Header.length)) {
            EUSART1_Write(CRC_ERROR);
            printf("calculate crc = 0x%X \r\n",FLASH_crc16(Header.dataBuffer, Header.length));
            printf("crc not verified \r\n");
            Header.crc = 0;
            return;
        } else {
            printf("crc verified \r\n");
            Header.crc = 0;
        }
    }
    
    /* Receive the End of Frame Character */
    if(Header.endOfPacket != ETX)
    {
        /* Error Response */
        EUSART1_Write(EOF_ERROR);
        printf("end of file error \r\n");
        return;
    } else {
        printf("writing.......");
        
    }
    
    /* Perform Write Operation */
    switch(Header.command)
    {
        case WR_FLASH:
            if (FLASH_WriteBlock(Header.address, (uint8_t *) Header.dataBuffer) == 0) {
                printf("write successfully \r\n");
                Header.address = 0;
                EUSART1_Write(NEXT);
            } else {
                printf("write failed \r\n");
            }     
            break;
        case WR_EEDATA:
            for(int i = 0; i < Header.length; i++)
            {
                DATAEE_WriteByte(Header.address++, Header.dataBuffer[i]);
            }
            EUSART1_Write(SUCCESS);
            break;
        default:
            EUSART1_Write(EXECUTION_ERROR);
            break;
    }
}

void BOOT_ReadVersion(void)
{
    /* Receive the End of Frame Character */
    if(Header.endOfPacket != ETX)
    {
        /* Error Response */
        printf("failed to read version \r\n");
        return;
    }   
    EUSART1_Write(STX); 
    /*Send Bootloader Version */
    EUSART1_Write(BOOT_VER_MAJOR);
    EUSART1_Write(BOOT_VER_MINOR);
    /*Send Device Identifier */
    EUSART1_Write(0x24);
    EUSART1_Write(0x61);  
    printf("\r\n");
    printf("version read successfully \r\n");
    EUSART1_Write(NEXT);
}

void BOOT_EraseUserFlash(void)
{
    /* Receive the End of Frame Character */
    if(Header.endOfPacket != ETX)
    {
        /* Error Response */
        printf("failed to erase flash \r\n");
        return;
    }     
    DATAEE_WriteByte(BOOT_KEY, ~APP_MODE); 
    uint32_t address = APPLICATION_MIN_ADDR;
    for(index = 0; index <768; index++) {
        FLASH_EraseBlock(address);
        /* point to next block */
        address += 64;
    }
    printf("successfully erased flashed  \r\n");
    EUSART1_Write(NEXT);    
}


uint8_t FLASH_AddToBlock(uint32_t writeAddr, uint8_t *flashWrBufPtr, uint8_t count)
{   
    uint8_t result = 0;
    
    if((writeAddr < currentBlock.startAddress) || 
       (writeAddr > currentBlock.endAddress) || count == 0)
    {
        if(currentBlock.dataPtr != currentBlock.data)
        {
            /* Save previous block */
            result += FLASH_WriteBlock(currentBlock.startAddress, currentBlock.data);
            currentBlock.dataPtr = currentBlock.data;
            FLASH_ClearBlockData();
        }
        
        /* Reset addresses */
        currentBlock.startAddress = writeAddr & BLOCK_MASK;
        currentBlock.endAddress = currentBlock.startAddress + WRITE_FLASH_BLOCKSIZE - 1;
        
        /* Return if dummy call */
        if(count == 0)
        {
            return result;
        }
    }
    
    currentBlock.dataPtr = &currentBlock.data[writeAddr - currentBlock.startAddress];
    
    for(int i = 0; i < count; i++)
    {
        /* Do we need to switch to the next block? */
        if((writeAddr + i) > currentBlock.endAddress)
        {
             /* Save previous block */
            result += FLASH_WriteBlock(currentBlock.startAddress, currentBlock.data);
            /* Reset addresses and pointer */
            currentBlock.startAddress = writeAddr + i;
            currentBlock.endAddress = currentBlock.startAddress + WRITE_FLASH_BLOCKSIZE - 1;
            currentBlock.dataPtr = currentBlock.data;
            FLASH_ClearBlockData();
        }
        
        *currentBlock.dataPtr++ = *flashWrBufPtr++;
    }
    
    return result;
}

uint16_t FLASH_crc16(uint8_t* data_p, uint8_t length)
{
    uint8_t x;
    /* Initial Polynomial */
    uint16_t crc = 0xFFFF;
    while (length--)
    {
        x = crc >> 8 ^ *data_p++;
        x ^= x>>4;
        crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
    }
    return crc;
}

void FLASH_ClearBlockData(void)
{
    for(int i = 0; i < 64; i++)
    {
        currentBlock.data[i] = 0xFF;
    }
}

/* *****************************************************************************
 End of File
 */
