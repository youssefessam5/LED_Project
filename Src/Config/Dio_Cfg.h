 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES              (2U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x01

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)5 /* PORTF */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)5 /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)4 /* Pin 4 in PORTF */

#endif /* DIO_CFG_H */
