/*************************************************************
 * 
 * Filename: RCC.c
 * Description: Source file of the RCC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "RCC_Cfg.h"
#include "RCC_Priv.h"
#include "RCC.h"

#include "MCAL/UTIL/IO_Map_RCC.h"
#include "UTIL/Bit_Utils.h"
#include "UTIL/Utils.h"
#include "MCAL/UTIL/Std_Types.h"



/*************************************************************
 * Description: Get system clock source currently in operation.
 * Parameters:
 *      [X]
 * Return:
 *      Error Status.
 *************************************************************/
void RCC_voidGetSysClk(RCC_tenuSysClk *Add_enuSysClk)
{
	*Add_enuSysClk = EXTRACT_FIELD(RCC->CFGR, SWS0, SWS1);
}


/*************************************************************
 * Description: Set system clock source on and wait until ready.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void RCC_voidSetSysClkOnAndWait(RCC_tenuSysClk Cpy_enuSysClk)
{
	u8 Loc_u8BitON = 0;
	u8 Loc_u8BitRDY = 0;

	switch (Cpy_enuSysClk)
	{
	case RCC_enuPLL:
		Loc_u8BitON = PLLON;
		Loc_u8BitRDY = PLLRDY;
		break;
	case RCC_enuHSE:
		Loc_u8BitON = HSEON;
		Loc_u8BitRDY = HSERDY;
		break;
	default:
		Loc_u8BitON = HSION;
		Loc_u8BitRDY = HSIRDY;
	}

	RCC->CR = SET_BIT(RCC->CR, Loc_u8BitON);   		/* Turn clock source on. */
	while (!GET_BIT(RCC->CR, Loc_u8BitRDY));		/* Wait until it is ready. */
}


/*************************************************************
 * Description: Set as system clock source.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void RCC_voidSetSysClk(RCC_tenuSysClk Cpy_enuSysClk)
{
	RCC_tenuSysClk Loc_enuCurrSysClk = RCC_enuHSI;

	RCC_voidSetSysClkOnAndWait(Cpy_enuSysClk);												/* Turn on and wait */
	RCC->CFGR = REPLACE_FIELD(RCC->CFGR, SW0, SW1, Cpy_enuSysClk);    						/* Select SysClk (SW) */

	do {
		RCC_voidGetSysClk(&Loc_enuCurrSysClk);												/* Wait until operating (SWS) */
	} while (Loc_enuCurrSysClk != Cpy_enuSysClk);
}


/*************************************************************
 * Description: Set PLL as system clock source.
 * Parameters:
 *   	[X]
 * Return:
 *      Error Status.
 *************************************************************/
RCC_tenuErrorStatus RCC_enuSetPLLAsSysClk(RCC_tenuSysClk Cpy_enuSrcClk, u8 Cpy_u8PrescaleM, u16 Cpy_u16FactorN, RCC_tenuPLLP Cpy_enuPrescaleP)
{
	RCC_tenuErrorStatus Loc_enuErrorStatus = RCC_enuOk;
	RCC_tenuSysClk Loc_enuCurrSysClk = RCC_enuHSI;
	u32 Loc_u32PLLCFGR = 0;

	if (Cpy_enuSrcClk == RCC_enuPLL || Cpy_u8PrescaleM < RCC_PLLM_MIN || Cpy_u8PrescaleM > RCC_PLLM_MAX || Cpy_u16FactorN < RCC_PLLN_MIN || Cpy_u16FactorN > RCC_PLLN_MAX)
	{
		Loc_enuErrorStatus = RCC_enuInvalidPLLCfg;   	/* Error: Invalid srcCLK, PLLM, or PLLN values */
	}
	else
	{
		RCC_voidGetSysClk(&Loc_enuCurrSysClk);  		/* Get current SysClk */

		if (Loc_enuCurrSysClk == RCC_enuPLL)			/* If PLL is currently operating ... */
		{
			RCC_voidSetSysClk(Cpy_enuSrcClk);				/* Turn on and switch to source clock */
		}
		else
		{
			RCC_voidSetSysClkOnAndWait(Cpy_enuSrcClk);   	/* Turn on source clock only */
		}

		RCC->CR = CLR_BIT(RCC->CR, PLLON);				/* 	Turn PLL off. */

														/* Finally, configure PLL */
		Loc_u32PLLCFGR = RCC->PLLCFGR;
		Loc_u32PLLCFGR = REPLACE_FIELD(Loc_u32PLLCFGR, PLLM0, PLLM5, Cpy_u8PrescaleM);
		Loc_u32PLLCFGR = REPLACE_FIELD(Loc_u32PLLCFGR, PLLN0, PLLN8, Cpy_u16FactorN);
		Loc_u32PLLCFGR = REPLACE_FIELD(Loc_u32PLLCFGR, PLLP0, PLLP1, Cpy_enuPrescaleP);
		Loc_u32PLLCFGR = REPLACE_BIT(Loc_u32PLLCFGR, PLLSRC, Cpy_enuSrcClk);
		RCC->PLLCFGR = Loc_u32PLLCFGR;

		RCC_voidSetSysClk(RCC_enuPLL);
	}

	return Loc_enuErrorStatus;
}
