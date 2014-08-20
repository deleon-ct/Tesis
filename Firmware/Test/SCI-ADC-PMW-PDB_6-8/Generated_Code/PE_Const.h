/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Const.h
**     Project     : SCI-ADC-PMW-PDB_6-8
**     Processor   : MC56F8006_48_LQFP
**     Component   : PE_Const
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 19:32, # CodeGen: 0
**     Abstract    :
**         This component "PE_Const" contains internal definitions
**         of the constants.
**     Settings    :
**     Contents    :
**         No public methods
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
** @file PE_Const.h
** @version 01.02
** @brief
**         This component "PE_Const" contains internal definitions
**         of the constants.
*/         
/*!
**  @addtogroup PE_Const_module PE_Const module documentation
**  @{
*/         

#ifndef __PE_Const_H
#define __PE_Const_H

#ifdef __cplusplus
extern "C" {
#endif

/* Constants for detecting running mode */
#define HIGH_SPEED        0x00U        /* High speed */
#define LOW_SPEED         0x01U        /* Low speed */
#define SLOW_SPEED        0x02U        /* Slow speed */

/* Reset cause constants */
#define RSTSRC_POR        0x01U        /* Power-on reset */
#define RSTSRC_PPD        0x02U        /* Partial power down reset */
#define RSTSRC_LVDR       0x04U        /* Low voltage detect reset */
#define RSTSRC_PIN        0x08U        /* External reset bit */
#define RSTSRC_COP_LOR    0x10U        /* COP loss of reference reset */
#define RSTSRC_COP_CPU    0x20U        /* CPU time-out reset */
#define RSTSRC_SWR        0x40U        /* Software reset */

/* Memory modes */
#define INT_EXT_MODE      0x00U        /* Internal & external memory mode */
#define EXT_MODE          0x01U        /* External memory mode */

#ifdef __cplusplus
}
#endif

#endif /* _PE_Const_H */
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
