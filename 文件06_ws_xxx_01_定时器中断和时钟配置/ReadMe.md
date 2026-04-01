# 定时器中断以及LED使用

## 1.配置定时器中断

选择定时器

![image-20240706103439305](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706103439305.png)

2.配置时钟

![image-20240706103602822](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706103602822.png)

会根据上一步的分频，时钟配置会显示相关最低最高的时间，我这边是31ns到2.05ms,也就是可以使用这范围内的中断

![image-20240706103625925](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706103625925.png)

直接输入定时器周期，但是要在高低频率的范围内，如果没有这个范围，调节分频

![image-20240706111647393](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706111647393.png)

开启中断，选择定时器

![image-20240706103814835](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240706103814835.png)
