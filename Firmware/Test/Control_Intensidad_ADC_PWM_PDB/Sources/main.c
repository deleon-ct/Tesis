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
**         Este firmware controla la intensidad de un led dependiendo el valor que lee de un 
**         potenciómetro colocado en AD5 y a esto lo realiza controlando su valor medio mediante 
**         el PWM.
**         El PWM esta configurado para funcionar a 3 * System Clock (32MHz) = 96MHz, un periodo de 50KHz
**         (Tosc = 20uS) con lo que tenemos un valor en PWM_CMOD de 960. La resolución es de:
**         Center Align -> (2 * 3 * (System Clock)) = (2 * (3 * 32MHz)^(-1)) =  20.83nS
**         					PWM_CMOD = 20uSg / 20.83nS = 960
**         El ADC estaba configurado en 12bits, 2^12 = 4096, que era mucha resolución para la que teniamos
**         en el PWM (2^10 = 1024 que es cercano a los 960 del PWM).
**         Entonces, aceptando un error, hicimos, ADC = 10 bits de resolución, con lo que obtenemos 1024 valores.
**         La resolución del ADC es entonces:
**         Resolución ADC = 3.3V / 1024 = 3.22mV
**         Por tanto cuando la tensión del potenciómetro alcance los (3.22mV * 960) = 3.09V el duty cicle del PWM 
**         será del 100%. El error relativo es de 6.36% a fondo de escala (error = 1 - (3.09V / 3.3V)).						 
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
#include "LED_PWM_OVERFLOW.h"
#include "Inhr2.h"
#include "SCI.h"
#include "Func_Sistema.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* Variables globales y Macros */

/* SCI */
#define CANTRXOK 	3
#define MAX_PWM		0x7FFF

byte arrRx[CANTRXOK];
byte SCI_Saludo_PWM;

UInt16 valor_ADC;

/* Interrupción del ADC */
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
 
  /* Saca por SCI el saludo de bienvenida y agrega dos renglones para que sea 
   * legible cada vez que inicia*/
  Agregar_Espacios_SCI(2);
  Saludo_Inicial_SCI();
  
  /* Solicita caracteres para arranque seguro */
  Arranque_Seguro_SCI();
  
  TI1_Enable();
  Inicializacion_Perifericos();
  LED_PWM_OVERFLOW_Off();
  
  for(;;)
  {
	  if(valor_ADC < MAX_PWM)
	  {
		  PWMC1_SetDuty(0, valor_ADC);
		  PWMC1_Load();
	  }else
	  {
		  LED_PWM_OVERFLOW_On();
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
