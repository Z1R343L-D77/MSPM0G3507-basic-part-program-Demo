# 左右电机编码器读取

## 1.syscfg配置

开启GPIO_ENC，设置四个PINs

![image-20240708150229731](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708150229731.png)

分别配置脉冲和方向PINs

根据原理图分配引脚

![image-20240708150403109](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708150403109.png)

![image-20240708150445809](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708150445809.png)

注意脉冲线开启中断

![image-20240708150515121](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708150515121.png)

![image-20240708150543655](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708150543655.png)

## 2.程序配置

直接初始化读取即可

```
// 初始化编码器，清除中断挂起状态并启用编码器中断
void encoder_init(void)
{
	NVIC_ClearPendingIRQ(GPIO_ENC_INT_IRQN);
	NVIC_EnableIRQ(GPIO_ENC_INT_IRQN);
}
```

通过OLED显示

```
void oled_mainloop(void)
{
	if(!f_100ms_oled)return;
	f_100ms_oled = 0;
	
	LCD_clear_L(0,0);	
	display_6_8_string(0,0,"ADC: ");		display_6_8_number_f1(30,0,vbat.value);								//显示计数器值get_battery_voltage
	LCD_clear_L(0,1);	
	display_6_8_string(0,1,"Right: ");	display_6_8_number_f1(34,1,NEncoder.right_motor_period_cnt);//显示右轮编码器
	LCD_clear_L(0,2);	
	display_6_8_string(0,2,"Left : ");	display_6_8_number_f1(34,2,NEncoder.left_motor_period_cnt); //显示左轮编码器e
}
```

