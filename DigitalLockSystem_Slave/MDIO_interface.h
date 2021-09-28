/*************************/
/*	Title	:	MDIO Interface File */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	MDIO		     	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 22, 2021   	*/
/*************************/
//Interface File : For Functions prototypes
/* some rules only on .H files , 1--> No includes in any .h files , 2 --> Naming Convensions , 3--> Any header file must have a file gurad*/
//File Guard: prevents the multiple includes , by only cheacking it first then  defining it once if not found
#ifndef	_MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_   	 //After this function prototypes
//*********PORTS************
#define MDIO_PORTA  0	     //these numbers are "Magic Numbers" it only defines for users but it doesn't matter for compiler ,(Hamming distance):Related to the binary representation of the bits
#define MDIO_PORTB  1			 //If i want anything to be visible in the main for use ( variables , functions ) i have to define them in the interface file , its the only one that included in project 
#define MDIO_PORTC  2
#define MDIO_PORTD  3
//*********PINS************
#define MDIO_PIN0	0
#define MDIO_PIN1	1
#define MDIO_PIN2	2
#define MDIO_PIN3	3
#define MDIO_PIN4	4
#define MDIO_PIN5	5
#define MDIO_PIN6	6
#define MDIO_PIN7	7
//*********OUTPUTS_INPUTS************
#define MDIO_PORT_OUTPUT 0xFF
#define MDIO_PORT_INPUT  0x00
#define MDIO_INPUT   0
#define MDIO_OUTPUT  1
#define MDIO_LOW  0
#define MDIO_HIGH 1
//*********PINS************
#define MDIO_PIN0		0
#define MDIO_PIN1		1
#define MDIO_PIN2		2
#define MDIO_PIN3		3
#define MDIO_PIN4		4
#define MDIO_PIN5		5
#define MDIO_PIN6		6
#define MDIO_PIN7		7

void MDIO_voidSetPortDirection( u8 ARG_u8PORT,u8 ARG_u8Direction); // void = vid (shortcuts) // Direction = dirc , shortcuts
void MDIO_voidSetPortValue	  (	u8 ARG_u8Port,u8 ARG_u8Value); // ARG = Copy (shortcuts) // Value = Val , shortcuts
u8 	 MDIO_u8GetPortValue      (	u8 ARG_u8Port);
void MDIO_voidSetPinDirection ( u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Direction);
void MDIO_voidSetPinValue 	  ( u8 ARG_u8Port,u8 ARG_u8PinNumber,u8 ARG_u8Value);
u8 	 MDIO_u8GetPinValue		  ( u8 ARG_u8PortNumber,u8 ARG_u8PinNumber);
#endif
