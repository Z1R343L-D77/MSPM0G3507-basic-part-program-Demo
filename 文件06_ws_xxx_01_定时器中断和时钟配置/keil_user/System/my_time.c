#include "my_time.h"

u8 f_500ms_led=0;
u8 f_100ms_oled=0;
u8 f_10ms_key=0;

void tim_proc(void);
//*********************************
void time_init(void)
{
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);//开启中断
    DL_TimerA_startCounter(TIMER_0_INST);//开启计数器
}

void TIMER_0_INST_IRQHandler(void)
{
    switch(DL_TimerG_getPendingInterrupt(TIMER_0_INST))
    {
        case DL_TIMER_IIDX_ZERO:
            //1ms定时器中断
            tim_proc();
        break;
        default:
        break;   
    }
	
}

void tim_proc(void)
{
    static u8 cnt_10ms=0;
    static u8 cnt_100ms=0;
    static u16 cnt_500ms=0;
    if(++cnt_10ms>=10)
    {
        f_10ms_key=1;
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

}










