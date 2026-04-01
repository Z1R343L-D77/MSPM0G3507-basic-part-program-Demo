#include "beep.h"

_laser_light  beep;
/***************************************
函数名:	void beep_init(void)
说明: beep初始化
***************************************/
void beep_init(void)
{
  beep.port = PORTA_PORT;
  beep.pin = PORTA_beep_PIN;
  beep.period = 200; //200*5ms
  beep.light_on_percent = 0.5f;
	
  beep.reset = 1;
  beep.times = 0;
}
/***************************************
函数名:	beep_mainloop(_laser_light *light)
入口:	_laser_light *light-gpio控制结构体
***************************************/
void beep_mainloop(_laser_light *light)
{
	if(!f_5ms_beep)return;
	f_5ms_beep=0;
	
	if(light->reset==1)
	{
		light->reset=0;
		light->cnt=0;
		light->times_cnt=0;//点亮次数计数器
		light->end=0;
	}
	
	if(light->times_cnt==light->times)
	{
		light->end=1;
		return;
	}

	light->cnt++;
	
	if(light->cnt<=light->period*light->light_on_percent)
	{
		DL_GPIO_setPins(light->port, light->pin);
	}
	else if(light->cnt<light->period)
	{
		DL_GPIO_clearPins(light->port, light->pin);
	}
	else//完成点亮一次
	{
		light->cnt=0;
		light->times_cnt++;
	}
}

void buzzer_setup(uint32_t _period, float _light_on_percent, uint16_t _times)
{
  beep.period = _period / 5; //20*5ms
  beep.light_on_percent = _light_on_percent;
  beep.reset = 1;
  beep.times = _times;
}