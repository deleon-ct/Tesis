/* ###################################################################
**     Filename    : main.c
**     Project     : Cliente_DSP_SCI_GPIO_Timer
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2015-11-24, 22:57, # CodeGen: 0
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
** @version 01.16
** @brief
**         19/12/15
**         Versión 2.1 envía y recibe comandos hacia y desde los 
**         clientes.
**         Versión de FW de clientes = Cliente_SCI_GPIO_Timer_20151121 
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Inhr4.h"
#include "LED_Act.h"
#include "Inhr1.h"
#include "LED2.h"
#include "Inhr5.h"
#include "LED3.h"
#include "Inhr6.h"
#include "LED4.h"
#include "Inhr7.h"
#include "LED_PC.h"
#include "Inhr2.h"
#include "LED_CLIENTE.h"
#include "Inhr3.h"
#include "TI1.h"
#include "RTS_Signal.h"
#include "AS1.h"
#include "btnSending.h"
#include "Globales.h"
#include "Funciones.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


bool 	gActivarTX   = FALSE;
bool 	gWait_For_Tx = FALSE;
bool	gWait_For_Btn = FALSE;
bool	gTimeOut_Func = FALSE;
UInt16  contador_Cambio = 0;
UInt16  gEstado_FW = IDLE;
UInt16	gEstado_Funcion = IDLE;
UInt16 	gProtocolo[4];
UInt16	gContador_Clientes = 0;
UInt16 	gTiempoRetardo10mS = 0;
UInt16	gEstado_Confirmacion = TRANSMISION;

UInt16  gClientes_ID[4]		= {DATA_ID17  , DATA_ID18  , DATA_ID19  , DATA_ID20};
UInt16  gClientes_Func[4] 	= {DATA_RELE_A, DATA_RELE_B, DATA_RELE_M, DATA_RELE_N};
UInt16  gClientes_Func_Off[4] 	= {DATA_RELE_OFF, DATA_RELE_OFF, DATA_RELE_OFF, DATA_RELE_OFF};

void Configuracion_Arranque(void)
{	
	//Configuración de SCI
	AS1_TurnRxOn();
	RTS_Signal_ClrVal();
	
	//Configuracion Leds
	LED2_Off();
	LED3_Off();
	LED4_Off();
	LED_PC_Off();
	LED_CLIENTE_Off();
}

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  
  //Recepción activa
  Configuracion_Arranque();

  //Borra el arreglo de comunicación
  Borrar_gProtocolo();
  
  for(;;)
  {
	  switch(gEstado_FW)
	  {
	  	  case IDLE:
	  	  {
	  		  break;
	  	  }
	  	  case TRANSMISION:
	  	  {
	  		  break;
	  	  }
	  	  case RECEPCION:
	  	  {
	  		  if (TRUE == Control_Datos_SCI(gProtocolo))
			  {
				  
	  			  if (DATA_SLB == gEstado_Funcion)
	  			  {
	  				  gEstado_FW = REALIZAR_FUNCION_2;
	  				  gTiempoRetardo10mS = MSEG_1500;
					  gWait_For_Tx = TRUE;
					  while (TRUE == gWait_For_Tx);
	  			  }
	  			  if (DATA_RELE_OFF == gEstado_Funcion)
				  {
					  gEstado_FW = REALIZAR_FUNCION_2;
					  gTiempoRetardo10mS = MSEG_1500;
					  gWait_For_Tx = TRUE;
					  while (TRUE == gWait_For_Tx);
				  }
	  			  //Caso en que recibimos datos desde la PC 
	  			  //No enviamos confirmación por ahora!!
	  			  else if ((IDLE == gEstado_Funcion) && (DATA_OK != gProtocolo[PROT_FUNC]))
	  			  {
	  				  //gEstado_FW = REALIZAR_FUNCION_1;
	  				  gEstado_FW = REALIZAR_FUNCION_2;
					  gEstado_Funcion = gProtocolo[PROT_FUNC];
	  				  
	  				  //Retardo para evitar problemas con los clientes
	  				  gTiempoRetardo10mS = MSEG_50;
	  				  gWait_For_Tx = TRUE;
	  				  while (TRUE == gWait_For_Tx); 				  
	  			  }
//	  			  else if (((IDLE == gEstado_Funcion) && ()) 
//	  			  {
//	  				gEstado_FW = IDLE;
//	  				Borrar_gProtocolo();
//	  			  }
			  }
			  else
			  {
				  gEstado_FW = IDLE;
				  Borrar_gProtocolo();
			  }
			  
	  		  break;
	  	  }
	  	  case REALIZAR_FUNCION_1:
	  	  {	  		 	  			  
			  gEstado_FW = REALIZAR_FUNCION_2;
			  gEstado_Funcion = gProtocolo[PROT_FUNC];
			  break;
	  	  }
	  	  case REALIZAR_FUNCION_2:
	  	  {	  		  
			  switch(gEstado_Funcion)
			  {
			  	  case IDLE:
			  	  {
			  		  break;
			  	  }
			  	  case DATA_LEDS_ON:
			  	  {
			  		  LED_CLIENTE_On();
			  		  LED_PC_On();
			  		  break;
			  	  }
			  	  case DATA_RELE_OFF:
			  	  {				  		  
			  		  //Metodo_Apagado_Reles();
			  		  Envio_Datos_Clientes(DATA_RELE_OFF, gClientes_ID, gClientes_Func_Off);
			  		  break;
			  	  }
			  	  case DATA_SLB:
			  	  {
			  		  //Metodo_Schlumberger();					
			  		  Envio_Datos_Clientes(DATA_SLB, gClientes_ID, gClientes_Func);
			  		  break;
			  	  }
			  }
			  
			  //Borrar_gProtocolo();			  
			  //gEstado_FW = IDLE;
			  break;
	  	  }  
	  	  default:{}
	  }
  }
}

/* END main */
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
