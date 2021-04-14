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
        Device            :  PIC24FJ256GA705
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
#include <stdio.h>
#include "p24FJ256GA705.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/dma.h"
#include <stdio.h>
char name[50] = "ABCDEFGHIJKLMNO";

unsigned char Array2[100];
int i;
void test(void);
int main(void)
{  
    // initialize the device
    SYSTEM_Initialize();
    for (i = 0; i < 100; i++) {
        Array2[i] = 0; //fill with 0
    }
    DMACONbits.DMAEN = 1;
    DMACONbits.PRSSEL = 1;
    DMAH = 0x5000; //set lower and upper address limit
    DMAL = 0x850;
    DMASRC0 = (unsigned int) &Array2;
    DMADST0 = (unsigned short int) &U1TXREG; // load destination address
    DMACNT0 = 4; //When the Uart buffer is full 4,
    //do a interrupt and transfer 4 bytes
    DMACH0 = 0;
    DMACH0bits.BYTE = 1;
    DMACH0bits.SAMODE = 0; //Source address increment mode,
    //do not increment
    DMACH0bits.DAMODE = 1; //Destination address increment mode,
    //increment 1
    DMACH0bits.TRMODE = 2; //Transfer mode Continous
    DMAINT0bits.CHSEL = 33; //Trigger on UART2 Receive
    DMACH0bits.CHEN = 1; //Channel enable
    IFS0bits.DMA0IF = 0;
    while (!IFS0bits.DMA0IF); //DONEIF=1;CHEN=0,DMA0IF=1 and
    //transfer complete with one trigger
    IFS0bits.DMA0IF = 0;
    while (1);
    while (1)
    {
 
    }

    return 1;
}
/**
 End of File
*/

