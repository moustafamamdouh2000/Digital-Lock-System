/*************************/
/*	Title	:	Bit Math FILE	    */
/*	Author	:	Moustafa Mamdouh 	*/
/*	Version	:	1.0              	*/
/*	Date	:	August 22, 2021   	*/
/*************************/
#ifndef BITMATH_H_
#define BITMATH_H_

	#define SET_BIT(Var,BitNo) 					((Var) |= 1<<(BitNo))
	#define CLEAR_BIT(Var,BitNo) 				(Var &= (~(1 << BitNo)))
	#define TOGGLE_BIT(Var,BitNo) 				((Var) ^= 1<<(BitNo))
	#define GET_BIT(Var,BitNo)					((Var) = (Var)&1>>(BitNo))
	#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)	(0b##A7##A6##A5##A4##A3##A2##A1##A0)
	#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)	(0b#A7#A6#A5#A4#A3#A2#A1#A0)
	#define SET_BYTE(Var)						((Var)=(Var)|255)
	#define CLEAR_BYTE(Var)						((Var)=(Var)&0)
	#define SET_NIBBLE_LOW(Var)					((Var)=(Var)|15)
	#define	SET_NIBBLE_HIGH(Var)				((Var)=(Var)|240)
	#define	CLEAR_NIBBLE_LOW(Var)				((Var)=(Var)&240)
	#define CLEAR_NIBBLE_HIGH(Var)				((Var)=(Var)&15)

#endif
