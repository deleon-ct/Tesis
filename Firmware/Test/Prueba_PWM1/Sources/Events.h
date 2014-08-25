/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "BTN1.h"
#include "Inhr1.h"
#include "PWM_Timer.h"
#include "LED1.h"
#include "Inhr2.h"

/* 2uS */
#define CICLO10		((word)64)
/* 5uS */
#define CICLO25		((word)160)
/* 10uS */
#define CICLO50		((word)320)
/* 18uS */
#define CICLO90		((word)576)


void BTN1_OnButton(void);
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

/* END Events */
#endif /* __Events_H*/

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
