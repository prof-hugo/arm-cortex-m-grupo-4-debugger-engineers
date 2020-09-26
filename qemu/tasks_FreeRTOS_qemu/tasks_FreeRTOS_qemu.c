/*==================================================================================================

  tasks_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS Real-Time Operating System on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"


void vBlinkLED4(void *pvParam){
  const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

  while(1){
    BSP_LED_Toggle(LED4);
    vTaskDelay(xDelay);
  } // while
} // vBlinkLED4


void vBlinkLED5(void *pvParam){
  TickType_t xLastWakeTime;
  const TickType_t xPeriod = 500 / portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount();

  while(1){
    BSP_LED_Toggle(LED5);
    vTaskDelayUntil(&xLastWakeTime, xPeriod);
  } // while
} // vBlinkLED5


void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);

  xTaskCreate(vBlinkLED4, "vBlinkLED4", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
  xTaskCreate(vBlinkLED5, "vBlinkLED5", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  while(1);
} // main
