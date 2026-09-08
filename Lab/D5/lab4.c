#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "ADC.h"

#define F_CPU 16000000UL

int main(void)
{
	ADC_Init();
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	while (1)
	{

		ADC_Read(PIN0);
		if (ADC_Read(PIN0)<500)
		{
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		}
		else{
			DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		}
		
	}
}