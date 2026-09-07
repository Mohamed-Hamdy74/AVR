
#include <avr/io.h>
#include "Dio.h"
#include "std_types.h"

int main(void)
{
	DIO_voidSetPortDirection	(DPORTA,INPUT);
	DIO_voidSetPinDirection		(DPORTC , PIN0, OUTPUT);
	DIO_voidSetPinDirection		(DPORTC , PIN1, OUTPUT);
	DIO_voidSetPinDirection		(DPORTC , PIN2, OUTPUT);


	DIO_voidSetPinValue         (DPORTA,PIN0,HIGH);
	DIO_voidSetPinValue         (DPORTA,PIN1,HIGH);
	DIO_voidSetPinValue         (DPORTA,PIN2,HIGH);
	DIO_voidSetPinValue         (DPORTA,PIN3,HIGH);
	
	while (1)
	{
		if(DIO_u8GetPinValue (DPORTA,PIN3)==0){
			DIO_voidSetPinValue         (DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue         (DPORTC,PIN1,HIGH);
			DIO_voidSetPinValue         (DPORTC,PIN2,HIGH);
		}
		else{
			if(DIO_u8GetPinValue (DPORTA,PIN0)==0){
				DIO_voidSetPinValue         (DPORTC,PIN0,HIGH);
			}
			else{
				DIO_voidSetPinValue         (DPORTC,PIN0,LOW);
			}
			if(DIO_u8GetPinValue (DPORTA,PIN1)==0){
				DIO_voidSetPinValue         (DPORTC,PIN1,HIGH);
			}
			else{
				DIO_voidSetPinValue         (DPORTC,PIN1,LOW);
			}
			if(DIO_u8GetPinValue (DPORTA,PIN2)==0){
				DIO_voidSetPinValue         (DPORTC,PIN2,HIGH);
			}
			else{
				DIO_voidSetPinValue         (DPORTC,PIN2,LOW);
			}
		}
		
	}
}

