/*************************/
/*	Title	:	KPD Interface File  */
/*	Author	:	Moustafa Mamdouh 	*/
/*  SWC		:	KPD 		     	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 25, 2021   	*/
/*************************/
#ifndef _HKPD_INTERFACE_H_
#define _HKPD_INTERFACE_H_
#define HKPD_PORT	MDIO_PORTC
#define HKPD_C1     MDIO_PIN0
#define HKPD_C2     MDIO_PIN1
#define HKPD_C3     MDIO_PIN2
#define HKPD_R1     MDIO_PIN3
#define HKPD_R2     MDIO_PIN4
#define HKPD_R3     MDIO_PIN5
#define HKPD_R4     MDIO_PIN6
void HKPD_voidInitialize();
u8   HKPD_u8GetButton();
#endif