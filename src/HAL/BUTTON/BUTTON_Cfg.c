/*************************************************************
 * 
 * Filename: BUTTON_Cfg.c
 * Description: Configuration source file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "BUTTON_Cfg.h"
#include "BUTTON_Types.h"
#include "BUTTON.h"
#include "MCAL/GPIO/GPIO.h"


/*************************************************************
 * Description: (Definition) BUTTON configurations.
 *
 *************************************************************/
BUTTON_cfg_t BUTTON_cfgs[BUTTON_name_Count] = {
	[BUTTON_name_0] = {GPIOA, GPIO_pinNumber_0, GPIO_mode_Input_PullDown, BUTTON_activeMode_ActiveHigh},
	[BUTTON_name_1] = {GPIOA, GPIO_pinNumber_1, GPIO_mode_Input_PullUp, BUTTON_activeMode_ActiveHigh},
	[BUTTON_name_2] = {GPIOA, GPIO_pinNumber_2, GPIO_mode_Input_PullDown, BUTTON_activeMode_ActiveLow},
	[BUTTON_name_3] = {GPIOA, GPIO_pinNumber_3, GPIO_mode_Input_PullUp, BUTTON_activeMode_ActiveLow}
};
