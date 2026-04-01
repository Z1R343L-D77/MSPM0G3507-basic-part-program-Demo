#include "oled.h"

void oled_mainloop(void)
{
	if(!f_100ms_oled)return;
	f_100ms_oled = 0;
	
	LCD_clear_L(0,0);	display_6_8_string(0,0,"ADC: ");		display_6_8_number_f1(30,0,adc_dat);								//ÏÔÊ¾¼ÆÊıÆ÷Öµget_battery_voltage
	LCD_clear_L(0,1);	display_6_8_string(0,1,"Right: ");	display_6_8_number_f1(34,1,NEncoder.right_motor_period_cnt);//ÏÔÊ¾ÓÒÂÖ±àÂëÆ÷
	LCD_clear_L(0,2);	display_6_8_string(0,2,"Left : ");	display_6_8_number_f1(34,2,NEncoder.left_motor_period_cnt); //ÏÔÊ¾×óÂÖ±àÂëÆ÷e
}