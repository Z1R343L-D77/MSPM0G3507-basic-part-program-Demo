# 按键配置及其使用

## 1.syscfg配置

选择添加GPIO宏定义，配置为input

![](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120334196.png)

根据原理图，将按键配置为上拉，并选择GPIOB-xx引脚

![image-20240706120450789](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120450789.png)

![image-20240706120141793](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120141793.png)

## 2.程序配置

直接移植的STM32ComKey按键程序

![image-20240706120650884](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120650884.png)

中断扫描

![image-20240706120720034](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120720034.png)

按键控制程序，代码测试成功

![image-20240706120757929](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706120757929.png)
