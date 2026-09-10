
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 1000000
#include "URT.h"


int main(void)
{
     UART_Init();
	 u8 m=0;
    while (1) 
    {

		
		UART_SendChar(m);
		TOG_BIT(m,0);
		_delay_ms(200);
    }
}

