# Digital-Lock-System

Simple Digital Lock System for ATM's using KeyPad and LCD and 2 Communication protocols.  Note: This program was made using Written drivers ( DIO , SPI , UART , KPD , LCD , DCMOTOR ) not the main avr libraries.

( UART ) for main options - can be replaced with special characters input from keypad for simpler functionality - .

( SPI ) for communication between the master and slave microcontroller

Note: UART protocol can also be replaced with third microcontroller and have more funtionalities and more safty concerning features 




Main Program : 

OPTION 1: Enter the default password - can be changed in the code 12345 - using keypad noramlly . you also can use the ON/C button to clear the last letter

OPTION 2: Entering the old password first ( default ) - you have 3 tries before system locks you out - after that you can assign the new password and try it once its setup.
