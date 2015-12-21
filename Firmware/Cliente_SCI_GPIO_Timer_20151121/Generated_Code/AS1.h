/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AS1.h
**     Project     : Cliente_SCI_GPIO_Timer_20151121
**     Processor   : MC9S08SH8CFK
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 01.33, CPU db: 3.00.019
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-12-16, 23:50, # CodeGen: 23
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**         Serial channel              : SCI
**
**         Protocol
**             Init baud rate          : 19200baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : SCID      [$003F]
**             Output buffer           : SCID      [$003F]
**             Control register        : SCIC1     [$003A]
**             Mode register           : SCIC2     [$003B]
**             Baud setting reg.       : SCIBD     [$0038]
**             Special register        : SCIS1     [$003C]
**
**         Input interrupt
**             Vector name             : Vscirx
**             Priority                : 
**
**         Output interrupt
**             Vector name             : Vscitx
**             Priority                : 
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     15               |  PTB0_PIB0_RxD_ADP4
**            Output  |     14               |  PTB1_PIB1_TxD_ADP5
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         RecvChar        - byte AS1_RecvChar(AS1_TComData *Chr);
**         SendChar        - byte AS1_SendChar(AS1_TComData Chr);
**         GetCharsInRxBuf - word AS1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word AS1_GetCharsInTxBuf(void);
**         TurnTxOn        - void AS1_TurnTxOn(void);
**         TurnTxOff       - void AS1_TurnTxOff(void);
**         TurnRxOn        - void AS1_TurnRxOn(void);
**         TurnRxOff       - void AS1_TurnRxOff(void);
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
** @file AS1.h
** @version 01.33
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup AS1_module AS1 module documentation
**  @{
*/         

#ifndef __AS1
#define __AS1

/* MODULE AS1. */

#include "Cpu.h"




#ifndef __BWUserType_AS1_TError
#define __BWUserType_AS1_TError
  /*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
  typedef union {
    byte err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      bool OverRun  : 1;               /* Overrun error flag */
      bool Framing  : 1;               /* Framing error flag */
      bool Parity   : 1;               /* Parity error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Noise    : 1;               /* Noise error flag */
      bool Break    : 1;               /* Break detect */
      bool LINSync  : 1;               /* LIN synchronization error */
      bool BitError  : 1;              /* Bit error flag - mismatch to the expected value happened. */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    } errName;
  } AS1_TError;                        /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
  /*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */
#endif

#ifndef __BWUserType_AS1_TComData
#define __BWUserType_AS1_TComData
  typedef byte AS1_TComData ;          /* User type for communication. Size of this type depends on the communication data width. */
#endif



byte AS1_RecvChar(AS1_TComData *Chr);
/*
** ===================================================================
**     Method      :  AS1_RecvChar (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). This method is enabled only if the receiver property
**         is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence the
**         information about an exception in interrupt mode is returned
**         only if there is a valid character ready to be read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service> property
**                           is disabled and the <Break signal> property
**                           is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/

byte AS1_SendChar(AS1_TComData Chr);
/*
** ===================================================================
**     Method      :  AS1_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

word AS1_GetCharsInRxBuf(void);
/*
** ===================================================================
**     Method      :  AS1_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/

word AS1_GetCharsInTxBuf(void);
/*
** ===================================================================
**     Method      :  AS1_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/

__interrupt void AS1_InterruptRx(void);
/*
** ===================================================================
**     Method      :  AS1_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void AS1_InterruptTx(void);
/*
** ===================================================================
**     Method      :  AS1_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the transmit interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void AS1_InterruptError(void);
/*
** ===================================================================
**     Method      :  AS1_InterruptError (component AsynchroSerial)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


void AS1_Init(void);
/*
** ===================================================================
**     Method      :  AS1_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#define AS1_TurnRxOff()\
  (SCIC2_RE = 0x00U)
/*
** ===================================================================
**     Method      :  AS1_TurnRxOff (component AsynchroSerial)
**     Description :
**         Turns off the receiver. This method is available only if the
**         receiver property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define AS1_TurnRxOn()\
  (SCIC2_RE = 0x01U)
/*
** ===================================================================
**     Method      :  AS1_TurnRxOn (component AsynchroSerial)
**     Description :
**         Turns on the receiver. This method is available only if the
**         receiver property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define AS1_TurnTxOff()\
  (SCIC2_TE = 0x00U)
/*
** ===================================================================
**     Method      :  AS1_TurnTxOff (component AsynchroSerial)
**     Description :
**         Turns off the transmitter. This method is available only if
**         the transmitter property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define AS1_TurnTxOn()\
  (SCIC2_TE = 0x01U)
/*
** ===================================================================
**     Method      :  AS1_TurnTxOn (component AsynchroSerial)
**     Description :
**         Turns on the transmitter. This method is available only if
**         the transmitter property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END AS1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

#endif /* ifndef __AS1 */
