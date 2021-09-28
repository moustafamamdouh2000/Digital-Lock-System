/*************************/
/*	Title	:	MDIO Program File */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	MDIO		     	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 22, 2021   	*/
/*************************/
//Contains the functions implementation ,,,,, // Config.h --> have user configurations.(5 files layer) , // ARG = Copy (shortcuts) // Value = Val , shortcuts , // void = vid (shortcuts) // Direction = dirc , shortcuts
//LIB --> L in names are for library ( for the layered architacture )
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
void MDIO_voidSetPortDirection( u8 ARG_u8PORT,u8 ARG_u8Direction)// User must supply direction for all of the 8 pins
{
	switch(ARG_u8PORT)
	{
		case MDIO_PORTA:
		{
			GPIOA -> DDR = ARG_u8Direction;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> DDR = ARG_u8Direction;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> DDR = ARG_u8Direction;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> DDR = ARG_u8Direction;
			break;
		}
		default:
		{
			//Report an Error.
			break;
		}
	}
}
void MDIO_voidSetPortValue	  (	u8 ARG_u8Port,u8 ARG_u8Value)
{
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:
		{
			GPIOA -> PORT = ARG_u8Value;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> PORT = ARG_u8Value;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> PORT = ARG_u8Value;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> PORT = ARG_u8Value;
			break;
		}
		default:
		{
			//Report an Error.
			break;
		}
	}
} 
u8 	 MDIO_u8GetPortValue      (	u8 ARG_u8Port)
{
	//LOCAL Variable doesn't need the SWC name like L_MDIO_u8PortInput
	u8 L_u8PortInput=0;
	switch (ARG_u8Port)
	{
		case MDIO_PORTA:
		{
			L_u8PortInput = GPIOA -> PIN;
			break;
		}
		case MDIO_PORTB:
		{
			L_u8PortInput = GPIOB -> PIN;
			break;
		}
		case MDIO_PORTC:
		{
			L_u8PortInput = GPIOC -> PIN;
			break;
		}
		case MDIO_PORTD:
		{
			L_u8PortInput = GPIOD -> PIN;
			break;
		}
		default:
		{
			//Report an Error.
			break;
		}
	}
	return L_u8PortInput;
}
void MDIO_voidSetPinDirection(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Direction)
{
	switch(ARG_u8Direction)
	{
		case 0:
		{
			switch(ARG_u8Port)
				{
					case MDIO_PORTA:
					{
						CLEAR_BIT(GPIOA->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTB:
					{
						CLEAR_BIT(GPIOB->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTC:
					{
						CLEAR_BIT(GPIOC->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTD:
					{
						CLEAR_BIT(GPIOD->DDR,ARG_u8PinNumber);
						break;
					}
					default:
					{
						//Report an Error
						break;
					}
				}
			break;
		}
		case 1:
		{
			switch(ARG_u8Port)
				{
					case MDIO_PORTA:
					{
						SET_BIT(GPIOA->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTB:
					{
						SET_BIT(GPIOB->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTC:
					{
						SET_BIT(GPIOC->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTD:
					{
						SET_BIT(GPIOD->DDR,ARG_u8PinNumber);
						break;
					}
					default:
					{
						//Report an Error
						break;
					}
				}
			break;
		}

	}
}
void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Value)
{
	switch (ARG_u8Value)
	{
		case MDIO_LOW:
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:
				{
					CLEAR_BIT(GPIOA->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTB:
				{
					CLEAR_BIT(GPIOB->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTC:
				{
					CLEAR_BIT(GPIOC->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTD:
				{
					CLEAR_BIT(GPIOD->PORT,ARG_u8PinNumber);
					break;
				}
				default:
				{
					//Report an Error
					break;
				}
			}
			break;
		}
		case MDIO_HIGH:
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:
				{
					SET_BIT(GPIOA->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTB:
				{
					SET_BIT(GPIOB->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTC:
				{
					SET_BIT(GPIOC->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTD:
				{
					SET_BIT(GPIOD->PORT,ARG_u8PinNumber);
					break;
				}
				default:
				{
					//Report an Error
					break;
				}
			}
			break;
		}
	}
}
u8 MDIO_u8GetPinValue(u8 ARG_u8PortNumber,u8 ARG_u8PinNumber)
{
	u8 L_u8PinInput=0;
	switch(ARG_u8PortNumber)
	{
		case MDIO_PORTA:
		{
			L_u8PinInput = GPIOA->PIN & (1<<ARG_u8PinNumber);
			break;
		}
		case MDIO_PORTB:
		{
			L_u8PinInput = GPIOB->PIN & (1<<ARG_u8PinNumber);
			break;
		}
		case MDIO_PORTC:
		{
			L_u8PinInput = GPIOC->PIN & (1<<ARG_u8PinNumber);
			break;
		}
		case MDIO_PORTD:
		{
			L_u8PinInput = GPIOD->PIN & (1<<ARG_u8PinNumber);
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
	return L_u8PinInput;
}

/*
 * set Pin direction
 * void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Value)
 * 	switch(ARG_u8PORT)
	{
		case MDIO_PORTA:
		{
			if(MDIO_OUTPUT==ARG_u8DIRECTION)
			{
				SET_BIT(GPIOA->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOA->DDR,ARG_u8PinNumber);
			}
			break;
		}
		case MDIO_PORTB:
		{
			if(MDIO_OUTPUT==ARG_u8DIRECTION)
			{
				SET_BIT(GPIOB->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOB->DDR,ARG_u8PinNumber);
			}
		}
		case MDIO_PORTC:
		{
			if(MDIO_OUTPUT==ARG_u8DIRECTION)
			{
				SET_BIT(GPIOC->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOC->DDR,ARG_u8PinNumber);
			}
		}
		case MDIO_PORTD:
		{
			if(MDIO_OUTPUT==ARG_u8DIRECTION)
			{
				SET_BIT(GPIOD->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOD->DDR,ARG_u8PinNumber);
			}
		}
		default:
		{
			//Report an Error.
			break;
		}
	}
 */
/*
 * Set Pin Value change DDR to PORT
 * void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Value)
 *  * 	switch(ARG_u8PORT)
	{
		case MDIO_PORTA:
		{
			if(MDIO_OUTPUT==ARG_u8Value)
			{
				SET_BIT(GPIOA->PORT,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOA->PORT,ARG_u8PinNumber);
			}
			break;
		}
		case MDIO_PORTB:
		{
			if(MDIO_OUTPUT==ARG_u8Value)
			{
				SET_BIT(GPIOB->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOB->DDR,ARG_u8PinNumber);
			}
		}
		case MDIO_PORTC:
		{
			if(MDIO_OUTPUT==ARG_u8Value)
			{
				SET_BIT(GPIOC->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOC->DDR,ARG_u8PinNumber);
			}
		}
		case MDIO_PORTD:
		{
			if(MDIO_OUTPUT==ARG_u8Value)
			{
				SET_BIT(GPIOD->DDR,ARG_u8PinNumber);
			}
			else
			{
				CLEAR_BIT(GPIOD->DDR,ARG_u8PinNumber);
			}
		}
		default:
		{
			//Report an Error.
			break;
		}
	}
	*/

/*
 * void MDIO_voidSetPinDirection(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Direction)
{
	switch(ARG_u8Direction)
	{
		case MDIO_INPUT:
		{
			switch(ARG_u8Port)
				{
					case MDIO_PORTA:
					{
						GPIOA->DDR=CLEAR_BIT(GPIOA->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTB:
					{
						GPIOB->DDR=CLEAR_BIT(GPIOB->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTC:
					{
						GPIOC->DDR=CLEAR_BIT(GPIOC->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTD:
					{
						GPIOD->DDR=CLEAR_BIT(GPIOD->DDR,ARG_u8PinNumber);
						break;
					}
					default:
					{
						//Report an Error
						break;
					}
				}
			break;
		}
		case MDIO_OUTPUT:
		{
			switch(ARG_u8Port)
				{
					case MDIO_PORTA:
					{
						GPIOA->DDR= SET_BIT(GPIOA->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTB:
					{
						GPIOB->DDR=SET_BIT(GPIOB->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTC:
					{
						GPIOC->DDR=SET_BIT(GPIOC->DDR,ARG_u8PinNumber);
						break;
					}
					case MDIO_PORTD:
					{
						GPIOD->DDR=SET_BIT(GPIOD->DDR,ARG_u8PinNumber);
						break;
					}
					default:
					{
						//Report an Error
						break;
					}
				}
			break;
		}

	}
}
void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Value)
{
	switch (ARG_u8Value)
	{
		case MDIO_LOW:
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:
				{
					GPIOA->PORT= CLEAR_BIT(GPIOA->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTB:
				{
					GPIOB->PORT=CLEAR_BIT(GPIOB->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTC:
				{
					GPIOC->PORT=CLEAR_BIT(GPIOC->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTD:
				{
					GPIOD->PORT=CLEAR_BIT(GPIOD->PORT,ARG_u8PinNumber);
					break;
				}
				default:
				{
					//Report an Error
					break;
				}
			}
			break;
		}
		case MDIO_HIGH:
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:
				{
					GPIOA->PORT= SET_BIT(GPIOA->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTB:
				{
					GPIOB->PORT=SET_BIT(GPIOB->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTC:
				{
					GPIOC->PORT=SET_BIT(GPIOC->PORT,ARG_u8PinNumber);
					break;
				}
				case MDIO_PORTD:
				{
					GPIOD->PORT=SET_BIT(GPIOD->PORT,ARG_u8PinNumber);
					break;
				}
				default:
				{
					//Report an Error
					break;
				}
			}
			break;
		}
	}
}
*/
