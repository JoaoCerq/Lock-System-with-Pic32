#include <xc.h>
#include <sys/attribs.h>
#include "timer1.h"
#pragma config FWDTEN = OFF 

void Keyboard_Configs(void);
const char* Key(unsigned int row, unsigned int column);

volatile unsigned int oldG, newG = 0; // used in CN interruptions!!!! We need to mantain the snapshot register up-to-date

// colunas - > inputs;
// linhas -> outputs; vamos mud�-las e pegar o resultado a partir das colunas
int main(void){
    INTCONSET = _INTCON_MVEC_MASK;
    __builtin_enable_interrupts();
    Keyboard_Configs();
    while(1){    
    }
}

void Keyboard_Configs(void){
    TRISACLR = 0x1F; // bitmask to define RA0 to RA4 as OUTPUTS (FIVE keyboard rows) 1111_1111_1111_1111_1111_1111_1110_0000
    TRISGSET = 0x3C0; // bitmask to define RG6, 7, 8, 9 as INPUTS (FOUR keyboard columns) 0000_0000_0000_0000_0000_0011_1100_0000
    LATACLR = 0x1F; // first, lets set all rows to 0. 1111_1111_1111_1111_1111_1111_1110_0000
    CNCONSET = _CNCON_ON_MASK; // turns CN on
    oldG = PORTF;
    CNENSET = 0xF00; //Enable CN function on "1" pins  0000_0000_0000_0000_0000_1111_0000_0000
    CNPUESET = 0xF00; //enable pull-up on the respective pins 
    IPC6bits.CNIP = 3; // set priority and sub-priority
    IPC6bits.CNIS = 0;
    IFS1CLR = _IFS1_CNIF_MASK; // Clears CN interruption flag
    IEC1SET = _IEC1_CNIE_MASK; //Enable CN interruption 
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL3SOFT) KeyBoardInterrupt(void){
    IEC1CLR = _IEC1_CNIE_MASK; // Disables new interruptions
    delay_ms(100);
    newG = PORTG; // Thats important, so we can update the snapshot
    LATASET = 0x1F; // Lets reset them to 1, therefore we can scan 
    unsigned int scan_position = 0x00000001;
    unsigned int detected_row = 0;
    unsigned int detected_column = 0;
    unsigned int temp = 00;
    for (unsigned int row = 0; row < 5; row++){ // we need to test all five possibiities
        LATA = (LATA & ~0x1F) | (0x1F & ~scan_position); // scan all bits
        // __delay_ms(1); // TODO: DEBOUNCER
        temp = (~newG & 0x000003C0) >> 6; //bitmask 0000_0000_0000_0000_0000_0011_1100_0000. Remember: Those registers are pull-up!
        if (temp){ 
            detected_column = 0;
            while (temp >>= 1){
                detected_column ++;
            }
            detected_row = row;
            const char* key = Key(detected_row, detected_column);
            break;
        }
        scan_position <<= 1;
    }
    IFS1CLR = _IFS1_CNIF_MASK; //Clears the flag
    IEC1SET = _IEC1_CNIE_MASK; //enables the interruption again
}

const char* Key(unsigned int row, unsigned int column){
    const char* KeyMatrix[5][4] = {
        {"F1", "F2", "#", "*"},
        {"1", "2", "3", "Up"},
        {"4", "5", "6", "Down"},
        {"7", "8", "9", "Esc"},
        {"Left", "0", "Right", "Ent"},
    };
    return KeyMatrix[row][column];
}