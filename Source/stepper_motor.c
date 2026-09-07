#include"Dio.h"
#include"stepper_motor.h"

    u8 a[4][4]={
               {0,0,0,1}
              ,{0,0,1,0}
              ,{0,1,0,0}
              ,{1,0,0,0}
    };

    u8 Aa[4][4]={
               {1,0,0,0}
              ,{0,1,0,0}
              ,{0,0,1,0}
              ,{0,0,0,1}
    };


    u8 af[8][4]={
               {1,0,0,1}
              ,{0,0,0,1}
              ,{0,0,1,1}
              ,{0,0,1,0}
              ,{0,1,1,0}
              ,{0,1,0,0}
              ,{1,1,0,0}
              ,{1,0,0,0}
    };
        u8 Aaf[8][4]={
               {1,0,0,0}
              ,{1,1,0,0}
              ,{0,1,0,0}
              ,{0,1,1,0}
              ,{0,0,1,0}
              ,{0,0,1,1}
              ,{0,0,0,1}
              ,{1,0,0,1}
    };           


void    SM_move_full_step (u8 portid, u8 movement)
{
    DIO_voidSetPinDirection		( portid, PIN0, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN2, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN1, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN3, OUTPUT);

    if(movement==CLOCKWISE){
        for(u8 i=0;i<4;i++){
        for(u8 j=0;j<4;j++){
            DIO_voidSetPinValue(portid,j,a[i][j]);
         }
        _delay_ms(100);
        }  
    }
    else if(movement==ANTICLOCKWISE){
        for(u8 i=0;i<4;i++){
        for(u8 j=0;j<4;j++){
            DIO_voidSetPinValue(portid,j,Aa[i][j]);
        }
        _delay_ms(100);
    }
    }
}



void    SM_move_half_stepp (u8 portid, u8 movement)
{
    DIO_voidSetPinDirection		( portid, PIN0, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN1, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN2, OUTPUT);
    DIO_voidSetPinDirection		( portid, PIN3, OUTPUT);
    
     if(movement==CLOCKWISE){
        for(u8 i=0;i<8;i++){
        for(u8 j=0;j<4;j++){
            DIO_voidSetPinValue(portid,j,af[i][j]);
         }
        _delay_ms(100);
       }
    }
    else if(movement==ANTICLOCKWISE){
        for(u8 i=0;i<8;i++){
        for(u8 j=0;j<4;j++){
            DIO_voidSetPinValue(portid,j,Aaf[i][j]);
        }
        _delay_ms(100);
      }
    }
}
