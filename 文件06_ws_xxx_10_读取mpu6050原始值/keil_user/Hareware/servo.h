#ifndef _SERVO_H
#define _SERVO_H
#include "common_inc.h"

extern float servo_angle;

typedef struct SPWM
{
	//通道
	u8 channel;
	
	//占空比
	float duty;
	
	//角度
	float angle;
}SPWM;

extern SPWM spwm0;

void Struct_SPWM_init(SPWM *spwm,u8 channel);

void set_SPWM0_duty(SPWM *spwm,float duty);

void spwm_init(void);

void set_Servo_angle(SPWM *spwm,float angle);

float gate_Servo_angle(SPWM *spwm);





#endif