#include "oled.h"

void oled_mainloop()
{
	if(!f_100ms_oled)return;
	f_100ms_oled = 0;
	
	LCD_clear_L(0,0);	display_6_8_string(0,0,"ADC: ");	display_6_8_number_f1(30,0,adc_dat);//显示计数器值get_battery_voltage
}