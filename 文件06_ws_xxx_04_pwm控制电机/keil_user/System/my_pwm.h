#ifndef _MY_PWM_H
#define _MY_PWM_H
#include "common_inc.h"

#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3

#define LEFT 1  //左
#define RIGHT 0 //右

typedef struct PWM
{
	//通道
	u8 IN1_channel;
	u8 IN2_channel;
	
	//占空比
	float duty;
}PWM;

extern PWM pwm0_left,pwm0_right;

void Struct_PWM_init(PWM *pwm,u8 IN1_channel,u8 IN2_channel);

extern float pwm_pulse;


void pwm_init(void);

void set_PWM0_duty(float duty,u8 channel);

float abs_float(float num);

void set_Wheels(PWM *pwm, float duty);



#endif