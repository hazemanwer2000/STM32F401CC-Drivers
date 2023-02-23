/*************************************************************
 * 
 * Filename: BUTTON.c
 * Description: Source file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "BUTTON_Cfg.h"
#include "BUTTON_Priv.h"
#include "BUTTON.h"
#include "BUTTON_Types.h"


/*************************************************************
 * Description: Button initialization (based on configuration files).
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void BUTTON_init() {
	uint8_t i = 0;
	GPIO_pinConfiguration_t pinCfg = {
		.pinSpeed = GPIO_speed_High
	};

	for (i = 0; i < BUTTON_name_Count; i++) {
		pinCfg.port = BUTTON_cfgs[i].port;
		pinCfg.pinNumber = BUTTON_cfgs[i].pinNumber;
		pinCfg.pinMode = BUTTON_cfgs[i].pinMode;

		GPIO_initializePin(&pinCfg);
	}
}


/*************************************************************
 * Description: Get Button state.
 * Parameters:
 *      [1] Button name (configuration files).
 * Return:
 *      Button state.
 *************************************************************/
BUTTON_state_t BUTTON_get(BUTTON_name_t name) {
	return BUTTON_cfgs[name].activeMode ^ GPIO_readPinState(BUTTON_cfgs[name].port, BUTTON_cfgs[name].pinNumber);
}

