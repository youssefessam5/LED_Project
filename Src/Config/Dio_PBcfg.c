 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "Dio.h"

/* PB structure used with Dio_Init API */
const Dio_ConfigType Dio_Configuration = {
                                             DioConf_LED1_PORT_NUM, DioConf_LED1_CHANNEL_NUM,
				             DioConf_SW1_PORT_NUM, DioConf_SW1_CHANNEL_NUM
				         };
