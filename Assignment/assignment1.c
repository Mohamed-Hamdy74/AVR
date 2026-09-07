#include <avr/io.h>
#include <util/delay.h>

#include "keypad.h"
#include "Dio.h"
#include "LCD.h"
#include "calc.h"

int main(void)
{	
	calc_init(DPORTA);
	
	while (1)
	{
		calc_start();
    }
}