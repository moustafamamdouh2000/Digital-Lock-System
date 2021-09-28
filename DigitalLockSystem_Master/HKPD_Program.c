/*************************/
/*	Title	:	KPD Program File    */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	KPD 		     	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"
#include "HKPD_interface.h"
#include "HKPD_private.h"
#include "util/delay.h"

void HKPD_voidInitialize()
{
	MDIO_voidSetPortDirection(HKPD_PORT,0x0F);
	MDIO_voidSetPortValue(HKPD_PORT,0xFF);
}
u8 HKPD_u8GetButton()
{
	u8 L_u8Charachter='\0';
	MDIO_voidSetPortValue(HKPD_PORT,0xFE);//0b11111110
	L_u8Charachter=HKPD_u8GetColm(1);
	if(L_u8Charachter!='\0')
		return L_u8Charachter;
	MDIO_voidSetPortValue(HKPD_PORT,0xFD);//0b11111110
	L_u8Charachter=HKPD_u8GetColm(2);
	if(L_u8Charachter!='\0')
		return L_u8Charachter;
	MDIO_voidSetPortValue(HKPD_PORT,0xFB);
	L_u8Charachter=HKPD_u8GetColm(3);
	if(L_u8Charachter!='\0')
		return L_u8Charachter;
	MDIO_voidSetPortValue(HKPD_PORT,0xF7);//0b11111110
	L_u8Charachter=HKPD_u8GetColm(4);
	if(L_u8Charachter!='\0')
		return L_u8Charachter;
	return L_u8Charachter;
}

static u8 HKPD_u8GetColm(u8 ARG_Row)
{
	switch(ARG_Row)
	{
		case 1:
		{
			if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN4)==0)
				return '7';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN5)==0)
				return '8';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN6)==0)
				return '9';
			else if (MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN7)==0)
				return '/';
			else
				return '\0';
			break;
		}
		case 2:
		{
			if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN4)==0)
				return '4';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN5)==0)
				return '5';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN6)==0)
				return '6';
			else if (MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN7)==0)
				return 'X';
			else
				return '\0';
			break;
		}
		case 3:
		{
			if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN4)==0)
				return '1';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN5)==0)
				return '2';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN6)==0)
				return '3';
			else if (MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN7)==0)
				return '-';
			else
				return '\0';
			break;
		}
		case 4:
		{
			if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN4)==0)
				return '$';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN5)==0)
				return '0';
			else if(MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN6)==0)
				return '=';
			else if (MDIO_u8GetPinValue(HKPD_PORT,MDIO_PIN7)==0)
				return '+';
			else
				return '\0';
			break;
		}
	}
	return 0;
}
