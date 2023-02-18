# STM32F401CC-Drivers

This repository provides the complete ***Micro-Controller Abstraction Layer (MCAL)*** of the *STM32F401CC* microcontroller of the *AVR* family, covering all built-in peripherals. A **Hardware Abstraction Layer (HAL)** accompanies, built upon the *MCAL*, and provides interfaces to many useful device modules.

Each driver in either the *MCAL* or *HAL* consists of several files:
* `DRIVER.h`, the header file of a driver, providing an interface to layers higher in the hierarchy.
* `DRIVER.c`, the source file of a driver (complements `DRIVER.h`).
* `DRIVER_Cfg.h`, the configuration header file of a driver, providing initial pre-build configuration settings.
* `DRIVER_Cfg.c`, the configuration source file of a driver (complements `DRIVER_Cfg.h`).
* `DRIVER_Priv.h`, the private header file of a driver, to be included by driver-associated files only.
