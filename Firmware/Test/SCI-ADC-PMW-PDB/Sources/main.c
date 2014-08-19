/* ###################################################################
**     Filename    : main.c
**     Project     : SCI-ADC-PWM-PDB_6-8
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-06, 13:21, # CodeGen: 0
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
#include "LED_SCI.h"
#include "Inhr1.h"
#include "LED_ADC.h"
#include "Inhr2.h"
#include "LED_TEST.h"
#include "Inhr3.h"
#include "LED3V.h"
#include "Inhr4.h"
#include "LED2V.h"
#include "Inhr5.h"
#include "LED1V.h"
#include "Inhr6.h"
#include "ADC0.h"
#include "PDB.h"
#include "PWMC1.h"
#include "AS1.h"
#include "TI1.h"
#include "SCI.h"
#include "MacrosGlobales.h"



/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

//Macros
/* Definición de tipos */
#define Channel_LED3	3
#define Channel_LED4	4
#define Channel_LED5	5

#define	Ciclo1		3
#define Ciclo25		80
#define Ciclo50		160
#define	Ciclo95		304	

#define TENSION05V	621
#define TENSION1V	1241	
#define TENSION15V	1862
#define TENSION2V	2482
#define TENSION25V	3103
#define TENSION3V	3724	

//Variables globales
byte arrRx[CANTRXOK];
byte SCI_Saludo_PWM		= 0;
byte led_test_On 		= 0;
byte modificar_Ciclo 	= 0;
word valor_ADC			= 0;

//Prototipos de función
void Inicializacion_Perifericos(void);
void actualizar_DC_PMW(word val_ADC);
void Inicializacion_Perifericos(void);

#pragma interrupt saveall
void  INT_ADC0_Complete(void)
{
	
	word contenedor_ADC;
		
	contenedor_ADC = ADC0_ADCRA;
	valor_ADC = contenedor_ADC >> 3;
	modificar_Ciclo = 1;
	LED_ADC_Toggle();
}
/******************************************************************************/
#pragma interrupt off


/*
** ===================================================================
**     Method      :  actualizar_DC_PWM(word val_ADC)
**     Description :
**         Este actualiza los ciclos de trabajo (duty cicle) de cada   
**         uno de los canales del PWM. 
**     Parameters  : word
**     Returns     : None
** ===================================================================
*/
void actualizar_DC_PMW(word val_ADC)
{
	byte i;
	
	if(val_ADC <= TENSION05V)
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo1);
		PWMC1_SetDuty(Channel_LED4, Ciclo1);
		PWMC1_SetDuty(Channel_LED5, Ciclo1);
	}
	else if((val_ADC > TENSION05V) && (val_ADC <= TENSION1V))
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo25);
		PWMC1_SetDuty(Channel_LED4, Ciclo1);
		PWMC1_SetDuty(Channel_LED5, Ciclo1);
	}
	else if((val_ADC > TENSION1V) && (val_ADC <= TENSION15V))
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo50);
		PWMC1_SetDuty(Channel_LED4, Ciclo25);
		PWMC1_SetDuty(Channel_LED5, Ciclo1);
	}
	else if((val_ADC > TENSION15V) && (val_ADC <= TENSION2V))
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo95);
		PWMC1_SetDuty(Channel_LED4, Ciclo50);
		PWMC1_SetDuty(Channel_LED5, Ciclo25);
	}
	else if((val_ADC > TENSION2V) && (val_ADC <= TENSION25V))
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo95);
		PWMC1_SetDuty(Channel_LED4, Ciclo95);
		PWMC1_SetDuty(Channel_LED5, Ciclo50);
	}
	else 
	{
		PWMC1_SetDuty(Channel_LED3, Ciclo95);
		PWMC1_SetDuty(Channel_LED4, Ciclo95);
		PWMC1_SetDuty(Channel_LED5, Ciclo95);
	}
	LED_SCI_Toggle();
	setRegBit(PWM_CTRL,LDOK);
}
/*
** ===================================================================
**     Method      :  Inicializacion_Perifericos()
**     Description :
**         Este método inicializa los periféricos unas vez que ya se 
**         confirmo el STRING de habilitación. 
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/
void Inicializacion_Perifericos(void)
{
	setRegBit(PDB_SCR, ENA);
	PWMC1_Enable();
	setReg(ADC0_ADCSC1A, 0x54);		//Habiitamos interrupción del ADC y canal AD5
	setRegBits(SCI_CTRL1, (SCI_CTRL1_RE_MASK | SCI_CTRL1_REIE_MASK | SCI_CTRL1_RFIE_MASK));
}

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  //Mejora la visual del Hyperterminal agregando espacios
  Agregar_Espacios_SCI(2);
  
  //Saludo Inicial
  Saludo_Inicial_SCI();
  
  //Deshabilitamos ISR del TX y sólo dejamos la ISR del RX. 
  //Espera que se reciban los caracteres, COPETTI 
  Arranque_Seguro_SCI();
  
  //Mejora la visual del Hyperterminal agregando espacios
  Agregar_Espacios_SCI(2);
  
  //Activamos el LED_ADC para indicar que esta conviertiendo
  led_test_On = 1;
  
  //Iniciamos el 1º PDB - 2ºPWM - 3ºADC - 4ºSCI-RX
  Inicializacion_Perifericos();
  
  //PWM y SCI RX/TX no están habilitados
  
  for(;;) {
	  while(!modificar_Ciclo){}			//La bandera cambia cada vez que entre a una conversión
	  actualizar_DC_PMW(valor_ADC);		//Actualizamos el valor del ciclo de trabajo del PMW
	  modificar_Ciclo = 0;				//Reiniciamos la bandera de control
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
