#include "SPI.h"

void    SPI_init(u8 mode)
{
    switch (mode){
        case Master :
        SET_BIT (SPCR,4);

        DIO_voidSetPinDirection(DPORTB,PIN4,OUTPUT);
        DIO_voidSetPinDirection(DPORTB,PIN5,OUTPUT);
        DIO_voidSetPinDirection(DPORTB,PIN6,INPUT);
        DIO_voidSetPinDirection(DPORTB,PIN7,OUTPUT);
        break;
        
        
        case Slave  : 
        CLR_BIT (SPCR,4);
        
        DIO_voidSetPinDirection(DPORTB,PIN4,INPUT);
        DIO_voidSetPinDirection(DPORTB,PIN5,INPUT);
        DIO_voidSetPinDirection(DPORTB,PIN6,OUTPUT);
        DIO_voidSetPinDirection(DPORTB,PIN7,INPUT);
        
        break;
        
    }
    
    SET_BIT (SPCR,7);  //SPI Interrupt Enable
    SET_BIT (SPCR,6);  //SPI Enable
    
    CLR_BIT (SPCR,5); // the MSB of the data word is transmitted first.
    CLR_BIT (SPCR,2); // use mode 0

    CLR_BIT (SPCR,0);
    CLR_BIT (SPCR,1);
}


u8   SPI_send (u8 data)
{
   SPDR=data;
   while(GET_Bit(SPSR,7)==0)
   {

   }
   return SPDR;
}

 SPI_ReciveData  (u8 data)
 {
    while(GET_Bit(SPSR,7)==0)
   {

   }
   return SPDR
 }