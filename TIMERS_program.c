/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.1            *************************/
/********************  DATE:         *************************/
/***********************************************************************/
/***********************************************************************/
/*LIB*/
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_State.h"
/*MCAL*/
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#include "TIMERS_register.h"




void timer0_init()
{
	//CTC MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//PRESCALER
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER0_PRESCALER;
	//Compare value
	OCR0 = 244;
	//enable interrupt
	SET_BIT(TIMSK,1);
	sei();
	
}

void timer1_init(){
	// CTC MODE 
	SET_BIT(TCCR1B,3);
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	
	//PRESCALER
	TCCR1B &= 0b11111000;
	TCCR1B |= TIMER1_PRESCALER;
	
}
void timer1_INT_disable(){
	
	// Disable Interrupts when Comparing with values A and B
	CLR_BIT(TIMSK,4);
	
}


void timer1_INT_enable(){
	
	// Enable Interrupts when Comparing with values A and B
	SET_BIT(TIMSK,4);
	
}

