/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM_Timer.h
**     Project     : Prueba_PWM1
**     Processor   : MC56F8006_48_LQFP
**     Component   : Init_PWM
**     Version     : Component 01.295, Driver 01.23, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-26, 08:51, # CodeGen: 11
**     Abstract    :
**         This "Init_PWM" Peripheral Inspector implements the
**         Puls Width Modulator module (PWM), basic initialization
**         and settings.
**     Settings    :
**         PWM module                  : PWM_Timer
**
**         Clock setting
**             PWM prescaler           : 1
**             Counter modulo          : 960
**             Dead time value         : 0
**             Reload frequency        : 1
**             PWM frequency           : 50 kHz
**             PWM period              : 20 us
**             PWM deadtime            : 0 us
**
**         Interrupts
**             Reload interrupt        : Disabled
**
**             Fault 0 interrupt       : Disabled
**             Fault 1 interrupt       : Disabled
**             Fault 2 interrupt       : Disabled
**             Fault 3 interrupt       : Disabled
**
**         HW acceleration             : Disabled
**
**         Correction
**             Method                  : Manual correction or no correction
**             Internal current ctrl.0 : Top
**             Internal current ctrl.1 : Top
**             Internal current ctrl.2 : Top
**
**         Channel settings
**             Alignment               : Center-aligned mode
**             Channels 0-1
**               Mode of PWM           : Independent
**               Phase shift PWM.      : Disabled
**               Top output polarity   : Positive
**               Bottom output polar.  : Positive
**             Channels 2-3
**               Mode of PWM channels  : Independent
**               Phase shift PWM.      : Disabled
**               Top output polarity   : Positive
**               Bottom output polar.  : Positive
**             Channels 4-5
**               Mode of PWM channels  : Independent
**               Phase shift PWM.      : Disabled
**               Top output polarity   : Positive
**               Bottom output polar.  : Positive
**
**         Enabled in wait mode        : no
**         Enabled in EnOnCE mode      : yes
**         Write protect               : no
**         Output pads                 : Disabled
**         Half cycle reload           : no
**
**         Channel 0
**             PWM Pin                 : GPIOA0_PWM0
**             Enable software control : yes
**             Channel masked          : no
**
**         Channel 3
**             PWM Pin                 : GPIOA3_PWM3_TXD_EXTAL
**             Enable software control : no
**             Channel masked          : no
**         Fault 0
**             clearing mode           : Manual
**             fault polarity          : Positive
**             glitch stretch          : Disabled
**         Fault 1
**             clearing mode           : Manual
**             fault polarity          : Positive
**             glitch stretch          : Disabled
**         Fault 2
**             clearing mode           : Manual
**             fault polarity          : Positive
**             glitch stretch          : Disabled
**         Fault 3
**             clearing mode           : Manual
**             fault polarity          : Positive
**             glitch stretch          : Disabled
**
**         Synchronization
**             output                  : Disabled
**             windowed input          : Disabled
**
**         Initialization
**             Call Init method        : yes
**             Enable peripheral clock : yes
**             Load values after init  : yes
**             Enable PWM generator    : yes
**
**     Contents    :
**         Init - void PWM_Timer_Init(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PWM_Timer.h
** @version 01.23
** @brief
**         This "Init_PWM" Peripheral Inspector implements the
**         Puls Width Modulator module (PWM), basic initialization
**         and settings.
*/         
/*!
**  @addtogroup PWM_Timer_module PWM_Timer module documentation
**  @{
*/         

#ifndef __PWM_Timer
#define __PWM_Timer

/* MODULE PWM_Timer. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"

/* PESL device mapping  */
#define PWM_Timer_DEVICE PWM

void PWM_Timer_Init(void);
/*
** ===================================================================
**     Method      :  PWM_Timer_Init (component Init_PWM)
**     Description :
**         Peripheral Initialization Beans provide a low-level
**         hardware approach to initialize registers of the
**         peripheral module. They are intended for experienced
**         users.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END PWM_Timer. */

#endif /* ifndef __PWM_Timer */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
