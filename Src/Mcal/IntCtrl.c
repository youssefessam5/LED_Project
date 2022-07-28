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

//static const IntCtrl_ConfigChannel * IntCtrl_PortChannels = NULL_PTR;

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
	
		volatile uint8 i;
		volatile uint32 RegOffset, Offset;
	
		for(i = 0 ;i < INTCTRL_CONFIGURED_CHANNLES ; i++)
		{
			RegOffset = ((ConfigPtr->interrupt_type)/ WORD_LENGTH_BIT) * WORD_LENGTH_BYTE;
			Offset = (ConfigPtr->interrupt_type) % WORD_LENGTH_BIT;
    
      switch(RegOffset / WORD_LENGTH_BYTE)
				{
                case  0: SET_BIT(NVIC_EN0_REG,Offset); /* NVIC Enable 0 - 31  */
                        break;
                case  1: SET_BIT(NVIC_EN1_REG,Offset); /* NVIC Enable 32 - 63  */
                        break;
                case  2: SET_BIT(NVIC_EN2_REG,Offset); /* NVIC Enable 64 - 95  */
                        break;
                case  3: SET_BIT(NVIC_EN3_REG,Offset); /* NVIC Enable 96 - 127 */
                        break;
        }
		}
		/*Configure Grouping\SubGrouping System in APINT register in SCB*/
		SCB_APINT_REG_OFFSET = VECTKEY | ((ConfigPtr -> priority_group) << 8);
	
		/*Assign Group\SubGroup priorty in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
		//wq
		
}