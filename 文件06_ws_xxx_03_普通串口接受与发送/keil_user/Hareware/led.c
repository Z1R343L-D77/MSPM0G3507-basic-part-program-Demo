#include "led.h"



void led_mainloop(void)
{
    if(!f_500ms_led)return;
    f_500ms_led=0;

    // DL_GPIO_togglePins(GPIO_LEDS_PORT_PORT,GPIO_LEDS_PORT_USER_LED_1_PIN);//电平翻转驱动LED		
	// DL_GPIO_togglePins(GPIO_RGB_PORT,GPIO_RGB_RED_PIN | GPIO_RGB_BLUE_PIN | GPIO_RGB_GREEN_PIN);//电平翻转驱动RGB
}


