/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AS1.c
**     Project     : Control_Tension_ADC_PWM
**     Processor   : MC56F8006_48_LQFP
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 02.07, CPU db: 3.00.209
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 17:23, # CodeGen: 3
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
**             Init baud rate          : 57600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : SCI_DATA  [F0E4]
**             Output buffer           : SCI_DATA  [F0E4]
**             Control register        : SCI_CTRL1 [F0E1]
**             Mode register           : SCI_CTRL1 [F0E1]
**             Baud setting reg.       : SCI_RATE  [F0E0]
**
**         Input interrupt
**             Vector name             : INT_SCI_Rx_Full_Over_Error
**             Priority                : 0
**
**         Output interrupt
**             Vector name             : INT_SCI_Tx_Empty_Idle
**             Priority                : 0
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     1                |  GPIOB6_ANA13_SDA_RXD_CMP0_P2_CLKIN
**            Output  |     3                |  GPIOB7_ANA11_SCL_TXD_CMP2_M3
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         RecvChar        - byte AS1_RecvChar(AS1_TComData *Chr);
**         SendChar        - byte AS1_SendChar(AS1_TComData Chr);
**         GetCharsInRxBuf - word AS1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word AS1_GetCharsInTxBuf(void);
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
** @file AS1.c
** @version 02.07
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

/* MODULE AS1. */

#include "AS1.h"
#include "Events.h"


#define OVERRUN_ERR      0x01U         /* Overrun error flag bit    */
#define FRAMING_ERR      0x02U         /* Framing error flag bit    */
#define PARITY_ERR       0x04U         /* Parity error flag bit     */
#define CHAR_IN_RX       0x08U         /* Char is in RX buffer      */
#define FULL_TX          0x10U         /* Full transmit buffer      */
#define RUNINT_FROM_TX   0x20U         /* Interrupt is in progress  */
#define FULL_RX          0x40U         /* Full receive buffer       */
#define NOISE_ERR        0x80U         /* Noise error flag bit      */
#define IDLE_ERR         0x0100U       /* Idle character flag bit   */
#define BREAK_ERR        0x0200U       /* Break detect              */
#define COMMON_ERR       0x0800U       /* Common error of RX       */

static word SerFlag;                   /* Flags for serial communication */
                                       /* Bits: 0 - OverRun error */
                                       /*       1 - Framing error */
                                       /*       2 - Parity error */
                                       /*       3 - Char in RX buffer */
                                       /*       4 - Full TX buffer */
                                       /*       5 - Running int from TX */
                                       /*       6 - Full RX buffer */
                                       /*       7 - Noise error */
                                       /*       8 - Idle character  */
                                       /*       9 - Break detected  */
                                       /*      10 - Unused */
                                       /*      11 - Unused */
static AS1_TComData BufferRead;        /* Input char for SCI communication */

