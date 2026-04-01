#include "common_inc.h"

void main_init(void);
//******************************
int main(void)
{
	main_init();
	while(1)
	{
		led_mainloop();
	}
}
//*******************************
void main_init(void)
{
	SYSCFG_DL_init(); //芯片资源初始化,由SysConfig配置软件自动生成
	time_init();      //定时器中断
	key_init();       //按键初始化
	uart_init();	  //串口0初始化
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
	if (key->clickCnt == 2) //双击
	{
		if(key == &Key_1)
		{
            DL_GPIO_setPins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);
		}
		if(key == &Key_2)
		{
            DL_GPIO_clearPins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN);
		}
		if(key == &Key_3)
		{
            DL_GPIO_clearPins(GPIO_RGB_PORT,GPIO_RGB_GREEN_PIN);
		}
	}
}

