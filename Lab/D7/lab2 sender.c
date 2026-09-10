

#include <avr/io.h>
#include <avr/delay.h>

#include "SPI.h"

int main(void)
{
	u8 m=0,r;
	   SPI_init        (Master);
	   

    while (1) 
    { 
		r=SPI_ReciveData(m);
		_delay_ms(200);
		TOG_BIT(m,0);
		
    }
}

