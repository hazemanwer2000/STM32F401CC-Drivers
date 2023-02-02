/*************************************************************
 * 
 * Filename: RCC.h
 * Description: Header (interface) file of the RCC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __RCC_H__
#define __RCC_H__

#include "MCAL/UTIL/Std_Types.h"


/*************************************************************
 * Description: Enumeration type of the system clock.
 *
 *************************************************************/
typedef enum
{
	RCC_enuHSI = 0,
	RCC_enuHSE = 1,
	RCC_enuPLL = 2
} RCC_tenuSysClk;


/*************************************************************
 * Description: Enumeration type of the possible error status(es).\
 *
 *************************************************************/
typedef enum
{
	RCC_enuOk = 0,
	RCC_enuInvalidPLLCfg				/* Invalid PLL clock source, 'M', or 'N' values. */
} RCC_tenuErrorStatus;


/*************************************************************
 * Description: Enumeration type of 'P' prescale value (PLL).
 *
 *************************************************************/
typedef enum
{
	RCC_enuPLLP2 = 0,
	RCC_enuPLLP4,
	RCC_enuPLLP6,
	RCC_enuPLLP8,
} RCC_tenuPLLP;


/*************************************************************
 * Description: Macros of the limits of 'M' prescale value (PLL).
 *
 *************************************************************/
#define RCC_PLLM_MIN							2
#define RCC_PLLM_MAX							63


/*************************************************************
 * Description: Macros of the limits of 'N' factor value (PLL).
 *
 *************************************************************/
#define RCC_PLLN_MIN							192
#define RCC_PLLN_MAX							432


/*************************************************************
 * Description: Get system clock source currently in operation.
 * Parameters:
 *      [X]
 * Return:
 *      Error Status.
 *************************************************************/
void RCC_voidGetSysClk(RCC_tenuSysClk *Add_enuSysClk);


/*************************************************************
 * Description: Set as system clock source.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void RCC_voidSetSysClk(RCC_tenuSysClk Cpy_enuSysClk);


/*************************************************************
 * Description: Set PLL as system clock source.
 * Parameters:
 *   	[X]
 * Return:
 *      Error Status.
 *************************************************************/
RCC_tenuErrorStatus RCC_enuSetPLLAsSysClk(RCC_tenuSysClk Cpy_enuSrcClk, u8 Cpy_u8PrescaleM, u16 Cpy_u16FactorN, RCC_tenuPLLP Cpy_enuPrescaleP);


#endif /* __RCC_H__ */
