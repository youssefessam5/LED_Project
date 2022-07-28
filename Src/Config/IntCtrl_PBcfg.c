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
                                             Bit_16_32_Timer_0A, SubGroup
				         };