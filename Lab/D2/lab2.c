#include <avr/io.h>
#include <util/delay.h>

#include "keypad.h"
#include "Dio.h"
#include "sev_seg.h"

int main(void)
{
	keypad_init(DPORTC);

	DIO_voidSetPortDirection(DPORTD, OUTPUT);

	u8 num;

	while (1)
	{
		num = keypad_get(DPORTC);
			SEV_SEG_DisplayNumber(DPORTD,num-'0' ,CATODE);
	}
}