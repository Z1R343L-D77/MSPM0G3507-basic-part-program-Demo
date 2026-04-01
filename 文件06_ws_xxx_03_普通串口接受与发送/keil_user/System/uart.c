#include "uart.h"

u8 uart0_rx_buf[128];
u16 uart0_rx_cnt=0;

void uart_init(void)
{
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);//清中断挂起
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);//中断使能

	DL_UART_clearInterruptStatus(UART_0_INST,DL_UART_INTERRUPT_RX);//清除中断标志位
}

void UART_0_INST_IRQHandler(void)
{
  if(DL_UART_getEnabledInterruptStatus(UART_0_INST,DL_UART_INTERRUPT_RX) == DL_UART_INTERRUPT_RX)
  {
		uart0_rx_buf[uart0_rx_cnt++] = DL_UART_receiveData(UART_0_INST);
		//处理数据
		usart0_send_bytes(uart0_rx_buf,sizeof(uart0_rx_buf));//串口发送
		DL_UART_clearInterruptStatus(UART_0_INST,DL_UART_INTERRUPT_RX);//清除中断标志位
  }
}



void usart0_send_string(uint8_t *ucstr)
{
  while(ucstr && *ucstr)
  {
    //DL_UART_Main_transmitData(UART_0_INST, *ucstr++);
    DL_UART_Main_transmitDataBlocking(UART_0_INST, *ucstr++);
  }
}


void usart0_send_bytes(unsigned char *buf, int len)
{
  while(len--)
  {
    DL_UART_Main_transmitDataBlocking(UART_0_INST, *buf);//DL_UART_Main_transmitData(UART_0_INST, *buf);
    buf++;
  }
}


int fputc(int ch, FILE *f)
{
  DL_UART_Main_transmitDataBlocking(UART_0_INST, ch);
  return ch;
}


/***************************************
函数名:	void UART_SendBytes(uint32_t port,uint8_t *ubuf, uint32_t len)
说明: 发送N个字节长度的数据
入口:	uint32_t port-串口号
			uint8_t *ubuf-待发生数据地址 
			uint32_t len-待发送数据长度
出口:	无
备注:	无
作者:	无名创新
***************************************/
void UART_SendBytes(UART_Regs *port,uint8_t *ubuf, uint32_t len)
{
  while(len--)
  {
    DL_UART_Main_transmitDataBlocking(port, *ubuf);
    ubuf++;
  }
}

/***************************************
函数名:	void UART_SendByte(uint32_t port,uint8_t data)
说明: 发送1个字节长度的数据
入口:	uint32_t port-串口号
			uint8_t data-待发生数据
出口:	无
备注:	无
作者:	无名创新
***************************************/
void UART_SendByte(UART_Regs *port,uint8_t data)
{
  DL_UART_Main_transmitDataBlocking(port, data);//DL_UART_Main_transmitData(UART_0_INST, *buf);
}

