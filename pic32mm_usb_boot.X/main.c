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
#include <stdbool.h>

#include "mcc_generated_files/system.h"

#define ASSERT(x)  while(!x)

typedef enum _BOOL { FALSE = 0, TRUE } BOOL;	// Undefined size

typedef unsigned char		BYTE;				// 8-bit unsigned
typedef unsigned short int	WORD;				// 16-bit unsigned
typedef unsigned long		DWORD;				// 32-bit unsigned
typedef unsigned long long	QWORD;				// 64-bit unsigned
typedef signed char			CHAR;				// 8-bit signed
typedef signed short int	SHORT;				// 16-bit signed
typedef signed long			LONG;				// 32-bit signed
typedef signed long long	LONGLONG;			// 64-bit signed

/* Alternate definitions */
typedef void                VOID;

typedef char                CHAR8;
typedef unsigned char       UCHAR8;

/* Processor & Compiler independent, size specific definitions */
// To Do:  We need to verify the sizes on each compiler.  These
//         may be compiler specific, we should either move them
//         to "compiler.h" or #ifdef them for compiler type.
typedef signed int          INT;
typedef signed char         INT8;
typedef signed short int    INT16;
typedef signed long int     INT32;
typedef signed long long    INT64;

typedef unsigned int        UINT;
typedef unsigned char       UINT8;
typedef unsigned short int  UINT16;
typedef unsigned long int   UINT32;  // other name for 32-bit integer
typedef unsigned long long  UINT64;


typedef union _BYTE_VAL
{
    BYTE Val;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    } bits;
} BYTE_VAL, BYTE_BITS;

typedef union _WORD_VAL
{
    WORD Val;
    BYTE v[2];
    struct
    {
        BYTE LB;
        BYTE HB;
    } byte;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
        unsigned char b9:1;
        unsigned char b10:1;
        unsigned char b11:1;
        unsigned char b12:1;
        unsigned char b13:1;
        unsigned char b14:1;
        unsigned char b15:1;
    } bits;
} WORD_VAL, WORD_BITS;

typedef union _DWORD_VAL
{
    DWORD Val;
	WORD w[2];
    BYTE v[4];
    struct
    {
        WORD LW;
        WORD HW;
    } word;
    struct
    {
        BYTE LB;
        BYTE HB;
        BYTE UB;
        BYTE MB;
    } byte;
    struct
    {
        WORD_VAL low;
        WORD_VAL high;
    }wordUnion;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
        unsigned char b9:1;
        unsigned char b10:1;
        unsigned char b11:1;
        unsigned char b12:1;
        unsigned char b13:1;
        unsigned char b14:1;
        unsigned char b15:1;
        unsigned char b16:1;
        unsigned char b17:1;
        unsigned char b18:1;
        unsigned char b19:1;
        unsigned char b20:1;
        unsigned char b21:1;
        unsigned char b22:1;
        unsigned char b23:1;
        unsigned char b24:1;
        unsigned char b25:1;
        unsigned char b26:1;
        unsigned char b27:1;
        unsigned char b28:1;
        unsigned char b29:1;
        unsigned char b30:1;
        unsigned char b31:1;
    } bits;
} DWORD_VAL;

#define LSB(a)          ((a).v[0])
#define MSB(a)          ((a).v[1])

#define LOWER_LSB(a)    ((a).v[0])
#define LOWER_MSB(a)    ((a).v[1])
#define UPPER_LSB(a)    ((a).v[2])
#define UPPER_MSB(a)    ((a).v[3])

