/*************************/
/*	Title	:	HLCD interface.h    */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	LCD		     		*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_
#define HLCD_DataPort	    MDIO_PORTC
#define HLCD_ControlPort	MDIO_PORTD
#define HLCD_RSPin		2
#define HLCD_EnPin		3
void HLCD_voidWriteCommand(u8 ARG_u8Command);
void HLCD_voidWriteData(u8 ARG_u8Data);
void HLCD_voidInitialize();
void HLCD_voidSetString(s8* ARG_u8String);
void HLCD_voidSetCursor(u8 ARG_u8CursorLocation);
void HLCD_voidCustomChar(u8 ARG_Location,u8* ARG_String);
void HLCD_voidSetStringXYPos(u8 row, u8 pos, s8 *str);
void HLCD_voidDeleteLastChar();
#endif
