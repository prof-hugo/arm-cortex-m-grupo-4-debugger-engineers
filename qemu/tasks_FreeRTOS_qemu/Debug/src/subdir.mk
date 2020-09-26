################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hello_world.c \
../src/stm32f4_discovery.c \
../src/system_stm32f4xx.c 

S_UPPER_SRCS += \
../src/startup_stm32f407xx.S 

OBJS += \
./src/hello_world.o \
./src/startup_stm32f407xx.o \
./src/stm32f4_discovery.o \
./src/system_stm32f4xx.o 

S_UPPER_DEPS += \
./src/startup_stm32f407xx.d 

C_DEPS += \
./src/hello_world.d \
./src/stm32f4_discovery.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\src" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\project" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\Libraries\CMSIS\Core\Include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\FreeRTOS4\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


