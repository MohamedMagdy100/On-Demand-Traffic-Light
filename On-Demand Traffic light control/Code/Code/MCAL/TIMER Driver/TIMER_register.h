


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TCCR0 			*((volatile u8*)0x53)
#define TCCR0_WGM00		6
#define TCCR0_WGM01		3
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2

#define TCNT0 			*((volatile u8*)0x52)

#define TIFR 			*((volatile u8*)0x58)
#define TIFR_TOV0		0
#define TIFR_OCF0		1


#endif /* TIMER_REGISTER_H_ */