# ADC 电压采集

1.syscfg配置

![image-20240708141410911](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708141410911.png)

模式选择

![image-20240708141449132](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708141449132.png)

开启中断

![image-20240708141522189](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708141522189.png)

根据原理图选择引脚

![image-20240708141548576](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708141548576.png)

2.程序配置

```
/**
 * ADC主循环函数
 * @note 如果5ms内未触发ADC转换，则函数直接返回
 */
void adc_mainloop()
{
	
	/* 如果5ms内未触发ADC转换，则返回 */
	if(!f_5ms_adc)return;
	f_5ms_adc = 0;
	
	/* 更新电池电压值 */
	adc = get_battery_voltage();
	adc_statemachine();
}

```

