
#include <avr/io.h>
#include "Dio.h"
#include <avr/delay.h>

int main(void)
{
	DIO_voidSetPortDirection (DPORTC,OUTPUT);
	DIO_voidSetPinDirection  (DPORTA,PIN0,INPUT);
	
	DIO_voidSetPinValue     (DPORTA,PIN0,HIGH);
	while (1)
	{
		if(DIO_u8GetPinValue(DPORTA,PIN0)==0){
			DIO_voidSetPinValue     (DPORTC,PIN0,LOW);
			DIO_voidSetPinValue     (DPORTC,PIN1,LOW);
			DIO_voidSetPinValue     (DPORTC,PIN2,HIGH);
			DIO_voidSetPinValue     (DPORTC,PIN3,HIGH);

		}
		else{
			DIO_voidSetPinValue     (DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue     (DPORTC,PIN1,HIGH);
			DIO_voidSetPinValue     (DPORTC,PIN2,LOW);
			DIO_voidSetPinValue     (DPORTC,PIN3,LOW);
		}

	}
}

