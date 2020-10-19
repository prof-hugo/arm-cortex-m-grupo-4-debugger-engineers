#include <FreeRTOS.h>
#include <task.h>
#include <stdbool.h>
#include "semphr.h"
#include "LED.h"

typedef struct xblink{
  int led;
	int timeMs;
}xBlink;

void vBlinkTask(void *pvParameters);

bool is_led_on = false;
bool is_initialized = false;
SemaphoreHandle_t xMutex;

xBlink xB0 = {0, 500}; 
xBlink xB1 = {1, 500}; 
xBlink xB2 = {2, 500}; 
xBlink xB3 = {3, 500};


int main()
{
	LED_Initialize();

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
		LED_Toggle(xB->led);
		xSemaphoreGive(xMutex);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
	}
}	

