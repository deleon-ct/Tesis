/*
 * Global.h
 *
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "PE_Types.h"
#include "Cpu.h"


//typedef unsigned int uint16_t
//typedef byte AS1_TComData;

///* Variables globales y Macros */
//
///*****************************************************************************/
///*	Estado del Led 
// * 	Valor		Estado					Velocidad de parpadeo(Segundos)	     */
///*	0  			Esperando clave/char	2							 
// * 	1			Modificando	PWM			0.2
// * 	2			Tensi�n estabilizada	1						   	
// *****************************************************************************/
#define ESPERANDO		0
#define CAMBIANDO_PWM 	1
#define TENSION_FIJA	2
//
////uint16_t ledEstado;
//unsigned int ledEstado;		
////uint16_t borrarContador;
//unsigned int borrarContador;
//
///* SCI */
//#define CANTRXOK 3
////AS1_TComData arrRx[CANTRXOK];
////AS1_TComData SCI_Saludo_PWM;
////AS1_TComData valorTension_SCI;
//byte arrRx[CANTRXOK];
//byte SCI_Saludo_PWM;
//byte valorTension_SCI;
//
/* ADC */
#define TENSION_05V		625
#define TENSION_10V		1250
#define TENSION_15V		1875
#define TENSION_20V		2500
#define TENSION_25V		3125
#define TENSION_30V		3750
#define OFFSET			10
#define PROC_OK			12
//uint16_t valor_ADC;
//uint16_t valorTension;
//uint16_t tensionAlcanzada;
//
///* Prop�sito general */
//uint16_t modificarSalida;
//bool timeOut_reach = FALSE;
//bool timeOut_Start = FALSE;

#endif /* GLOBAL_H_ */
