/***********************************************************************/
/***********************************************************************/
/********************                           *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:          *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
/*Prescaler Timer1
TIMER0_PRESCALER_NoClockSRC
TIMER0_PRESCALER_1
TIMER0_PRESCALER_8
TIMER0_PRESCALER_64
TIMER0_PRESCALER_256
TIMER0_PRESCALER_1024

*/

// *******************************//


/*Prescaler Timer0
TIMER0_PRESCALER_NoClockSRC
TIMER0_PRESCALER_1
TIMER0_PRESCALER_8
TIMER0_PRESCALER_64
TIMER0_PRESCALER_256
TIMER0_PRESCALER_1024

*/
#define TIMER0_PRESCALER  TIMER0_PRESCALER_1024

# define TIMER1_PRESCALER  TIMER1_PRESCALER_1024
/*WaveGeneration mode Timer0
TIMER0_WGM_Fast_PWM    
TIMER0_WGM_CORRECT_PWM 
TIMER0_WGM_NORMAL      
TIMER0_WGM_CTC         
*/
 #define TIMER0_WAVE_GEN_MODE   TIMER0_WGM_CTC  

#endif
