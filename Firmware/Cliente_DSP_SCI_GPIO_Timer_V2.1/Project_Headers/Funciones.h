/*
 * Funciones.h
 *
 *  Created on: Nov 25, 2015
 *      Author: cdeleon
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void Trasmitir_Trama(UInt16 id_Receptor, UInt16 func_Receptor);
bool Control_Datos_SCI(UInt16 gProtocolo1[]);
void Realizar_Tarea(UInt16 accion);
void Borrar_gProtocolo(void);
void Metodo_Schlumberger(void);
void Metodo_Apagado_Reles(void);

void Envio_Datos_Clientes(UInt16 habilitacion, UInt16 clientes_ID[], UInt16 clientes_Func[]);

extern UInt16  	gEstado_FW;
extern UInt16 	gEstado_Funcion;
extern UInt16	gContador_Clientes;
extern UInt16 	gTiempoRetardo10mS;
extern UInt16	gEstado_Confirmacion;

extern UInt16  gClientes_ID[4];
extern UInt16  gClientes_Func[4];
extern UInt16  gClientes_Func_Off[4]; 	

#endif /* FUNCIONES_H_ */
