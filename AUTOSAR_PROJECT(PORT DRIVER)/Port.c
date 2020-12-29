 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Omar Hany
 ******************************************************************************/






/*******************************************************************************
*                               INCLUDES                                        *
********************************************************************************/
#include "Port.h"
#include "Port_Regs.h"

/*if the development error is ON*/

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"


/*Check The AUTOSAR version*/

#if ((PORT_AR_RELEASE_MAJOR_VERSION!=DET_AR_MAJOR_VERSION)\
  ||(PORT_AR_RELEASE_MINOR_VERSION!=DET_AR_MINOR_VERSION)\
  ||(PORT_AR_RELEASE_PATCH_VERSION!=DET_AR_PATCH_VERSION))
   
#error " The AUTOSAR version of Det.h doesn't match the expected one"
   
#endif
   
#endif
/*******************************************************************************
*                           Macros definitions                                  *
********************************************************************************/
   
   
#define PORT_MASK                       (0xF0)/*mask to extarct port value*/
#define PIN_MASK                        (0x0F)/*mask to extract pin mask in port*/
#define BYTE_MASK                       (0x0F)/*Byte of 'b 1111 used for masking*/  
#define LOCK_REGISTER_VALUE             (0x4C4F434B)/*magic number used in lock register*/

   
/*******************************************************************************
*                               Global Variables                                *
********************************************************************************/
   
   
static uint8 Port_Status= PORT_NOT_INITIALIZED;
static const Port_ConfigType * pins=NULL_PTR;/*pointer to the first structure in the config. set*/



/*******************************************************************************
*                         Static Functions Prototypes                           *
********************************************************************************/


static boolean Check_mode(Port_PinModeType Mode);

/*******************************************************************************
*                               APIs                                           *
********************************************************************************/




/*******************************************************************************
*Service Name: Port_Init
*Service ID[hex]: 0x00
*Sync/Async: Synchronous
*Reentrancy: Non Reentrant
*Parameters (in): ConfigPtr (Pointer to configuration set)
*Parameters (inout): None       
*Parameters (out): None
*Return value: None
*Description: Initializes the Port Driver module.
*********************************************************************************/


