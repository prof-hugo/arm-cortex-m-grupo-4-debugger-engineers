#include <FreeRTOS.h>
#include <task.h>
#include <stdbool.h>
#include "semphr.h"
#ifdef BTL_TM4C1294
#include "LED.h"
#endif
#ifdef BTL_STM32F4
#include "stm32f4_discovery.h"
#endif

typedef struct xblink{
  int led;
	int timeMs;
}xBlink;

void vBlinkTask(void *pvParameters);

bool is_led_on = false;
bool is_initialized = false;
SemaphoreHandle_t xMutex;

#ifdef BTL_TM4C1294
	xBlink xB0 = {0, 500}; 
	xBlink xB1 = {1, 400}; 
	xBlink xB2 = {2, 300}; 
	xBlink xB3 = {3, 200};
#endif
#ifdef BTL_STM32F4
	xBlink xB0 = {LED3, 500}; 
	xBlink xB1 = {LED4, 400}; 
	xBlink xB2 = {LED5, 300}; 
	xBlink xB3 = {LED6, 200};
#endif

int main()
{
#ifdef BTL_TM4C1294
	LED_Initialize();
#endif
#ifdef BTL_STM32F4
	__HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);
#endif
	xMutex = xSemaphoreCreateBinary();
	xTaskCreate(vBlinkTask, "Blink0", configMINIMAL_STACK_SIZE, &xB0, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink1", configMINIMAL_STACK_SIZE, &xB1, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink2", configMINIMAL_STACK_SIZE, &xB2, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink3", configMINIMAL_STACK_SIZE, &xB3, 1, NULL);
	xSemaphoreGive(xMutex);
	vTaskStartScheduler();
	while(1);
}

void vBlinkTask(void *pvParameters)
{
	xBlink *xB = (xBlink *) pvParameters;
	const TickType_t xDelay = pdMS_TO_TICKS(xB->timeMs);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		xSemaphoreTake(xMutex,portMAX_DELAY);
#ifdef BTL_TM4C1294
		LED_Toggle(xB->led);
#endif
#ifdef BTL_STM32F4
		BSP_LED_Toggle(xB->led);
#endif
		xSemaphoreGive(xMutex);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
	}
}	

