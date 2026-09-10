
#include <avr/io.h>
#include <avr/delay.h>
#include "servo_motor.h"


int main(void)
{
    DIO_voidSetPinDirection(DPORTD,PIN5,OUTPUT);
	ServoMotor_Init();
    while (1)
    {
		ServoMotor_OCA1_movement(0);
		_delay_ms(2000);
		ServoMotor_OCA1_movement(1);
		_delay_ms(2000);
    }
}

