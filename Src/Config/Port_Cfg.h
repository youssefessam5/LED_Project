 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H   
   
/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (43U)
   
/* Number of the configured Port Modes */
#define PORT_CONFIGURED_MODES                 (10U)   

 /* Port Number in the array of structures in Port_PBcfg.c */
#define PortConf_PORTA_ID0_INDEX           (uint8)0x00
#define PortConf_PORTA_ID1_INDEX           (uint8)0x01
#define PortConf_PORTA_ID2_INDEX           (uint8)0x02
#define PortConf_PORTA_ID3_INDEX           (uint8)0x03
#define PortConf_PORTA_ID4_INDEX           (uint8)0x04
#define PortConf_PORTA_ID5_INDEX           (uint8)0x05
#define PortConf_PORTA_ID6_INDEX           (uint8)0x06
#define PortConf_PORTA_ID7_INDEX           (uint8)0x07
#define PortConf_PORTB_ID0_INDEX           (uint8)0x08
#define PortConf_PORTB_ID1_INDEX           (uint8)0x09
#define PortConf_PORTB_ID2_INDEX           (uint8)0x0A
#define PortConf_PORTB_ID3_INDEX           (uint8)0x0B
#define PortConf_PORTB_ID4_INDEX           (uint8)0x0C
#define PortConf_PORTB_ID5_INDEX           (uint8)0x0D
#define PortConf_PORTB_ID6_INDEX           (uint8)0x0E
#define PortConf_PORTB_ID7_INDEX           (uint8)0x0F
#define PortConf_PORTC_ID0_INDEX           (uint8)0x10
#define PortConf_PORTC_ID1_INDEX           (uint8)0x11
#define PortConf_PORTC_ID2_INDEX           (uint8)0x12
#define PortConf_PORTC_ID3_INDEX           (uint8)0x13
#define PortConf_PORTC_ID4_INDEX           (uint8)0x14
#define PortConf_PORTC_ID5_INDEX           (uint8)0x15
#define PortConf_PORTC_ID6_INDEX           (uint8)0x16
#define PortConf_PORTC_ID7_INDEX           (uint8)0x17
#define PortConf_PORTD_ID0_INDEX           (uint8)0x18
#define PortConf_PORTD_ID1_INDEX           (uint8)0x19
#define PortConf_PORTD_ID2_INDEX           (uint8)0x1A
#define PortConf_PORTD_ID3_INDEX           (uint8)0x1B
#define PortConf_PORTD_ID4_INDEX           (uint8)0x1C
#define PortConf_PORTD_ID5_INDEX           (uint8)0x1D
#define PortConf_PORTD_ID6_INDEX           (uint8)0x1E
#define PortConf_PORTD_ID7_INDEX           (uint8)0x1F
#define PortConf_PORTE_ID0_INDEX           (uint8)0x20
#define PortConf_PORTE_ID1_INDEX           (uint8)0x21
#define PortConf_PORTE_ID2_INDEX           (uint8)0x22
#define PortConf_PORTE_ID3_INDEX           (uint8)0x23
#define PortConf_PORTE_ID4_INDEX           (uint8)0x24
#define PortConf_PORTE_ID5_INDEX           (uint8)0x25
#define PortConf_PORTF_ID0_INDEX           (uint8)0x26
#define PortConf_PORTF_ID1_INDEX           (uint8)0x27
#define PortConf_PORTF_ID2_INDEX           (uint8)0x28
#define PortConf_PORTF_ID3_INDEX           (uint8)0x29
#define PortConf_PORTF_ID4_INDEX           (uint8)0x2A

/* PORT Configured Port ID's  */
#define PortConf_PORTA_NUM                   (Port_PortType)0 /* PORTA */
#define PortConf_PORTB_NUM                   (Port_PortType)1 /* PORTB */
#define PortConf_PORTC_NUM                   (Port_PortType)2 /* PORTC */
#define PortConf_PORTD_NUM                   (Port_PortType)3 /* PORTD */
#define PortConf_PORTE_NUM                   (Port_PortType)4 /* PORTE */
#define PortConf_PORTF_NUM                   (Port_PortType)5 /* PORTF */   

/* PORT Configured Channel ID's */
#define PortConf_CHANNEL0_NUM                (Port_PinType)0 /* Pin 0 */
#define PortConf_CHANNEL1_NUM                (Port_PinType)1 /* Pin 1 */
#define PortConf_CHANNEL2_NUM                (Port_PinType)2 /* Pin 2 */
#define PortConf_CHANNEL3_NUM                (Port_PinType)3 /* Pin 3 */
#define PortConf_CHANNEL4_NUM                (Port_PinType)4 /* Pin 4 */
#define PortConf_CHANNEL5_NUM                (Port_PinType)5 /* Pin 5 */
#define PortConf_CHANNEL6_NUM                (Port_PinType)6 /* Pin 6 */
#define PortConf_CHANNEL7_NUM                (Port_PinType)7 /* Pin 7 */

/* PORT Configured Default Mode */
#define PortConf_MODE_GPIO       (uint8)0   /* GPIO Mode */
#define PortConf_MODE_UART       (uint8)1   /* UART Mode */
#define PortConf_MODE_SSI        (uint8)2   /* SSI Mode */
#define PortConf_MODE_I2C        (uint8)3   /* I2C Mode */
#define PortConf_MODE_M0PWM      (uint8)4   /*M0PWM Mode */
#define PortConf_MODE_M0FAULT    (uint8)4   /*Motion Control Module  Mode */
#define PortConf_MODE_M1PWM      (uint8)5   /*M1PWM Mode */
#define PortConf_MODE_IDX_PHASE  (uint8)6   /* IDX AND PHASE Mode */
#define PortConf_MODE_TIMER      (uint8)7   /* TIMER  Mode */
#define PortConf_MODE_CAN        (uint8)8   /* CAN Mode */
#define PortConf_MODE_USB        (uint8)8   /* USB Mode */
#define PortConf_MODE_NMI        (uint8)8   /*Non-Maskable Interrupt*/
#define PortConf_MODE_ADC        (uint8)9   /* ADC Mode */

#endif /* PORT_CFG_H */
