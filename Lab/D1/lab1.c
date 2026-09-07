
#include <avr/io.h>
#include "Dio.h"
#include "std_types.h"

int main(void)
{
    DIO_voidSetPinDirection		(DPORTA , PIN0, INPUT);
	DIO_voidSetPinDirection		(DPORTA , PIN1, OUTPUT);
	DIO_voidSetPinValue         (PORTA,PIN0,HIGH);
	
    while (1) 
    {
		if(DIO_u8GetPinValue (DPORTA,PIN0)==0){
			DIO_voidSetPinValue         (DPORTA,PIN1,HIGH);
		}
		else{
			DIO_voidSetPinValue         (DPORTA,PIN1,LOW);
		}
			
    }
}

