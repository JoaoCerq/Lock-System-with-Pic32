#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "st7920.h"
#include "timer1.h"

#define DEBUG_LED      LATEbits.LATE0

// 1 = diga o que quer fazer (entrar na sala ou cadastrar novo user)
// 2 = insira login (para entrar na sala)
// 3 = insira senha (para entrar na sala)
// 4 = insira login (para cadastrar usu�rio)
// 5 = insira senha (para cadastrar usu�rio)
// 6 = insira se usu�rio para criar � comum ou admin
// 7 = insira login (do usu�rio a cadastrar)
// 8 = insira senha (do usu�rio a cadastrar)
unsigned int global_state = 3;

int main() {
    TRISEbits.TRISE0 = 0x00;
    DEBUG_LED = 1;
    
    timer1_init();
    LCD_init();
    LCD_clear();
    LCD_update_state(global_state);
    LCD_write_input("1234");
    LCD_write_output("sucesso!");
    
    while (1) {
    }
   
    return 1;
}
