#include "button.h"

void button_Initialize (void) {

	GPIO_InitTypeDef gpio;

  /* GPIO Ports Clock Enable */
#ifndef _RCC_GPIOA
#define _RCC_GPIOA
  __HAL_RCC_GPIOA_CLK_ENABLE();
#endif
	
	/*Configure External Interrupt */
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	
	/*Configure SysTick */
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  /*Configure GPIO pins : PA0 */
  gpio.Pin = GPIO_PIN_0;
  gpio.Mode = GPIO_MODE_IT_RISING;
  HAL_GPIO_Init(GPIOA, &gpio);	

}

void on_button(uint32_t num, void *callback){
	if(num == 0) {
		button0 = callback;
		is_button0_defined = true;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(is_button0_defined){
		button0();
	}		
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}