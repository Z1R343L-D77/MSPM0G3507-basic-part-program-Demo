#include "servo.h"

// 全局变量servo_angle用于存储伺服电机的角度值
float servo_angle=0;

// 定义PERIOD_COUNT为PWM周期的计数器周期数
// 定义PWM周期的计数器周期数，用于确定PWM的周期
#define PERIOD_COUNT 1000

// 定义了一个SPWM实例spwm0
// 定义一个SPWM实例
SPWM spwm0;

// spwm_init函数用于初始化SPWM，以控制伺服电机
// 初始化SPWM，用于伺服电机的控制
void spwm_init(void)
{
    // 启动PWM计数器
    // 开启PWM计数器
    DL_Timer_startCounter(PWM_SERVO_INST);

    // 初始化SPWM实例0，用于控制伺服电机的前轮
    Struct_SPWM_init(&spwm0,CHANNEL1); // 前轮舵机-CH1
	
		set_Servo_angle(&spwm0,0);
}

// Struct_SPWM_init函数用于初始化SPWM结构体
// @param spwm 指向SPWM结构体的指针
// @param channel SPWM的通道号
// 初始化SPWM结构体
/**
 * @brief 初始化SPWM结构体
 * @param spwm 指向SPWM结构体的指针
 * @param channel SPWM的通道号
 */
void Struct_SPWM_init(SPWM *spwm,u8 channel)
{
    // 设置SPWM的通道
    // 初始化PWM的输入通道
    spwm->channel=channel;
	
    // 初始化SPWM的占空比为0
    // 初始化占空比为0
    spwm->duty=0;
	
		spwm->angle=0;
}

// set_SPWM0_duty函数用于设置SPWM的占空比
// @param spwm 指向SPWM结构体的指针
// @param duty 新的占空比值
// 设置SPWM的占空比
/**
 * @brief 设置SPWM的占空比
 * @param spwm 指向SPWM结构体的指针
 * @param duty 新的占空比值
 */
void set_SPWM0_duty(SPWM *spwm,float duty) 
{
    // 更新SPWM的占空比
    spwm->duty=duty;
    
    // 根据占空比计算比较值
    // 计算比较值，通过占空比乘以周期计数器总数来得到
    u32 CompareValue;
    CompareValue=(float)PERIOD_COUNT/100.0f*spwm->duty;
    
    // 根据通道号设置比较值，以控制PWM的输出
    // 根据通道号设置不同的比较值
    switch(spwm->channel)
    {
        case 0:
            DL_Timer_setCaptureCompareValue(PWM_SERVO_INST, CompareValue, DL_TIMER_CC_0_INDEX);
        break;
        
        case 1:
            DL_Timer_setCaptureCompareValue(PWM_SERVO_INST, CompareValue, DL_TIMER_CC_1_INDEX);
        break;
                
        case 2:
            DL_Timer_setCaptureCompareValue(PWM_SERVO_INST, CompareValue, DL_TIMER_CC_2_INDEX);
        break;
        
        case 3:
            DL_Timer_setCaptureCompareValue(PWM_SERVO_INST, CompareValue, DL_TIMER_CC_3_INDEX);
        break;
        
        default: break;
    }
}

// set_Servo_angle函数用于设置伺服电机的角度
// @param spwm 指向SPWM结构体的指针
// @param angle 期望的角度值
void set_Servo_angle(SPWM *spwm,float angle)
{
	spwm->angle=angle;
	
	// 根据角度计算对应的占空比
	// 计算对应角度需要的占空比
	spwm->duty=1.0f*spwm->angle/9.0+14.0;
	
	// 设置SPWM的占空比
	set_SPWM0_duty(spwm,spwm->duty);	
}

// gate_Servo_angle函数用于获取伺服电机的角度
// @param spwm 指向SPWM结构体的指针
// @return 伺服电机的角度值
float gate_Servo_angle(SPWM *spwm)
{
	return spwm->angle;
}