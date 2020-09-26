################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/old/stm32f4_discovery.c \
../src/old/system_stm32f4xx.c 

OBJS += \
./src/old/stm32f4_discovery.o \
./src/old/system_stm32f4xx.o 

C_DEPS += \
./src/old/stm32f4_discovery.d \
./src/old/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/old/%.o: ../src/old/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\src" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\project" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\Libraries\CMSIS\Include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


