/* ###################################################################
**     Filename    : Events.c
**     Project     : Cliente_SCI_GPIO_Timer_20151121
**     Processor   : MC9S08SH8CFK
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-11-21, 17:38, # CodeGen: 0
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
** @version 01.02
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
void  AS1_OnError(void)
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
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  AS1_OnRxChar(void)
{
  /* Write your code here ... */
	byte received_Data;
	//byte received;
	static uint16_t i = 0;
	
	//received_Data = AS1_RecvChar(received_Data);
	AS1_RecvChar(&received_Data);
	
	if (DATA_INI == received_Data)
		i = 0;
	
	gProtocolo[i] = received_Data;
	
	i++;
	
	if (4 == i)
	{
		i = 0;
		gEstado_FW = DATOS_SCI_RECIBIDOS;
	}
	
//	if (0x51 == received_Data)
//		Led_Actividad_SetVal();
//	else
//		Led_Actividad_ClrVal();
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
void  AS1_OnTxChar(void)
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
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	static uint16_t	cambio   = 0;
	static uint16_t	tx_Timer = 0;
	static bool	toogle_Led   = 0;
	
	cambio++;
	
	if ((gLed_Actividad == cambio) && (FALSE == gLed_Funcion))
	{	
		if (toogle_Led)
		{
			Led_Actividad_PutVal(TRUE);
			toogle_Led = FALSE;
		}
		else
		{
			Led_Actividad_PutVal(FALSE);
			toogle_Led = TRUE;
		}
		cambio = 0;
	}
	
	if (cambio == 51)
		cambio = 0;
	
	if (TRUE == gWait_For_Tx)
	{
		tx_Timer++;
		
		if (gTiempoRetardo10mS == tx_Timer)
		{
			gWait_For_Tx = FALSE;
			tx_Timer = 0;
		}
	}
		
//	tx_Timer++;
//	
//	//Cada 5 segundos mandamos un character
//	if (20 >= tx_Timer)
//	{
//		//AS1_SendChar(0x50);
//		gActivar_TX = 1;
//	}
//	
//	if ((tx_Timer > 20) && (tx_Timer <=40))
//	{
//		//AS1_TurnTxOff();
//		//AS1_TurnRxOn();
//		RTS_Signal_ClrVal();
//		gActivar_TX = 2;
//	}
//	
//	if (41 == tx_Timer)
//		tx_Timer = 0;
}

/* END Events */

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
