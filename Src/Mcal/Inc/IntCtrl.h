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
 *                              Definations                                    *
 *******************************************************************************/
 /* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("CPSID F") 

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")

#define WORD_LENGTH_BIT              32

#define WORD_LENGTH_BYTE             4

#define INTCTRL_NUM_OF_PRI_FIELDS    4 

#define INTCTRL_PRI_RESERVED         5

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
	Bit_16_32_Timer_2B,
	Analog_Comparator_0,
	Analog_Comparator_1,
	System_Control = 28,
	Flash_Memory_Control_and_EEPROM_Control,
	GPIO_PortF,	
	UART_2 = 33,
	SSI_1,
	Bit_16_32_Timer_3A,
	Bit_16_32_Timer_3B,
	I2C_1,
	QEI_1,
	CAN_0,
	CAN_1,
	Hibernation_Module,
	USB,
	PWM_Generator_3,
	uDMA_Software,
	uDMA_Error,
	ADC1_Sequence_0,
	ADC1_Sequence_1,
	ADC1_Sequence_2,
	ADC1_Sequence_3,																												
	SSI_2 = 57,
	SSI_3,
	UART_3,
	UART_4,
	UART_5,
	UART_6,
	UART_7,
	I2C_2 = 68,
	I2C_3,								
	Bit_16_32_Timer_4A,
	Bit_16_32_Timer_4B,
	Bit_16_32_Timer_5A = 92,
	Bit_16_32_Timer_5B,
	Bit_32_64_Timer_0A,
	Bit_32_64_Timer_0B,
	Bit_32_64_Timer_1A,
	Bit_32_64_Timer_1B,
	Bit_32_64_Timer_2A,
	Bit_32_64_Timer_2B,
	Bit_32_64_Timer_3A,
	Bit_32_64_Timer_3B,
	Bit_32_64_Timer_4A,
	Bit_32_64_Timer_4B,
	Bit_32_64_Timer_5A,
	Bit_32_64_Timer_5B,
	SYSTEM_Exception,
	PWM1_Generator_0 = 134,
	PWM1_Generator_1,
	PWM1_Generator_2,
	PWM1_Generator_3,
	PWM1_Fault,
} IntCtrl_InterruptType;


/* Data Structure required for initializing the IntCtrl Driver */
typedef struct
{
	IntCtrl_InterruptType interrupt_type;
	IntCtrl_PriortyGroup priority_group;
} IntCtrl_ConfigChannel;

/* Data Structure required for initializing the IntCtrl Driver */
typedef struct
{
	IntCtrl_ConfigChannel Channels[INTCTRL_CONFIGURED_CHANNLES];
} IntCtrl_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for IntCtrl Initialization API */
void IntCtrl_Init(const IntCtrl_ConfigType * ConfigPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by IntCtrl and other modules */
extern const IntCtrl_ConfigType IntCtrl_Configuration;

#endif /* INTCTRL_H */
