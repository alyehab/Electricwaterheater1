#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H
#include "STD_TYPES.h"
#include "SYSTEM_CONFIG.h"

#define OFF 0
#define ON 1
#define SETTING 2


void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void); // cooler heater 
void add_new_temp(u16 * arr , u16 new_val);    
u16 calc_avg_temp(u16 * arr);  // calc avg 
void temp_arr_init(void); // store temp 
void go_to_sleep(void);  

u8 Curr_state;

u16 temp_arr[NUM_OF_TEMP_MEASURES];
u16 desired_temp;
u16 actual_temp;
u16 avg_temp;

u8  temp_measure_f;

 u8  setting_counter;
  u16 toggle_f;
u16 arr_counter;




#endif