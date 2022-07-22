 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Youssef Essam
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#include "Std_Types.h"

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

#include "Common_Macros.h"
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PortType used by the PORT APIs */
typedef uint8 Port_PortType;

/* Type definition for Port_Mode used by the PORT APIs */
typedef uint8 Port_Mode;

/* Type definition for Port_PinDirectionType used by the PORT APIs */
typedef enum
{
    PORT_PIN_MODE_OFF, PORT_PIN_MODE_ON
}Port_ModeChangeability;

/* Type definition for Port_PinDirectionType used by the PORT APIs */
typedef enum
{
    PORT_PIN_OFF, PORT_PIN_ON
}Port_DirectionChangeability;

/* Type definition for Port_PinDirectionType used by the PORT APIs */
typedef enum
{
    PORT_PIN_IN, PORT_PIN_OUT
}Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/*
 * Description: Enum to hold internal resistor type for PIN.
 */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

typedef struct
{
    Port_PortType port_num; 
    Port_PinType pin_num; 
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_Mode mode;
    Port_DirectionChangeability direction_changeability;
    Port_ModeChangeability mode_changeability;  
}Port_ConfigChannel;

/* Data Structure required for initializing the Port Driver */
typedef struct Port_ConfigType
{
	Port_ConfigChannel Channels[PORT_CONFIGURED_CHANNLES];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for PORT Set Pin Direction API */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction);

/* Function for PORT Set Pin Mode API */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/* Function for PORT Initialization API */
void Port_Init(const Port_ConfigType * ConfigPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
