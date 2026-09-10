
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "URT.h"
#define F_CPU 1000000

int main(void)
{
	UART_Init();
	u8 z;
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	while (1)
	{
		
		z=UART_GetChar();
		if (z==0)
		{
			DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		}
		else{
			DIO_voidSetPinValue(DPORTC,PIN0,LOW);
			DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		}
		
		
		
	}
}

