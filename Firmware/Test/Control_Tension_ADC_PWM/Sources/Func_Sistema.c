/*
 * Func_Sistema.c
 *	Descripci�n: 
 *	Aqu� se ejecutan las funciones propias del sistema
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */


#include "Cpu.h"
#include "Events.h"
#include "Global.h"
#include "Leds.h"

/* Prototipos de funciones internas al m�dulo */
void ActivarPerif�ricos(void);
void DesactivarPerifericos(void);
void Inicializacion_Perifericos(void);

/*
** ===================================================================
**     Method      :  void Activar_Salida(void)
**     Description (Extendida):
**         Inicia el PWM y el ADC para alcanzar el valor de tensi�n recibido
**         por SCI.
**         El PWM comienza a aumentar y esto es controlado por el ADC que
**         va sensando la tensi�n en la resistencia de salida. Una vez alcanza-
**         do el valor requerido el sistema se mantiene en esa tensi�n por 20
**         segundos, terminado este tiempo la salida vuelve a ser cero. 
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/

void Activar_Salida(uint16_t realizarAccion)
{
	if(realizarAccion == CAMBIANDO_PWM)
	{
		Led_Estado(CAMBIANDO_PWM);
		ActivarPerifericos();
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
**     Method      :  void ActivarPerif�ricos(void)
**     Description:
**         Inicializamos los perif�ricos y nos quedamos en un buble infinito
**         esperando que se alcance la tensi�n requerida. Si la misma no se 
**         alcanza en 8 segundos se deshabilitan todos los perif�ricos y se 
**         enciende el LED_ERROR.  
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/
void ActivarPerif�ricos(void)
{
	Inicializacion_Perifericos();
	
	Activar_TimeOut();
	
	do{
		if (valor_ADC < valorTension)
		{
			Cambiar_PMW(AUMENTAR_DUTY);
			LED_TENSION_OK_Off();
			Led_Estado(CAMBIANDO_PWM);
		}
		
		else if (valor_ADC > valorTension)
		{
			Cambiar_PWM(DISMINUIR_DUTY);
			LED_TENSION_OK_Off();
			Led_Estado(CAMBIANDO_PWM);
		}
		
		else if ((valor_ADC >= (valorTension - OFFSET)) || 
				(valor_ADC <= (valorTension + OFFSET)))
		{
			Led_Estado(TENSION_FIJA);
			LED_TENSION_OK_On();
		}
		
	}while((tensi�nAlcanzada != PROC_OK) || (timeOut));
	
	if (timeOut)
		LED_ERROR_On();
	if(tensionAlcanzada == PROC_OK)
		modificarSalida = 2;		
}


/*
** ===================================================================
**     Method      :  void DesactivarPerifericos(void)
**     Description :
**         C�mo su nombre lo indica desactiva todos los perif�ricos, se puede
**         llamar a esta funci�n por dos motivos, el primero que hayan pasado
**         los diez segundos de tensi�n constante a la salida y el segundo por-
**         que expiro el timeout de tensi�n no alcanzada. 
**     Parameters  : None
**     Returns     :
**         None
** ===================================================================
*/
void DesactivarPerifericos(void)
{
	while(!Esperar_20Segundos){}
	LED_TENSION_OK_Off();
	
	Desactivar_PWM();
	Desactivar_PDB();
	Desactivar_ADC();
	
	led_Estado(ESPERANDO);
}

/*
** ===================================================================
**     Method      :  void Inicializacion_Perifericos(void)
**     Description :
**         Inicializa los perif�ricos. 
**     Parameters  : None
**     Returns     :
					 None	
** ===================================================================
*/
void Inicializacion_Perifericos(void)
{		
	/* GPIO_A_PER: PE5=1,PE4=1,PE3=1,PE2=1,PE1=1,PE0=1 */
	//setRegBits(GPIO_A_PER, (GPIO_A_PER_PE3_MASK | GPIO_A_PER_PE4_MASK | GPIO_A_PER_PE5_MASK));      //Control Puerto A Perif�ricos
	//clrRegBits(GPIO_A_PUR, (GPIO_A_PUR_PU3_MASK | GPIO_A_PUR_PU4_MASK | GPIO_A_PUR_PU5_MASK));		//Deshabilitamos pull-up	
	
	setReg(ADC0_ADCSC1A, 0x45);		//Habiitamos interrupci�n del ADC y canal AD5
	setRegBit(ADC0_ADCSC2, ADTRG);
	setRegBits(SCI_CTRL1, (SCI_CTRL1_RE_MASK | SCI_CTRL1_REIE_MASK | SCI_CTRL1_RFIE_MASK));	
	PWMC1_Enable();
	setRegBit(PDB_SCR, ENA);
}
