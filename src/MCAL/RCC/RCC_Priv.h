/*************************************************************
 * 
 * Filename: RCC_Priv.h
 * Description: Private header file of the RCC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __RCC_PRIV_H__
#define __RCC_PRIV_H__

#include "RCC.h"


/*************************************************************
 * Description: Set system clock source on and wait until ready.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void RCC_voidSetSysClkOnAndWait(RCC_tenuSysClk Cpy_enuSysClk);


#endif /* __RCC_PRIV_H__ */
