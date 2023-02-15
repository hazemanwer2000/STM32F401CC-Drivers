
#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"

void main(void) {
	RCC_setPeripheralClockState(RCC_peripheral_GPIOA, RCC_clockState_On);

	GPIO_pinConfiguration_t pinCfg = {
		.port = GPIOA,
		.pinNumber = GPIO_pinNumber_0,
		.pinMode = GPIO_mode_Output_OpenDrain_PullUp,
		.pinSpeed = GPIO_speed_VeryHigh
	};

	GPIO_initializePin(&pinCfg);

	GPIO_selectAF(GPIOA, GPIO_pinNumber_11, GPIO_AF_7);
	GPIO_selectAF(GPIOA, GPIO_pinNumber_2, GPIO_AF_7);
}
