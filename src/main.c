
#include "MCAL/RCC/RCC.h"
#include "HAL/LED/LED.h"
#include "HAL/BUTTON/BUTTON.h"

void main(void) {
	volatile BUTTON_state_t state = 2;

	RCC_setPeripheralClockState(RCC_peripheral_GPIOA, RCC_clockState_On);
	BUTTON_init();

	state = BUTTON_get(BUTTON_name_0);
	state = BUTTON_get(BUTTON_name_1);
	state = BUTTON_get(BUTTON_name_2);
	state = BUTTON_get(BUTTON_name_3);
}
