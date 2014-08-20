/*
 * SCI.h
 *
 *  Created on: Aug 8, 2014
 *      Author: DeLeon
 */

#ifndef SCI_H_
#define SCI_H_

#include "Cpu.h"
#include "Global.h"

//Variables externas
extern byte arrRx[CANTRXOK];
extern byte SCI_Saludo_PWM;

//Prototipos de funciones
void Saludo_Inicial_SCI(void);
void Arranque_Seguro_SCI(void);
void Agregar_Espacios_SCI(byte espacios);
void Enviar_Datos_SCI_PWM(void);
void Enviar_Chr(byte Chrs);

#endif /* SCI_H_ */
