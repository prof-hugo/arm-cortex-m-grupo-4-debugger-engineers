#include <FreeRTOS.h>
#include <task.h>
#include "LED.h"

void vBlink0Task(void *pvParameters);
void vBlink1Task(void *pvParameters);
void vBlink2Task(void *pvParameters);
void vBlink3Task(void *pvParameters);

int main()
{
	LED_Initialize();
	xTaskCreate(vBlink0Task, "Blink0", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vBlink1Task, "Blink1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vBlink2Task, "Blink2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vBlink3Task, "Blink3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler();
	while(1);
}

void vBlink0Task(void *pvParameters)
{
	const TickType_t xDelay = pdMS_TO_TICKS(530);
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
	const TickType_t xDelay = pdMS_TO_TICKS(430);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(1);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(1);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}

void vBlink2Task(void *pvParameters)
{
	const TickType_t xDelay = pdMS_TO_TICKS(330);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(2);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(2);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}

void vBlink3Task(void *pvParameters)
{
	const TickType_t xDelay = pdMS_TO_TICKS(230);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(3);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(3);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}	
