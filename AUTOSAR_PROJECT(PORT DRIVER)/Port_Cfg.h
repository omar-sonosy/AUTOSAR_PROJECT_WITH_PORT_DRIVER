 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Hany
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* Module SW Version 1.0.0*/

#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3*/

#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (3U)

/*Number of TM4C123GH6PM Microcontroller pins to be configured*/
#define PortNumberOfPortPins            (43U)

/*Pre-compile option for Development error detect*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/*Pre-compile option for set pin direction API*/
#define PORT_SET_PIN_DIRECTION_API      (STD_ON)

/*Pre-compile option for set pin mode API*/
#define PORT_SET_PIN_MODE_API           (STD_ON)

/*Pre_compile option for Read version info API*/
#define PORT_VERSION_INFO_API           (STD_ON)

/*Default pin Dierction*/
#define PORT_DEFAULT_PIN_DIRECTION      (Input)

/*Input Pin Direction*/
#define PORT_INPUT_PIN                  (Input)

/*Output Pin Direction*/
#define PORT_OUTPUT_PIN                 (Output)

/*default option for Port pin direction Changeable*/
#define PORT_PIN_DEFAULT_DIRECTION_CHANGEABLE   (STD_OFF)

/* value of Port pin direction Changeable*/
#define PORT_PIN_DIRECTION_CHANGEABLE   (STD_ON)

/*value of  option for Port pin direction not Changeable*/
#define PORT_PIN_DIRECTION_NOT_CHANGEABLE   (STD_OFF)


/*default option for Port pin mode Changeable*/
#define PORT_PIN_DEFAULT_MODE_CHANGEABLE        (STD_OFF)


/*value of  Port pin mode not Changeable*/
#define PORT_PIN_MODE_NOT_CHANGEABLE        (STD_OFF)

/*value of  Port pin mode Changeable*/
#define PORT_PIN_MODE_CHANGEABLE        (STD_ON)


/*Default Pin mode*/
#define PORT_DEFAULT_PIN_MODE           (0U)

/*Default Pin Initial Value*/
#define PORT_DEFAULT_PIN_INITIAL_VALUE  (STD_LOW)


/*Pull up activated*/
#define PORT_PULL_UP                    (1U)


/*Pull Down activated*/
#define PORT_PULL_DOWN                  (2U)


/*Built in Pull option is not activated*/ 
#define PORT_PULL_OFF                   (0U)


/*Default Pin Pull down Value*/
#define PORT_DEFAULT_PULL_VALUE         (PORT_PULL_OFF)



/*Digital or Analog definition*/
#define DIGITAL_PIN                     (STD_HIGH)
#define ANALOG_PIN                      (STD_LOW)
#define DEFAULT_PIN_DIGITAL_OR_ANALOG   (DIGITAL_PIN)



/*Definition of pin index used in Port_PBcfg.c*/
                                        /*0x(PORT)(Pin)*/
#define PORT_PIN_01                     (0xB6)
#define PORT_PIN_04                     (0xB7)
#define PORT_PIN_05                     (0xF4)
#define PORT_PIN_06                     (0xE3)
#define PORT_PIN_07                     (0xE2)
#define PORT_PIN_08                     (0xE1)
#define PORT_PIN_09                     (0xE0)
#define PORT_PIN_10                     (0xD7)
#define PORT_PIN_13                     (0xC7)
#define PORT_PIN_14                     (0xC6)
#define PORT_PIN_15                     (0xC5)
#define PORT_PIN_16                     (0xC4)
#define PORT_PIN_17                     (0xA0)
#define PORT_PIN_18                     (0xA1)
#define PORT_PIN_19                     (0xA2)
#define PORT_PIN_20                     (0xA3)
#define PORT_PIN_21                     (0xA4)
#define PORT_PIN_22                     (0xA5)
#define PORT_PIN_23                     (0xA6)
#define PORT_PIN_24                     (0xA7)
#define PORT_PIN_28                     (0xF0)
#define PORT_PIN_29                     (0xF1)
#define PORT_PIN_30                     (0xF2)
#define PORT_PIN_31                     (0xF3)
#define PORT_PIN_43                     (0xD4)
#define PORT_PIN_44                     (0xD5)
#define PORT_PIN_45                     (0xB0)
#define PORT_PIN_46                     (0xB1)
#define PORT_PIN_47                     (0xB2)
#define PORT_PIN_48                     (0xB3)
#define PORT_PIN_49                     (0xC3)
#define PORT_PIN_50                     (0xC2)
#define PORT_PIN_51                     (0xC1)
#define PORT_PIN_52                     (0xC0)
#define PORT_PIN_53                     (0xD6)
#define PORT_PIN_57                     (0xB5)
#define PORT_PIN_58                     (0xB4)
#define PORT_PIN_59                     (0xE4)
#define PORT_PIN_60                     (0xE5)
#define PORT_PIN_61                     (0xD0)
#define PORT_PIN_62                     (0xD1)
#define PORT_PIN_63                     (0xD2)
#define PORT_PIN_64                     (0xD3)




#endif /*PORT_CFG_H*/



