 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Hany
 ******************************************************************************/
 /* Module SW Version 1.0.0*/

#define PORT_PBCFG_SW_MAJOR_VERSION           (1U)
#define PORT_PBCFG_SW_MINOR_VERSION           (0U)
#define PORT_PBCFG_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3*/

#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION   (3U)

#include "Port.h"

/*check SW Version*/ 
#if ((PORT_PBCFG_SW_MAJOR_VERSION!=PORT_SW_MAJOR_VERSION)\
  ||(PORT_PBCFG_SW_MINOR_VERSION!=PORT_SW_MINOR_VERSION)\
  ||(PORT_PBCFG_SW_PATCH_VERSION!=PORT_SW_PATCH_VERSION))
#error "The SW version of Port.h does not match the expected version"
#endif
 
/*Check AUTOSAR Version*/
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION!=PORT_AR_RELEASE_MAJOR_VERSION)\
   ||(PORT_PBCFG_AR_RELEASE_MINOR_VERSION!=PORT_AR_RELEASE_MINOR_VERSION)\
   ||(PORT_PBCFG_AR_RELEASE_PATCH_VERSION!=PORT_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Port.h does not match the expected version"
#endif
   
/* Array of Structures used in Port_init API*/
   
 const Port_ConfigType Pins[PortNumberOfPortPins]={
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_05,PORT_INPUT_PIN,PORT_DEFAULT_PIN_MODE,DIGITAL_PIN,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_PULL_UP,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_29,PORT_OUTPUT_PIN,PORT_DEFAULT_PIN_MODE,DIGITAL_PIN,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE},
   {PORT_PIN_01,PORT_DEFAULT_PIN_DIRECTION,PORT_DEFAULT_PIN_MODE,DEFAULT_PIN_DIGITAL_OR_ANALOG,PORT_DEFAULT_PIN_INITIAL_VALUE,PORT_DEFAULT_PULL_VALUE,PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE,PORT_PIN_DEFAULT_MODE_CHANGEABLE}};
     
