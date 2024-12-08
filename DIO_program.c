
#include "EER_STATE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"



u8 DIO_u8setPinDirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8pinDirection)
{
	u8 Local_u8Err_state=OK;
	
	
	if(copy_u8pin>=DIO_PIN_0 && copy_u8pin<=DIO_PIN_7 )
	{
		
		if(copy_u8pinDirection == DIO_PIN_OUTPUT)
		{
			
			switch(copy_u8port)
			{
				case DIO_PORTA: SET_BIT(DDRA,copy_u8pin); break;
				case DIO_PORTB: SET_BIT(DDRB,copy_u8pin); break;
				case DIO_PORTC: SET_BIT(DDRC,copy_u8pin); break;
				case DIO_PORTD: SET_BIT(DDRD,copy_u8pin); break;
				default: Local_u8Err_state=NOK; break;
			}
			
			
			
		}
		else if(copy_u8pinDirection == DIO_PIN_INPUT)
		{
			
			switch(copy_u8port)
			{
				case DIO_PORTA: CLR_BIT(DDRA,copy_u8pin); break;
				case DIO_PORTB: CLR_BIT(DDRB,copy_u8pin); break;
				case DIO_PORTC: CLR_BIT(DDRC,copy_u8pin); break;
				case DIO_PORTD: CLR_BIT(DDRD,copy_u8pin); break;
				default: Local_u8Err_state=NOK; break;
			}
			
			
		}
		else
		{
			Local_u8Err_state=NOK;
		}
	}
	else
	{
		Local_u8Err_state=NOK;
	}
	
	return Local_u8Err_state;
}
u8 DIO_u8setPinValue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8pinValue)
{
	u8 Local_u8Err_state=OK;
	
	
	if(copy_u8pin>=DIO_PIN_0 && copy_u8pin<=DIO_PIN_7 )
	{
		
		if(copy_u8pinValue == DIO_PIN_HIGH)
		{
			
			switch(copy_u8port)
			{
				case DIO_PORTA: SET_BIT(PORTA,copy_u8pin); break;
				case DIO_PORTB: SET_BIT(PORTB,copy_u8pin); break;
				case DIO_PORTC: SET_BIT(PORTC,copy_u8pin); break;
				case DIO_PORTD: SET_BIT(PORTD,copy_u8pin); break;
				default: Local_u8Err_state=NOK; break;
			}
			
			
			
		}
		else if(copy_u8pinValue == DIO_PIN_LOW)
		{
			
			switch(copy_u8port)
			{
				case DIO_PORTA: CLR_BIT(PORTA,copy_u8pin); break;
				case DIO_PORTB: CLR_BIT(PORTB,copy_u8pin); break;
				case DIO_PORTC: CLR_BIT(PORTC,copy_u8pin); break;
				case DIO_PORTD: CLR_BIT(PORTD,copy_u8pin); break;
				default: Local_u8Err_state=NOK; break;
			}
			
			
		}
		else
		{
			Local_u8Err_state=NOK;
		}
	}
	else
	{
		Local_u8Err_state=NOK;
	}
	
	return Local_u8Err_state;
	
	
	
}
u8 DIO_u8getPinValue(u8 copy_u8port,u8 copy_u8pin,u8 *copy_pu8pinResult) // 0X100
{
	
	u8 Local_u8Err_state=OK;

	if(copy_u8pin>=DIO_PIN_0 && copy_u8pin<=DIO_PIN_7 )
	{
		switch(copy_u8port)
		{
			case DIO_PORTA: *copy_pu8pinResult = GET_BIT(PINA,copy_u8pin); break;
			case DIO_PORTB: *copy_pu8pinResult = GET_BIT(PINB,copy_u8pin); break;
			case DIO_PORTC: *copy_pu8pinResult = GET_BIT(PINC,copy_u8pin); break;
			case DIO_PORTD: *copy_pu8pinResult = GET_BIT(PIND,copy_u8pin); break;
			default: Local_u8Err_state=NOK; break;
		}
	}
	else
	{
		Local_u8Err_state=NOK;
	}
	
	return Local_u8Err_state;
	

	
}



u8 DIO_u8setPortDirection(u8 copy_u8port,u8 copy_u8portDirection)
{
	
	
	u8 Local_u8Err_state=OK;
	
	

		switch(copy_u8port)
		{
			case DIO_PORTA: DDRA=copy_u8portDirection; break;
			case DIO_PORTB: DDRB=copy_u8portDirection; break;
			case DIO_PORTC: DDRC=copy_u8portDirection; break;
			case DIO_PORTD: DDRD=copy_u8portDirection; break;
			default: Local_u8Err_state=NOK; break;
		}
		

	
	
	return Local_u8Err_state;
	
}


u8 DIO_u8setPortValue(u8 copy_u8port, u8 copy_u8portValue)
{
	
	
	u8 Local_u8Err_state=OK;
	

	switch(copy_u8port)
	{
		case DIO_PORTA: PORTA=copy_u8portValue; break;
		case DIO_PORTB: PORTB=copy_u8portValue; break;
		case DIO_PORTC: PORTC=copy_u8portValue; break;
		case DIO_PORTD: PORTD=copy_u8portValue; break;
		default: Local_u8Err_state=NOK; break;
	}
	


	return Local_u8Err_state;




}
u8 DIO_u8getPortValue(u8 copy_u8port, u8 *copy_pu8portResult)
{


	u8 Local_u8Err_state=OK;

	
	switch(copy_u8port)
	{
		case DIO_PORTA: *copy_pu8portResult = PINA; break;
		case DIO_PORTB: *copy_pu8portResult = PINB; break;
		case DIO_PORTC: *copy_pu8portResult = PINC; break;
		case DIO_PORTD: *copy_pu8portResult = PIND; break;
		default: Local_u8Err_state=NOK; break;
	}
	
	return Local_u8Err_state;
	



}
