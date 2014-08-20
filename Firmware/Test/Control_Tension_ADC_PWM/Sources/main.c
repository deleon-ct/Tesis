/* ###################################################################
**     Filename    : main.c
**     Project     : Control_Tension_ADC_PWM
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-20, 12:11, # CodeGen: 0
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
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "ADC0.h"
#include "PDB.h"
#include "PWMC1.h"
#include "AS1.h"
#include "TI1.h"
#include "LED_ESTADO.h"
#include "Inhr1.h"
#include "LED_TENSION_OK.h"
#include "Inhr2.h"
#include "LED_ERROR.h"
#include "Inhr3.h"
#include "SCI.h"
#include "Global.h"
#include "Leds.h"
#include "Func_Sistema.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* Interrupci�n del ADC */
/******************************************************************************/
#pragma interrupt saveall
void  INT_ADC0_Complete(void)
{
	
	word contenedor_ADC;
		
	contenedor_ADC = ADC0_ADCRA;
	valor_ADC = contenedor_ADC >> 3;		
}
#pragma interrupt off
/******************************************************************************/

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  /* Modificamos estado del led de estado */
  Led_Estado(ESPERANDO);
  
  /* Saca por SCI el saludo de bienvenida y agrega dos renglones para que sea 
   * legible cada vez que inicia*/
  Agregar_Espacios_SCI(2);
  Saludo_Inicial_SCI();
  
  /* Solicita caracteres para arranque seguro */
  Arranque_Seguro_SCI();

  /* Espera la llegada de un caracter por la RX del SCI para iniciar el PWM 
   * junto con el ADC y lograr la tensi�n buscada*/

  
  for(;;)
  {
	  modificarSalida = 0;
	  
	  while(modificarSalida == 0){}
	  
	  if (modificarSalida == 1)
		  Activar_Salida(CAMBIANDO_PWM);
	  
	  else if (modificarSalida == 2)
		  Activar_Salida(ESPERANDO);
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
