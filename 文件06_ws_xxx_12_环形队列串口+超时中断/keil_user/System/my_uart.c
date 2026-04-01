#include "common_inc.h"
#include "my_uart.h"


// 定义UART0的实例和接收缓冲区
UU uart0;
uint8_t Uart0_buf[256];

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
 * 通过UART0发送字节数据
 * @param buf 发送缓冲区指针
 * @param len 发送数据长度
 */
void usart0_send_bytes(u8 *buf, int len)//发送数据
{
  while(len--)
  {
        DL_UART_Main_transmitDataBlocking(UART_0_INST, *buf);
				buf++;
  }
  
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

/**
 * 重置UART接收计数器
 * @param uart UART实例指针
 */
void clear_Uart_cnt(UU *uart)
{
	uart->f = 1;
	uart->cnt = 0;
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
			usart0_send_bytes(Uart0_buf,uart->index);
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