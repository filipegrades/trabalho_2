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

//
// SCIA -> SCI0 Pinmux
//
//
// SCIRXDA - GPIO Settings
//
#define GPIO_PIN_SCIRXDA 43
#define SCI0_SCIRX_GPIO 43
#define SCI0_SCIRX_PIN_CONFIG GPIO_43_SCIRXDA
//
// SCITXDA - GPIO Settings
//
#define GPIO_PIN_SCITXDA 42
#define SCI0_SCITX_GPIO 42
#define SCI0_SCITX_PIN_CONFIG GPIO_42_SCITXDA

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

// Interrupt Settings for INT_myCLA01
// ISR need to be defined for the registered interrupts
#define INT_myCLA01 INT_CLA1_1
#define INT_myCLA01_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr1(void);

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

// Interrupt Settings for INT_SCI0_RX
// ISR need to be defined for the registered interrupts
#define INT_SCI0_RX INT_SCIA_RX
#define INT_SCI0_RX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_SCI0_RX_ISR(void);

//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define SCI0_BASE SCIA_BASE
#define SCI0_BAUDRATE 115200
#define SCI0_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define SCI0_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define SCI0_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define SCI0_FIFO_TX_LVL SCI_FIFO_TX0
#define SCI0_FIFO_RX_LVL SCI_FIFO_RX4
void SCI0_init();

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
void	CLA_init();
void	CPUTIMER_init();
void	DAC_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	MEMCFG_init();
void	SCI_init();
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
