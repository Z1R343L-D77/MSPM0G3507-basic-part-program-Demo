#include "jy901.h"
#include "string.h"
#include "my_uart.h"

struct STime		stcTime;
struct SAcc 		stcAcc;
struct SGyro 		stcGyro;
struct SAngle 	stcAngle;
struct SMag 		stcMag;
struct SDStatus stcDStatus;
struct SPress 	stcPress;
struct SLonLat 	stcLonLat;
struct SGPSV 		stcGPSV;
struct SQ       stcQ;

//CopeSerialData为串口2中断调用函数，串口每收到一个数据，调用一次这个函数。
void CopeSerial2Data(void)
{	
	if (Uart0_buf[0]==0x55) //数据头不对，则重新开始寻找0x55数据头
	{
		switch(Uart0_buf[1])//判断数据是哪种数据，然后将其拷贝到对应的结构体中，有些数据包需要通过上位机打开对应的输出后，才能接收到这个数据包的数据
		{
			//case 0x50:	memcpy(&stcTime,&Uart0_buf[2],8);break;//memcpy为编译器自带的内存拷贝函数，需引用"string.h"，将接收缓冲区的字符拷贝到数据结构体里面，从而实现数据的解析。
			case 0x51:	memcpy(&stcAcc,&Uart0_buf[2],8);break;
			case 0x52:	memcpy(&stcGyro,&Uart0_buf[2],8);break;
			case 0x53:	memcpy(&stcAngle,&Uart0_buf[2],8);break;
			case 0x54:	memcpy(&stcMag,&Uart0_buf[2],8);break;
			//case 0x55:	memcpy(&stcDStatus,&Uart0_buf[2],8);break;
			case 0x56:	memcpy(&stcPress,&Uart0_buf[2],8);break;
			case 0x57:	memcpy(&stcLonLat,&Uart0_buf[2],8);break;
			case 0x58:	memcpy(&stcGPSV,&Uart0_buf[2],8);break;
			case 0x59:	memcpy(&stcQ,&Uart0_buf[2],8);break;
			default:break;
		}
	}
}