void Port_Init(const Port_ConfigType* ConfigPtr){
  uint8 pin_count=0; /*Variable used in the for loop of init pins*/
  uint8 current_pin_port_ID;/*variable to store the value of the port of cuurent pin*/ 
  uint8 current_pin_ID;/*Variable to store the mask of the curremt pin in the port*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
  if(ConfigPtr==NULL_PTR)
  {
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_INIT_SID,PORT_E_PARAM_PIN);
  
  
  }
   else
#endif
   { 
     pins=ConfigPtr;
     for(pin_count=0;pin_count<PortNumberOfPortPins;pin_count++){
       current_pin_port_ID=((ConfigPtr->Pin_ID)&PORT_MASK);
       current_pin_ID=((ConfigPtr->Pin_ID)&PIN_MASK);
       switch(current_pin_port_ID){
       case 0xA0:      {
                          if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                            {
                              SET_BIT(GPIO_PORTA_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                              CLEAR_BIT(GPIO_PORTA_DEN_REG,current_pin_ID);/*disable digital pin*/
                            }else{                                         /*if the pin is configured digital*/
                              CLEAR_BIT(GPIO_PORTA_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                              SET_BIT(GPIO_PORTA_DEN_REG,current_pin_ID);/*enable digital pin*/
                            }
                          /*check if the mode is default or not*/
                          if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                            CLEAR_BIT(GPIO_PORTA_AFSEL_REG,current_pin_ID);
                          }else{
                            SET_BIT(GPIO_PORTA_AFSEL_REG,current_pin_ID);
                          }
                          /*setting the mode of the pin*/
                          GPIO_PORTA_PCTL_REG=((GPIO_PORTA_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                          /*cehck the direction of the pin*/
                          if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                            /*if the pin is configured as input pin*/
                            CLEAR_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);/*clear bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTA_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTA_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTA_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTA_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTA_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTA_PUR_REG,current_pin_ID);
                            }
                          }else{
                            /*if the pin is output*/
                            SET_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);/*set bit as output bit*/
                            CLEAR_BIT(GPIO_PORTA_PUR_REG,current_pin_ID);/*clear pull up value*/
                            CLEAR_BIT(GPIO_PORTA_PDR_REG,current_pin_ID);/*clear pull down value*/
                            /*setting the initial value of the output pin*/
                            if((STD_LOW)==(ConfigPtr->Init_Value)){
                              CLEAR_BIT(GPIO_PORTA_DATA_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTA_DATA_REG,current_pin_ID);
                            }
                          }
                        }  
                        break;
                        
        case 0xB0:      {
                          if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                            {
                              SET_BIT(GPIO_PORTB_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                              CLEAR_BIT(GPIO_PORTB_DEN_REG,current_pin_ID);/*disable digital pin*/
                            }else{                                         /*if the pin is configured digital*/
                              CLEAR_BIT(GPIO_PORTB_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                              SET_BIT(GPIO_PORTB_DEN_REG,current_pin_ID);/*enable digital pin*/
                            }
                          /*check if the mode is default or not*/
                          if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                            CLEAR_BIT(GPIO_PORTB_AFSEL_REG,current_pin_ID);
                          }else{
                            SET_BIT(GPIO_PORTB_AFSEL_REG,current_pin_ID);
                          }
                          /*setting the mode of the pin*/
                          GPIO_PORTB_PCTL_REG=((GPIO_PORTB_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                          /*cehck the direction of the pin*/
                          if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                            /*if the pin is configured as input pin*/
                            CLEAR_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);/*cleat bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTB_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTB_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTB_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTB_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTB_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTB_PUR_REG,current_pin_ID);
                            }
                          }else{
                            /*if the pin is output*/
                            SET_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);/*set bit as output bit*/
                            CLEAR_BIT(GPIO_PORTB_PUR_REG,current_pin_ID);/*clear pull up value*/
                            CLEAR_BIT(GPIO_PORTB_PDR_REG,current_pin_ID);/*clear pull down value*/
                            /*setting the initial value of the output pin*/
                            if((STD_LOW)==(ConfigPtr->Init_Value)){
                              CLEAR_BIT(GPIO_PORTB_DATA_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTB_DATA_REG,current_pin_ID);
                            }
                          }
                        }
                        break;
        case 0xC0:      {
                          if((current_pin_ID)<=(uint8)3){
                            /*J-Tag pins, so it will be skipped*/
                          }else{
                             if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                              {
                                SET_BIT(GPIO_PORTC_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                                CLEAR_BIT(GPIO_PORTC_DEN_REG,current_pin_ID);/*disable digital pin*/
                              }else{                                         /*if the pin is configured digital*/
                                CLEAR_BIT(GPIO_PORTC_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                                SET_BIT(GPIO_PORTC_DEN_REG,current_pin_ID);/*enable digital pin*/
                              }
                            /*check if the mode is default or not*/
                            if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                              CLEAR_BIT(GPIO_PORTC_AFSEL_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTC_AFSEL_REG,current_pin_ID);
                            }
                            /*setting the mode of the pin*/
                            GPIO_PORTC_PCTL_REG=((GPIO_PORTC_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                            /*cehck the direction of the pin*/
                            if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                              /*if the pin is configured as input pin*/
                              CLEAR_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);/*cleat bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTC_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTC_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTC_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTC_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTC_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTC_PUR_REG,current_pin_ID);
                            }
                            }else{
                              /*the pin is output pin*/
                              SET_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);/*set bit as output bit*/
                              CLEAR_BIT(GPIO_PORTC_PUR_REG,current_pin_ID);/*clear pull up value*/
                              CLEAR_BIT(GPIO_PORTC_PDR_REG,current_pin_ID);/*clear pull down value*/
                              /*setting the initial value of the output pin*/
                              if((STD_LOW)==(ConfigPtr->Init_Value)){
                                CLEAR_BIT(GPIO_PORTC_DATA_REG,current_pin_ID);
                              }else{
                                SET_BIT(GPIO_PORTC_DATA_REG,current_pin_ID);
                              }
                            }                           
                          }
                        }
                        break;
        case 0xD0:      {
                           /*Unlock the registers in case of pin D7*/
                          if((current_pin_ID==7)){
                            GPIO_PORTD_LOCK_REG=LOCK_REGISTER_VALUE;
                            SET_BIT(GPIO_PORTD_CR_REG,current_pin_ID);
                          }else
                          {
                            /*For MISRA Rules*/
                          }
                          
                          if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                            {
                              SET_BIT(GPIO_PORTD_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                              CLEAR_BIT(GPIO_PORTD_DEN_REG,current_pin_ID);/*disable digital pin*/
                            }else{                                         /*if the pin is configured digital*/
                              CLEAR_BIT(GPIO_PORTD_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                              SET_BIT(GPIO_PORTD_DEN_REG,current_pin_ID);/*enable digital pin*/
                            }
                          /*check if the mode is default or not*/
                          if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                            CLEAR_BIT(GPIO_PORTD_AFSEL_REG,current_pin_ID);
                          }else{
                            SET_BIT(GPIO_PORTD_AFSEL_REG,current_pin_ID);
                          }
                          /*setting the mode of the pin*/
                          GPIO_PORTD_PCTL_REG=((GPIO_PORTD_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                          /*cehck the direction of the pin*/
                          if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                            /*if the pin is configured as input pin*/
                            CLEAR_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);/*cleat bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTD_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTD_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTD_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTD_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTD_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTD_PUR_REG,current_pin_ID);
                            }
                          }else{
                            /*the pin is output pin*/
                            SET_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);/*set bit as output bit*/
                            CLEAR_BIT(GPIO_PORTD_PUR_REG,current_pin_ID);/*clear pull up value*/
                            CLEAR_BIT(GPIO_PORTD_PDR_REG,current_pin_ID);/*clear pull down value*/
                            /*setting the initial value of the output pin*/
                            if((STD_LOW)==(ConfigPtr->Init_Value)){
                              CLEAR_BIT(GPIO_PORTD_DATA_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTD_DATA_REG,current_pin_ID);
                            }
                          }
                        }
                        break;
        case 0xE0:      {
                          if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                            {
                              SET_BIT(GPIO_PORTE_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                              CLEAR_BIT(GPIO_PORTE_DEN_REG,current_pin_ID);/*disable digital pin*/
                            }else{                                         /*if the pin is configured digital*/
                              CLEAR_BIT(GPIO_PORTE_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                              SET_BIT(GPIO_PORTE_DEN_REG,current_pin_ID);/*enable digital pin*/
                            }
                          /*check if the mode is default or not*/
                          if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                            CLEAR_BIT(GPIO_PORTE_AFSEL_REG,current_pin_ID);
                          }else{
                            SET_BIT(GPIO_PORTE_AFSEL_REG,current_pin_ID);
                          }
                          /*setting the mode of the pin*/
                          GPIO_PORTE_PCTL_REG=((GPIO_PORTE_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                          /*cehck the direction of the pin*/
                          if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                            /*if the pin is configured as input pin*/
                            CLEAR_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);/*cleat bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTE_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTE_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTE_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTE_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTE_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTE_PUR_REG,current_pin_ID);
                            }
                          }else{
                            /*the pin is output pin*/
                            SET_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);/*set bit as output bit*/
                            CLEAR_BIT(GPIO_PORTE_PUR_REG,current_pin_ID);/*clear pull up value*/
                            CLEAR_BIT(GPIO_PORTE_PDR_REG,current_pin_ID);/*clear pull down value*/
                            /*setting the initial value of the output pin*/
                            if((STD_LOW)==(ConfigPtr->Init_Value)){
                              CLEAR_BIT(GPIO_PORTE_DATA_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTE_DATA_REG,current_pin_ID);
                            }
                          }
                        }
                        break;
        case 0xF0:      {
                          /*Unlock the registers in case of pin F0*/
                          if((current_pin_ID==0)){
                            GPIO_PORTF_LOCK_REG=LOCK_REGISTER_VALUE;
                            SET_BIT(GPIO_PORTF_CR_REG,current_pin_ID);
                          }else
                          {
                            /*for MISRA Rules*/
                          }
                          
                          if((ConfigPtr->Digital_or_Analog)==(ANALOG_PIN))/*if the pin is conigured as analog*/
                            {
                              SET_BIT(GPIO_PORTF_AMSEL_REG,current_pin_ID);/*enable analog pin*/
                              CLEAR_BIT(GPIO_PORTF_DEN_REG,current_pin_ID);/*disable digital pin*/
                            }else{                                         /*if the pin is configured digital*/
                              CLEAR_BIT(GPIO_PORTF_AMSEL_REG,current_pin_ID);/*disable analog pin*/
                              SET_BIT(GPIO_PORTF_DEN_REG,current_pin_ID);/*enable digital pin*/
                            }
                          /*check if the mode is default or not*/
                          if(PORT_DEFAULT_PIN_MODE==(ConfigPtr->Mode)){
                            CLEAR_BIT(GPIO_PORTF_AFSEL_REG,current_pin_ID);
                          }else{
                            SET_BIT(GPIO_PORTF_AFSEL_REG,current_pin_ID);
                          }
                          /*setting the mode of the pin*/
                          GPIO_PORTF_PCTL_REG=((GPIO_PORTF_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((ConfigPtr->Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                          /*cehck the direction of the pin*/
                          if(PORT_INPUT_PIN==(ConfigPtr->Dir)){
                            /*if the pin is configured as input pin*/
                            CLEAR_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);/*cleat bit to set as input*/
                            /*check if the bit is pull up*/
                            if(PORT_PULL_UP==(ConfigPtr->Pull_value)){
                              /*set input as pull up*/
                              SET_BIT(GPIO_PORTF_PUR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTF_PDR_REG,current_pin_ID);
                            }
                            /*cehck if the bit is pull down*/
                            else if(PORT_PULL_DOWN==(ConfigPtr->Pull_value)){
                              /*set input as pull down*/
                              SET_BIT(GPIO_PORTF_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTF_PUR_REG,current_pin_ID);
                            }else{
                              /*if Pull option is disable or invalide pull value(default value)*/
                              CLEAR_BIT(GPIO_PORTF_PDR_REG,current_pin_ID);
                              CLEAR_BIT(GPIO_PORTF_PUR_REG,current_pin_ID);
                            }
                          }else{
                            /*pin is output pin*/
                            SET_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);/*set bit as output bit*/
                            CLEAR_BIT(GPIO_PORTF_PUR_REG,current_pin_ID);/*clear pull up value*/
                            CLEAR_BIT(GPIO_PORTF_PDR_REG,current_pin_ID);/*clear pull down value*/
                            /*setting the initial value of the output pin*/
                            if((STD_LOW)==(ConfigPtr->Init_Value)){
                              CLEAR_BIT(GPIO_PORTF_DATA_REG,current_pin_ID);
                            }else{
                              SET_BIT(GPIO_PORTF_DATA_REG,current_pin_ID);
                            }
                          }                          
                          
                        }
                        break;
         
       }
       ConfigPtr++;
       
       
     }
   }
  Port_Status=PORT_INITIALIZED;
}



