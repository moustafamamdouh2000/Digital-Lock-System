/*************************/
/*	Title	:	MSPI interface	    */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	MSPI		    	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#ifndef _MSPI_INTERFACE_H_
#define _MSPI_INTERFACE_H_
void MSPI_voidMasterInitialize(void);
void MSPI_voidSlaveInitialize(void);
void MSPI_voidSendByte(u8 ARG_u8Byte);
u8 	 MSPI_u8ReadByte();
#endif