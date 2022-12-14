/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    GIE				******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "GIE_interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
