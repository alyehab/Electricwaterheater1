/***********************************************************************/
/***********************************************************************/
/********************                         *************************/
/********************  SWC: DIO               *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE: 24/9/2024         *************************/
/***********************************************************************/
/***********************************************************************/
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include "STD_TYPES.h"

#define DIO_PORTA            0
#define DIO_PORTB            1
#define DIO_PORTC            2
#define DIO_PORTD            3

#define DIO_PIN_0            0  
#define DIO_PIN_1			 1
#define DIO_PIN_2			 2
#define DIO_PIN_3			 3
#define DIO_PIN_4			 4
#define DIO_PIN_5			 5
#define DIO_PIN_6			 6
#define DIO_PIN_7			 7

#define DIO_PIN_INPUT        0
#define DIO_PIN_OUTPUT       1

#define DIO_PIN_LOW        0
#define DIO_PIN_HIGH       1

#define DIO_PORT_LOW        0X00
#define DIO_PORT_HIGH       0XFF


#define DIO_PORT_INPUT        0
#define DIO_PORT_OUTPUT       0XFF


u8 DIO_u8setPinDirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8pinDirection);
u8 DIO_u8setPinValue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8pinValue);

u8 DIO_u8tglPinValue(u8 copy_u8port,u8 copy_u8pin);


u8 DIO_u8getPinValue(u8 copy_u8port,u8 copy_u8pin,u8 *copy_pu8pinResult);




u8 DIO_u8setPortDirection(u8 copy_u8port,u8 copy_u8portDirection);
u8 DIO_u8setPortValue(u8 copy_u8port, u8 copy_u8portValue);
u8 DIO_u8getPortValue(u8 copy_u8port, u8 *copy_pu8portResult);


#endif