typedef union _QWORD_VAL
{
    QWORD Val;
	DWORD d[2];
	WORD w[4];
    BYTE v[8];
    struct
    {
        DWORD LD;
        DWORD HD;
    } dword;
    struct
    {
        WORD LW;
        WORD HW;
        WORD UW;
        WORD MW;
    } word;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
        unsigned char b9:1;
        unsigned char b10:1;
        unsigned char b11:1;
        unsigned char b12:1;
        unsigned char b13:1;
        unsigned char b14:1;
        unsigned char b15:1;
        unsigned char b16:1;
        unsigned char b17:1;
        unsigned char b18:1;
        unsigned char b19:1;
        unsigned char b20:1;
        unsigned char b21:1;
        unsigned char b22:1;
        unsigned char b23:1;
        unsigned char b24:1;
        unsigned char b25:1;
        unsigned char b26:1;
        unsigned char b27:1;
        unsigned char b28:1;
        unsigned char b29:1;
        unsigned char b30:1;
        unsigned char b31:1;
        unsigned char b32:1;
        unsigned char b33:1;
        unsigned char b34:1;
        unsigned char b35:1;
        unsigned char b36:1;
        unsigned char b37:1;
        unsigned char b38:1;
        unsigned char b39:1;
        unsigned char b40:1;
        unsigned char b41:1;
        unsigned char b42:1;
        unsigned char b43:1;
        unsigned char b44:1;
        unsigned char b45:1;
        unsigned char b46:1;
        unsigned char b47:1;
        unsigned char b48:1;
        unsigned char b49:1;
        unsigned char b50:1;
        unsigned char b51:1;
        unsigned char b52:1;
        unsigned char b53:1;
        unsigned char b54:1;
        unsigned char b55:1;
        unsigned char b56:1;
        unsigned char b57:1;
        unsigned char b58:1;
        unsigned char b59:1;
        unsigned char b60:1;
        unsigned char b61:1;
        unsigned char b62:1;
        unsigned char b63:1;
    } bits;
} QWORD_VAL;




#define DATA_RECORD 		0
#define END_OF_FILE_RECORD 	1
#define EXT_SEG_ADRS_RECORD 2
#define EXT_LIN_ADRS_RECORD 4

#define FLASH_PAGE_SIZE		 		2048
#define DEV_CONFIG_REG_BASE_ADDRESS 0x1FC01700

#define SOH 01
#define EOT 04
#define DLE 16

#define FRAMEWORK_BUFF_SIZE					1000

#define FRAMEWORK_FrameWorkTask 			FrameWorkTask
#define FRAMEWORK_BuildRxFrame  			BuildRxFrame
#define FRAMEWORK_GetTransmitFrame 			GetTransmitFrame
#define FRAMEWORK_ExitFirmwareUpgradeMode 	ExitFirmwareUpgradeMode

#define APP_FLASH_BASE_ADDRESS 	0x1D004000 
#define APP_FLASH_END_ADDRESS   PROGRAM_FLASH_END_ADRESS


#define PROGRAM_FLASH_END_ADRESS (0x1D000000+0x30000-1)


//-------User configurable macros begin---------
#define MAJOR_VERSION 1
#define MINOR_VERSION 1

#define USER_APP_RESET_ADDRESS 	(0x1D004000 + 0x1000)

typedef enum {
    READ_BOOT_INFO = 1,
    ERASE_FLASH,
    PROGRAM_FLASH,
    READ_CRC,
    JMP_TO_APP

} T_COMMANDS;


typedef struct
{
	UINT Len;
	UINT8 Data[FRAMEWORK_BUFF_SIZE];
	
}T_FRAME;


typedef struct 
{
	UINT8 RecDataLen;
	DWORD_VAL Address;
	UINT8 RecType;
	UINT8* Data;
	UINT8 CheckSum;	
	DWORD_VAL ExtSegAddress;
	DWORD_VAL ExtLinAddress;
}T_HEX_RECORD;	


static const UINT8 BootInfo[2] =
{
    MAJOR_VERSION,
    MINOR_VERSION
};


static T_FRAME RxBuff;
static T_FRAME TxBuff;
static bool RxFrameValid;
static bool TriggerBaudChange;
static DWORD_VAL NewBaud;
static bool RunApplication = false;


void HandleCommand(void);
void BuildRxFrame(UINT8 *RxData, INT16 RxLen);
UINT GetTransmitFrame(UINT8* Buff);
void WriteHexRecord2Flash(UINT8* HexRecord, UINT totalRecLen);
bool BaudRateChangeRequested(void);
UINT16 CalculateCrc(UINT8 *data, UINT32 len);
	

extern void appFunction(void);


/********************************************************************
* Function: 	FrameWorkTask()
*
* Precondition: 
*
* Input: 		None.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview: 	Process the command if there is a valid fame.
*
*			
* Note:		 	None.
********************************************************************/


void FrameWorkTask(void)
{

	if(RxFrameValid)
	{
		// Valid frame received, process the command.
		HandleCommand();	
		// Reset the flag.
		RxFrameValid = false;			
	}        
}


