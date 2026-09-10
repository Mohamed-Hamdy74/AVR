

#include <avr/io.h>
#include <avr/delay.h>

#include "SPI.h"

int main(void)
{
	u8 m,r;
	SPI_init        (Slave);
	
DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
while (1)
{
	
	r=SPI_ReciveData(m);
	if (r==0)
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

