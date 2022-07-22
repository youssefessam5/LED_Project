 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

static const Port_ConfigChannel * Port_PortChannels = NULL_PTR;
static uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Port_Status       = PORT_INITIALIZED;
		Port_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */

          
          volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
          volatile uint32 delay = 0;
          volatile uint8 i;
          
          for(i = 0 ;i < PORT_CONFIGURED_CHANNLES ; i++)
          {
    
            switch(Port_PortChannels[i].port_num)
            {
                case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                        break;
                case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                        break;
                case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                        break;
                case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                        break;
                case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                        break;
                case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                        break;
            }
    
            /* Enable clock for PORT and allow time for clock to start*/
            SYSCTL_REGCGC2_REG |= (1 << Port_PortChannels[i].port_num);
            delay = SYSCTL_REGCGC2_REG;
    
            if( ((Port_PortChannels[i].port_num == 3) && (Port_PortChannels[i].pin_num == 7)) || ((Port_PortChannels[i].port_num == 5) && (Port_PortChannels[i].pin_num == 0)) ) /* PD7 or PF0 */
            {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = MAGIC_NUMBER;                     /* Unlock the GPIOCR register */   
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Port_PortChannels[i].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            }
            else if((Port_PortChannels[i].port_num == 2) && (Port_PortChannels[i].pin_num <= 3)) /* PC0 to PC3 */
            {
                continue; 
            }
            else
            {
                /* Do Nothing ... No need to unlock the commit register for this pin */
            }
            
            if ( Port_PortChannels[i].mode == PortConf_MODE_ADC)/*ADC Mode Select */
	     {
               SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[i].pin_num);/*SET Analog */
	       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[i].pin_num);/* Clear Digital */
	     }
	    else
	     {               
	       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[i].pin_num);/*Clear Analog */
	       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[i].pin_num);   /* Set Digital */
	     }

	    if (Port_PortChannels[i].mode == PortConf_MODE_GPIO)
	    {
	      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[i].pin_num); /* Clear Alternate Function To Select GPIO*/
	    }
	    else
	    {
	      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[i].pin_num); /* Set Alternate Function To Use Other Function Of Pin */
	    }
          
            if(Port_PortChannels[i].mode == PortConf_MODE_GPIO)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortChannels[i].pin_num * 4)); /* Set mode to Gpio */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_UART)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_UART << Port_PortChannels[i].pin_num * 4); /* Set mode to Uart */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_SSI)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_SSI << Port_PortChannels[i].pin_num * 4);  /* Set mode to SSI */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_I2C)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_I2C << (Port_PortChannels[i].pin_num * 4));  /* Set mode to I2C */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_M0PWM)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M0PWM << (Port_PortChannels[i].pin_num * 4));  /* Set mode to M0PWM */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_M0FAULT)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M0FAULT << (Port_PortChannels[i].pin_num * 4));   /* Set mode to Motion Control Module */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_M1PWM)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M1PWM << (Port_PortChannels[i].pin_num * 4));    /* Set mode to M1PWM */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_IDX_PHASE)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_IDX_PHASE << (Port_PortChannels[i].pin_num * 4));  /* Set mode to IDX AND PHASE */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_TIMER)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_TIMER << (Port_PortChannels[i].pin_num * 4));   /* Set mode to TIMER */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_CAN)
            {
              if(((Port_PortChannels[i].port_num == PortConf_PORTE_NUM) && (Port_PortChannels[i].pin_num == PortConf_CHANNEL0_NUM)) || 
                 ((Port_PortChannels[i].port_num == PortConf_PORTE_NUM) && (Port_PortChannels[i].pin_num == PortConf_CHANNEL3_NUM)))
              {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_I2C << Port_PortChannels[i].pin_num * 4);   /* Set mode to CAN with shift 3 */
              }
              else
              {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_CAN << Port_PortChannels[i].pin_num * 4);   /* Set mode to CAN with shift of 8 */
              }           
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_USB)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_USB << Port_PortChannels[i].pin_num * 4);   /* Set mode to USB */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_NMI)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_NMI << Port_PortChannels[i].pin_num * 4);   /* Set mode to NMI */
            }
            else if(Port_PortChannels[i].mode == PortConf_MODE_ADC)
            {
              /*Do Nothing*/
            }
            else
            {
              /* Do Nothing */
            }
            
            if(Port_PortChannels[i].direction == PORT_PIN_OUT)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[i].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
                if(Port_PortChannels[i].initial_value == STD_HIGH)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_PortChannels[i].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_PortChannels[i].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                }
            }
            else if(Port_PortChannels[i].direction == PORT_PIN_IN)
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
                if(Port_PortChannels[i].resistor == PULL_UP)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortChannels[i].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                }
                else if(Port_PortChannels[i].resistor == PULL_DOWN)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortChannels[i].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortChannels[i].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortChannels[i].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                }
            }
            else
            {
                /* Do Nothing */
            }
                  
        }
}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number.
*                  Direction - Port Pin Direction.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin direction.
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{  
        volatile uint32 * Port_Ptr = NULL_PTR;

                /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Port_PortChannels[Pin].port_num)
		{
            case 0:    Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
		               break;
            case 1:    Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
		               break;
            case 2:    Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
		               break;
            case 3:    Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
		               break;
            case 4:    Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
		               break;
            case 5:    Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
		               break;
		}
                
                if(Direction == PORT_PIN_OUT)
                {
                  SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[Pin].pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */  
                }
                else if (Direction == PORT_PIN_IN)
                {
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[Pin].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                }
                else
                {
                  /* No Action Required */
                }
}
//#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin  - Port Pin ID number.
                   Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	volatile uint32 * Port_Ptr = NULL_PTR;

          switch(Port_PortChannels[Pin].port_num)
            {
                case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                        break;
                case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                        break;
                case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                        break;
                case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                        break;
                case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                        break;
                case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                        break;
            }
          
            if (Mode == PortConf_MODE_ADC)/*ADC Mode Select */
	     {
               SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[Pin].pin_num);/*SET Analog */
	       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[Pin].pin_num);/* Clear Digital */
	     }
	    else
	     {               
	       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[Pin].pin_num);/*Clear Analog */
	       SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[Pin].pin_num);   /* Set Digital */
	     }

	    if (Mode == PortConf_MODE_GPIO)
	    {
	      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[Pin].pin_num); /* Clear Alternate Function To Select GPIO*/
	    }
	    else
	    {
	      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[Pin].pin_num); /* Set Alternate Function To Use Other Function Of Pin */
	    }
          
            if(Mode == PortConf_MODE_GPIO)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_UART)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_UART << Port_PortChannels[Pin].pin_num * 4);
            }
            else if(Mode == PortConf_MODE_SSI)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_SSI << Port_PortChannels[Pin].pin_num * 4);
            }
            else if(Mode == PortConf_MODE_I2C)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_I2C << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_M0PWM)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M0PWM << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_M0FAULT)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M0FAULT << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_M1PWM)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_M1PWM << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_IDX_PHASE)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_IDX_PHASE << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_TIMER)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_TIMER << (Port_PortChannels[Pin].pin_num * 4));
            }
            else if(Mode == PortConf_MODE_CAN)
            {
              if(((Port_PortChannels[Pin].port_num == PortConf_PORTE_NUM) && (Port_PortChannels[Pin].pin_num == PortConf_CHANNEL0_NUM)) || 
                 ((Port_PortChannels[Pin].port_num == PortConf_PORTE_NUM) && (Port_PortChannels[Pin].pin_num == PortConf_CHANNEL3_NUM)))
              {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_I2C << Port_PortChannels[Pin].pin_num * 4);
              }
              else
              {
                *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_CAN << Port_PortChannels[Pin].pin_num * 4);
              }
              
            }
            else if(Mode == PortConf_MODE_USB)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_USB << Port_PortChannels[Pin].pin_num * 4);
            }
            else if(Mode == PortConf_MODE_NMI)
            {
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)PortConf_MODE_NMI << Port_PortChannels[Pin].pin_num * 4);
            }
            else if(Mode == PortConf_MODE_ADC)
            {
              /*Do Nothing*/
            }
            else
            {
              /* Do Nothing */
            }
}
