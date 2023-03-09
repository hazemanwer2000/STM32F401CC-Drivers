
/*
__attribute__ ((section(".sospecial")))
const uint32_t var1 = 0xF0F0F0FF;
*/

#include "MCAL/NVIC/NVIC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/RCC/RCC.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "MCAL/UTIL/Std_Types.h"

#define __DEBUG_BKPT()  asm volatile ("bkpt 0")

volatile uint8_t random = 0;

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

void main(void) {
	if (init_RCC() == RCC_status_Ok) {
		init_GPIO();
		init_SYSTICK();
	}

	SYSTICK_enable();

	while (1) {
		random = !random;
	}
}

uint64_t counter = 0;

void __attribute__ ((section(".after_vectors"),weak))
SysTick_Handler (void) {
	// __DEBUG_BKPT();
	counter++;

	if (counter % 10 == 0) {
		GPIO_togglePin(GPIOA, GPIO_pinMask_0);
	}
}

void __attribute__ ((section(".after_vectors")))
WWDG_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
PVD_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TAMP_STAMP_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
RTC_WKUP_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
FLASH_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
RCC_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI0_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI1_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI3_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI4_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream0_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream1_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream3_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream4_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream5_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream6_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
ADC_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI9_5_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM1_BRK_TIM9_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM1_UP_TIM10_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM1_TRG_COM_TIM11_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM1_CC_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM3_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM4_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C1_EV_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C1_ER_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C2_EV_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C2_ER_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
SPI1_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
SPI2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
USART1_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
USART2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
EXTI15_10_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
RTC_Alarm_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
OTG_FS_WKUP_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA1_Stream7_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
SDIO_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
TIM5_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
SPI3_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream0_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream1_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream2_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream3_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream4_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
OTG_FS_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream5_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream6_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
DMA2_Stream7_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
USART6_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C3_EV_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
I2C3_ER_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
FPU_IRQHandler(void) { __DEBUG_BKPT(); }

void __attribute__ ((section(".after_vectors")))
SPI4_IRQHandler(void) { __DEBUG_BKPT(); }
