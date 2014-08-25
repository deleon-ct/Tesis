/*
 * Leds.h
 *
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "Cpu.h"

/* Variables externas */
//extern uint16_t ledEstado;
//extern uint16_t borrarContador;
extern unsigned int ledEstado;
extern unsigned int borrarContador;

/* Prototipos de función */
//void Led_Estado(uint16_t estado);
void Led_Estado(unsigned int estado);

#endif /* LEDS_H_ */
