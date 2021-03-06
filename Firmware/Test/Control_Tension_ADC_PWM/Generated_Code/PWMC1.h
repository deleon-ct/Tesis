/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWMC1.h
**     Project     : Control_Tension_ADC_PWM
**     Processor   : MC56F8006_48_LQFP
**     Component   : PWMMC
**     Version     : Component 01.779, Driver 01.32, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 14:24, # CodeGen: 1
**     Abstract    :
**         This component "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this component is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
**     Settings    :
**          Component name                                 : PWMC1
**          Device                                         : PWM_Timer
**          Align                                          : center-aligned mode
**          Mode of PWM Pair 0                             : independent
**          Mode of PWM Pair 1                             : independent
**          Mode of PWM Pair 2                             : independent
**          Top-Side PWM Pair 0 Polarity                   : Positive
**          Top-Side PWM Pair 1 Polarity                   : Positive
**          Top-Side PWM Pair 2 Polarity                   : Positive
**          Bottom-Side PWM Pair 0 Polarity                : Positive
**          Bottom-Side PWM Pair 1 Polarity                : Positive
**          Bottom-Side PWM Pair 2 Polarity                : Positive
**          Write Protect                                  : no
**          Output pads                                    : Disabled
**          Synchronization output                         : Disabled
**          Synchronization window                         : Disabled
**          Enable in Wait mode                            : no
**          Enable in EnOnCE mode                          : yes
**          Reload                                         : 1
**          Half cycle reload                              : no
**          Hardware acceleration                          : Disabled
**          Frequency/period                               : 100 kHz
**          Output Frequency                               : 50 kHz
**          Same frequency in modes                        : no
**          Dead-time                                      : 0 �s
**          Dead-time 1                                    : 0 �s
**          Correction                                     : Disabled
**          Interrupt service/event                        : Disabled
**          Channel 0                                      : 
**            Channel                                      : PWMod0
**            PWM pin                                      : GPIOA0_PWM0
**            PWM pin signal                               : 
**            Duty                                         : 0 %
**            Pin PWM0 active                              : no
**            Output software control                      : no
**            PWM compare invert                           : no
**            Mask channel                                 : no
**            Mask fault 0                                 : PWM unaffected
**            Mask fault 1                                 : PWM unaffected
**            Mask fault 2                                 : PWM unaffected
**            Mask fault 3                                 : PWM unaffected
**          Channel 1                                      : Disabled
**          Channel 2                                      : Disabled
**          Channel 3                                      : Disabled
**          Channel 4                                      : Disabled
**          Channel 5                                      : Disabled
**          Fault protection                               : controlled by this component
**            Fault 0                                      : Disabled
**            Fault 1                                      : Disabled
**            Fault 2                                      : Disabled
**            Fault 3                                      : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Simulation output mode                         : PWM
**          High output value                              : 1
**          Low output value                               : 0
**     Contents    :
**         Enable           - byte PWMC1_Enable(void);
**         Disable          - byte PWMC1_Disable(void);
**         SetDuty          - byte PWMC1_SetDuty(byte Channel, PWMC1_TPWMMC_Duty Duty);
**         Load             - void PWMC1_Load(void);
**         OutputPadEnable  - void PWMC1_OutputPadEnable(void);
**         OutputPadDisable - void PWMC1_OutputPadDisable(void);
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
** @file PWMC1.h
** @version 01.32
** @brief
**         This component "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this component is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
*/         
/*!
**  @addtogroup PWMC1_module PWMC1 module documentation
**  @{
*/         

#ifndef __PWMC1
#define __PWMC1

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"

/* MODULE PWMC1. */

#ifndef __BWUserType_PWMC1_TPWMMC_Duty
#define __BWUserType_PWMC1_TPWMMC_Duty
  typedef int PWMC1_TPWMMC_Duty;       /* User type for duty. */
#endif
#ifndef __BWUserType_PWMC1_TDuty
#define __BWUserType_PWMC1_TDuty
  typedef int PWMC1_TDuty;             /* User type for duty. */
#endif
#ifndef __BWUserType_TChannels
#define __BWUserType_TChannels
  typedef struct {
    byte channel0  : 1;                                           /* Channel 0 bit */
    byte channel1  : 1;                                           /* Channel 1 bit */
    byte channel2  : 1;                                           /* Channel 2 bit */
    byte channel3  : 1;                                           /* Channel 3 bit */
    byte channel4  : 1;                                           /* channel 4 bit */
    byte channel5  : 1;                                           /* channel 5 bit */
  } TChannels;                         /* Structure contains bit informations for 6 channels, one bit for each channel. */
