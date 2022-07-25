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
 
/* Type definition for GPT_ChannelType used by the GPT APIs */
typedef uint8 Gpt_ChannelType;

/* Type definition for Gpt_ValueType used by the GPT APIs */
typedef uint32 Gpt_ValueType;

/* Type definition for Gpt_ModeType used by the GPT APIs */
typedef enum
{
  GPT_MODE_NORMAL, Gpt_MODE_SLEEP
} Gpt_ModeType;

/* Type definition for Gpt_StateType used for each channel */
typedef enum
{
  INITIALIZED, RUNNING, STOPPED, EXPIRED
} Gpt_StateType;

/* Type definition for Gpt_InterruptOption used for each channel to enable interrupts */
typedef enum
{
  INTERRUPT_OFF, INTERRUPT_ON
} Gpt_InterruptOption;

typedef enum 
{
  WAKEUP_SOURCE_ON,WAKEUP_SOURCE_OFF
}Gpt_WakeupSourceOption;

/* Type definition for Gpt_InterruptOption used for each channel to enable interrupts */
typedef enum
{
  GPT_ONE_SHOTT, GPT_CONTINUOUS
} Gpt_RunningMode;

/* Description: Structure to configure each individual channel:
 *	1. The Id of the channel.
 *	2. The value of the channel (number of ticks).
 *      3. The channel status (initialized, running, stopped, expired).
 *      4. The channel wakeup interrupt option (on, off).
 *	5. The channel notification interrupt option (on, off).
 *	6. The channel running mode (one shott, continuous).
 */
typedef struct Gpt_ConfigChannel
{
  Gpt_ChannelType Gpt_ChannelNum;
  //Gpt_ValueType Gpt_ChannelValue; // this attribute send with function start_time()
  //Gpt_StateType Gpt_ChannelState; // all channels state in initialzation is (INITIALIZED)
  //Gpt_InterruptOption Gpt_EnableChannelWakeup; // all interrupt notifications must be disabled
  //Gpt_InterruptOption Gpt_EnableChannelNotification; // all wakeup notifications must be disabled
  Gpt_RunningMode Gpt_ChannelRunningMode; 
  Gpt_WakeupSourceOption Gpt_WakeupSource;
} Gpt_ConfigChannel;

/* Data Structure required for initializing the GPT Driver */
typedef struct Gpt_ConfigType
{
	Gpt_ConfigChannel Channels[GPT_CONFIGURED_CHANNLES];
} Gpt_ConfigType;

typedef struct Gpt_ConfigTypeDynamic
{
  Gpt_ChannelType Gpt_ChannelNum;
  Gpt_StateType Gpt_ChannelState;
  Gpt_InterruptOption Gpt_EnableChannelWakeup;
  Gpt_InterruptOption Gpt_EnableChannelNotification;
  bool Gpt_DirtyBitWakeup;
  bool Gpt_DirtyBitNotification;
}Gpt_ConfigTypeDynamic;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for GPT Initialization API */
void Gpt_Init(const Gpt_ConfigType * ConfigPtr);

/* Function starts a timer channel. */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/* Function stops a timer channel. */
void Gpt_StopTimer(Gpt_ChannelType Channel);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Gpt_ConfigType Gpt_Configuration;

#endif /* GPT_H */
