

#include <avr/io.h>
#include <avr/interrupt.h>

#include "ADC.h"
#include "Dio.h"
#include "intrupt.h"


u8 m=0,c=0;
int main(void)
{
	initExternalInterupts();
    ADC_Init();
	DIO_voidSetPortDirection(DPORTC,OUTPUT);
	TCT_mode(255-ADC_Read(PIN0)/4);
	timer0_init_1024();
    while (1) 
    {
		OCR0=255-(ADC_Read(PIN0)/4);
		if (m==0)
		{
			DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		}
		else{
			DIO_voidSetPinValue(DPORTC,PIN0,LOW);
			DIO_voidSetPinValue(DPORTC,PIN1,LOW);
			DIO_voidSetPinValue(DPORTC,PIN2,LOW);
		}
		
    }
}
ISR(TIMER0_COMP_vect){
	c++;
	if ((c%30)==0)
	{
		TOG_BIT(m,0);
	}
}