/********************************************************************
* Function: 	HandleCommand()
*
* Precondition: 
*
* Input: 		None.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview: 	Process the received frame and take action depending on
				the command received.
*
*			
* Note:		 	None.
********************************************************************/

int myvar;
int sendTXUart;
extern unsigned int addRead;

void HandleCommand(void)
{
	UINT8 Cmd;
	DWORD_VAL Address;
	UINT8 i;
	DWORD_VAL Length;
	UINT8 *DataPtr;
	UINT Result;
	WORD_VAL crc;
	void* pFlash;

    

	
	// First byte of the data field is command.
	Cmd = RxBuff.Data[0];
	// Partially build response frame. First byte in the data field carries command.
	TxBuff.Data[0] = RxBuff.Data[0];
	
	// Reset the response length to 0.
	TxBuff.Len = 0;
				
	// Process the command.		
	switch(Cmd)
	{
		case READ_BOOT_INFO: // Read boot loader version info.
			memcpy(&TxBuff.Data[1], BootInfo, 2);
			//Set the transmit frame length.
			TxBuff.Len = 2 + 1; // Boot Info Fields	+ command
            
            asm("nop");
            asm("nop");
            myvar = *(int*)addRead;
            asm("nop");
            asm("nop");
            addRead+=4;
            asm("nop");
            asm("nop");
            sendTXUart = 4;
			break;
			
		case ERASE_FLASH:
			pFlash = (void*)0x1D000000;									
			for( i = 0; i < (0x30000/FLASH_PAGE_SIZE); i++ )
			{
				
				Result = FLASH_ErasePage( pFlash + (i*FLASH_PAGE_SIZE) );
				// Assert on NV error. This must be caught during debug phase.
				ASSERT(Result==0);
			
			}		           
            //Set the transmit frame length.
            TxBuff.Len = 1; // Command
			break;
		
		case PROGRAM_FLASH:
		    WriteHexRecord2Flash(&RxBuff.Data[1], RxBuff.Len-3);	//Negate length of command and CRC RxBuff.Len.
		    //Set the transmit frame length.
            TxBuff.Len = 1; // Command	    	
		   	break;
		   
		   
		case READ_CRC:
			 // Get address from the packet.
    	    memcpy(&Address.v[0], &RxBuff.Data[1], sizeof(Address.Val));
    	    memcpy(&Length.v[0], &RxBuff.Data[5], sizeof(Length.Val));
			crc.Val = CalculateCrc((UINT8 *)Address.Val, Length.Val);
			memcpy(&TxBuff.Data[1], &crc.v[0], 2);	
			
			//Set the transmit frame length.
            TxBuff.Len = 1 + 2;	// Command + 2 bytes of CRC.
			
			break;
	    
	    case JMP_TO_APP:
	    	// Exit firmware upgrade mode.
            //appFunction();
	    	RunApplication = true;
	    	break;
	    	
	    default:
	    	// Nothing to do.
	    	break;
	}   
	

		
}

