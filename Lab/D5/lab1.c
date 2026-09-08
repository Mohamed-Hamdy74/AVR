#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "ADC.h"
#include "LCD.h"

#define F_CPU 16000000UL

int main(void)
{
	DIO_voidSetPortDirection(DPORTC,OUTPUT);
	ADC_Init();
	u32 av,vm,te;
	
    while (1) 
    {

	av = ADC_Read(0);
		if (av<(1.5*1024)/5)
		{
			DIO_voidSetPinValue(DPORTC,PIN2,LOW);
			DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		}
		else if (av>=(1.5*1024)/5 && av<(3*1024)/5)
		{
			DIO_voidSetPinValue(DPORTC,PIN0,LOW);
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN2,LOW);
			
		}
		else if(av>=(3*1024)/5){
			DIO_voidSetPinValue(DPORTC,PIN0,LOW);
			DIO_voidSetPinValue(DPORTC,PIN1,LOW);
			DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		}
		
    }
}

