#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "Dio.h"

#define TCCR1A_REG   (*(volatile u8*)0x4F)
#define TCCR1B_REG   (*(volatile u8*)0x4E)

#define OCR1AH_REG   (*(volatile u8*)0x4B)
#define OCR1AL_REG   (*(volatile u8*)0x4A)

#define ICR1H_REG    (*(volatile u8*)0x47)
#define ICR1L_REG    (*(volatile u8*)0x46)

#define OCR1AH_REG   (*(volatile u8*)0x4B)
#define OCR1AL_REG   (*(volatile u8*)0x4A)

#define OCR1BH_REG   (*(volatile u8*)0x49)
#define OCR1BL_REG   (*(volatile u8*)0x48)

#define CLOCKWISE 0
#define ANTI_CLOCKWISE 1


void    ServoMotor_Init(void);
void    ServoMotor_OCA1_movement(u8 movement_direction) ;
void    ServoMotor_OCB1_movement(u8 movement_direction) ;

#endif