/********************************************************************
* Function: 	BuildRxFrame()
*
* Precondition: 
*
* Input: 		Pointer to Rx Data and Rx byte length.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview: 	Builds rx frame and checks CRC.
*
*			
* Note:		 	None.
********************************************************************/
void BuildRxFrame(UINT8 *RxData, INT16 RxLen)
{
	static BOOL Escape = FALSE;
	WORD_VAL crc;
	
	
	while((RxLen > 0) && (!RxFrameValid)) // Loop till len = 0 or till frame is valid
	{
		RxLen--;
		
		if(RxBuff.Len >= sizeof(RxBuff.Data))
		{
			RxBuff.Len = 0;
		}	
		
		switch(*RxData)
		{
			
			case SOH: //Start of header
				if(Escape)
				{
					// Received byte is not SOH, but data.
					RxBuff.Data[RxBuff.Len++] = *RxData;
					// Reset Escape Flag.
					Escape = FALSE;
				}
				else
				{
					// Received byte is indeed a SOH which indicates start of new frame.
					RxBuff.Len = 0;				
				}		
				break;
				
			case EOT: // End of transmission
				if(Escape)
				{
					// Received byte is not EOT, but data.
					RxBuff.Data[RxBuff.Len++] = *RxData;
					// Reset Escape Flag.
					Escape = FALSE;
				}
				else
				{
					// Received byte is indeed a EOT which indicates end of frame.
					// Calculate CRC to check the validity of the frame.
					if(RxBuff.Len > 1)
					{
						crc.byte.LB = RxBuff.Data[RxBuff.Len-2];
						crc.byte.HB = RxBuff.Data[RxBuff.Len-1];
						if((CalculateCrc(RxBuff.Data, (UINT32)(RxBuff.Len-2)) == crc.Val) && (RxBuff.Len > 2))
						{
							// CRC matches and frame received is valid.
							RxFrameValid = TRUE;
												
						}
					}		
					
				}							
				break;
				
				
		    case DLE: // Escape character received.
				if(Escape)
				{
					// Received byte is not ESC but data.
					RxBuff.Data[RxBuff.Len++] = *RxData;
					// Reset Escape Flag.
					Escape = FALSE;					
				}
				else
				{
					// Received byte is an escape character. Set Escape flag to escape next byte.
					Escape = TRUE;					
				}	
				break;
			
			default: // Data field.
			    RxBuff.Data[RxBuff.Len++] = *RxData;
			    // Reset Escape Flag.
			    Escape = FALSE;
				break;	
			
		}

		//Increment the pointer.
		RxData++;	
	
	}	
	
}	

/********************************************************************
* Function: 	GetTransmitFrame()
*
* Precondition: 
*
* Input: 		Buffer pointer.
*
* Output:		Length of the buffer.
*
* Side Effects:	None.
*
* Overview: 	Gets the complete transmit frame into the "Buff".
*
*			
* Note:		 	None.
********************************************************************/
UINT GetTransmitFrame(UINT8* Buff)
{
	INT BuffLen = 0;
	WORD_VAL crc;
	UINT8 i;
	
	if(TxBuff.Len) 
	{
		//There is something to transmit.
		// Calculate CRC of the frame.
		crc.Val = CalculateCrc(TxBuff.Data, (UINT32)TxBuff.Len);
		TxBuff.Data[TxBuff.Len++] = crc.byte.LB;
		TxBuff.Data[TxBuff.Len++] = crc.byte.HB; 	
		
		// Insert SOH (Indicates beginning of the frame)	
		Buff[BuffLen++] = SOH;
		
		// Insert Data Link Escape Character.
		for(i = 0; i < TxBuff.Len; i++)
		{
			if((TxBuff.Data[i] == EOT) || (TxBuff.Data[i] == SOH)
				|| (TxBuff.Data[i] == DLE))
			{
				// EOT/SOH/DLE repeated in the data field, insert DLE.
				Buff[BuffLen++] = DLE;			
			}
			Buff[BuffLen++] = TxBuff.Data[i];
		} 
		
		// Mark end of frame with EOT.
		Buff[BuffLen++] = EOT;
		
		TxBuff.Len = 0; // Purge this buffer, no more required.
	}	
	
	return(BuffLen); // Return buffer length.
	
}	


/********************************************************************
* Function: 	WriteHexRecord2Flash()
*
* Precondition: 
*
* Input: 		HexRecord buffer.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview:     Writes hex record to flash.
*
*			
* Note:		 	None.
********************************************************************/
unsigned int WrDataHigh;
unsigned int WrDataLow;
unsigned int WrDataAux;
static unsigned int doubleWord = 0;
unsigned char __attribute__((address(0xA0003800), persistent)) rowSizeProg[256];
static unsigned int flagFirsOnce = 0;
static unsigned int flagProg = 0;
static unsigned int addressProgInit = 0;
unsigned int addressProgEnd;
unsigned int * pAdMemRam;
unsigned char countDataProg;
static unsigned int flagDataNotProg = 0;




