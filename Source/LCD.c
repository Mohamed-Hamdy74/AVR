
#include"LCD.h"
#include"Dio.h"
#include"std_types.h"
void LCD_init(){
_delay_ms(10);   
 LCD_SendCommand(LCD_F_SET);
_delay_ms(2);
 LCD_SendCommand(LCD_F_ON);
_delay_ms(2);
 LCD_SendCommand(LCD_CLR);
_delay_ms(3);
}


void LCD_sendChar(u8 Data){
    DIO_voidSetPortDirection (DPORTD,OUTPUT);
    DIO_voidSetPortDirection (DPORTC,OUTPUT);
    DIO_voidSetPinValue	     (DPORTD,PIN0,HIGH);
    DIO_voidSetPinValue	     (DPORTD,PIN1,LOW);
    DIO_voidSetPinValue	     (DPORTD,PIN2,HIGH);
    DIO_voidSetPortValue     (DPORTC,Data);
    DIO_voidSetPinValue	     (DPORTD,PIN2,LOW);
    _delay_ms(6);     
    DIO_voidSetPinValue	     (DPORTD,PIN2,HIGH);
}
 

void LCD_SendCommand(u8 command){
    DIO_voidSetPortDirection (DPORTD,OUTPUT);
    DIO_voidSetPortDirection (DPORTC,OUTPUT);
    DIO_voidSetPinValue	     (DPORTD,PIN0,LOW);
    DIO_voidSetPinValue	     (DPORTD,PIN1,LOW);
    DIO_voidSetPortValue     (DPORTC,command);
    DIO_voidSetPinValue	     (DPORTD,PIN2,HIGH);
    _delay_ms(2);    
    DIO_voidSetPinValue	     (DPORTD,PIN2,LOW);
    
}

void LCD_SendString (u8 *str){
    while(*str !='\0'){
        LCD_sendChar(*str);
        str++;
    }   
}

void LCD_WriteNumber(s32 number)
{
    u8 arr[10], i = 0;
    if(number == 0){
        LCD_sendChar('0');
        return;
    }

    if(number < 0){
        LCD_sendChar('-');
        number = -number;
    }

    while(number > 0){
        arr[i] = number % 10;
        number = number / 10;
        i++;
    }

    while(i > 0){
        i--;
        LCD_sendChar(arr[i] + '0');
    }
}