#define F_CPU 1000000
#include <util/delay.h>
// ************************ LIBRARY LAYER ************************ //
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// ****************** MICROCONTROLLER ABSTRACTION LAYER (MCAL) ****************** //
#include "SYSTEM_CONFIG.h"
#include "SYSTEM_INTERFACE.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMERS_interface.h"
#include "EEPROM_INTERFACE.h"
#include "EXTI_register.h"

// ******************** HARDWARE ABSTRACTION LAYER (HAL) ******************** //
#include "LED_interface.h"
#include "BUTTONS_INTERFACE.h"
#include "ssd.h"
#include "Cool_Heat_Elements.h"






void OFF_state(void) {
	SSD_turn_off();
	led_off();
	heat_stop();
	cool_stop();
	go_to_sleep();
}

void ON_state(void) {
	
	// If 100ms elapsed and flag is triggered
	// Measure temperature from the sensor, add to array, and get the average
	if (temp_measure_f == 1) {
		actual_temp = (ADC_read() * 0.5);
		add_new_temp(temp_arr, actual_temp);
		avg_temp = calc_avg_temp(temp_arr);
		temp_measure_f = 0;
	}

	SSD_write(actual_temp);

	// Turn cooler or heater ON/OFF based on average temperature
	change_temp();

	// Check if UP or DOWN buttons are pressed to switch to SETTING_MODE
 	if (UP_pressed() == PRESSED || DOWN_pressed() == PRESSED) {
	 setting_counter = 0;
	 	SSD_disable();
 		Curr_state = SETTING;
	}
}

void SET_state(void) {
	
	
      heat_stop();
   	cool_stop();
   	led_off();
 	

 	// to toggle the seven segment
 	// while writing the desired temperature
 
     	if(toggle_f==1){
     		SSD_write(desired_temp);
     	}
     	else{
     		SSD_turn_off();
     	}
		
   	// if UP or DOWN pressed, change the desired temp
   	// as long as it's still in range
   	
   if (UP_pressed()==PRESSED && desired_temp < MAX_TEMP) {
	   desired_temp += 5;   // Increase by 5
	   } else if (DOWN_pressed()==PRESSED && desired_temp > MIN_TEMP) {
	   desired_temp -= 5;   // Decrease by 5
   }

   
   if (UP_pressed() || DOWN_pressed()) {
	   SSD_write(desired_temp);  // Update the seven-segment display
	   setting_counter = 0;      // Reset the inactivity counter
   }
   	
  	EEPROM_write(0x0000,desired_temp);
}

void change_temp(void) {
	if ((desired_temp < avg_temp + MARGIN_TEMP) && (desired_temp > avg_temp - MARGIN_TEMP)) {
		// Actual Temperature equals Desired Temperature
		heat_stop();
		cool_stop();
		led_off();
		} else if (desired_temp < avg_temp + MARGIN_TEMP) {
		// Actual Temperature is Larger, turn Cooling element ON
		heat_stop();
		cool_start();
		led_on();
		} else if (desired_temp > avg_temp - MARGIN_TEMP) {
		// Actual Temperature is Smaller, turn Heating element ON
		heat_start();
		cool_stop();
		if (toggle_f == 1) {
			led_on();
			} else {
			led_off();
		}
	}
}

void temp_arr_init(void) {
	u16 first_temp = ADC_read() * 0.5;
	u8 i =0;
	for ( i = 0; i < NUM_OF_TEMP_MEASURES; i++) {
		temp_arr[i] = first_temp;
	}

	avg_temp = calc_avg_temp(temp_arr);
	arr_counter = 0;
}

void add_new_temp(u16 *arr, u16 new_val) {
	arr[arr_counter] = new_val;
	arr_counter++;

	if (arr_counter == NUM_OF_TEMP_MEASURES) {
		arr_counter = 0;
	}
}

u16 calc_avg_temp(u16 *arr) {
	u16 sum = 0;
	u8 i=0;
	u16 avg = 0 ;
	for ( i = 0; i < NUM_OF_TEMP_MEASURES; i++) {
		sum += arr[i];
	}
	avg = (u16) sum / NUM_OF_TEMP_MEASURES;
	return avg ;
}

void go_to_sleep(void) {
	CLR_BIT(MCUCR, 4);
	CLR_BIT(MCUCR, 5);
	CLR_BIT(MCUCR, 6);
	SET_BIT(MCUCR, 7);
}
