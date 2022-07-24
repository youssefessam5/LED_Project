/******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef INTCTRL_H
#define INTCTRL_H


#include "Std_Types.h"

/* IntCtrl Pre-Compile Configuration Header file */
#include "IntCtrl_Cfg.h"

#include "Common_Macros.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
 /* Data Structure required for initializing the IntCtrl Priorty Group */
 typedef enum
{
	Group = 4, 
	Group_Group_SubGroup = 5,
	Group_SubGroup_SubGroup = 6,
	SubGroup = 7
}IntCtrl_PriortyGroup;
 
 typedef enum
{
	GPIO_Port_A,
	GPIO_Port_B,
	GPIO_Port_C,
	GPIO_Port_D,
	GPIO_Port_E,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator_0,
	PWM0_Generator_1,
	PWM0_Generator_2,
	QEI0,
	ADC0_Sequence_0,
	ADC0_Sequence_1,
	ADC0_Sequence_2,
	ADC0_Sequence_3,
	Watchdog_Timers_0_and_1,
	Bit_16_32_Timer_0A,
	Bit_16_32_Timer_0B,
	Bit_16_32_Timer_1A,
	Bit_16_32_Timer_1B,
	Bit_16_32_Timer_2A,
	Bit_16_32_Timer_2B	
} IntCtrl_InterruptType;


/* Data Structure required for initializing the IntCtrl Driver */
typedef struct
{
	IntCtrl_PriortyGroup priority_group;
	IntCtrl_InterruptType interrupt_type;
} IntCtrl_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO Initialization API */
void IntCtrl_Init(const IntCtrl_ConfigType * ConfigPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const IntCtrl_ConfigType IntCtrl_Configuration;

#endif /* INTCTRL_H */
