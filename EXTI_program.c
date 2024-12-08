
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


u8 EXTI_u8EXTI_Enable(u8 copy_u8INTid,u8 copy_u8SenseControl)
{
	u8 local_u8ErrState=OK;
	
	//PIE
	SET_BIT(GICR,copy_u8INTid);

	switch(copy_u8INTid)
	{
		case EXTI_ID_INT0:
		
		switch(copy_u8SenseControl)
		{
			
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
			default : local_u8ErrState=NOK;
			
			
		}
		
		break;
		case EXTI_ID_INT1:
		
		switch(copy_u8SenseControl)
		{
			
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			default : local_u8ErrState=NOK;
			
			
		}
		
		

		break;
		case EXTI_ID_INT2:
		
		switch(copy_u8SenseControl)
		{
			
			
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			CLR_BIT(MCUCSR,6);
			break;
			
			case EXTI_SENSE_CTRL_RISING_EDGE:
			SET_BIT(MCUCSR,6);
			break;
			default : local_u8ErrState=NOK;
			
		}
		
		
		break;
		default : local_u8ErrState=NOK;
		
	}



	return local_u8ErrState;

}
u8 EXTI_u8EXTI_Disable(u8 copy_u8INTid)
{
	CLR_BIT(GICR,copy_u8INTid);
}