#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_
#include"Dio.h"

#define CLOCKWISE     0
#define ANTICLOCKWISE 1

 
void    SM_move_full_step (u8 portid, u8 movement);
void    SM_move_half_step (u8 portid, u8 movement);

#endif