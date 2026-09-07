 
#include <avr/io.h>
#include <avr/delay.h>
#include "Dio.h"
#include "stepper_motor.h"

int main(void)
{
    
    while (1) 
    {
		
		SM_move_half_stepp(DPORTC,	ANTICLOCKWISE);
		
    }
}

