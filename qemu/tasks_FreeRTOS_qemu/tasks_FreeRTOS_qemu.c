/*==================================================================================================

  tasks_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS Real-Time Operating System on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"

typedef struct T_led{
	Led_TypeDef led;
	int time;
} Led_type;

Led_type l3, l4, l5, l6;

void vBlinkLED(void *pvParam){

  Led_type *led_t=(Led_type *) pvParam;

  TickType_t xLastWakeTime;
  const TickType_t xPeriod = (*led_t).time / portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount();

  while(1){
	BSP_LED_Toggle((*led_t).led);
	vTaskDelayUntil(&xLastWakeTime, xPeriod);
  } // while
} // vBlinkLED

void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);

  l3.led=LED3;
  l3.time=530;

  l4.led=LED4;
  l4.time=430;

  l5.led=LED5;
  l5.time=330;

  l6.led=LED6;
  l6.time=230;

  xTaskCreate(vBlinkLED, "vBlinkLED3", configMINIMAL_STACK_SIZE, &l3, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED4", configMINIMAL_STACK_SIZE, &l4, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED5", configMINIMAL_STACK_SIZE, &l5, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED, "vBlinkLED6", configMINIMAL_STACK_SIZE, &l6, tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  while(1);
} // main
