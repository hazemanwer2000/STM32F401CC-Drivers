/*************************************************************
 * 
 * Filename: BUTTON_Cfg.h
 * Description: Configuration header file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __BUTTON_CFG_H__
#define __BUTTON_CFG_H__

#include "BUTTON_Types.h"


/*************************************************************
 * Description: BUTTON active mode options.
 *
 *************************************************************/
#define BUTTON_activeMode_ActiveHigh 			0
#define BUTTON_activeMode_ActiveLow 			1


/*************************************************************
 * Description: (Type-Enum) BUTTON names.
 *
 *************************************************************/
typedef enum {
	BUTTON_name_0 = 0,
	BUTTON_name_1,
	BUTTON_name_2,
	BUTTON_name_3,
	BUTTON_name_Count
} BUTTON_name_t;


/*************************************************************
 * Description: (Declaration) BUTTON configurations.
 *
 *************************************************************/
extern BUTTON_cfg_t BUTTON_cfgs[BUTTON_name_Count];


#endif /* __BUTTON_CFG_H__ */
