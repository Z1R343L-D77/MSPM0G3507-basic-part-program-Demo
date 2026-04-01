# 蜂鸣器报警

## 1.sysfig配置

添加GPIO

![image-20240708164509614](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708164509614.png)

引脚配置

![image-20240708164536568](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708164536568.png)

## 2.程序使用

beep.c和.h直接复制

主程序配置

```
int main(void)
{
	main_init();
	while(1)
	{
		led_mainloop();
		oled_mainloop();
		adc_mainloop();
		beep_mainloop(&beep);       //电源板蜂鸣器驱动
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
	beep_init();		//蜂鸣器初始化
}
```

在adc.c中修改电压阈值

```
	if(adc_dat<=10.5)
		buzzer_setup(1000,0.5f,1);//电压不够,报警
```

