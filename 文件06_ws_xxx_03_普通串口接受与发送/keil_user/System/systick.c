#include "systick.h"

#define DELAY (16000000)


void delay_ms(uint32_t ms)
{
	while(ms--)
	delay_cycles(CPUCLK_FREQ/1000);
}


