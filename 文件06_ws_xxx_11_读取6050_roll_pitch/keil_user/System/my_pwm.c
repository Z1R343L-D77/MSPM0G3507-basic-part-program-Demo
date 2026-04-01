#include "my_pwm.h"

// 定义了两个PWM实例，用于控制左右轮子
PWM pwm0_left;
PWM pwm0_right;

// 定义PWM周期的计数器总数
// 定义PWM周期的计数器总数
#define PERIOD_COUNT 1000

/**
 * PWM初始化函数
 * 启动PWM计数器，为PWM生成提供基础
 * 
 */
void pwm_init(void)
{
    // 开启PWM计数器
    DL_TimerA_startCounter(PWM_MOTO_INST);
    // 初始化PWM实例，设置左右电机的PWM通道
    Struct_PWM_init(&pwm0_left,CHANNEL1,CHANNEL0); // 左电机 IN1-CH1 IN2-CH0
    Struct_PWM_init(&pwm0_right,CHANNEL2,CHANNEL3); // 右电机 IN1-CH2 IN2-CH3
}

/**
 * 设置PWM0的占空比
 * @param duty 占空比值，范围为0到1
 * @param channel PWM通道，决定哪个通道的占空比被设置
 */
void set_PWM0_duty(float duty,u8 channel) 
{
    // 计算比较值，通过占空比乘以周期计数器总数来得到
    u32 CompareValue;
    CompareValue=(float)PERIOD_COUNT*duty;
    
    // 根据通道号设置不同的比较值
    switch(channel)
    {
        case 0:
            DL_TimerA_setCaptureCompareValue(PWM_MOTO_INST, CompareValue, DL_TIMER_CC_0_INDEX);
        break;
        
        case 1:
            DL_TimerA_setCaptureCompareValue(PWM_MOTO_INST, CompareValue, DL_TIMER_CC_1_INDEX);
        break;
				
        case 2:
            DL_TimerA_setCaptureCompareValue(PWM_MOTO_INST, CompareValue, DL_TIMER_CC_2_INDEX);
        break;
        
        case 3:
            DL_TimerA_setCaptureCompareValue(PWM_MOTO_INST, CompareValue, DL_TIMER_CC_3_INDEX);
        break;
        
        default: break;
    }
}

/**
 * 设置车轮的PWM占空比和方向
 * @param duty 占空比值，用于控制车轮的速度
 * @param direct 控制车轮的行驶方向
 * 
 * 该函数根据输入的占空比和方向，设置车轮的行驶状态。
 * 正值表示前进，负值表示后退，方向参数决定是左轮还是右轮驱动。
 */
void set_Wheels(PWM *pwm, float duty)
{
    pwm->duty=duty;
    if(pwm->duty>=0) // 前进
    {
        set_PWM0_duty(abs_float(duty) , pwm->IN1_channel);
        set_PWM0_duty(0 , pwm->IN2_channel);
    }
    else if(duty<0) // 后退
    {
        set_PWM0_duty(0 , pwm->IN1_channel);
        set_PWM0_duty(abs_float(duty) , pwm->IN2_channel);
    }
}

/**
 * 返回输入浮点数的绝对值
 * @param num 输入的浮点数
 * @return 输入数的绝对值
 * 
 * 该函数用于获取浮点数的绝对值，用于占空比的计算。
 */
float abs_float(float num) 
{
    return (num >= 0) ? num : -num;
}

/**
 * PWM结构体初始化函数
 * @param pwm PWM结构体指针
 * @param IN1_channel PWM输入通道1
 * @param IN2_channel PWM输入通道2
 * 
 * 该函数初始化PWM结构体，设置PWM的输入通道和初始占空比。
 */
void Struct_PWM_init(PWM *pwm,u8 IN1_channel,u8 IN2_channel)
{
    // 初始化PWM的输入通道
    pwm->IN1_channel=IN1_channel;
    pwm->IN2_channel=IN2_channel;
    // 初始化占空比为0
    pwm->duty=0;
}