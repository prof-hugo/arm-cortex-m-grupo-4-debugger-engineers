################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/STM32F4xx_StdPeriph_Driver/src/misc.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
../Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c 

OBJS += \
./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.o \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.o 

C_DEPS += \
./Libraries/STM32F4xx_StdPeriph_Driver/src/misc.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.d \
./Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STM32F4xx_StdPeriph_Driver/src/%.o: ../Libraries/STM32F4xx_StdPeriph_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F40_41xxx -DSTM32F407xx -DUSE_STDPERIPH_DRIVER -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\src" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\project" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\Libraries\CMSIS\Include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS3\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


