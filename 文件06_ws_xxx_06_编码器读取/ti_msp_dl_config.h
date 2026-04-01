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



/* Defines for PWM_MOTO */
#define PWM_MOTO_INST                                                      TIMA0
#define PWM_MOTO_INST_IRQHandler                                TIMA0_IRQHandler
#define PWM_MOTO_INST_INT_IRQN                                  (TIMA0_INT_IRQn)
#define PWM_MOTO_INST_CLK_FREQ                                           1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTO_C0_PORT                                              GPIOB
#define GPIO_PWM_MOTO_C0_PIN                                      DL_GPIO_PIN_14
#define GPIO_PWM_MOTO_C0_IOMUX                                   (IOMUX_PINCM31)
#define GPIO_PWM_MOTO_C0_IOMUX_FUNC                  IOMUX_PINCM31_PF_TIMA0_CCP0
#define GPIO_PWM_MOTO_C0_IDX                                 DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTO_C1_PORT                                              GPIOA
#define GPIO_PWM_MOTO_C1_PIN                                       DL_GPIO_PIN_3
#define GPIO_PWM_MOTO_C1_IOMUX                                    (IOMUX_PINCM8)
#define GPIO_PWM_MOTO_C1_IOMUX_FUNC                   IOMUX_PINCM8_PF_TIMA0_CCP1
#define GPIO_PWM_MOTO_C1_IDX                                 DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_PWM_MOTO_C2_PORT                                              GPIOA
#define GPIO_PWM_MOTO_C2_PIN                                       DL_GPIO_PIN_7
#define GPIO_PWM_MOTO_C2_IOMUX                                   (IOMUX_PINCM14)
#define GPIO_PWM_MOTO_C2_IOMUX_FUNC                  IOMUX_PINCM14_PF_TIMA0_CCP2
#define GPIO_PWM_MOTO_C2_IDX                                 DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_MOTO_C3_PORT                                              GPIOA
#define GPIO_PWM_MOTO_C3_PIN                                       DL_GPIO_PIN_4
#define GPIO_PWM_MOTO_C3_IOMUX                                    (IOMUX_PINCM9)
#define GPIO_PWM_MOTO_C3_IOMUX_FUNC                   IOMUX_PINCM9_PF_TIMA0_CCP3
#define GPIO_PWM_MOTO_C3_IDX                                 DL_TIMER_CC_3_INDEX

/* Defines for PWM_SERVO */
#define PWM_SERVO_INST                                                     TIMG7
#define PWM_SERVO_INST_IRQHandler                               TIMG7_IRQHandler
#define PWM_SERVO_INST_INT_IRQN                                 (TIMG7_INT_IRQn)
#define PWM_SERVO_INST_CLK_FREQ                                           100000
/* GPIO defines for channel 0 */
#define GPIO_PWM_SERVO_C0_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C0_PIN                                     DL_GPIO_PIN_23
#define GPIO_PWM_SERVO_C0_IOMUX                                  (IOMUX_PINCM53)
#define GPIO_PWM_SERVO_C0_IOMUX_FUNC                 IOMUX_PINCM53_PF_TIMG7_CCP0
#define GPIO_PWM_SERVO_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_SERVO_C1_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C1_PIN                                      DL_GPIO_PIN_2
#define GPIO_PWM_SERVO_C1_IOMUX                                   (IOMUX_PINCM7)
#define GPIO_PWM_SERVO_C1_IOMUX_FUNC                  IOMUX_PINCM7_PF_TIMG7_CCP1
#define GPIO_PWM_SERVO_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (31999U)



/* Defines for SPI_0 */
#define SPI_0_INST                                                         SPI1
#define SPI_0_INST_IRQHandler                                   SPI1_IRQHandler
#define SPI_0_INST_INT_IRQN                                       SPI1_INT_IRQn
#define GPIO_SPI_0_PICO_PORT                                              GPIOB
#define GPIO_SPI_0_PICO_PIN                                      DL_GPIO_PIN_15
#define GPIO_SPI_0_IOMUX_PICO                                   (IOMUX_PINCM32)
#define GPIO_SPI_0_IOMUX_PICO_FUNC                   IOMUX_PINCM32_PF_SPI1_PICO
#define GPIO_SPI_0_POCI_PORT                                              GPIOA
#define GPIO_SPI_0_POCI_PIN                                      DL_GPIO_PIN_16
#define GPIO_SPI_0_IOMUX_POCI                                   (IOMUX_PINCM38)
#define GPIO_SPI_0_IOMUX_POCI_FUNC                   IOMUX_PINCM38_PF_SPI1_POCI
/* GPIO configuration for SPI_0 */
#define GPIO_SPI_0_SCLK_PORT                                              GPIOA
#define GPIO_SPI_0_SCLK_PIN                                      DL_GPIO_PIN_17
#define GPIO_SPI_0_IOMUX_SCLK                                   (IOMUX_PINCM39)
#define GPIO_SPI_0_IOMUX_SCLK_FUNC                   IOMUX_PINCM39_PF_SPI1_SCLK



