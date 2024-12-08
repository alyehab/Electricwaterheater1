#define F_CPU 1000000
#include <util/delay.h>
#include "LED_interface.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

void led_init(void){
	// LED IN THE PORTB
	DIO_u8setPinDirection(DIO_PORTB,DIO_PIN_0,DIO_PORT_OUTPUT);
	// LED IS INITIALLY IS OFF
	DIO_u8setPinValue(DIO_PORTB,DIO_PIN_0,DIO_PORT_LOW);
}
void led_on(void){
	DIO_u8setPinValue(DIO_PORTB,DIO_PIN_0,DIO_PORT_HIGH);
	
}
void led_off(void){
	DIO_u8setPinValue(DIO_PORTB,DIO_PIN_0,DIO_PORT_LOW);
}
