#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/delay.h>

#include "std_types.h"
#include "Dio.h"
#include "LCD.h"

int main(void)
{
	LCD_init();
	LCD_SendString("Mohamed Hamdy");
	while (1)
	{
	}

}