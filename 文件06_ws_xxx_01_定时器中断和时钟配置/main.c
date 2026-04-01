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
	time_init();//定时器1ms中断
}
