#ifndef LCD_H_
#define LCD_H_

#include"Dio.h"

#define LCD_F_SET 0x38 
#define LCD_F_ON  0x0c 
#define LCD_CLR   0x01 

void LCD_init();
 
//char
void LCD_sendChar(u8 Data);
 
//send command
void LCD_SendCommand(u8 command);
 
//Send String
void LCD_SendString (u8 *str);

LCD_WriteNumber(s32 number);
#endif