/* ###################################################################
**     Filename    : Events.c
**     Project     : Cliente_DSP_SCI_GPIO_Timer
**     Processor   : MC56F8006_48_LQFP
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2015-11-24, 22:57, # CodeGen: 0
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
#include "Globales.h"

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
	
	static UInt16 cont_LedAct = 0;
	static UInt16 cont_TX = 0;
	static UInt16 cont_Btn = 0;
	static UInt16 cont_TimeOut = 0;
	
	if (TRUE == gWait_For_Tx)
	{
		cont_TX++;
		
		// Este retardo se modifica de acuerdo al momento de envio en el que esté.
		if (gTiempoRetardo10mS == cont_TX)
		{
			gWait_For_Tx = FALSE;
			cont_TX = 0;
		}
	}
	
	if (TRUE == gWait_For_Btn)
	{
		cont_Btn++;
		
		// Retardo de 30mS aprox.
		if (3 == cont_Btn)
		{
			gWait_For_Btn = FALSE;
			gEstado_FW = TRANSMISION;
			cont_Btn = 0;
		}
	}
	
//	if (TRUE == gTimeOut_Func)
//	{
//		cont_TimeOut++;
//		
//		// Retardo de 5S aprox.
//		if (500 == cont_TimeOut)
//		{
//			//gWait_For_Btn = FALSE;
//			//gEstado_FW = TRANSMISION;
//			gTimeOut_Func = FALSE;
//			
//			
//			LED_CLIENTE_Off();
//			LED_PC_Off();
//			cont_TimeOut = 0;					
//		}
//	}
	
	// On-Off Led de actividad cada 500mS aprox.
	cont_LedAct++;
	
	if (50 == cont_LedAct)
	{
		LED_Act_Toggle();
		cont_LedAct = 0;
	}
	
}

/*
** ===================================================================
**     Event       :  btnSEND_OnButton (module Events)
**
**     Component   :  btnSEND [Button]
**     Description :
**         This event is called when the button is pressed.
**         If button inactivity feature (advanced view) is enabled,
**         then the next OnButton event is not generated during dead
**         time.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void btnSEND_OnButton(void)
{
  /* Write your code here ... */
	
	
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
	/* Write your code here ... */
	byte received_Data;
	//UInt16 received_Data;
	//byte received;
	static UInt16 i = 0;
	
	//received_Data = AS1_RecvChar(received_Data);
	AS1_RecvChar(&received_Data);
	
	if (DATA_INI == received_Data)
		i = 0;
	
	gProtocolo[i] = received_Data;
			
	i++;
	
	
	
	if (4 == i)
	{
		i = 0;
		gEstado_FW = RECEPCION;		
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
**     Event       :  btnSending_OnButton (module Events)
**
**     Component   :  btnSending [Button]
**     Description :
**         This event is called when the button is pressed.
**         If button inactivity feature (advanced view) is enabled,
**         then the next OnButton event is not generated during dead
**         time.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void btnSending_OnButton(void)
{
  /* Write your code here ... */
	gActivarTX = TRUE;	
	gWait_For_Btn = TRUE;
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
