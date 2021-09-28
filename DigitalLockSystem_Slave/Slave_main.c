/*
 * Slave_main.c
 *
 *  Created on: 13 Sep 2021
 *      Author: HP
 */


#include "util/delay.h"
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "MSPI_Interface.h"
#include "HLCD_interface.h"
#include "HDM_Config.h"
#include "HDM_Interface.h"
void OpenDoor();
void Display_Message(s8* String1_Line1, s8* String2_Line2);
int main(void)
{
	//Initialisations
	HDM_voidInitialize();
	MSPI_voidSlaveInitialize();
	HLCD_voidInitialize();
	//General Flags
	u8 Option=0;
	u8 OptionFlag=0;
	u8 MasterFlag=0;
	u8 newMessage=0;
	//General Variables
	u8 UserInput;
	u8 Password[5];
	u8 Passright[5]= {'1','2','3','4','5'};
	u8 PassCheck[5];
	//Option1 counters & flags
	u8 CurrentPass_userInput= 0;
	u8 CurrentPass_rightPassword=0;
	//Option2 counters & flags
	u8 PasswordFlag=0;
	u8 NewPassword_counter=0;
	u8 CheckOldPass_userInput=0;
	u8 CheckOldPass_rightPassword=0;
	u8 OldMessage=0;
	u8 TimeOut=0;
	u8 TimeOutFlag=0;
	while(1)
	{
		//This condition to make sure only 1 option is enabled
		MasterFlag=MSPI_u8ReadByte();
		if((MasterFlag=='1'||MasterFlag=='2' )&& OptionFlag==0 )
		{
			Option=MasterFlag;
			OptionFlag++;
		}
		if(Option=='2')
		{
			//This while loop is for verifying old password before changing to the new one
			while(PasswordFlag==0)
			{
				if(OldMessage==0)
				{
					Display_Message("Enter Your","Old Pass: ");
				}
				OldMessage++;
				if(TimeOut==3)
				{
					Display_Message("3 Failed Entries","System will shutdown");
					return 0;
				}
				UserInput=MSPI_u8ReadByte();
				if(UserInput=='$')
				{
					HLCD_voidDeleteLastChar();
					CheckOldPass_userInput--;
					UserInput='\0';
				}
				if(UserInput != '0' && UserInput != '\0' && UserInput !='$')
				{
					PassCheck[CheckOldPass_userInput]= UserInput;
					HLCD_voidWriteData(UserInput);
					CheckOldPass_userInput++;
				}
				if(CheckOldPass_userInput==5)
				{
					HLCD_voidWriteCommand(0x01);
					for(CheckOldPass_rightPassword=0;CheckOldPass_rightPassword<5;CheckOldPass_rightPassword++)
					{
						if(PassCheck[CheckOldPass_rightPassword] == Passright[CheckOldPass_rightPassword])
						{
							continue;
						}
						else
						{
							TimeOutFlag++;
							break;
						}
					}
				}
				if(CheckOldPass_rightPassword==5)
				{
					Display_Message("Correct Password","");
					PasswordFlag=1;
				}
				if(TimeOutFlag==1)
				{
					Display_Message("Password Not","Correct");
					TimeOut++;
					OldMessage=0;
					CheckOldPass_userInput=0;
					TimeOutFlag=0;
				}
			}
			//After checking the correct password , install the new one
			if(newMessage==0)
			{
				Display_Message("Enter Your","New Pass: ");
			}
			newMessage++;
			UserInput=MSPI_u8ReadByte();
			if(UserInput=='$')
			{
				HLCD_voidDeleteLastChar();
				NewPassword_counter--;
				UserInput='\0';
			}
			if(UserInput != '0' && UserInput != '\0' && UserInput !='$')
			{
				Passright[NewPassword_counter]=UserInput;
				HLCD_voidWriteData(UserInput);
				NewPassword_counter++;
			}
			if(NewPassword_counter==5)
			{
				Display_Message("New Password","Assigned !");
				HLCD_voidWriteCommand(0x01);
				Option='1';
				newMessage=0;
			}
		}
		if(Option=='1')
		{
			if(newMessage==0)
			{
				Display_Message("Enter Your","Password: ");
			}
			newMessage++;
			UserInput=MSPI_u8ReadByte();
			if(UserInput=='$')
			{
				HLCD_voidDeleteLastChar();
				CurrentPass_userInput--;
				UserInput='\0';
			}
			if(UserInput != '0' && UserInput != '\0' && UserInput !='$')
			{
				Password[CurrentPass_userInput]= UserInput;
				HLCD_voidWriteData(UserInput);
				CurrentPass_userInput++;
			}
			if(CurrentPass_userInput==5)
			{
				for(CurrentPass_rightPassword=0;CurrentPass_rightPassword<5;CurrentPass_rightPassword++)
				{
					if(Password[CurrentPass_rightPassword] == Passright[CurrentPass_rightPassword])
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if(CurrentPass_rightPassword == 5)
				{
					Display_Message("Right Password","Door Will Open.");
					OpenDoor();
				}
				else
				{
					Display_Message("Password Is Not","Correct");
					newMessage=0;
					CurrentPass_userInput=0;
				}
			}
		}
	}
	return 0;
}
void OpenDoor()
{
	  //Rotating Motors to unlock
	  HLCD_voidWriteCommand(0x01);
	  HLCD_voidSetString("(0)_(0)");
	  HDM_voidMoveMotor(HDM_CLOCKWISE);
	  HDM_voidMoveMotor(HDM_ANTI_CLOCKWISE);
	  MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN2,0x01);
	  HDM_voidMoveMotor(HDM_CLOCKWISE);
	  HDM_voidMoveMotor(HDM_ANTI_CLOCKWISE);
	  HDM_voidMoveMotor(HDM_CLOCKWISE);
	  MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN3,0x01);
	  HDM_voidStopMotor();
	  //Displaying message after the door has been opened
	  HLCD_voidWriteCommand(0x01);
	  _delay_ms(10);
	  HLCD_voidSetString("Cool The door");
	  HLCD_voidWriteCommand(0xC0);
	  HLCD_voidSetString("has opened.");
	  _delay_ms(300);
}
void Display_Message(s8* String1_Line1, s8* String2_Line2)
{
	_delay_ms(200);
	HLCD_voidWriteCommand(0x01);
	_delay_ms(10);
	HLCD_voidSetString(String1_Line1);
	HLCD_voidWriteCommand(0xC0);
	HLCD_voidSetString(String2_Line2);
	_delay_ms(1000);
}
