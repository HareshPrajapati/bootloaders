/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <xc.h>
#include <stdbool.h>

#include "leds.h"

#define LED_LED3_RED_LAT     LATDbits.LATD1
#define LED_LED3_GREEN_LAT   LATCbits.LATC3
#define LED_LED3_BLUE_LAT    LATAbits.LATA5
#define LED_LED1_LAT         LATDbits.LATD3
#define LED_LED2_LAT         LATCbits.LATC13

#define LED_LED3_RED_TRIS    TRISDbits.TRISD1
#define LED_LED3_GREEN_TRIS  TRISCbits.TRISC3
#define LED_LED3_BLUE_TRIS   TRISAbits.TRISA5
#define LED_LED1_TRIS        TRISDbits.TRISD3
#define LED_LED2_TRIS        TRISCbits.TRISC13

#define LED_ON  1
#define LED_OFF 0

#define INPUT  1
#define OUTPUT 0

/*********************************************************************
 * Function: void LED_On(LED led);
 *
 * Overview: Turns requested LED on
 *
 * PreCondition: LED configured via LED_Configure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silk-screen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_On(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_On ( LED led )
{
    switch (led)
    {       
        case LED_LED3_RED:
            LED_LED3_RED_LAT = LED_ON ;
            break ;

        case LED_LED3_GREEN:
            LED_LED3_GREEN_LAT = LED_ON ;
            break ;

        case LED_LED3_BLUE:
            LED_LED3_BLUE_LAT = LED_ON ;
            break ;

        case LED_LED1:
            LED_LED1_LAT = LED_ON ;
            break ;

        case LED_LED2:
            LED_LED2_LAT = LED_ON ;
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: void LED_Off(LED led);
 *
 * Overview: Turns requested LED off
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silk-screen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Off(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_Off ( LED led )
{
    switch (led)
    {
        case LED_LED3_RED:
            LED_LED3_RED_LAT = LED_OFF ;
            break ;

        case LED_LED3_GREEN:
            LED_LED3_GREEN_LAT = LED_OFF ;
            break ;

        case LED_LED3_BLUE:
            LED_LED3_BLUE_LAT = LED_OFF ;
            break ;

        case LED_LED1:
            LED_LED1_LAT = LED_OFF ;
            break ;

        case LED_LED2:
            LED_LED2_LAT = LED_OFF ;
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: void LED_Toggle(LED led);
 *
 * Overview: Toggles the state of the requested LED
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silk-screen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Toggle(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_Toggle ( LED led )
{
    switch (led)
    {
        case LED_LED3_RED:
            LED_LED3_RED_LAT ^= 1 ;
            break ;

        case LED_LED3_GREEN:
            LED_LED3_GREEN_LAT ^= 1 ;
            break ;

        case LED_LED3_BLUE:
            LED_LED3_BLUE_LAT ^= 1 ;
            break ;

        case LED_LED1:
            LED_LED1_LAT ^= 1 ;
            break ;

        case LED_LED2:
            LED_LED2_LAT ^= 1 ;
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: bool LED_Get(LED led);
 *
 * Overview: Returns the current state of the requested LED
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silk-screen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Get(LED_CONNECTION_DETECTED);
 *
 * Output: true if on, false if off
 *
 ********************************************************************/
bool LED_Get ( LED led )
{
    switch (led)
    {
        case LED_LED3_RED:
            return ( ( LED_LED3_RED_LAT == LED_ON ) ? true : false ) ;

        case LED_LED3_GREEN:
            return ( ( LED_LED3_GREEN_LAT == LED_ON ) ? true : false ) ;

        case LED_LED3_BLUE:
            return ( ( LED_LED3_BLUE_LAT == LED_ON ) ? true : false ) ;

        case LED_LED1:
            return ( ( LED_LED1_LAT == LED_ON ) ? true : false ) ;

        case LED_LED2:
            return ( ( LED_LED2_LAT == LED_ON ) ? true : false ) ;
            
        case LED_NONE:
            return false ;
    }
    return false ;
}
/*********************************************************************
 * Function: void LED_Enable(LED led);
 *
 * Overview: Configures the LED for use by the other LED API
 *
 * PreCondition: none
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silk-screen on the board (as the demo code may
 *        be ported to other boards).
 *
 * Output: none
 *
 ********************************************************************/
void LED_Enable ( LED led )
{
    switch (led)
    {
        case LED_LED3_RED:
            LED_LED3_RED_TRIS = OUTPUT ;
            break ;

        case LED_LED3_GREEN:
            LED_LED3_GREEN_TRIS = OUTPUT ;
            break ;

        case LED_LED3_BLUE:
            LED_LED3_BLUE_TRIS = OUTPUT ;
            break ;

        case LED_LED1:
            LED_LED1_TRIS = OUTPUT ;
            break ;

        case LED_LED2:
            LED_LED2_TRIS = OUTPUT ;
            break ;

        case LED_NONE:
            break ;
    }
}

