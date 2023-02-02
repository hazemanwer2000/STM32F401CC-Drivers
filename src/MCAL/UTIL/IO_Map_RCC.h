/*************************************************************
 *
 * Filename: IO_Map.h
 * Description: Macro definitions of the relevant I/O registers in the RCC module,
 * 					in the STM32F401CC.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 *
 *************************************************************/

#include "Std_Types.h"



/*************************************************************
 * Description: Register layout of the RCC module.
 *
 *************************************************************/
typedef struct
{
	u32 CR;					/* Usage: Enable HSI, HSE, PLL, CSS */
	u32 PLLCFGR;			/* Usage: Configure PLL */
	u32 CFGR;				/* Usage: AHB, APB1, APB2 prescale, System clock switch/status */
	u32 CIR;

	u32 AHB1RSTR;
	u32 AHB2RSTR;

	u32 RESERVED0[2];

	u32 APB1RSTR;
	u32 APB2RSTR;

	u32 RESERVED1[2];

	u32 AHB1ENR;
	u32 AHB2ENR;

	u32 RESERVED2[2];

	u32 APB1ENR;
	u32 APB2ENR;

	u32 RESERVED3[2];

	u32 AHB1LPENR;
	u32 AHB2LPENR;

	u32 RESERVED4[2];

	u32 APB1LPENR;
	u32 APB2LPENR;

	u32 RESERVED5[2];

	u32 BDCR;
	u32 CSR;

	u32 RESERVED6[2];

	u32 SSCGR;
	u32 PLLI2SCFGR;

	u32 RESERVED7[1];

	u32 DCKCFGR;
} __attribute__((packed, aligned(1))) IO_tstrucRCC;



/*************************************************************
 * Description: Bit layout of the RCC_CR register.
 *
 *************************************************************/
#define PLLRDY						25
#define PLLON						24

#define CSSON						19

#define HSEBYP						18
#define HSERDY						17
#define HSEON						16

#define HSIRDY						1
#define HSION						0



/*************************************************************
 * Description: Bit layout of the RCC_PLLCFGR register.
 *
 *************************************************************/
#define PLLQ3						27
#define PLLQ2						26
#define PLLQ1						25
#define PLLQ0						24

#define PLLSRC						22

#define PLLP1						17
#define PLLP0						16

#define PLLN8						14
#define PLLN7						13
#define PLLN6						12
#define PLLN5						11
#define PLLN4						10
#define PLLN3						9
#define PLLN2						8
#define PLLN1						7
#define PLLN0						6

#define PLLM5						5
#define PLLM4						4
#define PLLM3						3
#define PLLM2						2
#define PLLM1						1
#define PLLM0						0



/*************************************************************
 * Description: Bit layout of the RCC_CFGR register.
 *
 *************************************************************/
#define	PPRE22						15
#define PPRE21						14
#define PPRE20						13

#define PPRE12						12
#define PPRE11						11
#define PPRE10						10

#define HPRE3						7
#define HPRE2						6
#define HPRE1						5
#define HPRE0						4

#define SWS1						3
#define SWS0						2

#define SW1							1
#define SW0							0



/*************************************************************
 * Description: Bit layout of the RCC_AHB1ENR register.
 *
 *************************************************************/
#define DMA2EN						22
#define DMA1EN						21

#define CRCEN						12

#define GPIOHEN						7
#define GPIOEEN						4
#define GPIODEN						3
#define GPIOCEN						2
#define GPIOBEN						1
#define GPIOAEN						0



/*************************************************************
 * Description: Bit layout of the RCC_AHB2ENR register.
 *
 *************************************************************/
#define OTGFSEN						7



/*************************************************************
 * Description: Bit layout of the RCC_APB1ENR register.
 *
 *************************************************************/
#define PWREN						28

#define I2C3RN						23
#define I2C2RN						22
#define I2C1RN						21

#define USART2EN					17

#define SPI3EN						15
#define SPI2EN						14

#define WWDGEN						11

#define TIM5EN						3
#define TIM4EN						2
#define TIM3EN						1
#define TIM2EN						0



/*************************************************************
 * Description: Bit layout of the RCC_APB2ENR register.
 *
 *************************************************************/
#define TIM11EN						18
#define TIM10EN						17
#define TIM9EN						16

#define SYSCFGEN					14
#define SPI4EN						13
#define SPI1EN						12

#define SDIOEN						11

#define ADC1EN						8

#define USART6EN					5
#define USART1EN					4

#define TIM1EN						0



/*************************************************************
 * Description: Bit layout of the RCC_DCKCFGR register.
 *
 *************************************************************/
#define TIMPRE						24



/*************************************************************
 * Description: Base address of RCC module in the uC.
 *
 *************************************************************/
#define IO_RCC_BASE_ADD					0x40023800



/*************************************************************
 * Description: Structure pointer-macro to RCC module.
 *
 *************************************************************/
#define RCC 				((volatile IO_tstrucRCC *) IO_RCC_BASE_ADD)
