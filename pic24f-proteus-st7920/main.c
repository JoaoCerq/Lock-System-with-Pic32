#include "config.h"
#include "st7920.h"

#define DEBUG_LED      LATEbits.LATE0
#define OUTPUT         0x0000
#define INPUT          0x0302

int main() {
    TRISEbits.TRISE0 = 0x00;
    DEBUG_LED = 1;
    
    timer1_init();
    LCD_init();
    LCD_clear();

    #if LCD_INTERFACE != MODE_SERIAL
        unsigned char x, y;
    #endif
    
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
    delay_ms(200);
    
    LCD_write_string(0x0300, "In:");
    LCD_write_string(OUTPUT, "output");
    LCD_write_string(INPUT, "1234");
    
    while (1) {
    }
   
    return 1;
}
