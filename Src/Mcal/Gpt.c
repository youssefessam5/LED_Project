/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Gpt Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/
 
#include "Gpt.h"
#include "Gpt_Regs.h"
   

static const Gpt_ConfigChannel * Gpt_GptChannels = NULL_PTR;

/* Global pointer to function used to point upper layer functions
 * to be used in Call Back 
 */
static void (*g_Gpt_Call_Back_Ptr)(void) = NULL_PTR;

/************************************************************************************
* Service Name: Gpt_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the IntCtrl module.
************************************************************************************/
void Gpt_Init(const Gpt_ConfigType * ConfigPtr)
{
		volatile uint32 * GPT_Ptr = NULL_PTR;
		volatile uint32 delay = 0;
		volatile uint8 i = 0;
		Gpt_GptChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
		
		for(i = 0 ;i < GPT_CONFIGURED_CHANNLES ; i++)
		{
			/* Enable clock for GPT and allow time for clock to start */
			SYSCTL_RCGCTIMER_REG |= (1 << (Gpt_GptChannels[i].Gpt_ChannelNum));
			delay = SYSCTL_RCGCTIMER_REG;
			
			uint8 temp = (Gpt_GptChannels[i].Gpt_ChannelNum) / 2;
			if(temp >= 0 && temp<= 7)
			{
				GPT_Ptr = (volatile uint32 *)GPT_TIMER0_BASE_ADDRESS +(1000 * temp);
			}
			else
			{
				GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER2_BASE_ADDRESS +(1000 * (temp-8));
			}
   
			if( (Gpt_GptChannels[i].Gpt_ChannelNum)%2 == 0) /* we are in Timer A */
			{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),0);/* Clear the TAEN to disable the timer */
					if(Gpt_GptChannels[i].Gpt_ChannelRunningMode == GPT_ONE_SHOT) /* initialization of one shot / periodic mode */
					{
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) &= 0xFC;
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) |= 0x01; /* select one shot mode */
					}
					else 
					{
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) &= 0xFC;
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET) |= 0x02; /* select periodic mode */
					}
					*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAPR_REG_OFFSET) = Gpt_GptChannels[i].Gpt_prescaler;
				
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAMR_REG_OFFSET),4);/* make the timer count down */
			}      
			else /* Timer B */ 
			{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),8);/* Clear the TBEN to disable the timer */
					if(Gpt_GptChannels[i].Gpt_ChannelRunningMode == GPT_ONE_SHOT) /* initialization of one shot / periodic mode */
					{
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) &= 0xFC;
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) |= 0x01; /* select one shot mode */ 
					}
					else 
					{
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) &= 0xFC;
						*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET) |= 0x02; /* elect periodic mode */ 
					}	
				
					*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBPR_REG_OFFSET) = Gpt_GptChannels[i].Gpt_prescaler;
				
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBMR_REG_OFFSET),4);/* make the timer count down */
			}
			*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCFG_REG_OFFSET) = 0x04; /* operate in 16 bit mode */
	}
}

/************************************************************************************
* Service Name: Gpt_StartTimer
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): Channel - numeric identifier of the GPT channel 
* Parameters (in): Value - numeric value for the timer ticks 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Start a timer channel.
************************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
		volatile uint32 * GPT_Ptr = NULL_PTR;	
		uint8 temp = Channel / 2 ;
	
		if(temp >= 0 && temp <= 7)
		{
			GPT_Ptr = (volatile uint32 *)GPT_TIMER0_BASE_ADDRESS + (1000 * temp);
		}
		else
		{
			GPT_Ptr = (volatile uint32 *)GPT_WIDE_TIMER2_BASE_ADDRESS +(1000 * (temp-8));
		}
		
		if( Channel %2 ==0) /* Timer A */
		{
			*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTAILR_REG_OFFSET) = (uint16)Value;		
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),0);
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMIMR_REG_OFFSET),0);		
		}
		else /*Timer B*/
		{
			*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMTBILR_REG_OFFSET) = (uint16)Value;
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMCTL_REG_OFFSET),8);
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)GPT_Ptr + GPT_GPTMIMR_REG_OFFSET),8);	
		}
}

/************************************************************************************
* Service Name: Gpt_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Ptr2Func - Call Back function address
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the Gpt Timer call back
************************************************************************************/
void Gpt_SetCallBack(void(*Ptr2Func)(void))
{
    g_Gpt_Call_Back_Ptr = Ptr2Func;
}

/************************************************************************************
* Service Name: Gpt_Handler
* Description:  Timer0A ISR
************************************************************************************/
void TIMER0A_Handler(void)
{
	/* Check if the Timer0_setCallBack is already called */
    if(g_Gpt_Call_Back_Ptr != NULL_PTR)
    {
        (*g_Gpt_Call_Back_Ptr)(); /* call the function in the scheduler using call-back concept */
    }
    /* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
}