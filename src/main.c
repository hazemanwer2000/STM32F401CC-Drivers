
#include "MCAL/UTIL/Std_Types.h"
#include "MCAL/RCC/RCC.h"

void main(void)
{
	volatile RCC_tenuSysClk sysClk;
	RCC_voidGetSysClk(&sysClk);

	RCC_voidSetSysClk(RCC_enuHSE);
	RCC_voidGetSysClk(&sysClk);

	RCC_enuSetPLLAsSysClk(RCC_enuHSI, 24, 192, RCC_enuPLLP8);
	RCC_voidGetSysClk(&sysClk);

	RCC_voidSetSysClk(RCC_enuHSI);
	RCC_voidGetSysClk(&sysClk);
}
