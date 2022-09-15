/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    PORT			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "PORT_interface.h"


void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INIT_VALUE;
	PORTB = PORTB_INIT_VALUE;
	PORTC = PORTC_INIT_VALUE;
	PORTD = PORTD_INIT_VALUE;
}