/*******************************************************************************
*Service Name: Port_SetPinDirection
*Service ID[hex]: 0x01
*Sync/Async: Synchronous
*Reentrancy: Reentrant
*Parameters (in): Pin (Port Pin ID number)
                  Drection (Port Pin Direction)
*Parameters (inout): None       
*Parameters (out): None
*Return value: None
*Description: Sets the port pin direction
*********************************************************************************/

#if (PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction){
  
  boolean pin_found= STD_LOW;/*variable to indicate that pin is found among cinfig. set*/
  uint8 pin_index;/*variable to store the value of pin index in the config. set*/
  uint8 count=0;/*counter for the for loop*/
  uint8 current_pin_port_ID;/*variable to store the value of the port of cuurent pin*/ 
  uint8 current_pin_ID;/*Variable to store the mask of the curremt pin in the port*/
  
  /*check if the PORT module is initialized*/
  if(PORT_INITIALIZED==Port_Status){
    /*for loop to find the index of chosen pin among config. set*/
    for(count=0;count<PortNumberOfPortPins;count++){
      if(((pins+count)->Pin_ID)==Pin){
        pin_found= STD_HIGH;
        pin_index=count;
      }else{
        /*for MISRA Rules*/
      }
      
    }
    /*check if the pin is not found, report error*/
    if(STD_LOW==pin_found){
#if (PORT_DEV_ERROR_DETECT==STD_ON)
      Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN);
#endif
    }else{
      /*pin found*/
      /*extracting port number and pin mask*/
      current_pin_port_ID=(Pin&PORT_MASK);
      current_pin_ID=(Pin&PIN_MASK);
      /*check if the pin is configured as direction changeable*/
      if(((pins+pin_index)->Pin_direction_changeable)==PORT_PIN_DIRECTION_CHANGEABLE){
        switch(current_pin_port_ID){
          case 0xA0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);
                              }
                            }
                            break;
          case 0xB0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);
                              }
                            }
                            break;
          case 0xC0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);
                              }
                            } 
                            break;
                          
          case 0xD0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          case 0xE0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          case 0xF0:        {
                              if(Input==Direction){
                                CLEAR_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          
        }
      }else{
        /*if the pin is configured as not changeable, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE);
#endif   
      }
    }
    
  }else{
    /*if the Port module is not initialized, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_UNINIT);
#endif
  }
  
}

#endif



/*******************************************************************************
*Service Name: Port_RefreshPortDirection
*Service ID[hex]: 0x02
*Sync/Async: Synchronous
*Reentrancy: Non Reentrant
*Parameters (in): None
*Parameters (inout): None       
*Parameters (out): None
*Return value: None
*Description: Refreshes port direction
*********************************************************************************/

void Port_RefreshPortDirection(void){
  
  
  uint8 count;/*counter to loop on the config. set*/
  uint8 current_pin_port_ID;/*variable to store the value of the port of cuurent pin*/ 
  uint8 current_pin_ID;/*Variable to store the mask of the curremt pin in the port*/
  
  /*check if the port is already initialized*/
  if(PORT_INITIALIZED==Port_Status){
    for(count=0;count<PortNumberOfPortPins;count++){
      /*check if the pin is configured to direction not changeable*/
      if(((pins+count)->Pin_direction_changeable)==PORT_PIN_DIRECTION_NOT_CHANGEABLE){
        current_pin_port_ID=(((pins+count)->Pin_ID)&PORT_MASK);
        current_pin_ID=(((pins+count)->Pin_ID)&PIN_MASK);
        switch(current_pin_port_ID){
          case 0xA0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTA_DIR_REG,current_pin_ID);
                              }
                            }
                            break;
          case 0xB0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTB_DIR_REG,current_pin_ID);
                              }
                            }
                            break;
          case 0xC0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTC_DIR_REG,current_pin_ID);
                              }
                            } 
                            break;
                          
          case 0xD0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTD_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          case 0xE0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTE_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          case 0xF0:        {
                              if(((pins+count)->Dir)==PORT_INPUT_PIN){
                                CLEAR_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);
                                
                              }else{
                                SET_BIT(GPIO_PORTF_DIR_REG,current_pin_ID);
                              }
                            }
                            break;        
          
        }
        
        
      }else{
        /*For MISRA Rules*/
      }
    }
    
  }else{
    /*port is not initialized, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_REFRESH_PORT_DIRECTION_SID,PORT_E_UNINIT);
#endif
    
  }
  
  
  
  
  
}


/*******************************************************************************
*Service Name: Port_GetVersionInfo
*Service ID[hex]: 0x03
*Sync/Async: Synchronous
*Reentrancy: Non Reentrant
*Parameters (in): None
*Parameters (inout): None       
*Parameters (out): versioninfo (Pointer to where to store the version information of this module)
*Return value: None
*Description: Returns the version information of this module
*********************************************************************************/
#if (PORT_VERSION_INFO_API==STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){
  
  /*check if the PORT module is initialized*/
  if(PORT_INITIALIZED==Port_Status){
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    /*check if the pointer is Null pointer*/
    if(NULL_PTR==versioninfo){
      Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER);
    }
    else
#endif
    {
      /*setting Vendor ID*/
      versioninfo->vendorID=(uint16)PORT_VENDOR_ID;
      /*setting Module ID*/
      versioninfo->moduleID=(uint16)PORT_MODULE_ID ;
      /*setting sw major version*/
      versioninfo->sw_major_version=(uint8)PORT_SW_MAJOR_VERSION;
      /*setting sw minor version*/
      versioninfo->sw_minor_version=(uint8)PORT_SW_MINOR_VERSION;
      /*setting patch version*/
      versioninfo->sw_patch_version=(uint8)PORT_SW_PATCH_VERSION;
      
    }
    
    
  }else{
    /*port module is no initialized, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_UNINIT);
#endif
  }
  
  
}

#endif



/*******************************************************************************
*Service Name: Port_SetPinMode
*Service ID[hex]: 0x04
*Sync/Async: Synchronous
*Reentrancy: Reentrant
*Parameters (in): Pin           (Port Pin ID number)
                  Mode          (New Port Pin mode to be set on port pin)
*Parameters (inout): None       
*Parameters (out): None
*Return value: None
*Description: Sets the port pin mode.
*********************************************************************************/


#if (PORT_SET_PIN_MODE_API==STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode){
  
  boolean pin_found= STD_LOW;/*variable to indicate that pin is found among cinfig. set*/
  uint8 pin_index;/*variable to store the value of pin index in the config. set*/
  uint8 count=0;/*counter for the for loop*/
  uint8 current_pin_port_ID;/*variable to store the value of the port of cuurent pin*/ 
  uint8 current_pin_ID;/*Variable to store the mask of the curremt pin in the port*/
  
  /*check if the PORT module is initialized*/
  if(PORT_INITIALIZED==Port_Status){
    /*for loop to find the index of chosen pin among config. set*/
    for(count=0;count<PortNumberOfPortPins;count++){
      if(((pins+count)->Pin_ID)==Pin){
        pin_found= STD_HIGH;
        pin_index=count;
      }else{
        /*for MISRA Rules*/
      }
      
    }
    /*check if the pin is not found, report error*/
    if(STD_LOW==pin_found){
#if (PORT_DEV_ERROR_DETECT==STD_ON)
      Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_PIN);
#endif
    }else{
      /*pin found*/
      /*extracting port number and pin mask*/
      current_pin_port_ID=(Pin&PORT_MASK);
      current_pin_ID=(Pin&PIN_MASK);
      /*check if the pin is configured as mode changeable*/
      if(((pins+pin_index)->Pin_mode_changeable)==PORT_PIN_MODE_CHANGEABLE){
        switch(current_pin_port_ID){
          case 0xA0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTA_PCTL_REG=((GPIO_PORTA_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            }
                            break;
          case 0xB0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTB_PCTL_REG=((GPIO_PORTB_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            }
                            break;
          case 0xC0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTC_PCTL_REG=((GPIO_PORTC_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            } 
                            break;
                          
          case 0xD0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTD_PCTL_REG=((GPIO_PORTD_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            }
                            break;        
          case 0xE0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTE_PCTL_REG=((GPIO_PORTE_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            }
                            break;        
          case 0xF0:        {
                              if(Check_mode(Mode))/*check if the mode value is availaible*/
                              {
                                GPIO_PORTF_PCTL_REG=((GPIO_PORTF_PCTL_REG&(~(BYTE_MASK<<(current_pin_ID*4))))|(((Mode)&(BYTE_MASK))<<(current_pin_ID*4)));
                                
                              }else{/*Mode value unvalid, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
                                Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_PARAM_INVALID_MODE);
#endif
                              }
                            }
                            break;        
          
        }
      }else{
        /*if the pin is configured as not changeable, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_MODE_UNCHANGEABLE);
#endif   
      }
    }
    
  }else{
    /*if the Port module is not initialized, report error*/
#if (PORT_DEV_ERROR_DETECT==STD_ON)
    Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE,PORT_E_UNINIT);
#endif
  }
  
  
  
  
}




#endif



/*******************************************************************************
*                            Not AUTOSAR APIs                                  *
********************************************************************************/


/*******************************************************************************
*Function Name: Check_mode
*Sync/Async: Synchronous
*Reentrancy: Reentrant
**Parameters (in): Mode (value of pin mode)
*Parameters (inout): None       
*Parameters (out): Check (boolean value that refers if the mode value available)
*Description: Checks if the mode value availabe or not.
********************************************************************************/

static boolean Check_mode(Port_PinModeType Mode){
  
  boolean check=FALSE;
  
  switch(Mode){
    case 0:     check=TRUE;
                break;
    case 1:     check=TRUE;
                break;
    case 2:     check=TRUE;
                break;                
    case 3:     check=TRUE;
                break;   
    case 4:     check=TRUE;
                break;  
    case 5:     check=TRUE;
                break;
    case 6:     check=TRUE;
                break;                             
    case 7:     check=TRUE;
                break; 
    case 8:     check=TRUE;
                break;                
    case 9:     check=TRUE;
                break;                
    case 14:     check=TRUE;
                break;
    default:    check=FALSE;
                break;                
                
  }
  
  return check;
}

