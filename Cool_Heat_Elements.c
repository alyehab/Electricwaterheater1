#include "Cool_Heat_Elements.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"
#include "DIO_interface.h"
// Initialize Heat Element Pin as Output
void heat_init(void) {
	DIO_u8setPinDirection(DIO_PORTB,  DIO_PIN_4, DIO_PIN_OUTPUT);
}

// Initialize Cool Element Pin as Output
void cool_init(void) {
	DIO_u8setPinDirection( DIO_PORTB, DIO_PIN_5, DIO_PIN_OUTPUT);
}

// Start the Heat Element (Set the Pin High)
void heat_start(void) {
	DIO_u8setPinValue(DIO_PORTB,  DIO_PIN_4, DIO_PIN_HIGH);
}

// Start the Cool Element (Set the Pin High)
void cool_start(void) {
	DIO_u8setPinValue( DIO_PORTB, DIO_PIN_5, DIO_PIN_HIGH);
}

// Stop the Heat Element (Set the Pin Low)
void heat_stop(void) {
	DIO_u8setPinValue(DIO_PORTB,  DIO_PIN_4, DIO_PIN_LOW);
}

// Stop the Cool Element (Set the Pin Low)
void cool_stop(void) {
	DIO_u8setPinValue( DIO_PORTB, DIO_PIN_5, DIO_PIN_LOW);
}
