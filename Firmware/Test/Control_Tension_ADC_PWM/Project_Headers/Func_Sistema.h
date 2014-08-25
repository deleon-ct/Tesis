/*
 * Func_Sistema.h
 *
 *  Created on: Aug 20, 2014
 *      Author: DeLeon
 */

#ifndef FUNC_SISTEMA_H_
#define FUNC_SISTEMA_H_

/* Variables externas */
//extern uint16_t valor_ADC;
extern UInt16 modificarSalida;
extern bool timeOut_Start;
extern UInt16 valor_ADC;
extern UInt16 valorTension;

/* Prototipos de funciones */
void Activar_Salida(UInt16 realizarAccion);


#endif /* FUNC_SISTEMA_H_ */
