/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    EXTI			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "EXTI_interface.h"

void (*EXTI_pvINT0_ISR_Func)(void) = NULL;
void (*EXTI_pvINT1_ISR_Func)(void) = NULL;
void (*EXTI_pvINT2_ISR_Func)(void) = NULL;

void EXTI_voidINT0Init(void)
{
	/*Set Sense Control for INT0*/
#if INT0_SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL == ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "Warning INT0_SENSE_CONTROL Configuration Option"
#endif

	/*Peripheral (Specific) interrupt for INT0*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Warning INT0_INITIAL_STATE Configuration Option"
#endif
}

void EXTI_voidINT1Init(void)
{
	/*Set Sense Control for INT1*/
#if INT1_SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT1_SENSE_CONTROL == ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#elif INT1_SENSE_CONTROL == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT1_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "Warning INT1_SENSE_CONTROL Configuration Option"
#endif

	/*Peripheral (Specific) interrupt for INT1*/
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Warning INT1_INITIAL_STATE Configuration Option"
#endif
}

void EXTI_voidINT2Init(void)
{
	/*Set Sense Control for INT2*/
#if INT2_SENSE_CONTROL == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Warning INT2_SENSE_CONTROL Configuration Option"
#endif

	/*Peripheral (Specific) interrupt for INT2*/
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Warning INT2_INITIAL_STATE Configuration Option"
#endif
}

u8 EXTI_u8INTSetSenseControl(u8 Copy_u8INT ,u8 Copy_u8SenseControl)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8INT == INT0)
	{
		switch(Copy_u8SenseControl)
		{
		case LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC01);	CLR_BIT(MCUCR,MCUCR_ISC00);	break;
		case ON_CHANGE:		CLR_BIT(MCUCR,MCUCR_ISC01);	SET_BIT(MCUCR,MCUCR_ISC00);	break;
		case FALLING_EDGE:  SET_BIT(MCUCR,MCUCR_ISC01);	CLR_BIT(MCUCR,MCUCR_ISC00);	break;
		case RISING_EDGE:   SET_BIT(MCUCR,MCUCR_ISC01);	SET_BIT(MCUCR,MCUCR_ISC00);	break;
		default: Local_u8ErrorState = NOT_OK;
		}
	}
	else if (Copy_u8INT == INT1)
	{
		switch(Copy_u8SenseControl)
		{
		case LOW_LEVEL:     CLR_BIT(MCUCR,MCUCR_ISC11);	CLR_BIT(MCUCR,MCUCR_ISC10);	break;
		case ON_CHANGE:     CLR_BIT(MCUCR,MCUCR_ISC11);	SET_BIT(MCUCR,MCUCR_ISC10);	break;
		case FALLING_EDGE:  SET_BIT(MCUCR,MCUCR_ISC11);	CLR_BIT(MCUCR,MCUCR_ISC10);	break;
		case RISING_EDGE:   SET_BIT(MCUCR,MCUCR_ISC11);	SET_BIT(MCUCR,MCUCR_ISC10);	break;
		default: Local_u8ErrorState = NOT_OK;
		}
	}
	else if (Copy_u8INT == INT2)
	{
		switch(Copy_u8SenseControl)
		{
		case FALLING_EDGE:	CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
		case RISING_EDGE:	SET_BIT(MCUCSR,MCUCSR_ISC2); break;
		default: Local_u8ErrorState = NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = NOT_OK;
	}

	return Local_u8ErrorState;
}


u8 EXTI_u8INTEnable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8INT == INT0)
	{
		SET_BIT(GICR,GICR_INT0);
	}
	else if (Copy_u8INT == INT1)
	{
		SET_BIT(GICR,GICR_INT1);
	}
	else if (Copy_u8INT == INT2)
	{
		SET_BIT(GICR,GICR_INT2);
	}
	else
	{
		Local_u8ErrorState = NOT_OK;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INTDisable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8INT == INT0)
	{
		CLR_BIT(GICR,GICR_INT0);
	}
	else if (Copy_u8INT == INT1)
	{
		CLR_BIT(GICR,GICR_INT1);
	}
	else if (Copy_u8INT == INT2)
	{
		CLR_BIT(GICR,GICR_INT2);
	}
	else
	{
		Local_u8ErrorState = NOT_OK;
	}

	return Local_u8ErrorState;
}


u8 EXTI_u8INT0SetCallBack(void (*Copy_pvINT0_ISR)(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvINT0_ISR != NULL)
	{
		EXTI_pvINT0_ISR_Func = Copy_pvINT0_ISR;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INT1SetCallBack(void (*Copy_pvINT1_ISR)(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvINT1_ISR != NULL)
	{
		EXTI_pvINT1_ISR_Func = Copy_pvINT1_ISR;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INT2SetCallBack(void (*Copy_pvINT2_ISR)(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvINT2_ISR != NULL)
	{
		EXTI_pvINT2_ISR_Func = Copy_pvINT2_ISR;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}




void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvINT0_ISR_Func != NULL)
	{
		EXTI_pvINT0_ISR_Func();
	}
	else
	{
		/* Do Nothing */
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvINT1_ISR_Func != NULL)
	{
		EXTI_pvINT1_ISR_Func();
	}
	else
	{
		/* Do Nothing */
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvINT2_ISR_Func != NULL)
	{
		EXTI_pvINT2_ISR_Func();
	}
	else
	{
		/* Do Nothing */
	}
}
