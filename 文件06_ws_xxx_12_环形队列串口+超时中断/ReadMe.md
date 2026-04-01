# 环形队列串口程序

参考资料 [串口环形队列实验——基于STM32F103CBT6_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1aF4m1P7vv/?spm_id_from=333.999.0.0&vd_source=98891bf2c072dc87fa2246bb3be2d573)



### 1.复制底层程序

![image-20240709144250979](https://z1r343l-001.obs.cn-north-4.myhuaweicloud.com/ws_C301/image-20240709144250979.png)



### 2.程序初始化

```c
/**
 * 初始化UART0
 * 设置中断使能和初始化接收缓冲区
 */
void uart_init(void)
{
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);//清中断挂起
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);//中断使能
		
		RingBuffer_Init(&Ringbuff0, Uart0_buf, 1, 512);   //ring_buffer 初始化
		uu_init(&uart0);  //初始化串口0
}


/**
 * 初始化UART实例
 * @param uart UART实例指针
 */
void uu_init(UU *uart) 
{
    uart->index = 0;
    uart->f = 0;
		uart->cnt = 0;
}
```



### 3.串口中断，将接收到的数据存入环形缓冲区

```c
 * UART0中断处理函数
 * 处理接收中断，将接收到的数据存入缓冲区
 */
void UART_0_INST_IRQHandler(void)//串口数据单字节中断
{
		u8 tmp=0;
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST))
    {   
        case DL_UART_MAIN_IIDX_RX:
        //接受中断处理
						clear_Uart_cnt(&uart0);
            DL_GPIO_togglePins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);//接受LED 闪烁
						tmp=DL_UART_Main_receiveData(UART_0_INST);//数据接受
						RingBuffer_Insert(&Ringbuff0, &tmp); 
        break;
        default:
        break;
    }
		
		
}


/**
 * 重置UART接收定时器
 * @param uart UART实例指针
 */
void clear_Uart_cnt(UU *uart)
{
	uart->f = 1;
	uart->cnt = 0;
}
```



### 4.定时器超时中断处理

```c
void tim_proc(void)
{
    static u8 cnt_10ms=0;
    static u8 cnt_100ms=0;
    static u16 cnt_500ms=0;
	
		
    if(++cnt_10ms>=10)
    {
				ComKey_Porc();
        cnt_10ms=0;
    }

    if(++cnt_100ms>=100)
    {
        f_100ms_oled=1;
        cnt_100ms=0;
    }

    if(++cnt_500ms>=500)
    {
        f_500ms_led=1;
        cnt_500ms=0;
    }
		
		Uart_Timeout_Interrupted(&uart0); //串口超时处理
}

/**
 * 处理UART超时中断
 * @param uart UART实例指针
 */
void Uart_Timeout_Interrupted(UU *uart)
{
	uint8_t i = 0;
	if(uart->f)
	{
		if(++uart->cnt>=10)
		{
			uart->index=RingBuffer_PopMult(&Ringbuff0, Uart0_buf, 512);
			uu_init(&uart0);
			uart_proc(&uart0);
		}
	}
}

/**
 * 处理UART数据
 * @param uart UART实例指针
 */
void uart_proc(UU *uart)
{
	//数据处理
}
```

