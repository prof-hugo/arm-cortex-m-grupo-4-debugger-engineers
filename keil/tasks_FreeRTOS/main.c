#include <FreeRTOS.h>
#include <task.h>
#include "LED.h"

typedef struct xblink{
  int led;
	int timeMs;
}xBlink;
void vBlinkTask(void *pvParameters);

int main()
{
	xBlink xB0 = {0, 100}; 
	xBlink xB1 = {1, 200}; 
	xBlink xB2 = {2, 300}; 
	xBlink xB3 = {3, 400};

	LED_Initialize();
	xTaskCreate(vBlinkTask, "Blink0", configMINIMAL_STACK_SIZE, &xB0, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink1", configMINIMAL_STACK_SIZE, &xB1, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink2", configMINIMAL_STACK_SIZE, &xB2, 1, NULL);
	xTaskCreate(vBlinkTask, "Blink3", configMINIMAL_STACK_SIZE, &xB3, 1, NULL);
	vTaskStartScheduler();
	while(1);
}

void vBlinkTask(void *pvParameters)
{
	xBlink *xB = (xBlink *) pvParameters;
	const TickType_t xDelay = pdMS_TO_TICKS(xB->timeMs);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1) {
		LED_On(xB->led);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		LED_Off(xB->led);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}	
