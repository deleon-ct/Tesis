/*
 * Leds.c
 *	Descripción:
 *	Manejamos el estado de los leds
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#include "Leds.h"
#include "Global.h"

//void Led_Estado(uint16_t estado)
void Led_Estado(unsigned int estado)
{
	ledEstado = estado;
	borrarContador = 0;
}
