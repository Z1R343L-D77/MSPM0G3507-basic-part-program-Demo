#include "encoder.h"

// 定义了一个名为NEncoder的编码器结构体实例，初始化了左右电机的周期时间为20ms
encoder NEncoder=
{
	.left_motor_period_ms=20,
	.right_motor_period_ms=20,
};

// 定义了一个电机配置结构体实例
motor_config trackless_motor;

// 初始化编码器，清除中断挂起状态并启用编码器中断
void encoder_init(void)
{
	NVIC_ClearPendingIRQ(GPIO_ENC_INT_IRQN);
	NVIC_EnableIRQ(GPIO_ENC_INT_IRQN);
}

// QEI0_IRQHandler处理右电机编码器中断
void QEI0_IRQHandler(void)
{
	// 根据右电机编码器的方向引脚确定电机旋转方向
	NEncoder.right_motor_dir=((GPIO_ENC_PORT->DIN31_0 & GPIO_ENC_RIGHT_DIR_PIN)!=0?1:-1);
	
	// 根据right_encoder_dir_config配置决定计数方式（增加或减少）
	if(trackless_motor.right_encoder_dir_config==0)
	{		
		if(NEncoder.right_motor_dir==1)	NEncoder.right_motor_period_cnt++;
		else NEncoder.right_motor_period_cnt--;
		NEncoder.right_motor_total_cnt+=NEncoder.right_motor_dir;	
	}
	else
	{
		if(NEncoder.right_motor_dir==1)	NEncoder.right_motor_period_cnt--;
		else NEncoder.right_motor_period_cnt++;
		NEncoder.right_motor_total_cnt-=NEncoder.right_motor_dir;				
	}	
}

// QEI1_IRQHandler处理左电机编码器中断
void QEI1_IRQHandler(void)
{
	// 根据左电机编码器的方向引脚确定电机旋转方向
	NEncoder.left_motor_dir=((GPIO_ENC_PORT->DIN31_0 & GPIO_ENC_LEFT_DIR_PIN)!=0?-1:1);
	
	// 根据left_encoder_dir_config配置决定计数方式（增加或减少）
	if(trackless_motor.left_encoder_dir_config==0)
	{	
		if(NEncoder.left_motor_dir==1)	NEncoder.left_motor_period_cnt++;
		else NEncoder.left_motor_period_cnt--;
		NEncoder.left_motor_total_cnt+=NEncoder.left_motor_dir;
	}
	else
	{
		if(NEncoder.left_motor_dir==1)	NEncoder.left_motor_period_cnt--;
		else NEncoder.left_motor_period_cnt++;
		NEncoder.left_motor_total_cnt-=NEncoder.left_motor_dir;
	}		
}

// GROUP1_IRQHandler处理GPIOB组中断
void GROUP1_IRQHandler(void)
{
	// 检查GPIOB组中断中是否有编码器脉冲中断
	if(DL_Interrupt_getStatusGroup(DL_INTERRUPT_GROUP_1,DL_INTERRUPT_GROUP1_GPIOB))
	{
		// 处理右电机编码器脉冲中断
		if(DL_GPIO_getEnabledInterruptStatus(GPIO_ENC_PORT, GPIO_ENC_RIGHT_PULSE_PIN))
		{				
			QEI0_IRQHandler();
			DL_GPIO_clearInterruptStatus(GPIO_ENC_PORT, GPIO_ENC_RIGHT_PULSE_PIN);				
		}
		
		// 处理左电机编码器脉冲中断
		if(DL_GPIO_getEnabledInterruptStatus(GPIO_ENC_PORT, GPIO_ENC_LEFT_PULSE_PIN))
		{
			QEI1_IRQHandler();
			DL_GPIO_clearInterruptStatus(GPIO_ENC_PORT, GPIO_ENC_LEFT_PULSE_PIN);
		}
		
		// 清除GPIOB组中断状态
		DL_Interrupt_clearGroup(DL_INTERRUPT_GROUP_1, DL_INTERRUPT_GROUP1_GPIOB);
	}
}