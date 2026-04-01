#include "common_inc.h"


#define DELAY (16000000)
void main_init(void);
//******************************
int main(void)
{
	main_init();
	while(1)
	{
		delay_cycles(DELAY);//延时0.5秒
		DL_GPIO_togglePins(PORTA_PORT,PORTA_LED_PIN);//电平翻转驱动LED		
		DL_GPIO_togglePins(PORTB_PORT,PORTB_RGB_R_PIN | PORTB_RGB_G_PIN | PORTB_RGB_B_PIN);//电平翻转驱动RGB
	}
}
//*******************************
void main_init(void)
{
	SYSCFG_DL_init(); //芯片资源初始化,由SysConfig配置软件自动生成
}
