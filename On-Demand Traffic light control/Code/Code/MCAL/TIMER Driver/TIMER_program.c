#include "TIMER_interface.h"
#include <math.h>

void TIMER_voidTimer0Init(void)
{
	/*Put Timer0 in Normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
}

void TIMER_voidTimer0Delay(u32 Copy_u32Delayms)
{
	/*Setting the clock source*/
	//Setting 256 prescaler
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
	
	f64 Local_f64TickTime = 256.0/1000.0;		//Calculating Tick time with 256 prescaler
	f64 Local_f64MaxDely = Local_f64TickTime *(1<<8);	//Calculate the max delay we can get with the tick time we have
	u32 Local_u32TimerInitialValue;	// Declaring variable to calculate the initial timer value in each state
	u32 Local_u32NumberOV;	//Declaring variable to calculate the number of overflows needed to generate time delay bigger than the max time delay
	u32 Local_u32OverflowCounter = 0;
	
	if(Copy_u32Delayms < Local_f64MaxDely)
	{
		Local_u32TimerInitialValue = (Local_f64MaxDely - Copy_u32Delayms)/Local_f64TickTime;
		/*Setting initial value of the timer*/
		TCNT0 = Local_u32TimerInitialValue;
		/*Busy waiting until overflow flag to be set*/
		while(GET_BIT(TIFR,TIFR_TOV0) == 0);
		/*Clear the overflow flag*/
		SET_BIT(TIFR,TIFR_TOV0);
		
	}
	else if(Copy_u32Delayms == Local_f64MaxDely)
	{
		/*Setting initial value of the timer*/
		TCNT0 = 0x00;
		/*Busy waiting until overflow flag to be set*/
		while(GET_BIT(TIFR,TIFR_TOV0) == 0);
		/*Clear the overflow flag*/
		SET_BIT(TIFR,TIFR_TOV0);
	}
	else
	{
		Local_u32NumberOV = ceil(Copy_u32Delayms/Local_f64MaxDely);
		Local_u32TimerInitialValue =(1<<8) - ((Copy_u32Delayms/Local_f64TickTime) / Local_u32NumberOV);
		/*Setting initial value of the timer*/
		TCNT0 = Local_u32TimerInitialValue;
		
		while(Local_u32OverflowCounter < Local_u32NumberOV)
		{
			/*Busy waiting until overflow flag to be set*/
			while(GET_BIT(TIFR,TIFR_TOV0) == 0);
			/*Clear the overflow flag*/
			SET_BIT(TIFR,TIFR_TOV0);
			
			Local_u32OverflowCounter++;
		}
		
	}
		
	/*Timer Stop*/
	TCCR0 = 0x00;
	
}
