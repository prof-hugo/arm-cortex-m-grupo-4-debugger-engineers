FreeRTOS version 10.4.0 on QEMU ARM 2.8.0-9.2:

* The Cortex-M3 port had to be used for STM32407 (a Cortex-M4F) because FPU is not implemented in QEMU-ARM.

* configASSERT of configPRIO_BITS had to be disabled in function xPortStartScheduler (in port.c) because PRIGROUP is not implemented in QEMU-ARM.

Hugo Vieira Neto, September 2020