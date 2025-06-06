/**************************************************************
 * File:    keyboard.h
 * Author:  João Pedro Cerqueira
 * Date:    2025-06-06
 * Brief:   Implementation of matrix keyboard reading with  
 *          Change Notification (CN) interrupts for PIC32.
 **************************************************************/

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h> 

void Keyboard_Configs(void);
int Enable_keyboard(void);
void Keyboard_actions(const char* key);
bool Search_password(int input_password);
const char* Key(unsigned int row, unsigned int column);
int Char_to_int(const char* input_char);
bool Search_password(int input_password);

#endif // KEYBOARD_H
