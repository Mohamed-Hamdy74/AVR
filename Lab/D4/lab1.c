#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "intrupt.h"
int main(void)
{
   
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(DPORTD,PIN3,INPUT);
	
	DIO_voidSetPinValue(DPORTD,PIN2,HIGH);
	DIO_voidSetPinValue(DPORTD,PIN3,HIGH);

	 initExternalInterupts();
	
	 
    while (1) 
    {
		
    }
}
ISR(INT0_vect){
	TOG_BIT(PORTC,PIN0);
}
ISR(INT1_vect){
	TOG_BIT(PORTC,PIN1);
}



