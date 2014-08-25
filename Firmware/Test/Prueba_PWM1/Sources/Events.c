/* ###################################################################
**     Filename    : Events.c
**     Project     : Prueba_PWM1
**     Processor   : MC56F8006_48_LQFP
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-08-25, 09:21, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  BTN1_OnButton (module Events)
**
**     Component   :  BTN1 [Button]
**     Description :
**         This event is called when the button is pressed.
**         If button inactivity feature (advanced view) is enabled,
**         then the next OnButton event is not generated during dead
**         time.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void BTN1_OnButton(void)
{
    static UInt16 contador;
    LED1_Toggle();
	switch(contador)
	{
		case 0:
		{
			setReg(PWM_VAL0, CICLO10);           
			setReg(PWM_VAL3, CICLO90);
			break;		
		}
		case 1:
		{
			setReg(PWM_VAL0, CICLO90);           
			setReg(PWM_VAL3, CICLO10);
			break;		
		}
		case 2:
		{
			setReg(PWM_VAL0, CICLO25);           
			setReg(PWM_VAL3, CICLO50);
			break;		
		}
		case 3:
		{
			setReg(PWM_VAL0, CICLO50);           
			setReg(PWM_VAL3, CICLO25);
			break;		
		}
		default:{}
	}
	
	/* LDOK = 1 */
	//setReg16Bits(PWM_CTRL, 0x02U);
	setRegBit(PWM_CTRL,LDOK);
	//clrReg16Bits(PWM_CTRL, 0x10U);       /* clear PWMF flag */
	
	contador++;
	if (contador == 4)
	{
		contador = 0;
	}
}

/* END Events */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
