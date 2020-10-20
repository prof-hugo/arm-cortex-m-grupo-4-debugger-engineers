#include <stdbool.h>
#include "stm32f4xx_hal.h" 

#ifndef __BUTTON__
#define __BUTTON__

void (*button0)(void);
bool is_button0_defined = false;
void on_button(uint32_t num, void *callback);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void EXTI0_IRQHandler(void);

#endif