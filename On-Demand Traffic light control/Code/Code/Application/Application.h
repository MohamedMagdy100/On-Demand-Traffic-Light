


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../LIB/STD_TYPES.h"
#include "../MCAL/PORT Driver/PORT_interface.h"
#include "../MCAL/DIO Driver/DIO_interface.h"
#include "../MCAL/GIE Driver/GIE_interface.h"
#include "../MCAL/INTERRUPT Driver/EXTI_interface.h"
#include "../MCAL/TIMER Driver/TIMER_interface.h"

#include "../ECUAL/LED Driver/LED_interface.h"
#include "../ECUAL/Switch Driver/SW_interface.h"

void APP_voidInit(void);
void APP_voidStart(void);

void TEST_voidModule(void);

#endif /* APPLICATION_H_ */