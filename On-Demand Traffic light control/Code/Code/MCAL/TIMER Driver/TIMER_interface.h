


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

/*Function to initialize Timer 0 in normal mode and setting initial of the counter with 0*/
void TIMER_voidTimer0Init(void);

/*Function to make delay with 256 prescaler*/
void TIMER_voidTimer0Delay(u32 Copy_u32Delayms);


#endif /* TIMER_INTERFACE_H_ */