/*************************************************************
 * 
 * Filename: LED_Cfg.c
 * Description: Configuration source file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LED_Cfg.h"
#include "LED_Types.h"
#include "LED.h"


/*************************************************************
 * Description: (Definition) LED configurations.
 *
 *************************************************************/
LED_cfg_t LED_cfgs[LED_name_Count] = {
	[LED_name_0] = {GPIOA, GPIO_pinNumber_0, LED_activeMode_ActiveLow},
	[LED_name_1] = {GPIOA, GPIO_pinNumber_1, LED_activeMode_ActiveLow}
};
