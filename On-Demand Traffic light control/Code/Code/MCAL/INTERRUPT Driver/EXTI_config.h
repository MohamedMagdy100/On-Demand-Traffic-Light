/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    EXTI			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*************************       Interrupt Sense Control Configuration:     *****************************
 **************** 	For Low Level interrupt sense control put LOW_LEVEL 			*********************
 ****************	For On Change interrupt sense control put ON_CHANGE 			*********************
 **************** 	For Falling edge interrupt sense control put FALLING_EDGE		*********************
 **************** 	For Rising edge interrupt sense control put RISING_EDGE			*********************
 ******************************************************************************************************* */
#define INT0_SENSE_CONTROL		FALLING_EDGE
#define INT1_SENSE_CONTROL		FALLING_EDGE
#define INT2_SENSE_CONTROL		FALLING_EDGE

/**********************    Peripheral Interrupt Initial state Configuration:     ************************
 **************** 	To initialize Peripheral Interrupt with Enable  put ENABLED 	*********************
 ****************	To initialize Peripheral Interrupt with Disable put DISABLED 	*********************
 ******************************************************************************************************* */
#define INT0_INITIAL_STATE 		ENABLED
#define INT1_INITIAL_STATE 		DISABLED
#define INT2_INITIAL_STATE 		DISABLED

#endif
