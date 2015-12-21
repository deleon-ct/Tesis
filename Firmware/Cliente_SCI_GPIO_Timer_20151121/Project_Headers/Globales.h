/*
 * Globales.h
 *
 *  Created on: Nov 21, 2015
 *      Author: cdeleon
 */

#ifndef GLOBALES_H_
#define GLOBALES_H_

////Estados del Switch del MAIN
//#define ESPERANDO_DATOS_SCI 0
//#define DATOS_SCI_RECIBIDOS 1
//#define REALIZAR_FUNCION	3

//Estados del Switch del MAIN
#define ESPERANDO_DATOS_SCI 0
#define DATOS_SCI_RECIBIDOS 1
#define REALIZAR_FUNCION_1	3
#define REALIZAR_FUNCION_2	4

#define IDLE				0
#define TRANSMISION 		1
#define RECEPCION 			2



//Leds
#define LENTO	50
#define RAPIDO 	25
#define RELEA	10
#define	RELEB   75
#define RELEM	20
#define RELEN	90

////Protocolo
//#define DATA_INI		0x60
//#define DATA_ID2		0x74
//#define DATA_ID_DSP		0x75
//#define DATA_IDPC		0x76
//#define DATA_RELE_A		0x48
//#define DATA_RELE_B		0x49
//#define DATA_RELE_M		0x4A
//#define DATA_RELE_N		0x4B
//#define DATA_OK			0x4C
//#define DATA_RETRY 		0x4D
//#define DATA_ERROR		0x4E
//#define DATA_RELE_OFF	0x4F

//Protocolo
#define DATA_INI		0x60
#define DATA_ID17		0x71
#define DATA_ID18		0x72
#define DATA_ID19		0x73
#define DATA_ID20		0x74
#define DATA_ID_DSP		0x75
#define DATA_IDPC		0x76
#define DATA_L4_ON		0x40
#define DATA_L4_OFF		0x41
#define DATA_L5_ON		0x42
#define DATA_L5_OFF		0x43
#define DATA_SLB		0x44
#define DATA_LEDS_ON	0x45
#define DATA_LEDS_OFF	0x46
#define DATA_RELE_A		0x48
#define DATA_RELE_B		0x49
#define DATA_RELE_M		0x4A
#define DATA_RELE_N		0x4B
#define DATA_OK			0x4C
#define DATA_RETRY 		0x4D
#define DATA_ERROR		0x4E
#define DATA_RELE_OFF	0x4F

#define PROT_INI	0
#define PROT_ID2	1
#define PROT_FUNC	2
#define PROT_CRC	3
#define PROT_MAX	4

#define CRC_INI		0
#define CRC_FUNC	1

//Tiempos para un timer de 10mS
#define MSEG_1000		100
#define MSEG_50  		5
#define MSEG_300  		30
#define MSEG_100  		10

//Funciones
#define LEDS_FUNC	1

#endif /* GLOBALES_H_ */
