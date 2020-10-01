#include "TM4C129.h"                    // Device header
#include "LED.h"

int main()
{
	int i;
	LED_Initialize();
	while(1){
		LED_On(0);
		LED_On(1);
		for(i=0;i<700000;i++);
		LED_Off(0);
		LED_Off(1);
		for(i=0;i<700000;i++);
	}
}
