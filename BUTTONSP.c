#define F_CPU 1000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Buttons_INTERFACE.h"
#include "DIO_interface.h"
#include "EXTI_register.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EXTI_interface.h"

void Buttons_init(void) {
		// Set button pins as input
		DIO_u8setPinDirection(DIO_PORTB, DIO_PIN_2, DIO_PIN_INPUT);
		DIO_u8setPinDirection(DIO_PORTB, DIO_PIN_1, DIO_PIN_INPUT);
		DIO_u8setPinDirection(DIO_PORTB, DIO_PIN_3, DIO_PIN_INPUT);

		// Enable internal pull-up resistors
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_2, DIO_PIN_HIGH);
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_1, DIO_PIN_HIGH);
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_3, DIO_PIN_HIGH);

		// Configure External Interrupt for ON/OFF Button (INT2)
		            
		SET_BIT(MCUCSR, 6);            // Trigger on Rising Edge
		SET_BIT(GICR, 5);              // Enable INT2
	}
	
	
	



u8 UP_pressed(void) {
	u8 pinValue=0;
	DIO_u8getPinValue(DIO_PORTB, DIO_PIN_1, &pinValue); // Read UP button state
	if (pinValue == DIO_PIN_LOW) {                  // Active low
		_delay_ms(DEBOUNCE_INTERVAL);               // Debounce delay
		DIO_u8getPinValue(DIO_PORTB, DIO_PIN_1, &pinValue);
		if (pinValue == DIO_PIN_LOW) {
			return PRESSED;
		}
		
	}
	else  return NOT_PRESSED;
}
u8 DOWN_pressed(void) {
	u8 pinValue=0;
	DIO_u8getPinValue(DIO_PORTB, DIO_PIN_3, &pinValue); // Read DOWN button state
	if (pinValue == DIO_PIN_LOW) {                    // Active low
		_delay_ms(DEBOUNCE_INTERVAL);                 // Debounce delay
		DIO_u8getPinValue(DIO_PORTB, DIO_PIN_3, &pinValue);
		if (pinValue == DIO_PIN_LOW) {
			return PRESSED;
		}
		
	}
	else  return NOT_PRESSED;
}

		

