/* ###################################################################
**     Filename    : Events.c
**     Project     : Control_Tension_ADC_PWM
**     Processor   : MC56F8006_48_LQFP
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 12:11, # CodeGen: 0
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
//#include "Global.h"
#include "SCI.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

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

	static uint16_t contador;
	
	contador++;
	if (contador == 5)
	{
		LED_ESTADO_Toggle();
		contador = 0;				
	}
}

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
void AS1_OnRxChar(void)
{
  /* Write your code here ... */
	static byte i = 0;
		
	register AS1_TComData dataRx;          /* Temporary variable for data */
	dataRx = (AS1_TComData)getReg(SCI_DATA); /* Read data from the receiver */
	
	if(SCI_Saludo_PWM == 1)
	{
		arrRx[i] = dataRx;
		
		/* Hace un eco de lo que entro */
		Enviar_Chr(arrRx[i]);
			
		i++;
		/* 7 cacteres o la 'm' reinicia el array */
		if ((i == 7) || (dataRx == 'm'))
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
