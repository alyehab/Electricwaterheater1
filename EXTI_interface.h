/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: DIO               *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:         *************************/
/***********************************************************************/
/***********************************************************************/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#define EXTI_ID_INT0                    6
#define EXTI_ID_INT1                    7
#define EXTI_ID_INT2                    5

#define EXTI_SENSE_CTRL_LOW_LEVEL       0
#define EXTI_SENSE_CTRL_ON_CHANGE       1
#define EXTI_SENSE_CTRL_FALLING_EDGE    2
#define EXTI_SENSE_CTRL_RISING_EDGE     3 


u8 EXTI_u8EXTI_Enable(u8 copy_u8INTid,u8 copy_u8SenseControl);
u8 EXTI_u8EXTI_Disable(u8 copy_u8INTid);


#endif