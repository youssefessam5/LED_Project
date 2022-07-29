/******************************************************************************
 *
 * Module: Main
 *
 * File Name: Main.c
 *
 * Description: Led Blinking
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "Port.h"
#include "Gpt.h"
#include "Dio.h"
#include "IntCtrl.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LED_toggle(void)
{
    Dio_LevelType state = Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
}

void Init_Task(void)
{
    /* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);
    
    /* Initialize Port Driver */
    Port_Init(&Port_Configuration);
	
    /* Initialize IntCtrl Driver */
    IntCtrl_Init(&IntCtrl_Configuration);

    /* Initialize Port Driver */
    Gpt_Init(&Gpt_Configuration);
}

int main(void)
{
	/* Initialize Function For Drivers */
	Init_Task();
	
	/* function to start timer */
	Gpt_StartTimer(TIMER0A, 65200);
	
	/* passing function to control led to call back function */
 	Gpt_SetCallBack(LED_toggle);
	
	while(1)
	{	
	}
	return 0;
}
