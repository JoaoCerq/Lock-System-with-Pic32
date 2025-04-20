// PIC24FJ256GA110 Configuration Bit Settings

// 'C' source line config statements

// CONFIG3
#pragma config WPFP = WPFP511           // Write Protection Flash Page Segment Boundary (Highest Page (same as page 170))
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable bit (Segmented code protection disabled)
#pragma config WPCFG = WPCFGDIS         // Configuration Word Code Page Protection Select bit (Last page(at the top of program memory) and Flash configuration words are not protected)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select bit (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMOD = NONE           // Primary Oscillator Select (Primary oscillator disabled)
#pragma config I2C2SEL = PRI            // I2C2 Pin Select bit (Use Default SCL2/SDA2 pins for I2C2)
#pragma config IOL1WAY = OFF            // IOLOCK One-Way Set Enable bit (Unlimited Writes To RP Registers)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSCO functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-safe Clock Monitor are disabled)
#pragma config FNOSC = FRCPLL           // Oscillator Select (Fast RC oscillator with Postscaler and PLL module (FRCPLL))
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-speed start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Standard Watchdog Timer is enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config ICS = PGx1               // Comm Channel Select (Emulator functions are shared with PGEC1/PGED1)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = ON              // JTAG Port Enable (JTAG port is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "st7920.h"

#define LED      LATBbits.LATB6   // LED conectado a LATB6
#define BUTTON   PORTBbits.RB5    // Botão conectado a RB5

int main() {
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB5 = 1;
    
     LED = 1;
    
    TRISE = 0x00;
    LATE = 0x00;
    TRISB = 0x00;
    LATB = 0x00;
    LATBbits.LATB15 = 1;
    LATBbits.LATB12 = 1;

    #if LCD_INTERFACE != MODE_SERIAL
        LATBbits.LATB11 = 1;
        unsigned char x, y;
    #endif

    LCD_init();
    LCD_clear();
    LCD_write_string(0x0102, "SalveGalera!");
    #if LCD_INTERFACE != MODE_SERIAL
        for (x = 31 - 3; x <= 112 + 3; x++)
        {
            LCD_write_dot(x, 16 - 3);
            LCD_write_dot(x, 31 + 3);
            //_delay_us(100);
        }
        for (y = 16 - 3; y <= 31 + 3; y++)
        {
            LCD_write_dot(31 - 3, y);
            LCD_write_dot(112 + 3, y);
            //_delay_us(100);
        }
    #endif
    _delay_ms(200);

    while (1) {
        if (BUTTON == 0) {
            LED = 1;
        } else {
            LED = 0;
        }
    }
   
    return 1;
}