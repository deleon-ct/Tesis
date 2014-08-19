/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Inhr6.h
**     Project     : SCI-ADC-PWM-PDB_6-8
**     Processor   : MC56F8006_48_LQFP
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.20, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-06, 14:03, # CodeGen: 1
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       29            |  GPIOA5_PWM5_FAULT2_EXT_SYNC_TIN3
**             ----------------------------------------------------
**
**         Port name                   : GPIOA
**
**         Bit number (in port)        : 5
**         Bit mask of the port        : 0020
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_A_DR [F181]
**         Port control register       : GPIO_A_DDR [F182]
**         Port function register      : GPIO_A_PER [F183]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal     - bool Inhr6_GetVal(void);
**         PutVal     - void Inhr6_PutVal(bool Val);
**         ClrVal     - void Inhr6_ClrVal(void);
**         SetVal     - void Inhr6_SetVal(void);
**         NegVal     - void Inhr6_NegVal(void);
**         ConnectPin - void Inhr6_ConnectPin(void);
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
** @file Inhr6.h
** @version 01.20
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup Inhr6_module Inhr6 module documentation
**  @{
*/         

#ifndef __Inhr6_H
#define __Inhr6_H

/* MODULE Inhr6. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define Inhr6_PIN_MASK          ((byte)0x20) /* Pin mask */


/*
** ===================================================================
**     Method      :  Inhr6_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Inhr6_GetVal() ((bool)(getRegBits(GPIO_A_DR,Inhr6_PIN_MASK)))

/*
** ===================================================================
**     Method      :  Inhr6_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Inhr6_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Inhr6_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr6_ClrVal() (clrRegBits(GPIO_A_DR,Inhr6_PIN_MASK))

/*
** ===================================================================
**     Method      :  Inhr6_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr6_SetVal() (setRegBits(GPIO_A_DR,Inhr6_PIN_MASK))

/*
** ===================================================================
**     Method      :  Inhr6_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr6_NegVal() (changeRegBits(GPIO_A_DR,Inhr6_PIN_MASK))

/*
** ===================================================================
**     Method      :  Inhr6_ConnectPin (component BitIO)
**     Description :
**         This method reconnects the selected pin for this component.
**         This method is available only for the CPU derivatives and
**         peripherals that support the runtime pin sharing with other
**         internal on-chip peripherals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr6_ConnectPin() (clrRegBits(GPIO_A_PER,Inhr6_PIN_MASK))


/* END Inhr6. */

#endif /* __Inhr6_H*/
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
