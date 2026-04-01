#include "common_inc.h"

void main_init(void);
//******************************
int main(void)
{
	main_init();
	while(1)
	{
		led_mainloop();
		oled_mainloop();
		adc_mainloop();
		//beep_mainloop(&beep);
		mpu6050_mainloop();
	}
}
//*******************************
void main_init(void)
{
	//
	SYSCFG_DL_init(); 	//芯片资源初始化,由SysConfig配置软件自动生成
	time_init();      	//定时器中断
	key_init();       	//按键初始化
	oled_init();		//oled显示屏初始化
	adc_init();			//ADC初始化
	encoder_init();		//编码器初始化
	pwm_init();			//电机初始化
	spwm_init();      	//初始化舵机
	beep_init();		//蜂鸣器初始化
	mpu6050_init();		//mpu6050初始化
	uart_init();	    //串口0初始化
}
//******************************
//连击函数(单双击)
void ComKey_MultipleClickCallback(comkey_t *key) 
{
	if (key->clickCnt == 1)//单击
	{
		if(key == &Key_1)
		{
            DL_GPIO_clearPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
			set_Wheels(&pwm0_right,0.5); //右轮前进50%占空比
		}
		if(key == &Key_2)
		{
            DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN);
			set_Wheels(&pwm0_left,0.5);
		}
		if(key == &Key_3)
		{
            DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_GREEN_PIN);
			set_Wheels(&pwm0_left,0);  set_Wheels(&pwm0_right,0);
		}
		if(key == &Key_D3_5)
		{
				DL_GPIO_clearPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
			
				servo_angle+=5;
				if(servo_angle>90) servo_angle=-90;
				set_Servo_angle(&spwm0,servo_angle);
		}
		if(key == &Key_D3_1)
		{
				DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN);
		}
		if(key == &Key_D3_2)
		{
				DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_GREEN_PIN);
		}
		if(key == &Key_D3_3)
		{
				DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_BLUE_PIN);
		}
		if(key == &Key_D3_4)
		{
				DL_GPIO_clearPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
				servo_angle-=5;
				if(servo_angle<-90) servo_angle=90;
				set_Servo_angle(&spwm0,servo_angle);
		}
	}
	if (key->clickCnt == 2) //双击
	{
		if(key == &Key_1)
		{
            DL_GPIO_setPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
			set_Wheels(&pwm0_right,-0.5); //右轮后进20%占空比
		}
		if(key == &Key_2)
		{
            DL_GPIO_clearPins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN);
			set_Wheels(&pwm0_left,-0.5);
		}
		if(key == &Key_3)
		{
            DL_GPIO_clearPins(GPIO_RGB_PORT,GPIO_RGB_GREEN_PIN);
		}
	}
}
//
void ComKey_HoldTriggerCallback(comkey_t *key)
{

	if(key == &Key_1)
	{
			DL_GPIO_clearPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
	}
	if(key == &Key_2)
	{
			DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN);
	}
	if(key == &Key_3)
	{
			DL_GPIO_setPins(GPIO_RGB_PORT,GPIO_RGB_GREEN_PIN);
	}
}
