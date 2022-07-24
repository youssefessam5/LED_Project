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

static const IntCtrl_ConfigChannel * IntCtrl_PortChannels = NULL_PTR;
static uint8 IntCtrl_Status = INTCTRL_NOT_INITIALIZED;

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
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		IntCtrl_Status       = INTCTRL_INITIALIZED;
		IntCtrl_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
}