#endif
#ifndef __BWUserType_TChannelPairs
#define __BWUserType_TChannelPairs
  typedef struct {
    byte pair0 : 1;                                               /* PWM pair 0 */
    byte pair1 : 1;                                               /* PWM pair 1 */
    byte pair2 : 1;                                               /* PWM pair 2 */
  } TChannelPairs;                     /* 3 channel pairs represented by bit in structure. */
#endif


byte PWMC1_Enable(void);
/*
** ===================================================================
**     Method      :  PWMC1_Enable (component PWMMC)
**     Description :
**         Enable the component - it starts the signal generation.
**         Events can be disabled/enabled by <DisableEvent>
**         /<EnableEvent>.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte PWMC1_Disable(void);
/*
** ===================================================================
**     Method      :  PWMC1_Disable (component PWMMC)
**     Description :
**         Disable the component - it stops signal generation and
**         events calling. When the timer is disabled, it is still
**         possible to call method <SetOutput> to control the output
**         value on corresponding pin.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void PWMC1_SetHigh(void);
/*
** ===================================================================
**     Method      :  PWMC1_SetHigh (component PWMMC)
**
**     Description :
**         The method reconfigures the bean and its selected peripheral(s)
**         when the CPU is switched to the High speed mode. The method is 
**         called automatically as s part of the CPU SetHighSpeed method.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void PWMC1_Init(void);
/*
** ===================================================================
**     Method      :  PWMC1_Init (component PWMMC)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

byte PWMC1_SetDuty(byte Channel,PWMC1_TPWMMC_Duty Duty);
/*
** ===================================================================
**     Method      :  PWMC1_SetDuty (component PWMMC)
**     Description :
**         Setting duty (value) register(s) of selected channel. The
**         value is loaded after calling <Load> method.
**         
**         [ Version specific information for Freescale 56800/E and
**         HC08 and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         [ Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Duty register(s) value is not affected during speed mode
**         change. It should be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - Channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Duty            - Duty value for selected channel.
**                           
**                           Writing a number less than or equal to 0
**                           causes the PWM to be off for the entire PWM
**                           period. Writing a number greater than or
**                           equal to the 15 bit (12-bit on HC08MR32 CPU)
**                           modulus causes the PWM to be on for the
**                           entire PWM period.
**                           
**                           [ Version specific information for
**                           Freescale 56800/E derivatives - eFlexPWM
**                           device ] 
**                           Parameter duty is an unsigned value. 
**                           - _edge-aligned mode:_ parameter value is
**                           written into PWM clear-edge
**                           (eFlexPWM_SMn_VALx) register; PWM set-edge
**                           (eFlexPWM_SMn_VALx) register is not
**                           affected (zero value assumed); where x = 2,
**                           4. 
**                           - _center-aligned mode:_ parameter value is
**                           split between PWM set-edge
**                           (eFlexPWM_SMn_VALx) and PWM clear-edge
**                           (eFlexPWM_SMn_VAL(x+1)) registers; where x
**                           = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_NOTAVAIL - Channel is disabled 
**                           - ERR_RANGE - Parameter Channel is out of
**                           range
** ===================================================================
*/

#define PWMC1_Load() setRegBit(PWM_CTRL,LDOK)
/*
** ===================================================================
**     Method      :  PWMC1_Load (component PWMMC)
**     Description :
**         Apply last setting of the methods <SetDuty>, <SetDutyPercent>,
**         both <SetRatio*>, <SetPeriod> and <SetPrescaler>.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define PWMC1_OutputPadEnable() setRegBit(PWM_OUT,PAD_EN)
/*
** ===================================================================
**     Method      :  PWMC1_OutputPadEnable (component PWMMC)
**     Description :
**         Method enables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define PWMC1_OutputPadDisable() clrRegBit(PWM_OUT,PAD_EN)
/*
** ===================================================================
**     Method      :  PWMC1_OutputPadDisable (component PWMMC)
**     Description :
**         Method disables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END PWMC1. */

#endif /* ifndef __PWMC1 */
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
