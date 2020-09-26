################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c 

OBJS += \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o 

C_DEPS += \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STM32F4xx_HAL_Driver/Src/%.o: ../Libraries/STM32F4xx_HAL_Driver/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\CMSIS\Core\Include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


