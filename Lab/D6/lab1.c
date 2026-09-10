

#include <avr/io.h>
#include "avr/interrupt.h"
#include "Dio.h"
#include "intrupt.h"
#include "timer_0.h"
u8 m=0,c=0;
int main(void)
{
	initExternalInterupts();
    TCNT0=128;
	timer0_interrupt (1024);
	DIO_voidSetPinDirection(DPORTA,PIN0,OUTPUT);
    while (1) 
    {
		if (m==0)
		{
			DIO_voidSetPinValue(DPORTA,PIN0,HIGH);
		}
		
		else{
			DIO_voidSetPinValue(DPORTA,PIN0,LOW);
		}
    }
}
ISR(TIMER0_OVF_vect){
	c++;
	if ((c%30)==0)
	{
		TOG_BIT(m,0);
	}
}
