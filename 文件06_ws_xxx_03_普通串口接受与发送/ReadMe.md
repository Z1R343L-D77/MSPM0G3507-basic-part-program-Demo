# 普通串口的接受与发送

## 1.打开串口配置

添加串口

![image-20240706134250189](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706134250189.png)

配置波特率及其时钟

![image-20240706134448799](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706134448799.png)

串口中断配置，我们要使能接受中断

![image-20240706134717919](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706134717919.png)

串口选择以及引脚选择,根据原理图选择

![image-20240706135702680](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706135702680.png)

PA10 PA11

![image-20240706135754181](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706135754181.png)

## 2.程序配置

![image-20240706144922794](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706144922794.png)

## 3.效果验证

单片机接收到数据，led会闪一次，并且将数据发送回上位机

![image-20240706145127738](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706145127738.png)

上位机发送什么，单片机就返回什么

![image-20240706145052084](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706145052084.png)
