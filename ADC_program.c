/***********************************************************************/
/***********************************************************************/
/********************                          *************************/
/********************  SWC: ADC                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:          *************************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"




void ADC_init(void)
{
	/*Reference Selection Bits AVCC with external capacitor at AREF pin*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	/*set channel*/
	ADMUX &= 0b11100000;
	ADMUX |= ADC_CHANNEL_0;
	/*ADC RIGHT Adjust Result select*/
	CLR_BIT(ADMUX,5);
	/*prescaler division factor8*/
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESCALER;
	/*ADC Enable*/
	SET_BIT(ADCSRA,7);
}
u16 ADC_read()
{
	u16 DATA ;
	/*start conversion*/
	SET_BIT(ADCSRA,6);
	/*waiting until flag=1 */
	while(GET_BIT(ADCSRA,4) == 0);
	// READ THE DATA 
	DATA = ADCL;
	DATA |= (ADCH<<8);
	/*clear flag*/
	SET_BIT(ADCSRA,4);
	/*return digital value 8 bits*/
	return DATA;
}

