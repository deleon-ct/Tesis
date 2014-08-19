/* ###################################################################
**     Filename    : Events.c
**     Project     : SCI-ADC-PWM-PDB_6-8
**     Processor   : MC56F8006_48_LQFP
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-06, 13:21, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "SCI.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  AS1_OnError (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void AS1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnRxChar (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**         Version specific information for Freescale 56800 derivatives
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         receiver is configured to use DMA controller then this event
**         is disabled. Only OnFullRxBuf method can be used in DMA mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
extern byte arrRx[CANTRXOK];
void AS1_OnRxChar(void)
{
  /* Write your code here ... */
	static byte i = 0;
	
	register AS1_TComData dataRx;          /* Temporary variable for data */
	dataRx = (AS1_TComData)getReg(SCI_DATA); /* Read data from the receiver */
	
	if(SCI_Saludo_PWM == 1)
	{
		arrRx[i] = dataRx;
		
		setRegBit(SCI_CTRL1, TE);
		getReg(SCI_STAT);
		setReg(SCI_DATA, arrRx[i]);
		while(!(SCI_STAT & SCI_STAT_TIDLE_MASK)){}
		clrRegBit(SCI_CTRL1, TE);
			
		i++;
		
		if ((i == 7) || (dataRx == 'm'))
			i = 0;
	}
	else if (SCI_Saludo_PWM == 2)
	{		
		arrRx[i] = dataRx;
		
		if ((arrRx[0] == 'q') && (arrRx[1] == 'w') && (arrRx[2] == 'e'))
		{
			enviar_Datos_SCI_PWM();
			LED_ADC_On();
			LED_TEST_On();
			LED_SCI_On();
		}
		
		i++;
		if ((i == 3) || (dataRx == 'm'))
			i = 0;
	}
}

/*
** ===================================================================
**     Event       :  AS1_OnTxChar (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void AS1_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
  if(led_test_On == 1)
	LED_ADC_Toggle();	
}

/* END Events */

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
