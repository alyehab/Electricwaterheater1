#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include "STD_TYPES.h"

#define PRESSED             1
#define NOT_PRESSED         0
#define DEBOUNCE_INTERVAL   100




void Buttons_init(void);
u8 UP_pressed(void);
u8 DOWN_pressed(void);



#endif