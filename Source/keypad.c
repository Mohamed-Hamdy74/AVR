#include"keypad.h"

u8 keypad[4][4]={
    
        {'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'c','0','=','+'}
};

void   keypad_init(u8 portid)
{
 DIO_voidSetPinDirection (portid,PIN0,INPUT);   
 DIO_voidSetPinDirection (portid,PIN1,INPUT);   
 DIO_voidSetPinDirection (portid,PIN2,INPUT);   
 DIO_voidSetPinDirection (portid,PIN3,INPUT);
 DIO_voidSetPinDirection (portid,PIN4,OUTPUT);   
 DIO_voidSetPinDirection (portid,PIN5,OUTPUT);   
 DIO_voidSetPinDirection (portid,PIN6,OUTPUT);   
 DIO_voidSetPinDirection (portid,PIN7,OUTPUT); 
 
 DIO_voidSetPinValue (portid,PIN0,HIGH);
 DIO_voidSetPinValue (portid,PIN1,HIGH);
 DIO_voidSetPinValue (portid,PIN2,HIGH);
 DIO_voidSetPinValue (portid,PIN3,HIGH);
}

u8 keypad_get  (u8 portid)
{
    for(u8 row=0;row<4;row++){
        DIO_voidSetPinValue (portid,PIN4+row,LOW);
        for(u8 col=0;col<4;col++){
            if(DIO_u8GetPinValue(portid,PIN0+col)==0){
                while(DIO_u8GetPinValue(portid,PIN0+col)==0);
                return keypad[row][col];
            }
        }
        DIO_voidSetPinValue (portid,PIN4+row,HIGH);
    }
    return 0xff;    
}