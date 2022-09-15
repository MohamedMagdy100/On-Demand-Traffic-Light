
#include "Application.h"

/*Macros used in the application*/
#define NORMAL_MODE			1
#define PEDESTRIAN_MODE		2

#define CAR_GREEN_STATE		1
#define CAR_YELLOW_STATE	2
#define CAR_RED_STATE		3

/*Function Prototype*/
void ISR_TEST(void);		//Prototype of Interrupt service routine testing function
void ISR_APP(void);			//Prototype of Interrupt service routine application function
void pedestrianMode(void);	//Prototype of pedestrian mode cycle function


/*Leds Initializations*/
LED_t LED_GREEN_CARS = {DIO_u8PORTA,DIO_u8PIN0,LED_u8SOURCE};
LED_t LED_YELLOW_CARS = {DIO_u8PORTA,DIO_u8PIN1,LED_u8SOURCE};
LED_t LED_RED_CARS = {DIO_u8PORTA,DIO_u8PIN2,LED_u8SOURCE};
	
LED_t LED_GREEN_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN0,LED_u8SOURCE};
LED_t LED_YELLOW_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN1,LED_u8SOURCE};
LED_t LED_RED_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN2,LED_u8SOURCE};
	
LED_t LED_TEST_1 = {DIO_u8PORTC,DIO_u8PIN0,LED_u8SOURCE};
LED_t LED_TEST_2 = {DIO_u8PORTC,DIO_u8PIN7,LED_u8SOURCE};
	
/*Pedestrian Switch*/
SW_t PedestrianSwitch = {DIO_u8PORTD,DIO_u8PIN2,SW_u8MOMENTARY,SW_u8PULL_UP};
u8 ReadingState;
u32 longPress =0;
	
/*Variables of application*/
u8 mode = NORMAL_MODE;
u8 carTrafficState;
u8 pedestrianDone = 0;
#define MAX_PRESSED_DURATION	2000


void APP_voidInit(void)
{
	/*Port and Interrupt Initializations*/
	PORT_voidInit();
	EXTI_voidINT0Init();
	GIE_voidEnable();
	EXTI_u8INT0SetCallBack(&ISR_APP);
	TIMER_voidTimer0Init();
	
}

void APP_voidStart(void)
{
	while(mode == NORMAL_MODE)			//Normal mode will be on until the pedestrian pressed the button
	{
	carTrafficState = CAR_GREEN_STATE;	//Flag to know which color state in Car Traffic light 
	/*Turning Green led on for 5 second by making 100ms delay 50 times using for loop to check the mode continuously*/
	LED_u8TurnOn(&LED_GREEN_CARS);
	for (u8 i=0 ; i<50 ; i++)
	{
		TIMER_voidTimer0Delay(100);
		SW_u8GetState(&PedestrianSwitch,&ReadingState);
		/*Check for the press duration */
		while(ReadingState == SW_u8PRESSED)
		{
			SW_u8GetState(&PedestrianSwitch,&ReadingState);
			longPress++;
		}
		if (longPress > MAX_PRESSED_DURATION)
		{
			mode = NORMAL_MODE;
		}
		/*Applying the Pedestrian mode for the short press*/
		if(mode == PEDESTRIAN_MODE)
		{
			LED_u8TurnOff(&LED_RED_PEDESTRIAN);
			pedestrianMode();
			pedestrianDone = 1;
			break;
		}
	}
	if (pedestrianDone)
	{
		pedestrianDone=0;
		continue;
	}
	longPress = 0;
	
	LED_u8TurnOff(&LED_GREEN_CARS);
	
	/*Blinking Yellow led on for 5 second by making delay 1 second with 20ms delay 50 times using for loop  for 5 times to check the mode continuously*/
	carTrafficState = CAR_YELLOW_STATE;
	for (u8 i=0 ; i<5 ; i++)
	{
		LED_voidToggle(&LED_YELLOW_CARS);
		for(u8 i=0 ; i< 50; i++)
		{
			TIMER_voidTimer0Delay(20);
			SW_u8GetState(&PedestrianSwitch,&ReadingState);
			/*Check for the press duration */
			while(ReadingState == SW_u8PRESSED)
			{
				SW_u8GetState(&PedestrianSwitch,&ReadingState);
				longPress++;
			}
			if (longPress > MAX_PRESSED_DURATION)
			{
				mode = NORMAL_MODE;
			}
			/*Applying the Pedestrian mode for the short press*/
			if(mode == PEDESTRIAN_MODE)
			{
				LED_u8TurnOff(&LED_RED_PEDESTRIAN);
				pedestrianMode();
				pedestrianDone = 1;
				break;
			}
		}
		if (pedestrianDone)
		{
			break;
		}
	}
	if (pedestrianDone)
	{
		pedestrianDone=0;
		continue;
	}
	LED_u8TurnOff(&LED_YELLOW_CARS);
	longPress = 0;

/*Turning Red led on for 5 second by making 100ms delay 50 times using for loop to check the mode continuously*/
	carTrafficState = CAR_RED_STATE;
	LED_u8TurnOn(&LED_RED_CARS);
	for (u8 i=0 ; i<50 ; i++)
	{
		TIMER_voidTimer0Delay(100);
		SW_u8GetState(&PedestrianSwitch,&ReadingState);
		/*Check for the press duration */
		while(ReadingState == SW_u8PRESSED)
		{
			SW_u8GetState(&PedestrianSwitch,&ReadingState);
			longPress++;
		}
		if (longPress > MAX_PRESSED_DURATION)
		{
			mode = NORMAL_MODE;
		}
		/*Applying the Pedestrian mode for the short press*/
		if(mode == PEDESTRIAN_MODE)
		{
			LED_u8TurnOff(&LED_RED_PEDESTRIAN);
			pedestrianMode();
			pedestrianDone = 1;
			break;
		}
	}
	if (pedestrianDone)
	{
		pedestrianDone=0;
		continue;
	}
	LED_u8TurnOff(&LED_RED_CARS);
	longPress = 0;
	}
}

