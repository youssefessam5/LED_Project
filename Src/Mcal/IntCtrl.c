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

/************************************************************************************
* Service Name: IntCtrl_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the IntCtrl module.
************************************************************************************/
void IntCtrl_Init(const IntCtrl_ConfigType * ConfigPtr)
{
		Enable_Exceptions();
		Enable_Faults();
		/*Configure Grouping\SubGrouping System in APINT register in SCB*/
		SCB_APINT_REG_OFFSET = VECTKEY | ((ConfigPtr -> priority_group) << 8));
	
		/*Assign Group\SubGroup priorty in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
		wq
		
		/*Enable\Disable based on user configuration in NVIC_ENx and SCB_Sys Registers*/
		wq
}