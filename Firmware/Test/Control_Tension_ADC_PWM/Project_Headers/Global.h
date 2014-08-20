/*
 * Global.h
 *
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Variables globales y Macros */

/*****************************************************************************/
/*	Estado del Led 
 * 	Valor		Estado					Velocidad de parpadeo(Segundos)	     */
/*	0  			Esperando clave/char	2							 
 * 	1			Modificando	PWM			0.2
 * 	2			Tensión estabilizada	1						   	
 *****************************************************************************/
#define ESPERANDO		0
#define CAMBIANDO_PWM 	1
#define TENSION_FIJA	2
uint16_t ledEstado;
uint16_t borrarContador;

/* SCI */
AS1_TComData arrRx[CANTRXOK];
AS1_TComData SCI_Saludo_PWM;
AS1_TComData valorTension_SCI;

/* ADC */
#define TENSION_05V		625
#define TENSION_10V		1250
#define TENSION_15V		1875
#define TENSION_20V		2500
#define TENSION_25V		3125
#define TENSION_30V		3750
#define OFFSET			10
#define PROC_OK			12
uint16_t valor_ADC;
uint16_t valorTension;
uint16_t tensionAlcanzada;

/* Propósito general */
uint16_t modificarSalida;

#endif /* GLOBAL_H_ */
