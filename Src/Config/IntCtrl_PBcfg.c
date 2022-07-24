 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "IntCtrl.h"

/* PB structure used with Dio_Init API */
const IntCtrl_ConfigType IntCtrl_Configuration = {
                                             DioConf_LED1_PORT_NUM, DioConf_LED1_CHANNEL_NUM,
				             DioConf_SW1_PORT_NUM, DioConf_SW1_CHANNEL_NUM
				         };