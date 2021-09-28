/*
 * Master_main.c
 *
 *  Created on: 13 Sep 2021
 *      Author: HP
 */
#include "util/delay.h"
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "MSPI_Interface.h"
#include "HKPD_interface.h"
#include "MUART_Interface.h"
void Start_Message();
void Send_UserInput();
int main(void)
{
	MSPI_voidMasterInitialize();
	HKPD_voidInitialize();
	MUART_voidInit();
	Start_Message();
	u8 Option=0,OptionSelect=0;
	u8 OptionFlag=0;
	while(1)
	{
		if(OptionSelect==0)
		{
			Option=MUART_voidRecieve();
		}
		if(Option=='1')
		{
			if(OptionFlag==0)
			{
				MSPI_voidSendByte('1');
			}
			OptionFlag++;
			OptionSelect=1;
			Send_UserInput();
		}
		else if (Option == '2')
		{
			if(OptionFlag==0)
			{
				MSPI_voidSendByte('2');
			}
			OptionFlag++;
			OptionSelect=2;
			Send_UserInput();
		}
	}
	return 0;
}

void Start_Message()
{
	MUART_voidString("   Welcome to the ATM Safe System \r");
    MUART_voidString("Choose from the options Below: \r");
    MUART_voidString("Option 1 : Open the Lock \r");
    MUART_voidString("Option 2 : Change Current Password \r");
    MUART_voidString("Enter Your Option: ");
}

void Send_UserInput()
{
	u8 UserInput=0;
    while(UserInput == '0' || UserInput=='\0')
    {
    	UserInput=HKPD_u8GetButton();
    }
	   MSPI_voidSendByte(UserInput);
	   _delay_ms(300);
	   UserInput = '0';
}
