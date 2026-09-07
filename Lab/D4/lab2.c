#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "intrupt.h"

int main(void)
{
	
	DIO_voidSetPortDirection(DPORTC,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
	
	DIO_voidSetPinValue(DPORTD,PIN2,HIGH);

	 initExternalInterupts();

    while (1) 
    {
		for (u8 i=0;i<8;i++)
		{
			DIO_voidSetPinValue(DPORTC,PIN0+i,HIGH);
			_delay_ms(250);
			DIO_voidSetPinValue(DPORTC,PIN0+i,LOW);
			_delay_ms(250);
		}
    }
}

ISR(INT0_vect){
	DIO_voidSetPortValue(DPORTC,LOW);
	for (u8 i=0;i<8;i++){
				_delay_ms(250);
				DIO_voidSetPinValue(DPORTC,PIN0+i,HIGH);
				_delay_ms(250);
			}
			DIO_voidSetPortValue(DPORTC,LOW);
}
