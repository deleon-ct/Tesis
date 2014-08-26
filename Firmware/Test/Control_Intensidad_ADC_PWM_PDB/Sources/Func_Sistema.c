/*
 * Func_Sistema.c
 *	Descripción: 
 *	Aquí se ejecutan las funciones propias del sistema
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */


#include "Cpu.h"
#include "Events.h"
#include "Func_Sistema.h"

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
	setReg(ADC0_ADCSC1A, 0x45);		//Habilitamos interrupción del ADC y canal AD5
	setRegBit(ADC0_ADCSC2, ADTRG);
	PWM_OUT = 0x8001;
	PWMC1_Enable();
	setRegBit(PDB_SCR, ENA);
}


