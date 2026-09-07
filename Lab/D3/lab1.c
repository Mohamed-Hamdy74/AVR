
#include <avr/io.h>
#include "Dio.h"
#include <avr/delay.h>

int main(void)
{
	DIO_voidSetPinDirection (DPORTC,PIN0,OUTPUT);

	
	while (1)
	{
		DIO_voidSetPinValue     (DPORTC,PIN0,HIGH);
		_delay_ms(10000);
		DIO_voidSetPinValue     (DPORTC,PIN0,LOW);
		_delay_ms(5000);

	}
}

