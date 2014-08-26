/* ###################################################################
**     Filename    : main.c
**     Project     : Prueba_PWM1
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-25, 09:21, # CodeGen: 0
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
**         La idea de este firmware es comprender bien el funcionamiento del PWM. Por ejemplo, sirve para entender cual es la 
**         resolución del PWM.
**         
**         Funcionamiento:
**         ---------------
**         A partir de presionar el IRQ_SW2 los CH0 y CH1 del PWM cambian a valores fijos de PWM.
**         Aclaración:
**         El periodo del PWM viene dado por la siguiente fórmula: 

**         Alineamiento central (Center align):
**         		
**         		PWM PERIODO = 2 * (PWM_CMOD) * (PWM_CLOCK_PERIOD)
**         
**         Alineamiento flanco (Edge align):
**         
**         		PWM PERIODO = (PWM_CMOD) * (PWM_CLOCK_PERIOD)
**         		
**         PWM PERIODO		= Periodo de funcionamiento del PWM, o sea, para 50KHz es 20uS
**         PWM_CMOD			= Registro que contiene un valor que define el periodo del PWM
**         PWM_CLOCK_PERIOD	= Pasos del PWM, puede ser 32MHZ (System clock) o 3 * (System Clock) o sea 96MHz
**         
**         La primera versión de este firmware estaba hecho con un System clock de 32MHz entonces PWM_CMOD = 640 y edge align.
**         Los #DEFINE para los ciclos de porcentajes fijos eran:
**         		10% -> 2uS 	-> #define CICLO10		((word)64)
**         		25% -> 5uS 	-> #define CICLO25		((word)160)
**         		50% -> 10uS	-> #define CICLO50		((word)320)
**         		90% -> 18uS -> #define CICLO90		((word)576)
**		   La resolución máxima es de (32MHz)^-1. Que multiplicado por 640 dan los 20uS (100% ciclo)
**		   
**		   La segunda versión de este firmware estaba hecho con un System clock de 96MHz entonces PWM_CMOD = 960 y center align.
**         Los #DEFINE para los ciclos de porcentajes fijos eran:
**         		10% -> 2uS 	-> #define CICLO10		((word)96)   
**         		25% -> 5uS 	-> #define CICLO25		((word)240)
**         		50% -> 10uS	-> #define CICLO50		((word)480)
**         		90% -> 18uS -> #define CICLO90		((word)864)         		 			 
**         La resolución máxima es de ( 2 * (96MHz)^-1) (Esto porque es center align, si fuera edge align mejora la resolución). 
**         Que multiplicado por 960 dan los 20uS (100% ciclo)
**         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "BTN1.h"
#include "Inhr1.h"
#include "PWM_Timer.h"
#include "LED1.h"
#include "Inhr2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
   
  /* Write your code here */

  /* Esta instrucción habilita el PWM, fundamental */
  setReg16(PWM_OUT, 0x8009);	  
  
  for(;;) {}
  
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
