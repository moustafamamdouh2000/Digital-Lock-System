/*************************************/
/* Author:     Fady Samy             */
/* SWC:        HDM                   */
/* Version:    1.0                   */
/* Date:       August 28,2021        */      
/*************************************/

#ifndef _HDM_INTERFACE_H_
#define _HDM_INTERFACE_H_

#define HDM_CLOCKWISE 		10
#define HDM_ANTI_CLOCKWISE	20
	
void HDM_voidInitialize();
void HDM_voidMoveMotor(u8 ARG_u8Direction);
void HDM_voidStopMotor();

#endif
