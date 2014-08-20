/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PDB.h
**     Project     : Control_Tension_ADC_PWM
**     Processor   : MC56F8006_48_LQFP
**     Component   : Init_PDB
**     Version     : Component 01.005, Driver 01.00, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 14:24, # CodeGen: 1
**     Abstract    :
**         This bean provides initialization of the Programable Dealy Block (PDB).
**         The primary function of the programmable delay block is simply to provide
**         a controllable delay from the PWM SYNC output to the sample trigger input
**         of the programmable gain amplifiers (PGA) and ADCs.
**         An alternate function of the PDB is to generate timing for comparator (HSCMP) sampling windows,
**         or to generate a sampling/filter clock that can be used by the comparator.
**     Settings    :
**          Bean name                                      : PDB
**          Device                                         : PDB
**          Settings                                       : 
**            Trigger A                                    : 
**              Output enable                              : Disabled
**              Output select                              : OneShot mode
**              Delay                                      : 10.000 us
**              Delay                                      : 320
**            Trigger B                                    : 
**              Output enable                              : Disabled
**              Output select                              : bypassed to input
**              Delay                                      : 0.000 us
**              Delay                                      : 0
**            Counter                                      : 
**              Counter speed                              : 32000 kHz
**              Clock prescaler select                     : clock/1
**              Continuous mode                            : Disabled
**              Reset period                               : 2047.969 us
**              Modulus                                    : 65535
**          Pins                                           : 
**            Input trigger select                         : PWM_reload_sync
**            Input trigger select signal                  : 
**          Initialization                                 : 
**            Enable peripheral clock                      : yes
**            Call Init method                             : yes
**     Contents    :
**         Init - void PDB_Init(void);
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
** @file PDB.h
** @version 01.00
** @brief
**         This bean provides initialization of the Programable Dealy Block (PDB).
**         The primary function of the programmable delay block is simply to provide
**         a controllable delay from the PWM SYNC output to the sample trigger input
**         of the programmable gain amplifiers (PGA) and ADCs.
**         An alternate function of the PDB is to generate timing for comparator (HSCMP) sampling windows,
**         or to generate a sampling/filter clock that can be used by the comparator.
*/         
/*!
**  @addtogroup PDB_module PDB module documentation
**  @{
*/         

#ifndef __PDB_H
#define __PDB_H

/* MODULE PDB. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"




void PDB_Init(void);
/*
** ===================================================================
**     Method      :  PDB_Init (component Init_PDB)
**     Description :
**         This method initializes registers of the PDB module
**         according to this Peripheral Initialization Bean settings.
**         Call this method in the user code to initialize the module.
**         By default, the method is called by PE automatically; see
**         <Call Init method> property of the bean for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END PDB. */

#endif
/* ifndef __PDB_H */
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