/*
** ===================================================================
**     Method      :  HWEnDi (component AsynchroSerial)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of the Enable and 
**         Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  getReg(SCI_STAT);                    /* Reset interrupt request flags */
  setRegBits(SCI_CTRL1, (SCI_CTRL1_TE_MASK | SCI_CTRL1_RE_MASK | SCI_CTRL1_RFIE_MASK | SCI_CTRL1_REIE_MASK)); /* Enable device */
}

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
**         Version specific information for Freescale 56800 derivatives
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         receiver is configured to use DMA controller then this
**         method only sets the selected DMA channel. Then the status
**         of the DMA transfer can be checked using GetCharsInRxBuf
**         method. See an example of a typical usage for details about
**         the communication using DMA.
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
**                           Version specific information for Freescale
**                           56800 derivatives 
**                           DMA mode:
**                           If DMA controller is available on the
**                           selected CPU and the receiver is configured
**                           to use DMA controller then only ERR_OK,
**                           ERR_RXEMPTY, and ERR_SPEED error code can
**                           be returned from this method.
** ===================================================================
*/
byte AS1_RecvChar(AS1_TComData *Chr)
{
  register byte Result = ERR_OK;       /* Return error code */

  if ((SerFlag & CHAR_IN_RX) == 0x00U) { /* Is any char in RX buffer? */
    return ERR_RXEMPTY;                /* If no then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  *Chr = BufferRead;                   /* Received char */
  Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR))? ERR_COMMON : ERR_OK);
  SerFlag &= (word)~(word)(OVERRUN_ERR|COMMON_ERR|CHAR_IN_RX); /* Clear all errors in the status variable */
  ExitCritical();                      /* Enable global interrupts */
  return Result;                       /* Return error code */
}

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
**         Version specific information for Freescale 56800 derivatives
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         transmitter is configured to use DMA controller then this
**         method only sets selected DMA channel. Then the status of
**         the DMA transfer can be checked using GetCharsInTxBuf method.
**         See an example of a typical usage for details about
**         communication using DMA.
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
byte AS1_SendChar(AS1_TComData Chr)
{
  if ((SerFlag & FULL_TX) != 0x00U) {  /* Is any char is in TX buffer */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  getReg(SCI_STAT);                    /* Reset interrupt request flags */
  setReg(SCI_DATA, Chr);               /* Store char to transmitter register */
  setRegBit(SCI_CTRL1, TEIE);          /* Enable transmit interrupt */
  SerFlag |= (FULL_TX);                /* Set the flag "full TX buffer" */
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS1_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**         Version specific information for Freescale 56800 derivatives
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         receiver is configured to use DMA controller then this
**         method returns the number of characters in the receive
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word AS1_GetCharsInRxBuf(void)
{
  return (word)(((SerFlag & CHAR_IN_RX) != 0x00U)? 1 : 0); /* Return number of chars in receive buffer */
}

/*
** ===================================================================
**     Method      :  AS1_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**         Version specific information for Freescale 56800 derivatives
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         transmitter is configured to use DMA controller then this
**         method returns the number of characters in the transmit
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word AS1_GetCharsInTxBuf(void)
{
  return (word)(((SerFlag & FULL_TX) != 0x00U)? 1 : 0); /* Return number of chars in the transmitter buffer */
}

/*
** ===================================================================
**     Method      :  AS1_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_ERROR    0x01U
#define ON_FULL_RX  0x02U
#define ON_RX_CHAR  0x04U
#pragma interrupt alignsp saveall
void AS1_InterruptRx(void)
{
  register AS1_TComData Data;          /* Temporary variable for data */
  register word OnFlags = 0x00U;       /* Temporary variable for flags */
  register word StatReg = getReg(SCI_STAT); /* Read status register */

  if ((StatReg & (SCI_STAT_OR_MASK|SCI_STAT_NF_MASK|SCI_STAT_FE_MASK|SCI_STAT_PF_MASK)) != 0x00U) { /* Is any error flag set? */
    setReg(SCI_STAT, 0x00U);           /* Reset error request flags */
    if(StatReg & (SCI_STAT_OR_MASK|SCI_STAT_NF_MASK|SCI_STAT_FE_MASK|SCI_STAT_PF_MASK)) { /* Is an error detected? */
      SerFlag |= COMMON_ERR;           /* If yes then set an internal flag */
    }
    AS1_OnError();                     /* If yes then invoke user event */
  }
  if ((StatReg & SCI_STAT_RDRF_MASK) != 0x00U) { /* Is the receiver interrupt flag set? */
    Data = (AS1_TComData)getReg(SCI_DATA); /* Read data from the receiver */
    if(StatReg & (SCI_STAT_OR_MASK)) { /* Is HW overrun error detected? */
      setReg(SCI_STAT, 0U);            /* Reset error request flags */
      SerFlag |= (OVERRUN_ERR);        /* Set flag OVERRUN_ERR */
      OnFlags |= (ON_ERROR);           /* Set flag "OnError" */
    }
    if ((SerFlag & CHAR_IN_RX) == 0x00U) { /* Is SW overrun detected? */
      BufferRead = Data;
      OnFlags |= (ON_RX_CHAR);         /* Set flag "OnRxChar" */
    }
    else {
      SerFlag |= OVERRUN_ERR;          /* Set flag OVERRUN_ERR */
      OnFlags |= ON_ERROR;             /* Set flag "OnError" */
    }
    SerFlag |= CHAR_IN_RX;             /* Set flag "char in RX buffer" */
    if ((OnFlags & ON_ERROR) != 0x00U) { /* Was error flag detect? */
      AS1_OnError();                   /* If yes then invoke user event */
    }
    if ((OnFlags & ON_RX_CHAR) != 0x00U) { /* Is OnRxChar flag set? */
      AS1_OnRxChar();                  /* If yes then invoke user event */
    }
  }
}

/*
** ===================================================================
**     Method      :  AS1_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_FREE_TX  0x01U
#define ON_TX_CHAR  0x02U
#pragma interrupt alignsp saveall
void AS1_InterruptTx(void)
{
  register word OnFlags = 0x00U;       /* Temporary variable for flags */

  if ((SerFlag & FULL_TX) != 0x00U) {  /* Is any char already present in the transmit buffer? */
    OnFlags |= ON_TX_CHAR;             /* Set flag "OnTxChar" */
  }
  SerFlag &= (word)~(word)(FULL_TX);   /* Reset flag "full TX buffer" */
  clrRegBit(SCI_CTRL1, TEIE);          /* Disable transmit interrupt */
  if ((OnFlags & ON_TX_CHAR) != 0x00U) { /* Is flag "OnTxChar" set? */
    AS1_OnTxChar();                    /* If yes then invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  AS1_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AS1_Init(void)
{
  SerFlag = 0x00U;                     /* Reset flags */
  /* SCI_CTRL1: LOOP=0,SWAI=0,RSRC=0,M=0,WAKE=0,POL=0,PE=0,PT=0,TEIE=0,TIIE=0,RFIE=0,REIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  setReg(SCI_CTRL1, 0x00U);            /* Set the SCI configuration */
  /* SCI_RATE: SBR=0x22,FRAC_SBR=6 */
  setReg(SCI_RATE, 0x0116U);           /* Set prescaler bits */
  HWEnDi();                            /* Enable/disable device according to status flags */
}


/* END AS1. */


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
