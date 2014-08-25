/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BTN1.h
**     Project     : Prueba_PWM1
**     Processor   : MC56F8006_48_LQFP
**     Component   : Button
**     Version     : Component 01.026, Driver 01.14, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-25, 09:25, # CodeGen: 1
**     Abstract    :
**          This bean provides service for Buttons with inactivity timer.
**          Method GetVal() return the actual (boolean) status of the button.
**          Returned value 'TRUE' is used for 'pressed button' indication.
**          The value 'FALSE' correspond to 'released button'.
**          OnButton event is called after button pressed.
**          The bean contain button inactivity feature to eliminate multiple-call
**          of  OnButton event due the mechanical oscillations of contacts.
**     Settings    :
**         Bean name                   : BTN1
**         Used pin                    : GPIOB3_ANA3_ANB3_PWM5_MOSI_TIN3_CMP1_OUT
**         Button inactivity           : Disabled
**         Initialization                                      
**           Bean enabled in init.     : yes
**           Events enabled in init    : yes
**     Contents    :
**         GetVal - byte BTN1_GetVal(bool *Status);
**         Init   - void BTN1_Init(void);
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
** @file BTN1.h
** @version 01.14
** @brief
**          This bean provides service for Buttons with inactivity timer.
**          Method GetVal() return the actual (boolean) status of the button.
**          Returned value 'TRUE' is used for 'pressed button' indication.
**          The value 'FALSE' correspond to 'released button'.
**          OnButton event is called after button pressed.
**          The bean contain button inactivity feature to eliminate multiple-call
**          of  OnButton event due the mechanical oscillations of contacts.
*/         
/*!
**  @addtogroup BTN1_module BTN1 module documentation
**  @{
*/         

#ifndef __BTN1
#define __BTN1

/* MODULE BTN1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "Inhr1.h"

#include "Cpu.h"


void Inhr1_OnInterrupt(void);

byte BTN1_GetVal(bool *Status);
/*
** ===================================================================
**     Method      :  BTN1_GetVal (component Button)
**     Description :
**         Return actual status of the button.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Status          - Pointer to current button value.
**                           TRUE - Button is pressed
**                           FALSE - Button is not pressed
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
** ===================================================================
*/

void BTN1_Init(void);
/*
** ===================================================================
**     Method      :  BTN1_Init (component Button)
**     Description :
**         Initialization of the bean.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END BTN1. */

#endif /* ifndef __BTN1 */
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
