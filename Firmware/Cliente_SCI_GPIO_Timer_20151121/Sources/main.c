/* ###################################################################
**     Filename    : main.c
**     Project     : Cliente_SCI_GPIO_Timer_20151121
**     Processor   : MC9S08SH8CFK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-11-21, 17:38, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
**         
**         ID de este Esclavo:
**         DATA_ID20		0x74
**         
**         v1.1 - 20/12/2015
**         Se aggregó un IF en el evento del recepcion de datos
**         para que cada vez que se reciba un caracter DATA_INI
**         el indice i sea igual a cero.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Led_Actividad.h"
#include "AS1.h"
#include "TI1.h"
#include "RTS_Signal.h"
#include "Rele_N.h"
#include "Rele_M.h"
#include "Rele_B.h"
#include "Rele_A.h"
#include "Funciones.h"

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Globales.h"

//Variables globales
uint16_t 	gActivar_TX = 0;
//uint16_t 	gProtocolo[4];
byte 		gProtocolo[4];
bool 		gProtocolo_Listo = FALSE;
uint16_t 	gEstado_FW = ESPERANDO_DATOS_SCI;
uint16_t 	gLed_Actividad = LENTO;
bool		gLed_Funcion = FALSE;
bool 		gWait_For_Tx = FALSE;	
uint16_t 	gTiempoRetardo10mS = 0;


/* User includes (#include below this line is not maintained by Processor Expert) */

void Configurar_SCI(void);


void Configurar_SCI(void)
{
	//AS1_TurnRxOff();
	//AS1_TurnTxOn();
	//RTS_Signal_SetVal();
	
	AS1_TurnRxOn();
	RTS_Signal_ClrVal();
}

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  Configurar_SCI();
  
  for(;;)
  {
	  gLed_Actividad = LENTO;
	  
	  switch(gEstado_FW)
	  {
		  case ESPERANDO_DATOS_SCI:
		  {
			  break;
		  }
		  case DATOS_SCI_RECIBIDOS:
		  {
			  gLed_Actividad = RAPIDO;
			  
			  if (TRUE == Control_Datos_SCI(gProtocolo))
			  {
				  //gEstado_FW = REALIZAR_FUNCION_1;
				  Confirma_Recepcion(TRUE);
			  }
			  else
			  {
				  Borrar_gProtocolo();
				  gEstado_FW = ESPERANDO_DATOS_SCI;
			  }
			  break;
		  }
		  case REALIZAR_FUNCION_1:
		  {			  
			  gLed_Funcion = TRUE;
			  Ejecutar_Funcion(gProtocolo[PROT_FUNC]);
			  gEstado_FW = ESPERANDO_DATOS_SCI;
			  Borrar_gProtocolo();
			  break;
		  }
		  default:{}
	  }
  }
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