void WriteHexRecord2Flash(UINT8* HexRecord, UINT totalHexRecLen)
{
	static T_HEX_RECORD HexRecordSt;
	UINT8 Checksum = 0;
	UINT i;
	UINT RdData;
	void* ProgAddress;
	UINT Result;
	UINT nextRecStartPt = 0;
	UINT8 temp[4];
    unsigned int caseAddr;

	while(totalHexRecLen>=5) // A hex record must be atleast 5 bytes. (1 Data Len byte + 1 rec type byte+ 2 address bytes + 1 crc)
	{
		HexRecord = &HexRecord[nextRecStartPt];
		HexRecordSt.RecDataLen = HexRecord[0];
		HexRecordSt.RecType = HexRecord[3];	
		HexRecordSt.Data = &HexRecord[4];
		
		//Determine next record starting point.
		nextRecStartPt = HexRecordSt.RecDataLen + 5;	
		
		// Decrement total hex record length by length of current record.
		totalHexRecLen = totalHexRecLen - nextRecStartPt;
		
		// Hex Record checksum check.
		Checksum = 0;
		for(i = 0; i < HexRecordSt.RecDataLen + 5; i++)
		{
			Checksum += HexRecord[i];
		}	
		
	    if(Checksum != 0)
	    {
		    //Error. Hex record Checksum mismatch.
		} 
		else
		{
			// Hex record checksum OK.
			switch(HexRecordSt.RecType)
			{
				case DATA_RECORD:  //Record Type 00, data record.
					HexRecordSt.Address.byte.MB = 0;
					HexRecordSt.Address.byte.UB = 0;
					HexRecordSt.Address.byte.HB = HexRecord[1];
					HexRecordSt.Address.byte.LB = HexRecord[2];
					
					// Derive the address.
					HexRecordSt.Address.Val = HexRecordSt.Address.Val + HexRecordSt.ExtLinAddress.Val + HexRecordSt.ExtSegAddress.Val;
							
					while(HexRecordSt.RecDataLen) // Loop till all bytes are done.
					{
						// Convert the Physical address to Virtual address. 
						ProgAddress = (void *)HexRecordSt.Address.Val;
						
						// Make sure we are not writing boot area and device configuration bits.
						if(((ProgAddress >= (void *)0x1D000000) && (ProgAddress <= (void *)APP_FLASH_END_ADDRESS))
						   )//&& (ProgAddress < (void*)DEV_CONFIG_REG_BASE_ADDRESS) )//|| (ProgAddress > (void*)DEV_CONFIG_REG_END_ADDRESS)))
						{

							if(HexRecordSt.RecDataLen < 4)
							{
								
								// Sometimes record data length will not be in multiples of 4. Appending 0xFF will make sure that..
								// we don't write junk data in such cases.
								WrDataAux = 0xFFFFFFFF;
								memcpy(&WrDataAux, HexRecordSt.Data, HexRecordSt.RecDataLen);	
							}
							else
							{	
								memcpy(&WrDataAux, HexRecordSt.Data, 4);
							}
                            
                            if(flagFirsOnce == 0)
                                //gravando o endereco na primeira passagem
                                //gravando o primeiro valor junto do endereco
                            {
                                flagFirsOnce = 1;
                                countDataProg = 255;//seta para o ultimo valor
                                rowSizeProg[0]=0xff;//carrega o primeiro valor na ram
                                //pq nao passa dentro do while o valor 0
                                while(countDataProg)
                                {
                                    rowSizeProg[countDataProg]=0xff;//carrega o vetor para 
                                    //novas gravacoes
                                    countDataProg--;//decrementa
                                }
                                countDataProg = 0;//ter certeza que o inicio do ponteiro esta no zero
                                if(flagDataNotProg)
                                    //tem dado nao gravado pq nao saiu do while e chegou 
                                    //no final do ponteiro de gravacao e ja gravou a linha anterior
                                    //aqui faz o carregamento do novo ponteiro
                                {
                                    if((HexRecordSt.Address.Val - 4) == (addressProgInit+256))
                                        //verifica se o dado esta na sequencia do anterior
                                    {
                                        addressProgInit = HexRecordSt.Address.Val - 4;
                                        addressProgEnd = addressProgInit + 255;
                                        flagDataNotProg = 0;
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataLow >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataLow >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataLow >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataLow >> 24);
                                        countDataProg += 4;
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataAux >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataAux >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataAux >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataAux >> 24);
                                        countDataProg += 4;
                                    }else
                                        //nao esta na sequencia do anterior 
                                        //esta em qualquer lugar da linha
                                    {
                                        addressProgInit = HexRecordSt.Address.Val & 0xffffff00;
                                        addressProgEnd = addressProgInit + 255;
                                        countDataProg = (unsigned char)((HexRecordSt.Address.Val & 0x000000ff) - 4);
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataLow >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataLow >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataLow >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataLow >> 24);
                                        countDataProg += 4;
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataAux >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataAux >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataAux >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataAux >> 24);
                                        countDataProg += 4;
                                    }
                                    
                                    
                                }
                                else
                                {
                                    addressProgInit = HexRecordSt.Address.Val;
                                    if(addressProgInit & 0x0000000c)
                                        //verificando se o endereco esta com valor final
                                        // 12 ou 8 ou 4 que eh uma posicao ruim
                                    {
                                        switch(addressProgInit & 0x0000000c)
                                        {
                                            case 12:
                                            //myvar = *(int*)addRead;
                                            addressProgInit = addressProgInit - 12;
                                            addressProgEnd = addressProgInit + 255;
                                            rowSizeProg[countDataProg + 12] = (unsigned char)(WrDataAux >> 0);
                                            rowSizeProg[countDataProg + 13] = (unsigned char)(WrDataAux >> 8);
                                            rowSizeProg[countDataProg + 14] = (unsigned char)(WrDataAux >> 16);
                                            rowSizeProg[countDataProg + 15] = (unsigned char)(WrDataAux >> 24);
                                            countDataProg += 16;
                                            break;
                                            case 8:
                                            addressProgInit = addressProgInit - 8;
                                            addressProgEnd = addressProgInit + 255;
                                            rowSizeProg[countDataProg + 8] = (unsigned char)(WrDataAux >> 0);
                                            rowSizeProg[countDataProg + 9] = (unsigned char)(WrDataAux >> 8);
                                            rowSizeProg[countDataProg + 10] = (unsigned char)(WrDataAux >> 16);
                                            rowSizeProg[countDataProg + 11] = (unsigned char)(WrDataAux >> 24);
                                            countDataProg += 12;
                                            break;
                                            case 4:
                                            addressProgInit = addressProgInit - 4;
                                            addressProgEnd = addressProgInit + 255;
                                            rowSizeProg[countDataProg + 4] = (unsigned char)(WrDataAux >> 0);
                                            rowSizeProg[countDataProg + 5] = (unsigned char)(WrDataAux >> 8);
                                            rowSizeProg[countDataProg + 6] = (unsigned char)(WrDataAux >> 16);
                                            rowSizeProg[countDataProg + 7] = (unsigned char)(WrDataAux >> 24);
                                            countDataProg += 8;
                                            break;
                                        }
                                    }
                                    else
                                        //endereco esta com uma posicao zero o melhor caso que existe
                                    {
                                        addressProgInit = HexRecordSt.Address.Val;
                                        addressProgEnd = addressProgInit + 255;
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataAux >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataAux >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataAux >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataAux >> 24);
                                        countDataProg += 4;

                                    }
                                }
                                
                            }
                            else
                                //nao eh primeira vez .. entao ele vem para cara fazer esse if
                            {
                                if((HexRecordSt.Address.Val >= addressProgInit) && (HexRecordSt.Address.Val <= (addressProgInit+255)))
                                    //valor do endereco dentro do intervalo de gravacao
                                {
                                    if((unsigned char)(HexRecordSt.Address.Val & 0x000000ff) == countDataProg)
                                        //favor colocar na posicao certa conforme o endereco vigente
                                    {
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataAux >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataAux >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataAux >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataAux >> 24);
                                        countDataProg+=4;
                                    }
                                    else
                                    {
                                        countDataProg += ((unsigned char)(HexRecordSt.Address.Val & 0x000000ff));
                                        rowSizeProg[countDataProg + 0] = (unsigned char)(WrDataAux >> 0);
                                        rowSizeProg[countDataProg + 1] = (unsigned char)(WrDataAux >> 8);
                                        rowSizeProg[countDataProg + 2] = (unsigned char)(WrDataAux >> 16);
                                        rowSizeProg[countDataProg + 3] = (unsigned char)(WrDataAux >> 24);
                                        countDataProg+=4;
                                    }
                                    
                                }
                                else
                                    //fora do intervalo chama a gravacao da linha
                                    //se o endereco for maior que 256 bytes
                                    //chama a gravacao e reseta a flag para reiniciar
                                {
                                    pAdMemRam = (void*)rowSizeProg;
                                    Result = FLASH_WriteRow((void *)addressProgInit,(void*)rowSizeProg);
                                    ASSERT(Result==0);
                                    flagFirsOnce = 0;
                                    //guarda o valor do WrDataux para usar na proxima vez
                                    WrDataLow = WrDataAux;
                                    flagDataNotProg = 1;
                                    countDataProg = 0;
                                    
                                }
                            }
                        }
						
						// Increment the address.
						HexRecordSt.Address.Val += 4;
						// Increment the data pointer.
						HexRecordSt.Data += 4;
						// Decrement data len.
						if(HexRecordSt.RecDataLen > 3)
						{
							HexRecordSt.RecDataLen -= 4;
						}	
						else
						{
							HexRecordSt.RecDataLen = 0;
						}	
					}
					break;
				
				case EXT_SEG_ADRS_RECORD:  // Record Type 02, defines 4th to 19th bits of the data address.
				    HexRecordSt.ExtSegAddress.byte.MB = 0;
					HexRecordSt.ExtSegAddress.byte.UB = HexRecordSt.Data[0];
					HexRecordSt.ExtSegAddress.byte.HB = HexRecordSt.Data[1];
					HexRecordSt.ExtSegAddress.byte.LB = 0;
					// Reset linear address.
					HexRecordSt.ExtLinAddress.Val = 0;
					break;
					
				case EXT_LIN_ADRS_RECORD:   // Record Type 04, defines 16th to 31st bits of the data address. 
					HexRecordSt.ExtLinAddress.byte.MB = HexRecordSt.Data[0];
					HexRecordSt.ExtLinAddress.byte.UB = HexRecordSt.Data[1];
					HexRecordSt.ExtLinAddress.byte.HB = 0;
					HexRecordSt.ExtLinAddress.byte.LB = 0;
					// Reset segment address.
					HexRecordSt.ExtSegAddress.Val = 0;
					break;
					
				case END_OF_FILE_RECORD:  //Record Type 01, defines the end of file record.
					HexRecordSt.ExtSegAddress.Val = 0;
					HexRecordSt.ExtLinAddress.Val = 0;
                    if(countDataProg != 0)
                        //tem valores que ainda nao foram gravados na memoria flash
                    {
                        Result = FLASH_WriteRow((void *)addressProgInit,(void*)rowSizeProg);
                        ASSERT(Result==0);
                        countDataProg = 0;
                        
                    }
                    
					break;
				default: 
					HexRecordSt.ExtSegAddress.Val = 0;
					HexRecordSt.ExtLinAddress.Val = 0;                    
                    break;
			}		
		}	
	}//while(1)	
		
}	