/* Defines for ADC12_0 */
#define ADC12_0_INST                                                        ADC0
#define ADC12_0_INST_IRQHandler                                  ADC0_IRQHandler
#define ADC12_0_INST_INT_IRQN                                    (ADC0_INT_IRQn)
#define ADC12_0_ADCMEM_1                                      DL_ADC12_MEM_IDX_1
#define ADC12_0_ADCMEM_1_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_1_REF_VOLTAGE_V                                       3.3
#define GPIO_ADC12_0_C1_PORT                                               GPIOA
#define GPIO_ADC12_0_C1_PIN                                       DL_GPIO_PIN_26



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
/* Defines for D3_2: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_KEY_D3_2_PIN                                        (DL_GPIO_PIN_9)
#define GPIO_KEY_D3_2_IOMUX                                      (IOMUX_PINCM26)
/* Defines for D3_1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_KEY_D3_1_PIN                                        (DL_GPIO_PIN_8)
#define GPIO_KEY_D3_1_IOMUX                                      (IOMUX_PINCM25)
/* Defines for D3_3: GPIOB.10 with pinCMx 27 on package pin 62 */
#define GPIO_KEY_D3_3_PIN                                       (DL_GPIO_PIN_10)
#define GPIO_KEY_D3_3_IOMUX                                      (IOMUX_PINCM27)
/* Defines for D3_4: GPIOB.11 with pinCMx 28 on package pin 63 */
#define GPIO_KEY_D3_4_PIN                                       (DL_GPIO_PIN_11)
#define GPIO_KEY_D3_4_IOMUX                                      (IOMUX_PINCM28)
/* Defines for D3_5: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_KEY_D3_5_PIN                                       (DL_GPIO_PIN_12)
#define GPIO_KEY_D3_5_IOMUX                                      (IOMUX_PINCM29)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOB)

/* Defines for RST: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_OLED_RST_PIN                                       (DL_GPIO_PIN_16)
#define GPIO_OLED_RST_IOMUX                                      (IOMUX_PINCM33)
/* Defines for DC: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_OLED_DC_PIN                                        (DL_GPIO_PIN_17)
#define GPIO_OLED_DC_IOMUX                                       (IOMUX_PINCM43)
/* Defines for CS: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_OLED_CS_PIN                                        (DL_GPIO_PIN_20)
#define GPIO_OLED_CS_IOMUX                                       (IOMUX_PINCM48)
/* Port definition for Pin Group GPIO_ENC */
#define GPIO_ENC_PORT                                                    (GPIOB)

/* Defines for RIGHT_DIR: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_ENC_RIGHT_DIR_PIN                                   (DL_GPIO_PIN_6)
#define GPIO_ENC_RIGHT_DIR_IOMUX                                 (IOMUX_PINCM23)
/* Defines for RIGHT_PULSE: GPIOB.4 with pinCMx 17 on package pin 52 */
// pins affected by this interrupt request:["RIGHT_PULSE","LEFT_PULSE"]
#define GPIO_ENC_INT_IRQN                                       (GPIOB_INT_IRQn)
#define GPIO_ENC_INT_IIDX                       (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_ENC_RIGHT_PULSE_IIDX                            (DL_GPIO_IIDX_DIO4)
#define GPIO_ENC_RIGHT_PULSE_PIN                                 (DL_GPIO_PIN_4)
#define GPIO_ENC_RIGHT_PULSE_IOMUX                               (IOMUX_PINCM17)
/* Defines for LEFT_DIR: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_ENC_LEFT_DIR_PIN                                    (DL_GPIO_PIN_7)
#define GPIO_ENC_LEFT_DIR_IOMUX                                  (IOMUX_PINCM24)
/* Defines for LEFT_PULSE: GPIOB.5 with pinCMx 18 on package pin 53 */
#define GPIO_ENC_LEFT_PULSE_IIDX                             (DL_GPIO_IIDX_DIO5)
#define GPIO_ENC_LEFT_PULSE_PIN                                  (DL_GPIO_PIN_5)
#define GPIO_ENC_LEFT_PULSE_IOMUX                                (IOMUX_PINCM18)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTO_init(void);
void SYSCFG_DL_PWM_SERVO_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_SPI_0_init(void);
void SYSCFG_DL_ADC12_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
