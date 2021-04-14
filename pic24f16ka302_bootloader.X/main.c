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
        Device            :  PIC24F16KA302
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
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/memory/flash.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define HIGH 1
#define LOW  0
volatile uint32_t ticker;
uint32_t flash_storage_address;

void timer_callback() {
    ticker++;
}

uint32_t millis() {
    return ticker;
}

void delayMs(uint32_t delay) {
    uint32_t currentTime = millis();
    while (millis() <= currentTime + delay) {
    }
}

char *UART_Read_String(char *Output, uint16_t length) {

    uint16_t i;
    for (i = 0; i < length; i++) {
        Output[i] = UART1_Read();
    }
    return Output;
}

char buffer[32];
 uint8_t d = 200;
 
 void print_no(uint32_t d){
     uint32_t no =d;
     uint32_t t = 0x80000000;
     if(no <=255){
         
     }
 }
/*
                         Main application
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(timer_callback);
    // Enable the Global Interrupts
    INTERRUPT_GlobalEnable();
    bool inBootloaderMode = false;
    int count;
    bool result;
    flash_storage_address = 0x1000;
    //    printf("address = 0x%lX \r\n",flash_storage_address);
    strcpy(buffer, "result");
    int i = 0;
    while (buffer[i] != '\0') {
        UART1_Write(buffer[i]);
        i++;
    }
   
    char *val = __STR(d);
    while (*val != '\0') {
        UART1_Write(*val);
        val++;
    }

    while (1) {
        if (IO_RA0_GetValue() == HIGH) {
            inBootloaderMode = true;
        }
        if (inBootloaderMode) {
            IO_RA2_SetHigh();
            char data[5];
            char *data2 = UART_Read_String(data, sizeof (data));
            if (data2 = "ERASE") {

                uint32_t add = flash_storage_address;
                while (count <= 13) {

                    FLASH_Unlock(FLASH_UNLOCK_KEY);
                    result = FLASH_Erase4Row(add);
                    //                printf("address = 0x%lX \r\n", add);
                    add += 512;
                    FLASH_Lock();
                    //                printf("result = %d \r\n", result);
                    count++;

                }

            }
        }
    }

    return 1;
}
/**
 End of File
 */

