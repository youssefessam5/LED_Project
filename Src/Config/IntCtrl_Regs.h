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
/* Clock Register For All Ports */
#define SYSCTL_REGCGC2_REG       (*((volatile uint32 *)0x400FE108))

/* Magic Number Of Lock Register */
#define MAGIC_NUMBER                (uint32)0x4C4F434B;   

/* INTCTRL Registers base addresses */
#define CORTEXM4_PERIPHERAL_BASE_ADDRESS           0xE000E000


/* INTCTRL Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC

/* SCB Registers offset addresses */
#define SCB_INTCTRL_REG_OFFSET              0xD04
#define SCB_APINT_REG_OFFSET                0xD0C


#endif /* INTCTRL_REGS_H */