/*
 * Funciones.h
 *
 *  Created on: Nov 21, 2015
 *      Author: cdeleon
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//Funciones públicas
bool Control_Datos_SCI(byte *gProtocolo);
void Confirma_Recepcion(bool confirmacion);
void Ejecutar_Funcion(uint16_t comando);
void Borrar_gProtocolo(void);

//Variables globales
//extern uint16_t gProtocolo[4];
extern byte 	gProtocolo[4];
extern uint16_t gEstado_FW;
extern uint16_t gLed_Actividad;
extern uint16_t gTiempoRetardo10mS;
extern bool 	gWait_For_Tx;

#endif /* FUNCIONES_H_ */
