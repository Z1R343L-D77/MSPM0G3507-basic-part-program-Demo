#ifndef _MY_UART_H
#define _MY_UART_H

#include "common_inc.h"



typedef struct UU
{
	u8 index;
	u8 f;
	u8 cnt;
//	RINGBUFF_T TestRingbuff;
}UU;

extern UU uart0;

extern uint8_t 	 Uart0_buf[256];

void uart_init(void);

void uu_init(UU *uart);

void usart0_send_bytes(u8 *buf, int len);

void Uart_Timeout_Interrupted(UU *uart);

void clear_Uart_cnt(UU *uart);

void uart_proc(UU *uart);


#endif 







