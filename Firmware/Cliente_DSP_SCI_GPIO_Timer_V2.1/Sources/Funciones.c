/*
 * Funciones.c
 *
 *  Created on: Nov 25, 2015
 *      Author: cdeleon
 */

#include "Cpu.h"
#include "Events.h"
#include "Globales.h"
#include "Funciones.h"


void Trasmitir_Trama(UInt16 id_SendData, UInt16 func_SendData)
{		
	uint16_t arregloTX[4];
	uint16_t k = 0;
	

	AS1_TurnRxOff();
	AS1_TurnTxOn();
	RTS_Signal_SetVal();
	
	// Demora de 50mS antes de cargar el arreglo y enviar los datos
	gTiempoRetardo10mS = MSEG_50;
	gWait_For_Tx = TRUE;
	while(TRUE == gWait_For_Tx);
	
	arregloTX[PROT_INI] = DATA_INI;
	arregloTX[PROT_ID] = id_SendData;
	
	arregloTX[PROT_FUNC] = func_SendData;
	arregloTX[PROT_CRC] = id_SendData - func_SendData;
	
	
	//Probar esto si funciona con Hyperterminal
	for(k = 0; k < PROT_MAX; k++)
	{	
		while(!getRegBit(SCI_STAT, TDRE));
		SCI_DATA = arregloTX[k];
		while(!getRegBit(SCI_STAT, TIDLE));		//__RESET_WATCHDOG();		
	}		
		
	AS1_TurnTxOff();
	AS1_TurnRxOn();
	RTS_Signal_ClrVal();
}


/*
** ===================================================================
**     Method      :  Control_Datos_SCI 
**     Description :
**         Este método espera la recepción de la trama correcta. La misma
**         tiene este formato:
**  BYTES =      INI (1)                  ID (2) 				 FUNC (3)						 CRC (4)
**         || DATA_INI 0x60 | <---> | DATA_ID2 0x74| <---> | DATA_RELE_A 0x48| <---> | DATA_CRC (DATA_IDx - DATA_FUNC)|| 
**	
**		   Válida la trama y cambia el estado del SWITCH del main.
**		   
**		   En caso de que la trama no sea la esperada borra el buffer 
**		   de recepción.
** ===================================================================
*/
bool Control_Datos_SCI(UInt16 gProtocolo1[])
{
	static uint16_t dataRX[2];
	uint16_t i, l;
	
	if (DATA_INI == gProtocolo1[PROT_INI])
	{
		if (DATA_ID_DSP == gProtocolo1[PROT_ID])
		{
			dataRX[CRC_INI] = gProtocolo1[PROT_ID];
			
			//if ((gProtocolo1[PROT_FUNC] >= DATA_RELE_A) && (gProtocolo1[PROT_FUNC] <= DATA_RELE_OFF))
			if ((gProtocolo1[PROT_FUNC] >= DATA_L4_ON) && (gProtocolo1[PROT_FUNC] <= DATA_RELE_OFF))
			{
				dataRX[CRC_FUNC] = gProtocolo1[PROT_FUNC];
				
				if ((dataRX[CRC_INI] - dataRX[CRC_FUNC]) == gProtocolo1[PROT_CRC])
				{
					//gEstado_FW = REALIZAR_FUNCION;
					return TRUE;
				}				
			}
			//Acá Debería pedir reconfirmación de datos!!
		}
		else
		{
			gProtocolo1[0] = 0;
			gProtocolo1[1] = 0;
			gProtocolo1[2] = 0;
			gProtocolo1[3] = 0;
			
			return FALSE;			
		}
	}
}

