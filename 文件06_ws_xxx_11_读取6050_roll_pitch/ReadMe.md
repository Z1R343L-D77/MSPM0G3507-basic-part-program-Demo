# 读取MPU6050原始数据

## 1.syscfg配置

配置i2c总线

![image-20240708223824663](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708223824663.png)

![image-20240708223835702](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708223835702.png)

![image-20240708223851505](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708223851505.png)

根据原理图重新配置引脚

![image-20240708223915801](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708223915801.png)

## 2.程序使用

重定义i2c时序函数，直接复制使用

![image-20240708224012252](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708224012252.png)

初始化函数

![image-20240708224153455](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708224153455.png)

读取函数与测试

![image-20240708224206997](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708224206997.png)

利用oled显示，看原始变化值

![image-20240708224313829](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240708224313829.png)
