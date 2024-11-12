/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
? [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 aliases
#define IO_RA3_TRIS                 TRISAbits.TRISA3
#define IO_RA3_LAT                  LATAbits.LATA3
#define IO_RA3_PORT                 PORTAbits.RA3
#define IO_RA3_WPU                  WPUAbits.WPUA3
#define IO_RA3_OD                   ODCONAbits.ODCA3
#define IO_RA3_ANS                  ANSELAbits.ANSELA3
#define IO_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IO_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IO_RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IO_RA3_GetValue()           PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IO_RA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define IO_RA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define IO_RA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define IO_RA3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RB1 aliases
#define DIP_BIT0_TRIS                 TRISBbits.TRISB1
#define DIP_BIT0_LAT                  LATBbits.LATB1
#define DIP_BIT0_PORT                 PORTBbits.RB1
#define DIP_BIT0_WPU                  WPUBbits.WPUB1
#define DIP_BIT0_OD                   ODCONBbits.ODCB1
#define DIP_BIT0_ANS                  ANSELBbits.ANSELB1
#define DIP_BIT0_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DIP_BIT0_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DIP_BIT0_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DIP_BIT0_GetValue()           PORTBbits.RB1
#define DIP_BIT0_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DIP_BIT0_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DIP_BIT0_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define DIP_BIT0_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define DIP_BIT0_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define DIP_BIT0_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define DIP_BIT0_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define DIP_BIT0_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define DIP_BIT1_TRIS                 TRISBbits.TRISB2
#define DIP_BIT1_LAT                  LATBbits.LATB2
#define DIP_BIT1_PORT                 PORTBbits.RB2
#define DIP_BIT1_WPU                  WPUBbits.WPUB2
#define DIP_BIT1_OD                   ODCONBbits.ODCB2
#define DIP_BIT1_ANS                  ANSELBbits.ANSELB2
#define DIP_BIT1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DIP_BIT1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DIP_BIT1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DIP_BIT1_GetValue()           PORTBbits.RB2
#define DIP_BIT1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DIP_BIT1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DIP_BIT1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define DIP_BIT1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define DIP_BIT1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define DIP_BIT1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define DIP_BIT1_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define DIP_BIT1_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define DIP_BIT2_TRIS                 TRISBbits.TRISB3
#define DIP_BIT2_LAT                  LATBbits.LATB3
#define DIP_BIT2_PORT                 PORTBbits.RB3
#define DIP_BIT2_WPU                  WPUBbits.WPUB3
#define DIP_BIT2_OD                   ODCONBbits.ODCB3
#define DIP_BIT2_ANS                  ANSELBbits.ANSELB3
#define DIP_BIT2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DIP_BIT2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DIP_BIT2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DIP_BIT2_GetValue()           PORTBbits.RB3
#define DIP_BIT2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DIP_BIT2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DIP_BIT2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DIP_BIT2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DIP_BIT2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DIP_BIT2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DIP_BIT2_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DIP_BIT2_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define SPI_MISO_TRIS                 TRISCbits.TRISC3
#define SPI_MISO_LAT                  LATCbits.LATC3
#define SPI_MISO_PORT                 PORTCbits.RC3
#define SPI_MISO_WPU                  WPUCbits.WPUC3
#define SPI_MISO_OD                   ODCONCbits.ODCC3
#define SPI_MISO_ANS                  ANSELCbits.ANSELC3
#define SPI_MISO_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SPI_MISO_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SPI_MISO_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SPI_MISO_GetValue()           PORTCbits.RC3
#define SPI_MISO_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SPI_MISO_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SPI_MISO_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SPI_MISO_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SPI_MISO_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SPI_MISO_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SPI_MISO_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SPI_MISO_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define SPI_MOSI_TRIS                 TRISCbits.TRISC4
#define SPI_MOSI_LAT                  LATCbits.LATC4
#define SPI_MOSI_PORT                 PORTCbits.RC4
#define SPI_MOSI_WPU                  WPUCbits.WPUC4
#define SPI_MOSI_OD                   ODCONCbits.ODCC4
#define SPI_MOSI_ANS                  ANSELCbits.ANSELC4
#define SPI_MOSI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SPI_MOSI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SPI_MOSI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SPI_MOSI_GetValue()           PORTCbits.RC4
#define SPI_MOSI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SPI_MOSI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SPI_MOSI_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SPI_MOSI_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SPI_MOSI_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SPI_MOSI_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SPI_MOSI_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SPI_MOSI_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define SPI_SCLK_TRIS                 TRISCbits.TRISC5
#define SPI_SCLK_LAT                  LATCbits.LATC5
#define SPI_SCLK_PORT                 PORTCbits.RC5
#define SPI_SCLK_WPU                  WPUCbits.WPUC5
#define SPI_SCLK_OD                   ODCONCbits.ODCC5
#define SPI_SCLK_ANS                  ANSELCbits.ANSELC5
#define SPI_SCLK_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SPI_SCLK_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SPI_SCLK_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SPI_SCLK_GetValue()           PORTCbits.RC5
#define SPI_SCLK_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SPI_SCLK_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SPI_SCLK_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SPI_SCLK_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SPI_SCLK_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SPI_SCLK_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SPI_SCLK_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SPI_SCLK_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RD3 aliases
#define SPI_CS_L_TRIS                 TRISDbits.TRISD3
#define SPI_CS_L_LAT                  LATDbits.LATD3
#define SPI_CS_L_PORT                 PORTDbits.RD3
#define SPI_CS_L_WPU                  WPUDbits.WPUD3
#define SPI_CS_L_OD                   ODCONDbits.ODCD3
#define SPI_CS_L_ANS                  ANSELDbits.ANSELD3
#define SPI_CS_L_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SPI_CS_L_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SPI_CS_L_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SPI_CS_L_GetValue()           PORTDbits.RD3
#define SPI_CS_L_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SPI_CS_L_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SPI_CS_L_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define SPI_CS_L_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define SPI_CS_L_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define SPI_CS_L_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define SPI_CS_L_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define SPI_CS_L_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set RD4 aliases
#define FAN_PWR_EN_L_TRIS                 TRISDbits.TRISD4
#define FAN_PWR_EN_L_LAT                  LATDbits.LATD4
#define FAN_PWR_EN_L_PORT                 PORTDbits.RD4
#define FAN_PWR_EN_L_WPU                  WPUDbits.WPUD4
#define FAN_PWR_EN_L_OD                   ODCONDbits.ODCD4
#define FAN_PWR_EN_L_ANS                  ANSELDbits.ANSELD4
#define FAN_PWR_EN_L_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define FAN_PWR_EN_L_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define FAN_PWR_EN_L_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define FAN_PWR_EN_L_GetValue()           PORTDbits.RD4
#define FAN_PWR_EN_L_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define FAN_PWR_EN_L_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define FAN_PWR_EN_L_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define FAN_PWR_EN_L_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define FAN_PWR_EN_L_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define FAN_PWR_EN_L_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define FAN_PWR_EN_L_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define FAN_PWR_EN_L_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set RD5 aliases
#define RELAY_EN_TRIS                 TRISDbits.TRISD5
#define RELAY_EN_LAT                  LATDbits.LATD5
#define RELAY_EN_PORT                 PORTDbits.RD5
#define RELAY_EN_WPU                  WPUDbits.WPUD5
#define RELAY_EN_OD                   ODCONDbits.ODCD5
#define RELAY_EN_ANS                  ANSELDbits.ANSELD5
#define RELAY_EN_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define RELAY_EN_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define RELAY_EN_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RELAY_EN_GetValue()           PORTDbits.RD5
#define RELAY_EN_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define RELAY_EN_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define RELAY_EN_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define RELAY_EN_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define RELAY_EN_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define RELAY_EN_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define RELAY_EN_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define RELAY_EN_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set RD6 aliases
#define LED_GREEN_L_TRIS                 TRISDbits.TRISD6
#define LED_GREEN_L_LAT                  LATDbits.LATD6
#define LED_GREEN_L_PORT                 PORTDbits.RD6
#define LED_GREEN_L_WPU                  WPUDbits.WPUD6
#define LED_GREEN_L_OD                   ODCONDbits.ODCD6
#define LED_GREEN_L_ANS                  ANSELDbits.ANSELD6
#define LED_GREEN_L_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LED_GREEN_L_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define LED_GREEN_L_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LED_GREEN_L_GetValue()           PORTDbits.RD6
#define LED_GREEN_L_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LED_GREEN_L_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define LED_GREEN_L_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define LED_GREEN_L_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define LED_GREEN_L_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define LED_GREEN_L_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define LED_GREEN_L_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define LED_GREEN_L_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RD7 aliases
#define LED_BLUE_L_TRIS                 TRISDbits.TRISD7
#define LED_BLUE_L_LAT                  LATDbits.LATD7
#define LED_BLUE_L_PORT                 PORTDbits.RD7
#define LED_BLUE_L_WPU                  WPUDbits.WPUD7
#define LED_BLUE_L_OD                   ODCONDbits.ODCD7
#define LED_BLUE_L_ANS                  ANSELDbits.ANSELD7
#define LED_BLUE_L_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define LED_BLUE_L_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define LED_BLUE_L_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define LED_BLUE_L_GetValue()           PORTDbits.RD7
#define LED_BLUE_L_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define LED_BLUE_L_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define LED_BLUE_L_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define LED_BLUE_L_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define LED_BLUE_L_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define LED_BLUE_L_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define LED_BLUE_L_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define LED_BLUE_L_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set RF1 aliases
#define BRKR_CLOSED_L_TRIS                 TRISFbits.TRISF1
#define BRKR_CLOSED_L_LAT                  LATFbits.LATF1
#define BRKR_CLOSED_L_PORT                 PORTFbits.RF1
#define BRKR_CLOSED_L_WPU                  WPUFbits.WPUF1
#define BRKR_CLOSED_L_OD                   ODCONFbits.ODCF1
#define BRKR_CLOSED_L_ANS                  ANSELFbits.ANSELF1
#define BRKR_CLOSED_L_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define BRKR_CLOSED_L_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define BRKR_CLOSED_L_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define BRKR_CLOSED_L_GetValue()           PORTFbits.RF1
#define BRKR_CLOSED_L_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define BRKR_CLOSED_L_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define BRKR_CLOSED_L_SetPullup()          do { WPUFbits.WPUF1 = 1; } while(0)
#define BRKR_CLOSED_L_ResetPullup()        do { WPUFbits.WPUF1 = 0; } while(0)
#define BRKR_CLOSED_L_SetPushPull()        do { ODCONFbits.ODCF1 = 0; } while(0)
#define BRKR_CLOSED_L_SetOpenDrain()       do { ODCONFbits.ODCF1 = 1; } while(0)
#define BRKR_CLOSED_L_SetAnalogMode()      do { ANSELFbits.ANSELF1 = 1; } while(0)
#define BRKR_CLOSED_L_SetDigitalMode()     do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set RF2 aliases
#define IO_RF2_TRIS                 TRISFbits.TRISF2
#define IO_RF2_LAT                  LATFbits.LATF2
#define IO_RF2_PORT                 PORTFbits.RF2
#define IO_RF2_WPU                  WPUFbits.WPUF2
#define IO_RF2_OD                   ODCONFbits.ODCF2
#define IO_RF2_ANS                  ANSELFbits.ANSELF2
#define IO_RF2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define IO_RF2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define IO_RF2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define IO_RF2_GetValue()           PORTFbits.RF2
#define IO_RF2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define IO_RF2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define IO_RF2_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define IO_RF2_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define IO_RF2_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define IO_RF2_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define IO_RF2_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define IO_RF2_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set RF3 aliases
#define IO_RF3_TRIS                 TRISFbits.TRISF3
#define IO_RF3_LAT                  LATFbits.LATF3
#define IO_RF3_PORT                 PORTFbits.RF3
#define IO_RF3_WPU                  WPUFbits.WPUF3
#define IO_RF3_OD                   ODCONFbits.ODCF3
#define IO_RF3_ANS                  ANSELFbits.ANSELF3
#define IO_RF3_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define IO_RF3_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define IO_RF3_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define IO_RF3_GetValue()           PORTFbits.RF3
#define IO_RF3_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define IO_RF3_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define IO_RF3_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define IO_RF3_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define IO_RF3_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define IO_RF3_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define IO_RF3_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define IO_RF3_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set RF4 aliases
#define DIP_BIT3_TRIS                 TRISFbits.TRISF4
#define DIP_BIT3_LAT                  LATFbits.LATF4
#define DIP_BIT3_PORT                 PORTFbits.RF4
#define DIP_BIT3_WPU                  WPUFbits.WPUF4
#define DIP_BIT3_OD                   ODCONFbits.ODCF4
#define DIP_BIT3_ANS                  ANSELFbits.ANSELF4
#define DIP_BIT3_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define DIP_BIT3_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define DIP_BIT3_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define DIP_BIT3_GetValue()           PORTFbits.RF4
#define DIP_BIT3_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define DIP_BIT3_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define DIP_BIT3_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define DIP_BIT3_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define DIP_BIT3_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define DIP_BIT3_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define DIP_BIT3_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define DIP_BIT3_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set RF5 aliases
#define IO_RF5_TRIS                 TRISFbits.TRISF5
#define IO_RF5_LAT                  LATFbits.LATF5
#define IO_RF5_PORT                 PORTFbits.RF5
#define IO_RF5_WPU                  WPUFbits.WPUF5
#define IO_RF5_OD                   ODCONFbits.ODCF5
#define IO_RF5_ANS                  ANSELFbits.ANSELF5
#define IO_RF5_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define IO_RF5_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define IO_RF5_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define IO_RF5_GetValue()           PORTFbits.RF5
#define IO_RF5_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define IO_RF5_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define IO_RF5_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define IO_RF5_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define IO_RF5_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define IO_RF5_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define IO_RF5_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define IO_RF5_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set RF7 aliases
#define LED_RED_L_TRIS                 TRISFbits.TRISF7
#define LED_RED_L_LAT                  LATFbits.LATF7
#define LED_RED_L_PORT                 PORTFbits.RF7
#define LED_RED_L_WPU                  WPUFbits.WPUF7
#define LED_RED_L_OD                   ODCONFbits.ODCF7
#define LED_RED_L_ANS                  ANSELFbits.ANSELF7
#define LED_RED_L_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define LED_RED_L_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define LED_RED_L_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define LED_RED_L_GetValue()           PORTFbits.RF7
#define LED_RED_L_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define LED_RED_L_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define LED_RED_L_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define LED_RED_L_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define LED_RED_L_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define LED_RED_L_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define LED_RED_L_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define LED_RED_L_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/