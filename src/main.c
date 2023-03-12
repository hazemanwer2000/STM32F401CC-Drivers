
#include "NVIC.h"
#include "GPIO.h"
#include "RCC.h"
#include "SYSTICK.h"
#include "Std_Types.h"

#define __DEBUG_BKPT()  	__asm__("bkpt 0")

uint64_t counter = 0;

void __attribute__ ((section(".after_vectors")))
SysTick_Handler (void) {
	counter++;

	if (counter % 2 == 0) {
		GPIO_togglePin(GPIOA, GPIO_pinMask_0);
	}
}

RCC_status_t init_RCC() {
	RCC_status_t status = RCC_status_Ok;

	status = RCC_setSystemClockState(RCC_systemClock_HSE, RCC_clockState_On);
	if (status == RCC_status_Ok) {
		status = RCC_selectSystemClock(RCC_systemClock_HSE);
		if (status == RCC_status_Ok) {
			RCC_configureBusClock(RCC_bus_AHB, RCC_busPrescale_AHB_1);
			RCC_configureBusClock(RCC_bus_APB1, RCC_busPrescale_APB_1);
			RCC_configureBusClock(RCC_bus_APB2, RCC_busPrescale_APB_1);
		}
	}

	return status;
}

void init_GPIO() {
	GPIO_pinConfiguration_t pinCfg = {GPIOA, GPIO_pinNumber_0, GPIO_speed_High, GPIO_mode_Output_PushPull_Float};

	RCC_setPeripheralClockState(RCC_peripheral_GPIOA, RCC_clockState_On);
	GPIO_initializePin(&pinCfg);
	GPIO_resetPin(GPIOA, GPIO_pinMask_0);
}

void init_SYSTICK() {
	SYSTICK_enableException();
	SYSTICK_configureClockSource(SYSTICK_clockSource_AHB);
	SYSTICK_setPeriod_us(500000);
}

void __attribute__ ((noreturn))
main(void) {
	if (init_RCC() == RCC_status_Ok) {
		init_GPIO();
		init_SYSTICK();
	}

	SYSTICK_enable();

	while (1);
}
