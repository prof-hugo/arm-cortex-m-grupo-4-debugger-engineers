################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_2.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_2.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_2.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.o: ../FreeRTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -I"C:\Users\hviei\eclipse-workspace\FreeRTOS" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\src" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\project" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\Libraries\CMSIS\Include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


