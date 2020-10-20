#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "LED.h"

const uint32_t led_mask[] = { 1UL << 1, 1UL << 0, 1UL << 4, 1UL << 0  };

/*----------------------------------------------------------------------------
  initialize LED Pins (GPION1, GPION0, GPIOF0, GPIOF4)
 *----------------------------------------------------------------------------*/
void LED_Initialize (void) {

	GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
#ifndef _RCC_GPIOH
#define _RCC_GPIOH
  __HAL_RCC_GPIOH_CLK_ENABLE();
#endif
#ifndef _RCC_GPIOD
#define _RCC_GPIOD
  __HAL_RCC_GPIOD_CLK_ENABLE();
#endif

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct. Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);	

}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_On (uint32_t num) {
		if (num < LED_NUM) {
    switch (num) {
      case 0: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,1); break;
      case 1: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,1); break;
      case 2: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,1); break;
      case 3: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,1); break;
    }
  }
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED_Off (uint32_t num) {
	if (num < LED_NUM) {
    switch (num) {
      case 0: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0); break;
      case 1: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0); break;
      case 2: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,0); break;
      case 3: HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,0); break;
    }
  }
}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_Toggle (uint32_t num) {
  if (num < LED_NUM) {
    switch (num) {
      case 0: HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12); break;
      case 1: HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13); break;
      case 2: HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14); break;
      case 3: HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15); break;
    }
  }
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
void LED_Out(uint32_t value) {
  int i;

  for (i = 0; i < LED_NUM; i++) {
    if (value & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
}
