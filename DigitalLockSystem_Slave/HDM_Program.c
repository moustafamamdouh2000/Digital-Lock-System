/*************************************/
/* Author:     Fady Samy             */
/* SWC:        HDM                   */
/* Version:    1.0                   */
/* Date:       August 28,2021        */      
/*************************************/

#include <util/delay.h>
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "HDM_Interface.h"
#include "HDM_Config.h"


void HDM_voidInitialize()
{
	MDIO_voidSetPortDirection(HDM_BRIDGEPORT,0xFF);
	MDIO_voidSetPortValue(HDM_BRIDGEPORT,0x00);
}


void HDM_voidMoveMotor(u8 ARG_u8Direction)
{
	switch(ARG_u8Direction)
	{
		
		case HDM_CLOCKWISE:
		{
			MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN0,MDIO_HIGH);
			_delay_ms(HDM_DELAY);
			
			MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN1,MDIO_LOW);
			_delay_ms(HDM_DELAY);
			
			break;
		}
		
		case HDM_ANTI_CLOCKWISE:
		{
			MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN1,MDIO_HIGH);
			_delay_ms(HDM_DELAY);
			
			MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN0,MDIO_LOW);
			_delay_ms(HDM_DELAY);
			
			break;
		}
		
	}
}

void HDM_voidStopMotor()
{

	MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN1,MDIO_LOW);
	MDIO_voidSetPinValue(HDM_BRIDGEPORT,HDM_BRIDGEPIN0,MDIO_LOW);

}
