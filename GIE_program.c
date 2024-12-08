
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"

#include "GIE_register.h"
#include "GIE_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_Enable(void)
{
SET_BIT(SREG,7);
}
void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}





