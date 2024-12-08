/***********************************************************************/
/***********************************************************************/
/********************                           *************************/
/********************  SWC: TIMERS                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
 
 /*TIMER0 Registers*/
#define TCCR0        (*(( volatile u8 *)0X53))
#define TCNT0        (*(( volatile u8 *)0X52))
#define OCR0         (*(( volatile u8 *)0X5C))
#define TIMSK        (*(( volatile u8 *)0X59))
#define TIFR         (*(( volatile u8 *)0X58))
#define TCCR1A        (*(( volatile u8 *)0X4F))
#define TCCR1B         (*(( volatile u8 *)0X4E))
#define OCR1AH        (*(( volatile u8 *)0X4B))
#define OCR1AL        (*(( volatile u8 *)0X4A))
#define OCR1BH        (*(( volatile u8 *)0X49))
#define OCR1BL        (*(( volatile u8 *)0X48))

#endif