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
#include "uart.h"
//**************************
//***HARDWARE **************
//**************************
#include "led.h"
#include "key.h"

#endif 

