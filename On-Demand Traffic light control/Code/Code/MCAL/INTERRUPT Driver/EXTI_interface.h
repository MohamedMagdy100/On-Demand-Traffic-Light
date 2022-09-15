/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    EXTI			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Sense Control*/
#define LOW_LEVEL				1
#define ON_CHANGE				2
#define FALLING_EDGE			3
#define RISING_EDGE				4

/*Interrupts Pins*/
#define INT0					1
#define INT1					2
#define INT2					3


void EXTI_voidINT0Init(void);

void EXTI_voidINT1Init(void);

void EXTI_voidINT2Init(void);

/*Description : Function to set the required Sense Control for INTx using Post-Build Configuration
 * Input:   Copy_u8INT  , 	Copy_u8SenseControl
 * Options: 1-INT0			1-LOW_LEVEL
 *          2-INT1			2-ON_CHANGE
 *          3-INT2			3-FALLING_EDGE
 *          				4-RISING_EDGE
 * Output: Error status with type u8
 *   */
u8 EXTI_u8INTSetSenseControl(u8 Copy_u8INT ,u8 Copy_u8SenseControl);

/*Description : Functions to Enable or Disable INTX using Post-Build Configuration
 * Input:   Copy_u8INT
 * Options: 1-INT0
 *          2-INT1
 *          3-INT2
 * Output: Error status with type u8
 *   */
u8 EXTI_u8INTEnable(u8 Copy_u8INT);
u8 EXTI_u8INTDisable(u8 Copy_u8INT);

/*Description : Functions to send ISR Function of INTX to implement it with its vector table number
 * Input:   (*Copy_pvINTx_ISR)(void)    --->   (x = 0,1,2)
 * Output: Error status with type u8
 *   */
u8 EXTI_u8INT0SetCallBack(void (*Copy_pvINT0_ISR)(void));
u8 EXTI_u8INT1SetCallBack(void (*Copy_pvINT1_ISR)(void));
u8 EXTI_u8INT2SetCallBack(void (*Copy_pvINT2_ISR)(void));

#endif
