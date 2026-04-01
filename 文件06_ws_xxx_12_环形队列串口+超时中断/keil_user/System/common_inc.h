#ifndef _COMMON_INC_H
#define _COMMON_INC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>


typedef   signed           char int8;
typedef unsigned           char u8;
typedef unsigned           char uint8;
typedef unsigned           char byte;
typedef   signed short     int int16;
typedef unsigned short     int uint16;
typedef unsigned short     int u16;
typedef unsigned long      int u32; 
typedef signed       	char 	s8;
typedef signed short 	int 	s16;
typedef signed       	int 	s32;

//**************************
//***LIBRARY****************
//**************************
#include "ti_msp_dl_config.h"
//**************************
//***SYSTEM ****************
//**************************
#include "systick.h"
#include "my_time.h"
#include "my_pwm.h"
#include "my_i2c.h"
#include "my_uart.h"
#include "ring_buffer.h"
//**************************
//***HARDWARE **************
//**************************
#include "led.h"
#include "key.h"
#include "oled.h"
#include "adc.h"
#include "encoder.h"
#include "servo.h"
#include "beep.h"
#include "mpu6050.h"
#include "jy901.h"
//**************************
//***Driver   **************
//**************************
#include "filter.h"
#include "wp_math.h"

#endif 

