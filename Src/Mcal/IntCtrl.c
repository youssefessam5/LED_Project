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

static const IntCtrl_ConfigChannel * IntCtrl_PortChannels = NULL_PTR;
static  volatile unsigned long  * Pri_Reg		=		NULL_PTR;
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
		Enable_Exceptions();
		Enable_Faults();
	
		volatile uint8 i;
		volatile uint32 Reg_Offset, Offset, Groups;
		IntCtrl_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
	
		for(i = 0 ;i < INTCTRL_CONFIGURED_CHANNLES ; i++)
		{
			Reg_Offset = ((IntCtrl_PortChannels[i].interrupt_type)/ WORD_LENGTH_BIT) * WORD_LENGTH_BYTE;
			Offset = (IntCtrl_PortChannels[i].interrupt_type) % WORD_LENGTH_BIT;
    
      switch(Reg_Offset / WORD_LENGTH_BYTE)
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
				switch(IntCtrl_PortChannels[i].priority_group)
				{
                case  Group: Groups = ((Group << 0) & 0x7) | (SubGroup & 0x0);
                        break;
                case  Group_Group_SubGroup: Groups = ((Group << 1) & 0x6) | (SubGroup & 0x1);
                        break;
                case  Group_SubGroup_SubGroup: Groups = ((Group << 2) & 0x4) | (SubGroup & 0x3);
                        break;
                case  SubGroup: Groups = ((Group << 3) & 0x0)|(SubGroup & 0x7);
                        break;
        }
			/*Configure Grouping\SubGrouping System in APINT register in SCB*/
			SCB_APINT_REG_OFFSET = VECTKEY | ((IntCtrl_PortChannels[i].priority_group) << 8);
			
			Reg_Offset = ((IntCtrl_PortChannels[i].interrupt_type) / INTCTRL_NUM_OF_PRI_FIELDS);
			Offset = INTCTRL_PRI_RESERVED + (((IntCtrl_PortChannels[i].interrupt_type)% INTCTRL_NUM_OF_PRI_FIELDS)*8);
			Pri_Reg =& (NVIC_PRI0_REG);
			Pri_Reg += Reg_Offset;
			*(Pri_Reg)|= (Groups << Offset);	
		}
}