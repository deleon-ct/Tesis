/*
 * asw.c
 *
 *  Created on: Aug 8, 2014
 *      Author: DeLeon
 */

#include "SCI.h"
#include "AS1.h"
#include "Events.h"
#include "Global.h"

//Prototipos privados
void Enviar_Chr(byte Chrs);

/*
** ===================================================================
**     Method      :  Saludo_Inicial_SCI(void)
**     Description :
**         Este metodo transmite un saludo inicial por el puerto serie.
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/
#define CANT1	18
void Saludo_Inicial_SCI(void)
{
	byte i;
	byte arregloBienvenida[CANT1] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', 13, 10, 'P', 'a', 's', 's', ':', ' '};
	
	//Deshabilitamos RX
	//setRegBit(SCI_CTRL1, TE);
	clrRegBit(SCI_CTRL1, RE);
	
	for (i = 0; i < CANT1; i++)
	{
		Enviar_Chr(arregloBienvenida[i]);
//		getReg(SCI_STAT);
//		setReg(SCI_DATA, arregloBienvenida[i]);
//		while(!(SCI_STAT & SCI_STAT_TIDLE_MASK)){}
	}				
	//Deshabilitamos el TX y RX
	//clrRegBit(SCI_CTRL1, TE);
}

/*
** ===================================================================
**     Method      :  Arranque_Seguro_SCI();
**     Description :
**         Este metodo espera que llegue la secuencia de caracteres 
**         "copetti" para continuar con la ejecuci�n del firmware. 
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/

void Arranque_Seguro_SCI(void)
{	
	byte recepcionSegura = 0;
	byte i;
	//Habilitamos RX y RFIE (RDRF = 1)
	setRegBits(SCI_CTRL1, (SCI_CTRL1_RE_MASK | SCI_CTRL1_RFIE_MASK | 
			SCI_CTRL1_REIE_MASK));
	
	//LED_SCI_On();
	SCI_Saludo_PWM = 1;
	
	do
	{
		if ((arrRx[0] == 'q') && (arrRx[1] == 'w') && (arrRx[2] == 'e'))
			recepcionSegura = 1;		
	}while(recepcionSegura == 0);
	
	//LED_SCI_Off();
	//LED_TEST_Off();
	SCI_Saludo_PWM = 2;
}

/*
** ===================================================================
**     Method      :  Agregar_Espacios_SCI(byte espacios)
**     Description :
**         Este metodo recibe un entero y env�a esa cantidad de caracteres 
**         ASCII nueva linea de tal manera de mejorar la legilibilidad 
**         del c�digo 
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/

void Agregar_Espacios_SCI(byte espacios)
{
	byte i;
	
	setRegBit(SCI_CTRL1, TE);
	
	//Baja la cantidad de nuevas lineas que recibio 
	//la fucni�n como par�metro
	for(i = 0; i < espacios; i++)
	{	
		getReg(SCI_STAT);
		setReg(SCI_DATA, 10);
		while(!(SCI_STAT & SCI_STAT_TIDLE_MASK)){}
	}
	
	//Coloca el puntero en el inicio de la linea - 
	getReg(SCI_STAT);
	setReg(SCI_DATA, 13);
	while(!(SCI_STAT & SCI_STAT_TIDLE_MASK)){}
	
	clrRegBit(SCI_CTRL1, TE);
}

void Enviar_Chr(byte Chrs)
{
	setRegBit(SCI_CTRL1, TE);		 
	getReg(SCI_STAT);
	setReg(SCI_DATA, Chrs);
	while(!(SCI_STAT & SCI_STAT_TIDLE_MASK)){}
	
	clrRegBit(SCI_CTRL1, TE);
}


void Enviar_Datos_SCI_PWM(void)
{
	Agregar_Espacios_SCI(2);
	Enviar_Chr('P');
	Enviar_Chr('W');
	Enviar_Chr('M');
	Enviar_Chr('_');
	Enviar_Chr('3');
	Enviar_Chr(':');
	Enviar_Chr((AS1_TComData)PWM_VAL3);
	
	Agregar_Espacios_SCI(1);
	Enviar_Chr('P');
	Enviar_Chr('W');
	Enviar_Chr('M');
	Enviar_Chr('_');
	Enviar_Chr('4');
	Enviar_Chr(':');
	Enviar_Chr((AS1_TComData)PWM_VAL4);
	
	Agregar_Espacios_SCI(1);
	Enviar_Chr('P');
	Enviar_Chr('W');
	Enviar_Chr('M');
	Enviar_Chr('_');
	Enviar_Chr('5');
	Enviar_Chr(':');
	Enviar_Chr((AS1_TComData)PWM_VAL5);
	
	Agregar_Espacios_SCI(1);
	Enviar_Chr('A');
	Enviar_Chr('D');
	Enviar_Chr('C');	
	Enviar_Chr(':');
	Enviar_Chr((AS1_TComData)ADC0_ADCRA);
}
