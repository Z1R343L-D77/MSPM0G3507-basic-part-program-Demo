#ifndef __ADC_H
#define __ADC_H

#include "common_inc.h"

//定义电压采集变量
#define no_voltage_enable_default 0
#define no_voltage_upper_default 7.2f
#define no_voltage_lower_default 5.5f

//采集电压结构体
typedef struct
{
	float value;
	uint8_t enable;
	float upper;
	float lower;
	uint16_t low_vbat_cnt;
}low_voltage;

extern low_voltage vbat;
extern float adc_dat;

void adc_init(void);
void adc_statemachine(void);

float get_battery_voltage(void);
void adc_mainloop(void);

#endif




