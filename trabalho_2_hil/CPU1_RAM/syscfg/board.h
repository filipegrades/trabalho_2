/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> EPWM_S12 Pinmux
//
//
// EPWM1A - GPIO Settings
//
#define GPIO_PIN_EPWM1A 0
#define EPWM_S12_EPWMA_GPIO 0
#define EPWM_S12_EPWMA_PIN_CONFIG GPIO_0_EPWM1A
//
// EPWM1B - GPIO Settings
//
#define GPIO_PIN_EPWM1B 1
#define EPWM_S12_EPWMB_GPIO 1
#define EPWM_S12_EPWMB_PIN_CONFIG GPIO_1_EPWM1B

//
// EPWM2 -> EPWM_S34 Pinmux
//
//
// EPWM2A - GPIO Settings
//
#define GPIO_PIN_EPWM2A 2
#define EPWM_S34_EPWMA_GPIO 2
#define EPWM_S34_EPWMA_PIN_CONFIG GPIO_2_EPWM2A
//
// EPWM2B - GPIO Settings
//
#define GPIO_PIN_EPWM2B 3
#define EPWM_S34_EPWMB_GPIO 3
#define EPWM_S34_EPWMB_PIN_CONFIG GPIO_3_EPWM2B
//
// GPIO6 - GPIO Settings
//
#define S1_GPIO_PIN_CONFIG GPIO_6_GPIO6
//
// GPIO7 - GPIO Settings
//
#define S2_GPIO_PIN_CONFIG GPIO_7_GPIO7
//
// GPIO8 - GPIO Settings
//
#define S3_GPIO_PIN_CONFIG GPIO_8_GPIO8
//
// GPIO9 - GPIO Settings
//
#define S4_GPIO_PIN_CONFIG GPIO_9_GPIO9

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define ADC0_BASE ADCA_BASE
#define ADC0_RESULT_BASE ADCARESULT_BASE
#define ADC0_SOC0 ADC_SOC_NUMBER0
#define ADC0_FORCE_SOC0 ADC_FORCE_SOC0
#define ADC0_SAMPLE_WINDOW_SOC0 75
#define ADC0_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM1_SOCA
#define ADC0_CHANNEL_SOC0 ADC_CH_ADCIN0
#define ADC0_SOC1 ADC_SOC_NUMBER1
#define ADC0_FORCE_SOC1 ADC_FORCE_SOC1
#define ADC0_SAMPLE_WINDOW_SOC1 75
#define ADC0_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM1_SOCA
#define ADC0_CHANNEL_SOC1 ADC_CH_ADCIN2
void ADC0_init();


//*****************************************************************************
//
// CLA Configurations
//
//*****************************************************************************
#define myCLA0_BASE CLA1_BASE

//
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them global
// and the main CPU can make use of them.
//
__attribute__((interrupt)) void Cla1Task1();
void myCLA0_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// DAC Configurations
//
//*****************************************************************************
#define myDAC0_BASE DACA_BASE
void myDAC0_init();
#define myDAC1_BASE DACB_BASE
void myDAC1_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define EPWM_S12_BASE EPWM1_BASE
#define EPWM_S12_TBPRD 5000
#define EPWM_S12_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_S12_TBPHS 0
#define EPWM_S12_CMPA 0
#define EPWM_S12_CMPB 0
#define EPWM_S12_CMPC 0
#define EPWM_S12_CMPD 0
#define EPWM_S12_DBRED 0
#define EPWM_S12_DBFED 0
#define EPWM_S12_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_S12_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_S12_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_S34_BASE EPWM2_BASE
#define EPWM_S34_TBPRD 5000
#define EPWM_S34_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_S34_TBPHS 0
#define EPWM_S34_CMPA 0
#define EPWM_S34_CMPB 0
#define EPWM_S34_CMPC 0
#define EPWM_S34_CMPD 0
#define EPWM_S34_DBRED 0
#define EPWM_S34_DBFED 0
#define EPWM_S34_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_S34_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_S34_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define S1 6
void S1_init();
#define S2 7
void S2_init();
#define S3 8
void S3_init();
#define S4 9
void S4_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 6
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();
#define myINPUTXBARINPUT1_SOURCE 7
#define myINPUTXBARINPUT1_INPUT XBAR_INPUT5
void myINPUTXBARINPUT1_init();
#define myINPUTXBARINPUT2_SOURCE 8
#define myINPUTXBARINPUT2_INPUT XBAR_INPUT6
void myINPUTXBARINPUT2_init();
#define myINPUTXBARINPUT3_SOURCE 9
#define myINPUTXBARINPUT3_INPUT XBAR_INPUT13
void myINPUTXBARINPUT3_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCPUTIMER0
// ISR need to be defined for the registered interrupts
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myCPUTIMER0_ISR(void);

// Interrupt Settings for INT_S1_XINT
// ISR need to be defined for the registered interrupts
#define INT_S1_XINT INT_XINT1
#define INT_S1_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_S1_XINT_ISR(void);

// Interrupt Settings for INT_S2_XINT
// ISR need to be defined for the registered interrupts
#define INT_S2_XINT INT_XINT2
#define INT_S2_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_S2_XINT_ISR(void);

// Interrupt Settings for INT_S3_XINT
// ISR need to be defined for the registered interrupts
#define INT_S3_XINT INT_XINT3
#define INT_S3_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP12
extern __interrupt void INT_S3_XINT_ISR(void);

// Interrupt Settings for INT_S4_XINT
// ISR need to be defined for the registered interrupts
#define INT_S4_XINT INT_XINT4
#define INT_S4_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP12
extern __interrupt void INT_S4_XINT_ISR(void);

//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
#define S1_XINT GPIO_INT_XINT1
#define S1_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void S1_XINT_init();
#define S2_XINT GPIO_INT_XINT2
#define S2_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void S2_XINT_init();
#define S3_XINT GPIO_INT_XINT3
#define S3_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void S3_XINT_init();
#define S4_XINT GPIO_INT_XINT4
#define S4_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void S4_XINT_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	CLA_init();
void	CPUTIMER_init();
void	DAC_init();
void	EPWM_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	MEMCFG_init();
void	SYNC_init();
void	XINT_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
