#include "oled.h"

void oled_mainloop(void)
{
	if(!f_100ms_oled)return;
	f_100ms_oled = 0;
	
	LCD_clear_L(0,0);	display_6_8_string(0,0,"ADC: ");	display_6_8_number_f1(30,0,adc_dat);					//ÏÔÊ¾¼ÆÊıÆ÷Öµget_battery_voltage
	LCD_clear_L(0,1);	display_6_8_string(0,1,"Right: ");	display_6_8_number_f1(34,1,NEncoder.right_motor_period_cnt);//ÏÔÊ¾ÓÒÂÖ±àÂëÆ÷
	LCD_clear_L(0,2);	display_6_8_string(0,2,"Left : ");	display_6_8_number_f1(34,2,NEncoder.left_motor_period_cnt); //ÏÔÊ¾×óÂÖ±àÂëÆ÷
	
//	LCD_clear_L(0,3);	display_6_8_string(0,3,"gyroX : ");	display_6_8_number_f1(34,3,gyro.x); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ
//	LCD_clear_L(0,4);	display_6_8_string(0,4,"gyroY : ");	display_6_8_number_f1(34,4,gyro.y); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ
//	LCD_clear_L(0,5);	display_6_8_string(0,5,"gyroZ : ");	display_6_8_number_f1(34,5,gyro.z); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ

	LCD_clear_L(0,3);	display_6_8_string(0,3,"accelX : ");	display_6_8_number_f1(34,3,accel.x); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ
	LCD_clear_L(0,4);	display_6_8_string(0,4,"accelY : ");	display_6_8_number_f1(34,4,accel.y); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ
	LCD_clear_L(0,5);	display_6_8_string(0,5,"accelZ : ");	display_6_8_number_f1(34,5,accel.z); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ

	LCD_clear_L(0,6);	display_6_8_string(0,6,"temp : ");	display_6_8_number_f1(34,6,temperature); //ÏÔÊ¾mpu6050ÍÓÂİÒÇ


}