/**
 * Static table used for the table_driven implementation.
 *****************************************************************************/
static const UINT16 crc_table[16] = 
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef
};

/********************************************************************
* Function: 	CalculateCrc()
*
* Precondition: 
*
* Input: 		Data pointer and data length
*
* Output:		CRC.
*
* Side Effects:	None.
*
* Overview:     Calculates CRC for the given data and len
*
*			
* Note:		 	None.
********************************************************************/	
UINT16 CalculateCrc(UINT8 *data, UINT32 len)
{
    UINT i;
    UINT16 crc = 0;
    
    while(len--)
    {
        i = (crc >> 12) ^ (*data >> 4);
	    crc = crc_table[i & 0x0F] ^ (crc << 4);
	    i = (crc >> 12) ^ (*data >> 0);
	    crc = crc_table[i & 0x0F] ^ (crc << 4);
	    data++;
	} 

    return (crc & 0xFFFF);
}


/********************************************************************
* Function: 	ExitFirmwareUpgradeMode()
*
* Precondition: 
*
* Input: 		Void
*
* Output:		True if firmware upgrade mode has to be exited.
*
* Side Effects:	None.
*
* Overview:     This function returns true if firmware mode has to be exited.
*
*			
* Note:		 	None.
********************************************************************/
BOOL ExitFirmwareUpgradeMode(void)
{
	return RunApplication;
}	





int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
     
    }
    return 1; 
}
/**
 End of File
*/

