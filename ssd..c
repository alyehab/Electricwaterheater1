#define F_CPU 1000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"
#include "DIO_interface.h"
#include "ssd.h"

// Array for Numbers' Values (Common Cathode Encoding)
u8 Nums[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// Initialize Seven Segment Display
void SSD_init(void) {
	// Set seven-segment pins as output
	DIO_u8setPortDirection(DIO_PORTD, 0xFF); // Data pins as output

	// Set enable pins as output
	DIO_u8setPinDirection(DIO_PORTB, DIO_PIN_6, DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(DIO_PORTB, DIO_PIN_7, DIO_PIN_OUTPUT);

	// Disable seven-segment displays initially
	SSD_disable();
}

// Send data to Seven Segment Display
void SSD_send(u8 N) {
	DIO_u8setPortValue( DIO_PORTD, Nums[N]);
}

// Enable specific seven-segment display
void SSD_enable(u8 disp) {
	if (disp == DISP1) {
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_6, DIO_PIN_HIGH);
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_7, DIO_PIN_LOW);
		} else if (disp == DISP2) {
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_7, DIO_PIN_HIGH);
		DIO_u8setPinValue(DIO_PORTB, DIO_PIN_6, DIO_PIN_LOW);
	}
}

// Disable both seven-segment displays
void SSD_disable(void) {
	DIO_u8setPinValue(DIO_PORTB, DIO_PIN_6, DIO_PIN_LOW);
	DIO_u8setPinValue(DIO_PORTB, DIO_PIN_7, DIO_PIN_LOW);
}

// Turn off the seven-segment display
void SSD_turn_off(void) {
	DIO_u8setPortValue(DIO_PORTD, 0x00);
}

// Write a number on the seven-segment display
void SSD_write(u16 N) {
	u8 units = N % 10;            // Extract units digit
	u8 tens = (u8)(N / 10);       // Extract tens digit

	SSD_enable(DISP1);            // Enable first display (units)
	SSD_send(units);              // Send units digit
	_delay_ms(5);                 // Small delay for stable display

	SSD_enable(DISP2);            // Enable second display (tens)
	SSD_send(tens);               // Send tens digit
	_delay_ms(5);                 // Small delay for stable display
}

