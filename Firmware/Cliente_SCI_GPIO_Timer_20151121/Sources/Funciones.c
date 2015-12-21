/*
 * Funciones.c
 *
 *  Created on: Nov 21, 2015
 *      Author: cdeleon
 */


#include "Cpu.h"
#include "Events.h"
#include "Globales.h"
#include "Funciones.h"

/*
** ===================================================================
**     Method      :  Control_Datos_SCI 
**     Description :
**         Este método espera la recepción de la trama correcta. La misma
**         tiene este formato:
**  BYTES =      INI (1)                  ID (2) 				 FUNC (3)						 CRC (4)
**         || DATA_INI 0x60 | <---> | DATA_ID20	0x74| <---> | DATA_RELE_A 0x48| <---> | DATA_CRC (DATA_IDx - DATA_FUNC)|| 
**	
**		   Válida la trama y cambia el estado del SWITCH del main.
**		   
**		   En caso de que la trama no sea la esperada borra el buffer 
**		   de recepción.
** ===================================================================
*/
bool Control_Datos_SCI(byte gProtocolo1[])
{
	//static uint16_t dataRX[2];
	static byte dataRX[2];
	//uint16_t i;
	
	if (DATA_INI == gProtocolo1[PROT_INI])
	{
		if (DATA_ID20 == gProtocolo1[PROT_ID2])
		{
			dataRX[CRC_INI] = gProtocolo1[PROT_ID2];
			
			//Limite mal!
			if ((gProtocolo1[PROT_FUNC] >= DATA_RELE_A) && (gProtocolo1[PROT_FUNC] <= DATA_RELE_OFF))
			{
				dataRX[CRC_FUNC] = gProtocolo1[PROT_FUNC];
				
				if ((dataRX[CRC_INI] - dataRX[CRC_FUNC]) == gProtocolo1[PROT_CRC])
				{
					gEstado_FW = REALIZAR_FUNCION_1;
					return TRUE;
				}				
			}
		}
		else
		{
			gProtocolo1[0] = 0;
			gProtocolo1[1] = 0;
			gProtocolo1[2] = 0;
			gProtocolo1[3] = 0;
			
//			for(i = 0; i < 4; i++)
//			{
//				gProtocolo1[i] = 0;
//			}
			return FALSE;			
		}
	}
}

void Confirma_Recepcion(bool confirmacion)
{
	static uint16_t	cant_Erorres = 0;
	//uint16_t arregloTX[4];
	byte arregloTX[4];
	
	uint16_t k = 0;
	
	AS1_TurnRxOff();
	AS1_TurnTxOn();
	RTS_Signal_SetVal();
	
	//Espera 100mS
	
	gTiempoRetardo10mS = MSEG_100;
	gWait_For_Tx = TRUE;
	while (TRUE == gWait_For_Tx);
	
	arregloTX[PROT_INI] = DATA_INI;
	//arregloTX[PROT_ID2] = DATA_IDPC;
	arregloTX[PROT_ID2] = DATA_ID_DSP;
	
	arregloTX[PROT_FUNC] = DATA_OK;
	arregloTX[PROT_CRC] = DATA_ID_DSP - DATA_OK;
	
//	if (TRUE == confirmacion)
//	{
//		arregloTX[PROT_FUNC] = DATA_OK;
//		arregloTX[PROT_CRC] = DATA_ID_DSP - DATA_OK;
//		
//		//AS1_SendChar(DATA_OK);
//		//AS1_SendChar(DATA_IDPC - DATA_OK);
//	}
//	else
//	{
//		//cant_Erorres++;
//		arregloTX[PROT_FUNC] = DATA_ERROR;
//		arregloTX[PROT_CRC] = DATA_ID_DSP - DATA_ERROR;
//		
//		//AS1_SendChar(DATA_ERROR);
//		//AS1_SendChar(DATA_IDPC - DATA_ERROR);
//	}	
//	//if (cant_Erorres == 3)
	
	for(k = 0; k < PROT_MAX; k++)
	{
		while(!SCIS1_TDRE);				
		SCID = arregloTX[k];
		while(!SCIS1_TC);		//__RESET_WATCHDOG();		
	}		
	
//	gWait_For_Tx = TRUE;
//	while(TRUE == gWait_For_Tx);
	
	AS1_TurnTxOff();
	AS1_TurnRxOn();
	RTS_Signal_ClrVal();
	
//	gWait_For_Tx = TRUE;
//	while(TRUE == gWait_For_Tx);
}

void Ejecutar_Funcion(uint16_t comando)
{
	switch(comando)
	{
		case DATA_RELE_A:
		{
			//gLed_Actividad = RELEA;
			Rele_A_PutVal(TRUE);
			Led_Actividad_PutVal(TRUE);
			break;
		}
		case DATA_RELE_B:
		{
			//gLed_Actividad = RELEB;
			Rele_B_PutVal(TRUE);
			Led_Actividad_PutVal(TRUE);
			break;
		}
		case DATA_RELE_M:
		{
			//gLed_Actividad = RELEM;
			Rele_M_PutVal(TRUE);
			Led_Actividad_PutVal(TRUE);
			break;
		}
		case DATA_RELE_N:
		{
			//gLed_Actividad = RELEN;
			Rele_N_PutVal(TRUE);
			Led_Actividad_PutVal(TRUE);
			break;
		}
		case DATA_RELE_OFF:
		{
			//gLed_Actividad = LENTO;
			Rele_A_PutVal(FALSE);
			Rele_B_PutVal(FALSE);
			Rele_M_PutVal(FALSE);
			Rele_N_PutVal(FALSE);
			Led_Actividad_PutVal(FALSE);
			gLed_Funcion = FALSE;
			break;
		}
		default:
		{
			break;
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

