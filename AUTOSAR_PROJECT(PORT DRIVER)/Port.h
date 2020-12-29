 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Omar Hany
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*PORT vendor ID*/
#define PORT_VENDOR_ID    (1000U)

/*PORT module ID*/
#define PORT_MODULE_ID   (124U)

/*PORT instance ID*/
#define PORT_INSTANCE_ID  (0U)




/* Module SW Version 1.0.0*/

#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3*/

#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*Definitions for port status*/

#define PORT_NOT_INITIALIZED   (0U)
#define PORT_INITIALIZED        (1U)



/*******************************************************************************
                                INCLUDES
*******************************************************************************/

/*include Standard types*/

#include "Std_Types.h"
/*AUTOSAR version checking*/
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION!=PORT_AR_RELEASE_MAJOR_VERSION)\
 ||(STD_TYPES_AR_RELEASE_MINOR_VERSION!=PORT_AR_RELEASE_MINOR_VERSION)\
 ||(STD_TYPES_AR_RELEASE_PATCH_VERSION!=PORT_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Std_Types.h doesn't match the expected version"
#endif

/*Include of pre-compile configuration file*/
   
#include "Port_Cfg.h"
   
/*check software version*/

#if ((PORT_SW_MAJOR_VERSION!=PORT_CFG_SW_MAJOR_VERSION)\
   ||(PORT_SW_MINOR_VERSION!=PORT_CFG_SW_MINOR_VERSION)\
   ||(PORT_SW_PATCH_VERSION!=PORT_CFG_SW_PATCH_VERSION))
#error " The software version of Port_Cfg.h doesn't match the expected version"
#endif
 
/*Check AUTOSAR version*/
#if ((PORT_AR_RELEASE_MAJOR_VERSION!=PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
   ||(PORT_AR_RELEASE_MINOR_VERSION!=PORT_CFG_AR_RELEASE_MINOR_VERSION)\
   ||(PORT_AR_RELEASE_PATCH_VERSION!=PORT_CFG_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Port_Cfg.h doesn't match the expected version"
#endif
   
   /* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

 /*Service ID for PORT initialization*/
#define PORT_INIT_SID                   (uint8)0x00

/*Service ID for PORT set pin direction*/
#define PORT_SET_PIN_DIRECTION_SID      (uint8)0x01
   
/*Service ID for PORT Refresh port direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID (uint8)0x02
   
 /* Service ID for PORT get version info*/
#define PORT_GET_VERSION_INFO_SID       (uint8)0x03
   
/*Service ID for PORT set pin mode*/
#define PORT_SET_PIN_MODE               (uint8)0x04
   
/*******************************************************************************
*                      DET Error Codes                                        *
*******************************************************************************/
   
/*Invalid Port Pin ID requested*/
#define PORT_E_PARAM_PIN                (uint8)0x0A
   
/*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
   
/*API Port_Init service called with wrong parameter*/
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
   
/*API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
   
/*API service called without module initialization*/
#define PORT_E_UNINIT                   (uint8)0x0F
   
/*APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER            (uint8)0x10
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/   
/*Type definition for Port_PinType used by Port APIs */
typedef uint8 Port_PinType;

/*Type definition for Port_PinDirectionType used by Port APIs*/
typedef enum{
  Input,Output
}Port_PinDirectionType;

/*Type definition for Port_PinModeType used by Port APIs*/
typedef uint8 Port_PinModeType;

/*Type definition for Port_ConfigType used by Port APIs*/ 
 typedef struct {
    Port_PinType Pin_ID;
    Port_PinDirectionType Dir;
    Port_PinModeType Mode;
    uint8 Digital_or_Analog;
    uint8 Init_Value;
    uint8 Pull_value;
    uint8 Pin_direction_changeable;
    uint8 Pin_mode_changeable;
   }Port_ConfigType;
 
/*******************************************************************************
*                      Function Prototypes                                    *
*******************************************************************************/
 
/*Function prototype for PORT Initialization API */
 void Port_Init(const Port_ConfigType* ConfigPtr);
 
/*Function Prototype for PORT set pin direction API*/

#if (PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif


/*Function Prototype for PORT Refresh Port direction API*/
void Port_RefreshPortDirection(void);

/*Function Prototype for PORT get version info API*/
#if (PORT_VERSION_INFO_API==STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/*Function Prototype for PORT set Pin mode API*/

#if (PORT_SET_PIN_MODE_API==STD_ON)

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

#endif

/*******************************************************************************
*                       External Variables                                    *
*******************************************************************************/

/*Extern Configuration Set that is used by PORT module*/
extern const Port_ConfigType Pins[PortNumberOfPortPins];


#endif /* PORT_H */
