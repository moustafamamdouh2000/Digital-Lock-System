/* Author:     Fady Samy             */
/* SWC:        MUART                 */
/* Version:    1.0                   */
/* Date:       September 6,2021      */      
/*************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MUART_Private.h"
#include "MUART_Interface.h"


void MUART_voidInit(void)
{
	int Baud=51;

	UBRRH=(Baud>>8);
	UBRRL = Baud;

	UCSRB =(1<<RXEN) | (1<<TXEN);
	UCSRC =(1<<URSEL)|(1<<UCSZ0) |(1<<UCSZ1);
}

u8 MUART_voidRecieve(void)
{
	while((UCSRA&(1<<RXC))==0);
		return UDR;
}

void MUART_voidSend(u8 u8_Data)
{
	while((UCSRA & (1<<UDRE))==0);
	UDR = u8_Data;
}
