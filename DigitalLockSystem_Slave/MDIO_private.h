/*************************/
/*	Title	:	MDIO Private File */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	MDIO		     	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 22, 2021   	*/
/*************************/
//File Guard: prevents the multiple includes , by only cheacking it first then  defining it once if not found
//Registers defention (only for the 3 files defention , for the 5 files we put them in registers)
/* some rules only on .H files , 1--> No includes in any .h files , 2 --> Naming Convensions , 3--> Any header file must have a file gurad*/

#ifndef _MDIO_PRIVATE_H_ // Never copy paste the file guard from old codes you might forget to change the name and cause a problem
#define _MDIO_PRIVATE_H_ // 
/*#define PIND 	*((volatile u8*0x30))
#define DDRD 	*((volatile u8*0x31))
#define PORTD 	*((volatile u8*0x32))*/ //this is a method , or the struct method below
typedef struct{
    u8 PIN;
	u8 DDR;
	u8 PORT;
}GPIO_Type;
//ZERO memory, No object was created
#define	GPIOA ((volatile GPIO_Type *) 0x39)
#define	GPIOB ((volatile GPIO_Type *) 0x36)//No Derefence Operator to use the Arror in the calling down(GPIO->DDR)
#define	GPIOC ((volatile GPIO_Type *) 0x33)
#define	GPIOD ((volatile GPIO_Type *) 0x30)
/*	GPIOA	-> Pin  when calling the type
	GPIOA	-> Port
	GPIOA	-> DDR
*/
#endif
