/*
 * Func_Sistema.c
 *	Descripción: 
 *	Aquí se ejecutan las funciones propias del sistema
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */


#include "Cpu.h"
#include "Events.h"
#include "Global.h"
#include "Func_Sistema.h"
#include "Leds.h"

/* Macros */
#define AUMENTAR_DUTY	1
#define DISMINUIR_DUTY	2
#define CHANNEL_PWM_0	0

/* Prototipos de funciones internas al módulo */
void Alcanzando_Tension(void);
void DesactivarPerifericos(void);
void Inicializacion_Perifericos(void);
void Activar_TimeOut(void);
void Cambiar_PMW(UInt16 valor_PWM);

/*
** ===================================================================
**     Method      :  void Activar_Salida(void)
**     Description (Extendida):
**         Inicia el PWM y el ADC para alcanzar el valor de tensión recibido
**         por SCI.
**         El PWM comienza a aumentar y esto es controlado por el ADC que
**         va sensando la tensión en la resistencia de salida. Una vez alcanza-
**         do el valor requerido el sistema se mantiene en esa tensión por 20
**         segundos, terminado este tiempo la salida vuelve a ser cero. 
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/
void Activar_Salida(UInt16 realizarAccion)
{
	if(realizarAccion == CAMBIANDO_PWM)
	{
		Led_Estado(CAMBIANDO_PWM);		
		Inicializacion_Perifericos();
		Activar_TimeOut();
		Alcanzando_Tension();
	}
	else if(realizarAccion == ESPERANDO)
	{
		Led_Estado(ESPERANDO);
		LED_TENSION_OK_Off();
		DesactivarPerifericos();
	}
}


/*
** ===================================================================
**     Method      :  void Alcanzando_Tension(void)
**     Description:
**         Inicializamos los periféricos y nos quedamos en un buble infinito
**         esperando que se alcance la tensión requerida. Si la misma no se 
**         alcanza en 8 segundos se deshabilitan todos los periféricos y se 
**         enciende el LED_ERROR. Queda encendido durante la etapa de debuggeo 
**         y lo vamos a tratar más adelante.  
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/
void Alcanzando_Tension(void)
{	
	do{
		if (valor_ADC < valorTension)
		{
			Cambiar_PMW(AUMENTAR_DUTY);
			LED_TENSION_OK_Off();
			Led_Estado(CAMBIANDO_PWM);
		}		
		
		else if (valor_ADC > valorTension)
		{
			Cambiar_PMW(DISMINUIR_DUTY);
			LED_TENSION_OK_Off();
			Led_Estado(CAMBIANDO_PWM);
		}
		
		else if ((valor_ADC >= (valorTension - OFFSET)) || 
				(valor_ADC <= (valorTension + OFFSET)))
		{
			Led_Estado(TENSION_FIJA);
			LED_TENSION_OK_On();
		}
		
	}while((tensionAlcanzada != PROC_OK) || (!timeOut_reach));
	
	if (timeOut_reach)
	{
		LED_ERROR_On();
		DesactivarPerifericos();
		timeOut_reach = FALSE;
	}
	if(tensionAlcanzada == PROC_OK)
	{		
		modificarSalida = 2;
		timeOut_Start = FALSE;
	}
}

/*
** ===================================================================
**     Method      :  void DesactivarPerifericos(void)
**     Description :
**         Cómo su nombre lo indica desactiva todos los periféricos, se puede
**         llamar a esta función por dos motivos, el primero que hayan pasado
**         los diez segundos de tensión constante a la salida y el segundo por-
**         que expiro el timeout de tensión no alcanzada. 
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/
void DesactivarPerifericos(void)
{
	clrRegBit(PDB_SCR, ENA);
	PWMC1_Disable();
	setReg(ADC0_ADCSC1A, 0x05);		
	clrRegBit(ADC0_ADCSC2, ADTRG);
}

/*
** ===================================================================
**     Method      :  void Inicializacion_Perifericos(void)
**     Description :
**         Inicializa los periféricos. 
**     Parameters  : None
**     Returns     :
					 None	
** ===================================================================
*/
void Inicializacion_Perifericos(void)
{		
	/* GPIO_A_PER: PE5=1,PE4=1,PE3=1,PE2=1,PE1=1,PE0=1 */
	//setRegBits(GPIO_A_PER, (GPIO_A_PER_PE3_MASK | GPIO_A_PER_PE4_MASK | GPIO_A_PER_PE5_MASK));      //Control Puerto A Periféricos
	//clrRegBits(GPIO_A_PUR, (GPIO_A_PUR_PU3_MASK | GPIO_A_PUR_PU4_MASK | GPIO_A_PUR_PU5_MASK));		//Deshabilitamos pull-up	
	
	setReg(ADC0_ADCSC1A, 0x45);		//Habilitamos interrupción del ADC y canal AD5
	setRegBit(ADC0_ADCSC2, ADTRG);
	setRegBits(SCI_CTRL1, (SCI_CTRL1_RE_MASK | SCI_CTRL1_REIE_MASK | SCI_CTRL1_RFIE_MASK));	
	PWMC1_Enable();
	setRegBit(PDB_SCR, ENA);
}

/*
** ===================================================================
**     Method      :  void Activar_TimeOut(void)
**     Description :
**         Activa un timeout de 10 segundos que es el tiempo máximo que tenemos 
**         para alcanzar el nivel de tensión deseado 
**     Parameters  : None
**     Returns     :
					 None	
** ===================================================================
*/
void Activar_TimeOut(void)
{
	timeOut_Start = TRUE;
}

/*
** ===================================================================
**     Method      :  void Cambiar_PMW(uint16_t valor_PWM)
**     Description :
**         Modifica el valor del ciclo del PWM. 
**     Parameters  : AUMENTAR_DUTY
**     				 DISMINUIR_DUTY	
**     Returns     :
					 None	
** ===================================================================
*/
void Cambiar_PMW(UInt16 cambiar_PWM)
{
	static int valor_PWM;
	
	if(cambiar_PWM == AUMENTAR_DUTY)
	{
		valor_PWM++;
		PWMC1_SetDuty(CHANNEL_PWM_0, valor_PWM);
	}
	else if(cambiar_PWM == DISMINUIR_DUTY)
	{
		valor_PWM--;
		PWMC1_SetDuty(CHANNEL_PWM_0, valor_PWM);
	}
	PWMC1_Load();
}
