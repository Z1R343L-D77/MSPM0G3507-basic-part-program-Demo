#ifndef _ENCODER_H
#define _ENCODER_H

#include "common_inc.h"

typedef struct
{
	int16_t left_motor_cnt,right_motor_cnt;//单个采样周期内的脉冲数量
	int8_t left_motor_dir,right_motor_dir; //运动方向
	float left_motor_speed_rpm,right_motor_speed_rpm;//转速单位转每分钟
	float left_motor_gyro_rps,right_motor_gyro_rps;//转速单位rad/s
	float left_motor_speed_cmps,right_motor_speed_cmps;//转速c单位为cm/s
	float left_motor_period_ms,right_motor_period_ms;
	
	int32_t left_motor_total_cnt,right_motor_total_cnt;
	int32_t left_motor_period_cnt,right_motor_period_cnt;
	uint8_t left_motor_cnt_clear,right_motor_cnt_clear;
	
}encoder;
extern encoder NEncoder;

typedef struct
{
	int8_t left_encoder_dir_config,right_encoder_dir_config;//编码器方向配置
	int8_t left_motion_dir_config	,right_motion_dir_config; //电机运动方向配置
	float wheel_radius_cm;				//轮胎半径,单位为cm
	uint16_t pulse_num_per_circle;//轮胎转动一圈累计的脉冲数量
	uint16_t servo_median_value1,servo_median_value2;
}motor_config;

void encoder_init(void);

#endif 
