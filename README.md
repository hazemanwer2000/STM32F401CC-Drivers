# STM32F401CC-Drivers

This repository provides the complete ***Micro-Controller Abstraction Layer (MCAL)*** of the *STM32F401CC* microcontroller, based upon ARM Cortex M4, covering all built-in peripherals. A **Hardware Abstraction Layer (HAL)** accompanies, built upon the *MCAL*, and provides interfaces to many useful device modules.

Each driver in either the *MCAL* or *HAL* may consist of one or more of the following files:
* `DRIVER.h`, the header file of a driver, providing an interface to the layer above in the hierarchy.
* `DRIVER.c`, the source file of a driver (complements `DRIVER.h`).
* `DRIVER_Types.h`, the type-definition file of a driver, containing all types specific to a driver.
* `DRIVER_Priv.h`, the private header file of a driver, to be included by driver-associated files only.
* `DRIVER_Cfg.h`, the configuration header file of a driver.
* `DRIVER_Cfg.c`, the configuration source file of a driver (complements `DRIVER_Cfg.h`).
* `DRIVER_Reg.h` or `DRIVER_Map.h`, the register-definition file of a driver, usually corresponding to the memory interface of a particular peripheral (relevant only in *HAL*).

For a brief summary of command-line debugging using *GDB*, check out my [*Brief Summary of gdb*](brief_summary_of_gdb.ipynb) *Jupyter* notebook, that relies on *OpenOCD*'s GDB server to debug with remote embedded targets.
