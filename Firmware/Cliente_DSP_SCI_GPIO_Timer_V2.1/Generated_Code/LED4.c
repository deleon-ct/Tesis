/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LED4.c
**     Project     : Cliente_DSP_SCI_GPIO_Timer_V2.1
**     Processor   : MC56F8006_48_LQFP
**     Component   : DSC_LED
**     Version     : Component 01.000, Driver 01.06, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2015-12-19, 10:51, # CodeGen: 0
**     Abstract    :
**          This bean provide methods for driving of LED device.
**          Methods On, Off, Set and Toggle (or only initialization code)
**          could be used to drive it. Output value, defined by Init.
**          value property, is used for initialization implicitly.
**          It is not necessary to use any method explicitly in start up.
**          Method Status return current status of the LED device.
**          LED drivers without output inverter are supported
**          via Inverted value property.
**     Settings    :
**          Output PIN                                     :GPIOA2_PWM2
**          Initialize Value                               :Off
**          Inverted Value                                 :no
**     Contents    :
**         On         - void LED4_On(void);
**         Off        - void LED4_Off(void);
**         Toggle     - void LED4_Toggle(void);
**         Set        - void LED4_Set(bool Output);
**         Status     - bool LED4_Status(void);
**         ConnectPin - void LED4_ConnectPin(void);
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
** @file LED4.c
** @version 01.06
** @brief
**          This bean provide methods for driving of LED device.
**          Methods On, Off, Set and Toggle (or only initialization code)
**          could be used to drive it. Output value, defined by Init.
**          value property, is used for initialization implicitly.
**          It is not necessary to use any method explicitly in start up.
**          Method Status return current status of the LED device.
**          LED drivers without output inverter are supported
**          via Inverted value property.
*/         
/*!
**  @addtogroup LED4_module LED4 module documentation
**  @{
*/         

/* MODULE LED4. */

#include "LED4.h"

/*
** ===================================================================
**     Method      :  LED4_On (component DSC_LED)
**     Description :
**         Switch ON the LED device
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_On(void)
{
  // This function is implemented as a macro
}
*/

/*
** ===================================================================
**     Method      :  LED4_Off (component DSC_LED)
**     Description :
**         Switch OFF the LED device
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_Off(void)
{
  // This function is implemented as a macro
}
*/

/*
** ===================================================================
**     Method      :  LED4_Toggle (component DSC_LED)
**     Description :
**         Toggle the LED device value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_Toggle(void)
{
  // This function is implemented as a macro
}
*/

/*
** ===================================================================
**     Method      :  LED4_Set (component DSC_LED)
**     Description :
**         Put the specified value to the LED
**     Parameters  :
**         NAME            - DESCRIPTION
**         Output          - Set LED status (ON/OFF) accordant
**                           with the 'Output' value
**                           <true> - Turn the LED ON
**                           <false> - Turn the LED OFF
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_Set(bool Output)
{
  // This function is implemented as a macro
}
*/

/*
** ===================================================================
**     Method      :  LED4_Status (component DSC_LED)
**     Description :
**         Return the last written value of the LED device
**     Parameters  : None
**     Returns     :
**         ---             - The last written value of the LED device.
**                           <true> - The LED is ON
**                           <false> - The LED is OFF
** ===================================================================
*/
/*
bool LED4_Status(void)
{
  // This function is implemented as a macro
}
*/

/*
** ===================================================================
**     Method      :  LED4_ConnectPin (component DSC_LED)
**     Description :
**         This method reconnects selected pin in this bean. This
**         method is available only for CPU derivatives and peripherals
**         that support runtime pin sharing with other internal on-chip
**         peripherals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_ConnectPin(void)
{
  // This function is implemented as a macro
}
*/

/* END LED4. */

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