void Envio_Datos_Clientes(UInt16 habilitacion, UInt16 clientes_ID[], UInt16 clientes_Func[])
{
	
	if ((DATA_OK == gProtocolo[PROT_FUNC]) || (habilitacion == gProtocolo[PROT_FUNC])) 
	{
		Borrar_gProtocolo();
				
		Trasmitir_Trama(clientes_ID[gContador_Clientes], clientes_Func[gContador_Clientes]);
		gEstado_FW = IDLE;
		gContador_Clientes++;
		
		if (4 == gContador_Clientes)
		{			
			gEstado_Funcion = IDLE;
			gContador_Clientes = 0;
			Borrar_gProtocolo();			
		}
	}
}


/*
** ===================================================================
**     Method      :  Realizar_Tarea 
**     Description :
**         En este método se realizan las acciones que recibe el DSP a 
**         traves del SCI.
**         
**         Valores y acciones:
**         acciones = 1 ==> Apaga leds
** ===================================================================
*/
void Metodo_Schlumberger(void)
{
	
	if ((DATA_OK == gProtocolo[PROT_FUNC]) || (DATA_SLB == gProtocolo[PROT_FUNC])) 
	{
		Borrar_gProtocolo();
				
		Trasmitir_Trama(gClientes_ID[gContador_Clientes], gClientes_Func[gContador_Clientes]);
		gEstado_FW = IDLE;
		gContador_Clientes++;
		
		if (4 == gContador_Clientes)
		{			
			gEstado_Funcion = IDLE;
			gContador_Clientes = 0;
		}
	}
	
//	
//	//Envia dato cliente 19
//	if (0 == gContador_Clientes)
//	{
//		Borrar_gProtocolo();
//		
//		Trasmitir_Trama(DATA_ID19, DATA_RELE_A);
//		gEstado_FW = IDLE;
//		gContador_Clientes++;
//	}
//	
//	//En caso de que el DATO recibido sea corrupto hay que hacer algo acá
//	//else if ((1 == gContador_Clientes) && (DATA_ID19 == gProtocolo[PROT_ID]))
//	else if ((1 == gContador_Clientes) && (DATA_OK == gProtocolo[PROT_FUNC]))
//	{	
//		Borrar_gProtocolo();
//		
//		Trasmitir_Trama(DATA_ID20, DATA_RELE_B);
//		gEstado_FW = IDLE;
//		//No lo hago cero acá porque tndríamos que agregar más clientes
//		gContador_Clientes++;
//	}
//	//else if ((2 == gContador_Clientes) && (DATA_ID20 == gProtocolo[PROT_ID]))
//	else if ((2 == gContador_Clientes) && (DATA_OK == gProtocolo[PROT_FUNC]))
//	{	
//		Borrar_gProtocolo();
//		
//		Trasmitir_Trama(DATA_IDPC, DATA_OK);
//		gEstado_FW = IDLE;
//		gEstado_Funcion = IDLE;
//		//No lo hago cero acá porque tndríamos que agregar más clientes
//		gContador_Clientes = 0;
//	}
	
}


/*
** ===================================================================
**     Method      :  Metodo_Apagado_Reles 
**     Description :
**         En este método como su nombre lo indica manda comandados
**         a cada uno de los clientes para apagar sus reles.
** ===================================================================
*/
void Metodo_Apagado_Reles(void)
{
	if (DATA_OK == gProtocolo[PROT_FUNC])
	{
		Borrar_gProtocolo();
				
		Trasmitir_Trama(gClientes_ID[gContador_Clientes], DATA_RELE_OFF);
		gEstado_FW = IDLE;
		gContador_Clientes++;
		
		if (4 == gContador_Clientes)
		{			
			gEstado_Funcion = IDLE;
			gContador_Clientes = 0;
		}
	}
}


/*
** ===================================================================
**     Method      :  Borrar_gProtocolo 
**     Description :
**         En este método como su nombre lo indica pone a cero el arreglo
**         de datos recibidos a través del SCI
** ===================================================================
*/
void Borrar_gProtocolo(void)
{
	gProtocolo[0] = 0;
	gProtocolo[1] = 0;
	gProtocolo[2] = 0;
	gProtocolo[3] = 0;
}

