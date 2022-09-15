

#include "Application/Application.h"

int main(void)
{
	//TEST_voidModule();		//Module for testing the drivers
	
	APP_voidInit();				//Initialization of App	drivers and Components
    while (1) 
    {
	APP_voidStart();			//Starting our Project
    }
}
