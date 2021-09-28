/*************************/
/*	Title	:	HLCD Program.c File */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	LCD		     		*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#include "util/delay.h"
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"

void HLCD_voidWriteCommand(u8 ARG_u8Command)
{
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_RSPin,MDIO_LOW);
	MDIO_voidSetPortValue(HLCD_DataPort,ARG_u8Command);
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_LOW);
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_HIGH);// this is for ensuring that theres a rising edge
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_LOW);
}
void HLCD_voidWriteData(u8 ARG_u8Data)
{
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_RSPin,MDIO_HIGH);
	_delay_ms(5);
	MDIO_voidSetPortValue(HLCD_DataPort,ARG_u8Data);
	_delay_ms(5);
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_LOW);
	_delay_ms(5);
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_HIGH);// this is for ensuring that theres a rising edge
	_delay_ms(5);
	MDIO_voidSetPinValue(HLCD_ControlPort,HLCD_EnPin,MDIO_LOW);
	_delay_ms(5);
}
void HLCD_voidInitialize()
{
	MDIO_voidSetPortDirection(HLCD_DataPort,0xFF);
	_delay_ms(5);
	MDIO_voidSetPinDirection(HLCD_ControlPort,HLCD_RSPin,MDIO_HIGH);
	_delay_ms(5);
	MDIO_voidSetPinDirection(HLCD_ControlPort,HLCD_EnPin,MDIO_HIGH);
	_delay_ms(5);
	//Fn set 0b00111000
	HLCD_voidWriteCommand(0x38);
	//Entry Mode
	HLCD_voidWriteCommand(0x07);
	//Home Position , DIsplay on, Cursor off
	HLCD_voidWriteCommand(0x0C);
	//Clear Display
	HLCD_voidWriteCommand(0x01);
	_delay_ms(10);//or 2 , 5
}

void HLCD_voidSetCursor(u8 ARG_u8CursorLocation)
{

}

void HLCD_voidCustomChar(u8 ARG_Location,u8* ARG_u8String)
{
	u8 i;
	if(ARG_Location < 8)
	{
		HLCD_voidWriteCommand(0x40 + (ARG_Location* 8));
		for(i = 0 ; i < 8 ; i++)
		{
			HLCD_voidWriteData(ARG_u8String[i]);
		}
	}
}

void HLCD_voidSetString(s8* ARG_u8String)
{
	u32 i;
	for(i=0;ARG_u8String[i]!=0;i++)
	{
		HLCD_voidWriteData(ARG_u8String[i]);
	}

}
void HLCD_voidSetStringXYPos(u8 ARG_u8Row, u8 ARG_u8Pos, s8 *ARG_u8String) /* Send string to LCD with xy position */
{
	if (ARG_u8Row == 0 && ARG_u8Pos<16)
		HLCD_voidWriteCommand((ARG_u8Pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (ARG_u8Row == 1 && ARG_u8Pos<16)
		HLCD_voidWriteCommand((ARG_u8Pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	HLCD_voidSetString(ARG_u8String);		/* Call LCD string function */
}
void HLCD_voidDeleteLastChar()
{
	HLCD_voidWriteCommand(0x10);
	HLCD_voidWriteData(' ');
	HLCD_voidWriteCommand(0x10);
}
