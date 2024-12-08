#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EEPROM_INTERFACE.h"
#include "EEPROM_REGISTER.h"



u8 EEPROM_read(u16 addr) {
	// Setup Address Register
	EEARL = (u8)addr;             // Lower 8 bits of the address
	EEARH = (u8)(addr >> 8);      // Upper 8 bits of the address

	// Start Reading
	SET_BIT(EECR, 0);             // Set EERE (EEPROM Read Enable)

	// Return Data
	return EEDR;                  // EEPROM Data Register
}

void EEPROM_write(u16 addr, u8 data) {
	 EEARL = (u8)addr;             // Lower 8 bits of the address
	 EEARH = (u8)(addr >> 8);      // Upper 8 bits of the address

	 // Put Data in Data Register
	 EEDR = data;

	 // Start Writing
	 SET_BIT(EECR, 2);             // Set EEMWE (EEPROM Master Write Enable)
	 SET_BIT(EECR, 3);             // Set EEWE (EEPROM Write Enable)

	 // Wait for write operation to complete
	 while (GET_BIT(EECR, 3));
}


