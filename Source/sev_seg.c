#include "sev_seg.h"

u8 sevseg[10] ={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SEV_SEG_DisplayNumber(u8 portid, u8 number, u8 type)
{
	if(number <= 9){
		if(type == CATODE){
			DIO_voidSetPortValue(portid,sevseg[number]);
		}
		else if(type == ANODE){
			DIO_voidSetPortValue(portid,~sevseg[number]);
		}
	}
}