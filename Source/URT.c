#include "URT.h"

void UART_Init(void)
{
    SET_BIT (UCSRB, 4);
    //Receiver Enable
    
    SET_BIT (UCSRB, 3);
    //Transmitter Enable
   
    CLR_BIT (UCSRC,6);
    //Asynchronous mode
   
    SET_BIT (UCSRC,0);
    SET_BIT (UCSRC,1);
    //data of 8bits
    
    CLR_BIT (UCSRC,3);
    //1bit to stop
    
    CLR_BIT (UCSRC,4);
    CLR_BIT (UCSRC,5);
    //no patity
    
    UBRRL=6;
    UBRRH=0;
}

void UART_SendChar(u8 data)
{

    while(GET_BIT(UCSRA,5)==0)  // no data in reg
    {

    }
    UDR=data;
}

u8 UART_GetChar(void)
{
   
    while(GET_BIT(UCSRA,7)==0)  //no data receved
    {

    }
    return UDR;
}

