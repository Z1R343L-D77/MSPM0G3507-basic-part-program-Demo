/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for CAR_PWM0 */
#define CAR_PWM0_INST                                                      TIMA0
#define CAR_PWM0_INST_IRQHandler                                TIMA0_IRQHandler
#define CAR_PWM0_INST_INT_IRQN                                  (TIMA0_INT_IRQn)
#define CAR_PWM0_INST_CLK_FREQ                                           1000000
/* GPIO defines for channel 0 */
#define GPIO_CAR_PWM0_C0_PORT                                              GPIOB
#define GPIO_CAR_PWM0_C0_PIN                                      DL_GPIO_PIN_14
#define GPIO_CAR_PWM0_C0_IOMUX                                   (IOMUX_PINCM31)
#define GPIO_CAR_PWM0_C0_IOMUX_FUNC                  IOMUX_PINCM31_PF_TIMA0_CCP0
#define GPIO_CAR_PWM0_C0_IDX                                 DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_CAR_PWM0_C1_PORT                                              GPIOA
#define GPIO_CAR_PWM0_C1_PIN                                       DL_GPIO_PIN_3
#define GPIO_CAR_PWM0_C1_IOMUX                                    (IOMUX_PINCM8)
#define GPIO_CAR_PWM0_C1_IOMUX_FUNC                   IOMUX_PINCM8_PF_TIMA0_CCP1
#define GPIO_CAR_PWM0_C1_IDX                                 DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_CAR_PWM0_C2_PORT                                              GPIOA
#define GPIO_CAR_PWM0_C2_PIN                                       DL_GPIO_PIN_7
#define GPIO_CAR_PWM0_C2_IOMUX                                   (IOMUX_PINCM14)
#define GPIO_CAR_PWM0_C2_IOMUX_FUNC                  IOMUX_PINCM14_PF_TIMA0_CCP2
#define GPIO_CAR_PWM0_C2_IDX                                 DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_CAR_PWM0_C3_PORT                                              GPIOA
#define GPIO_CAR_PWM0_C3_PIN                                       DL_GPIO_PIN_4
#define GPIO_CAR_PWM0_C3_IOMUX                                    (IOMUX_PINCM9)
#define GPIO_CAR_PWM0_C3_IOMUX_FUNC                   IOMUX_PINCM9_PF_TIMA0_CCP3
#define GPIO_CAR_PWM0_C3_IDX                                 DL_TIMER_CC_3_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (31999U)




/* Port definition for Pin Group GPIO_LEDS_PORT */
#define GPIO_LEDS_PORT_PORT                                              (GPIOA)

/* Defines for USER_LED_1: GPIOA.0 with pinCMx 1 on package pin 33 */
#define GPIO_LEDS_PORT_USER_LED_1_PIN                            (DL_GPIO_PIN_0)
#define GPIO_LEDS_PORT_USER_LED_1_IOMUX                           (IOMUX_PINCM1)
/* Port definition for Pin Group GPIO_RGB */
#define GPIO_RGB_PORT                                                    (GPIOB)

/* Defines for RED: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_RGB_RED_PIN                                        (DL_GPIO_PIN_26)
#define GPIO_RGB_RED_IOMUX                                       (IOMUX_PINCM57)
/* Defines for GREEN: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_RGB_GREEN_PIN                                      (DL_GPIO_PIN_27)
#define GPIO_RGB_GREEN_IOMUX                                     (IOMUX_PINCM58)
/* Defines for BLUE: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_RGB_BLUE_PIN                                       (DL_GPIO_PIN_22)
#define GPIO_RGB_BLUE_IOMUX                                      (IOMUX_PINCM50)
/* Port definition for Pin Group GPIO_KEY */
#define GPIO_KEY_PORT                                                    (GPIOB)

/* Defines for KEY_1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_KEY_KEY_1_PIN                                      (DL_GPIO_PIN_21)
#define GPIO_KEY_KEY_1_IOMUX                                     (IOMUX_PINCM49)
/* Defines for KEY_2: GPIOB.23 with pinCMx 51 on package pin 22 */
#define GPIO_KEY_KEY_2_PIN                                      (DL_GPIO_PIN_23)
#define GPIO_KEY_KEY_2_IOMUX                                     (IOMUX_PINCM51)
/* Defines for KEY_3: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_KEY_KEY_3_PIN                                      (DL_GPIO_PIN_24)
#define GPIO_KEY_KEY_3_IOMUX                                     (IOMUX_PINCM52)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_CAR_PWM0_init(void);
void SYSCFG_DL_TIMER_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
