#ifndef EEPROM_REGISTER_H_
#define EEPROM_REGISTER_H_




#define EEARH   (*((volatile u8*)0x3F))
#define EEARL    (*((volatile u8*)0x3E))
#define EEDR   (*((volatile u8*)0x3D))
#define EECR   (*((volatile u8*)0x3C))



#endif