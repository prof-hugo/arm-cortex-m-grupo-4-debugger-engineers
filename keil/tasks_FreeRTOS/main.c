#include <FreeRTOS.h>
#include <task.h>
#include "LED.h"

void vBlink0Task(void *pvParameters);
void vBlink1Task(void *pvParameters);

int main()
{
	LED_Initialize();
	xTaskCreate(vBlink0Task, "Blink0", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vBlink1Task, "Blink1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler();
	while(1);
}

void vBlink0Task(void *pvParameters)
{
	const TickType_t xDelay = pdMS_TO_TICKS(500);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(0);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(0);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}

void vBlink1Task(void *pvParameters)
{
	const TickType_t xDelay = pdMS_TO_TICKS(500);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(1);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(1);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}

