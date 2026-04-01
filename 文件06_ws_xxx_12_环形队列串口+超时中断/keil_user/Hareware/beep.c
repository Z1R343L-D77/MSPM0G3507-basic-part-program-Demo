#include "beep.h"

/* 定义一个结构体变量beep，用于控制激光或蜂鸣器的输出 */
_laser_light  beep;

/* 初始化蜂鸣器模块 */
/***************************************
函数名:	void beep_init(void)
说明: 初始化蜂鸣器的控制结构体
参数: 无
返回值: 无
***************************************/
void beep_init(void)
{
  /* 将蜂鸣器的端口和引脚赋值给beep结构体 */
  beep.port = PORTA_PORT;
  beep.pin = PORTA_beep_PIN;
  /* 初始时，周期和亮起百分比设为0 */
  beep.period = 0;
  beep.light_on_percent = 0.5f;
  /* 初始化重置标志和计数器 */
  beep.reset = 1;
  beep.times = 0;
}

/* 蜂鸣器的主要循环函数 */
/***************************************
函数名:	beep_mainloop(_laser_light *light)
参数: _laser_light *light - 指向控制结构体的指针
返回值: 无
说明: 控制蜂鸣器的亮灭循环和重置逻辑
***************************************/
void beep_mainloop(_laser_light *light)
{
  if(!f_5ms_beep)return;//200HZ
  f_5ms_beep=0;

  /* 如果处于重置状态，则重置相关计数器和标志 */
  if(light->reset==1)
  {
    light->reset=0;
    light->cnt=0;
    light->times_cnt=0;//点亮次数计数器
    light->end=0;
  }

  /* 如果累计点亮次数达到设定值，则结束循环 */
  if(light->times_cnt==light->times)
  {
    light->end=1;
    return;
  }

  /* 增加计数器 */
  light->cnt++;
  /* 根据计数器和设定的周期与亮起百分比，控制蜂鸣器的亮灭 */
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

/* 设置蜂鸣器的响铃周期和亮起百分比 */
void buzzer_setup(uint32_t _period, float _light_on_percent, uint16_t _times)
{
  /* 将计算后的周期和亮起百分比赋值给beep结构体 */
  beep.period = _period / 5; //20*5ms
  beep.light_on_percent = _light_on_percent;
  /* 初始化重置标志和计数器 */
  beep.reset = 1;
  beep.times = _times;
}