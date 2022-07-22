 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#include "Port.h"

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
                                             PortConf_PORTA_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL5_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL6_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTA_NUM, PortConf_CHANNEL7_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL5_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL6_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTB_NUM, PortConf_CHANNEL7_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL5_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL6_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTC_NUM, PortConf_CHANNEL7_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL5_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL6_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTD_NUM, PortConf_CHANNEL7_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTE_NUM, PortConf_CHANNEL5_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTF_NUM, PortConf_CHANNEL0_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTF_NUM, PortConf_CHANNEL1_NUM, PORT_PIN_OUT, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTF_NUM, PortConf_CHANNEL2_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTF_NUM, PortConf_CHANNEL3_NUM, PORT_PIN_IN, OFF, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON,
                                             PortConf_PORTF_NUM, PortConf_CHANNEL4_NUM, PORT_PIN_IN, PULL_UP, STD_LOW, PortConf_MODE_GPIO, PORT_PIN_ON, PORT_PIN_MODE_ON    
				         };  
