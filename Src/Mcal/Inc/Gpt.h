/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Gpt Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef GPT_H
#define GPT_H


#include "Std_Types.h"

/* Gpt Pre-Compile Configuration Header file */
#include "Gpt_Cfg.h"

#include "Common_Macros.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
 typedef enum
{
		
} Gpt_InterruptType;


/* Data Structure required for initializing the IntCtrl Driver */
typedef struct
{
	
} Gpt_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO Initialization API */
void Gpt_Init(const Gpt_ConfigType * ConfigPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Gpt_ConfigType Gpt_Configuration;

#endif /* GPT_H */
