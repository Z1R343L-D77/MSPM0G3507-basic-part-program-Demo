# 普通定时器PWM输出配置



## 1.sysconfig配置

![image-20240707192935945](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240707192935945.png)

开启PWM通道

![image-20240707193019652](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240707193019652.png)

初始值设置为0占空比

需要注意，pwm的3、4通道真实通道是反相的，所以要加上invert再次取反表示是同相

![image-20240707193221733](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240707193221733.png)

根据原理图，配置出相关引脚

![image-20240707193245640](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240707193245640.png)

## 2.程序使用

我们使用结构体指针来确定pwm的通道选择已经正反相

```
#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3

#define LEFT 1  //左
#define RIGHT 0 //右

typedef struct PWM
{
	//通道
	u8 IN1_channel;
	u8 IN2_channel;
	
	//占空比
	float duty;
}PWM;

extern PWM pwm0_left,pwm0_right;
```

并封装初始化以及设置占空比的函数

```
/**
 * PWM初始化函数
 * 启动PWM计数器，为PWM生成提供基础
 * 
 */
void pwm_init(void)
{
    // 开启PWM计数器
    DL_TimerA_startCounter(CAR_PWM0_INST);
    // 初始化PWM实例，设置左右电机的PWM通道
    Struct_PWM_init(&pwm0_left,CHANNEL1,CHANNEL0); // 左电机 IN1-CH1 IN2-CH0
    Struct_PWM_init(&pwm0_right,CHANNEL2,CHANNEL3); // 右电机 IN1-CH2 IN2-CH3
}
```

