/*
 * Leds.c
 *	Descripción:
 *	Manejamos el estado de los leds
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#include "Cpu.h"
#include "Global.h"

void Led_Estado(uint16_t estado)
{
	ledEstado = estado;
	borrarContador = 0;
}
