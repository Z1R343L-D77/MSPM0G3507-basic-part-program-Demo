#include "adc.h"


/* 用于存储计算后的电池电压 */
float adc_dat;

/* 定义电池电压检测对象，初始化为默认状态 */
low_voltage vbat=
{  
	.enable=no_voltage_enable_default,
	.value=0,
	.upper=no_voltage_upper_default,
	.lower=no_voltage_lower_default
};
/* 存储ADC转换后的电池电压值 */
uint16_t adc_value;
/**
 * ADC主循环函数
 * @note 如果5ms内未触发ADC转换，则函数直接返回
 */
void adc_mainloop()
{
//	if(!f_100ms_adc)return;
//	f_100ms_adc = 0;
	
	/* 更新电池电压值 */
	adc_dat = get_battery_voltage()*11.218f;
	adc_statemachine();
	
	if(adc_dat<=10.5)
		buzzer_setup(1000,0.5f,1);//电压不够,报警
}

/**
 * 初始化ADC，使能ADC12_0的中断
 */
void adc_init(void)
{
	NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
}

/**
 * 获取电池电压
 * @return 电池电压的浮点数表示
 */
float get_battery_voltage(void)//ADC获取   
{
	/* 使用低通滤波器平滑电压值 */
	static float value_filter;
	value_filter=(double)(0.7f*value_filter)+0.3f*3.3f*adc_value/4095.0f;	

  return value_filter;	
}

/* 标记ADC转换是否完成的全局变量 */
volatile bool gCheckADC=false;

/**
 * ADC状态机函数，启动ADC转换并处理转换结果
 */
void adc_statemachine(void)
{
	/* 启动ADC转换 */
	DL_ADC12_startConversion(ADC12_0_INST);	//开始转换
	/* 等待转换完成 */
	/* Wait until all data channels have been loaded. */
	while (gCheckADC == false);
	/* 读取转换结果 */
	adc_value = DL_ADC12_getMemResult(ADC12_0_INST, ADC12_0_ADCMEM_1);//通过PA25读取AD值
	/* 启用连续转换 */
	DL_ADC12_enableConversions(ADC12_0_INST);
}

/**
 * ADC12_0中断服务程序
 */
void ADC12_0_INST_IRQHandler(void)
{
    /* 处理ADC转换完成中断 */
    switch (DL_ADC12_getPendingInterrupt(ADC12_0_INST)) 
	{
        case DL_ADC12_IIDX_MEM1_RESULT_LOADED:
            /* 标记转换完成 */
            gCheckADC = true;
            break;
        default:
            break;
    }
}

