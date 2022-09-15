/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    LED				******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO Driver/DIO_interface.h"
#include "LED_config.h"
#include "LED_private.h"

#define LED_u8SINK				0
#define LED_u8SOURCE			1

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 ConnectionType;
}LED_t;

//For Connection Types put LED_u8SINK or LED_u8SOURCE
u8 LED_u8TurnOn(LED_t* Copy_u8LED);

u8 LED_u8TurnOff(LED_t* Copy_u8LED);

void LED_voidToggle(LED_t* Copy_u8LED);

#endif
