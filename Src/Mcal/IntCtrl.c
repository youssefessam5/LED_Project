/******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/
 
#include "IntCtrl.h"
#include "IntCtrl_Regs.h"
//#include "tm4c123gh6pm_registers.h"


/************************************************************************************
* Service Name: IntCtrl_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the IntCtrl module.
************************************************************************************/
void IntCtrl_Init(const IntCtrl_ConfigType * ConfigPtr)
{
		/*Configure Grouping\SubGrouping System in APINT register in SCB*/
		SCB_APINT_REG_OFFSET = VECTKEY | ((ConfigPtr -> priority_group) << 8));
	
		/*Assign Group\SubGroup priorty in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
		wq
		
		/*Enable\Disable based on user configuration in NVIC_ENx and SCB_Sys Registers*/
		wq
}