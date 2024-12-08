/*
 * GccApplication1.c
 *
 * Created: 27-Nov-24 2:05:10 AM
 * Author : lenovo
 */ 
#define F_CPU 1000000
#include <util/delay.h>
#include <avr/interrupt.h>
// ************************ LIBRARY LAYER ************************ //
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// ****************** MICROCONTROLLER ABSTRACTION LAYER (MCAL) ****************** //
#include "SYSTEM_INTERFACE.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMERS_interface.h"
#include "EEPROM_INTERFACE.h"
#include "EXTI_register.h"
#include "GIE_interface.h"

// ******************** HARDWARE ABSTRACTION LAYER (HAL) ******************** //
#include "BUTTONS_INTERFACE.h"
#include "LED_interface.h"
#include "ssd.h"
#include "Cool_Heat_Elements.h"


int main(void)
{
	Curr_state=OFF;
    desired_temp=INIT_DESIRED_TEMP;
	Buttons_init();
	GIE_Enable();
	SSD_init();
	ADC_init();
	cool_init();
	heat_init();
	led_init();
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	
	while(1){
	
  		
  		switch (Curr_state){
  			case ON:{
  				ON_state();
  				break;
  			}
  			case OFF:{
  				OFF_state();
  				break;
  			}
  			case SETTING:{
  				SET_state();
  				break;
  			}
 		}
	}
}


ISR(INT2_vect){
	
	 
	if(Curr_state==OFF){
		Curr_state = ON;
	   desired_temp = EEPROM_read(0x0000);
	}
	else if (Curr_state==ON || Curr_state==SETTING){
		Curr_state = OFF;
	}
}


ISR(TIMER1_COMPA_vect){
	
	temp_measure_f = 1;
}
ISR(TIMER0_COMP_vect){
	toggle_f=0;
	u16 x ;
	if ((Curr_state==SETTING) || (Curr_state==ON)){
		setting_counter++;
		x= setting_counter % 4;
		if(x == 0){
        toggle_f ^= 1;
		}
		if (setting_counter > 20){	
			// Write the new desired temperature in EEPROM
			Curr_state = ON;
		}
	}
}