void TEST_voidModule(void)
{
	u8 i=0;
	PORT_voidInit();					//Setting the direction of ports
	EXTI_u8INT0SetCallBack(&ISR_TEST);  //Sending the address of ISR to implement the function with its vector table number
	EXTI_voidINT0Init();				//Initialization of Interrupt pre-configured in config file
	GIE_voidEnable();					//Enable SREG 7th bit (General Interrupt)
	TIMER_voidTimer0Init();				//Initialize Timer and putting it in Normal mode
	/*Toggling led for 10 seconds*/
	for(i=0 ; i<10 ; i++)
	{
		LED_voidToggle(&LED_TEST_2);
		TIMER_voidTimer0Delay(1000);
	}
}


void ISR_TEST(void)
{
	LED_u8TurnOn(&LED_TEST_1);	//Turning the LED Test on
}

void ISR_APP(void)
{
	mode = PEDESTRIAN_MODE;		//Switching to pedestrian mode when the button is pressed
}


void pedestrianMode(void)
{
	/*Close all the leds of Traffic lights*/
	LED_u8TurnOff(&LED_RED_CARS);
	LED_u8TurnOff(&LED_YELLOW_CARS);
	LED_u8TurnOff(&LED_GREEN_CARS);
	
	LED_u8TurnOff(&LED_RED_PEDESTRIAN);
	LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
	LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
	
	/*Checking in which state normal mode is interrupted*/
	switch(carTrafficState)
	{
		case CAR_RED_STATE:		//Normal mode is interrupted when the red led is on
		LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOn(&LED_RED_CARS);
		TIMER_voidTimer0Delay(5000);
		break;
		
		case CAR_GREEN_STATE: case CAR_YELLOW_STATE:	//Normal mode is interrupted when the green led or yellow led are on
		LED_u8TurnOn(&LED_RED_PEDESTRIAN);
		
		for(u8 i=0; i<5 ; i++)
		{
			LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
			LED_voidToggle(&LED_YELLOW_CARS);
			TIMER_voidTimer0Delay(1000);
		}
		LED_u8TurnOff(&LED_RED_PEDESTRIAN);
		LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
		LED_voidToggle(&LED_YELLOW_CARS);
		
		LED_u8TurnOn(&LED_RED_CARS);
		LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
		TIMER_voidTimer0Delay(5000);
		break;
	}
	/*Finishing the two states by closing the red car led and blinking both yellow leds for 5 seconds while the green pedestrian led is still on*/
	LED_u8TurnOff(&LED_RED_CARS);
	for(u8 i=0; i<5 ; i++)
	{
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		LED_voidToggle(&LED_YELLOW_CARS);
		TIMER_voidTimer0Delay(1000);
	}
	LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
	LED_u8TurnOff(&LED_YELLOW_CARS);
	
	LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
	LED_u8TurnOn(&LED_RED_PEDESTRIAN);
	LED_u8TurnOn(&LED_GREEN_CARS);
	mode = NORMAL_MODE;		//Going back to the Normal mode after the Pedestrian mode ends
}