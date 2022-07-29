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
/* Type definition for GPT_PreScaler used by the GPT APIs */
typedef uint8 Gpt_PreScaler;

/* Type definition for GPT_ChannelType used by the GPT APIs */
typedef uint8 Gpt_ChannelType;

/* Type definition for Gpt_ValueType used by the GPT APIs */
typedef uint32 Gpt_ValueType;

typedef enum
{
  GPT_ONE_SHOT, GPT_CONTINUOUS
} Gpt_RunningMode;

typedef struct Gpt_ConfigChannel
{
	/* The Id of the channel */
  Gpt_ChannelType Gpt_ChannelNum;
	/* The channel running mode (one shott, continuous) */
  Gpt_RunningMode Gpt_ChannelRunningMode;
	/* The channel prescaler */
	Gpt_PreScaler   Gpt_prescaler;
} Gpt_ConfigChannel;

/* Data Structure required for initializing the Gpt Driver */
typedef struct
{
	Gpt_ConfigChannel Channels[GPT_CONFIGURED_CHANNLES];
} Gpt_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for GPT Initialization API */
void Gpt_Init(const Gpt_ConfigType * ConfigPtr);

/* Function starts a timer channel. */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/* Function to Setup the Gpt Timer call back */
void Gpt_SetCallBack(void (*Ptr2Func)(void));

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Gpt and other modules */
extern const Gpt_ConfigType Gpt_Configuration;

#endif /* GPT_H */
