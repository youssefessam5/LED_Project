 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver Registers
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef INTCTRL_REGS_H
#define INTCTRL_REGS_H

#include "Std_Types.h"

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/
/* VECTKEY Number Of APINT Register */
#define VECTKEY                (uint32)0xFA05   

/* INTCTRL Registers base addresses */
#define CORTEXM4_PERIPHERAL_BASE_ADDRESS            0xE000E000


/* INTCTRL Registers offset addresses */
#define PORT_DATA_REG_OFFSET                				0x3FC

/* SCB Registers offset addresses */
#define SCB_INTCTRL_REG_OFFSET              				(*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0xD04))
#define SCB_APINT_REG_OFFSET                				(*((volatile uint32 *)(CORTEXM4_PERIPHERAL_BASE_ADDRESS + 0xD0C))


#endif /* INTCTRL_REGS_H */