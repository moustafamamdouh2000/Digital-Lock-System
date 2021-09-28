/*************************/
/*	Title	:	MSPI program	    */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	MSPI		    	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"
#include "MDIO_private.h"




void MSPI_voidMasterInitialize(void)
{
	GPIOB -> DDR =(1<<5)|(1<<7)|(1<<4);
	SPCR=(1<<SPE)|(1<<MSTR);
}
void MSPI_voidSlaveInitialize(void)
{
	GPIOB -> DDR &= ~((1<<6)|(1<<7)|(1<<5));
	GPIOB -> DDR |= (1<<7);
	SPCR = (1<<SPE);
}
void MSPI_voidSendByte(u8 ARG_u8Byte)
{
	 SPDR=ARG_u8Byte;
	 while(!(SPSR&(1<<SPIF)));
}
u8 	 MSPI_u8ReadByte()
{
	while(!(SPSR & (1<<SPIF)));
		return(SPDR);
}