/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    SWITCH			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"
#include "SW_config.h"
#include "SW_private.h"

#define SW_u8PULL_DOWN   		0
#define SW_u8PULL_UP 		  	1

#define SW_u8MOMENTARY			0
#define SW_u8MAINTAINED			1

#define SW_u8NOT_PRESSED 		0
#define SW_u8PRESSED 			1


typedef struct
{
	u8 Port;
	u8 Pin;
	u8 SelfLockingType;
	u8 PullType;
}SW_t;


//Pass address of variable to store the state of the switch in it
u8 SW_u8GetState(SW_t* Copy_u8Switch,u8* Copy_u8PressingState);


#endif
