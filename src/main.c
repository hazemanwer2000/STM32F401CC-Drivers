
#include "MCAL/RCC/RCC.h"

void main(void) {
	volatile RCC_status_t status;

	RCC_configureBusClock(RCC_bus_AHB, RCC_busPrescale_AHB_2);
}
