 /******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Gpt Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "Gpt.h"

/* PB structure used with Gpt_Init API */
const Gpt_ConfigType IntCtrl_Configuration = {
                                             DioConf_LED1_PORT_NUM, DioConf_LED1_CHANNEL_NUM,
				             DioConf_SW1_PORT_NUM, DioConf_SW1_CHANNEL_NUM
				         };