################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f4_discovery.c \
../system_stm32f4xx.c \
../tasks_FreeRTOS_qemu.c 

S_UPPER_SRCS += \
../startup_stm32f407xx.S 

OBJS += \
./startup_stm32f407xx.o \
./stm32f4_discovery.o \
./system_stm32f4xx.o \
./tasks_FreeRTOS_qemu.o 

S_UPPER_DEPS += \
./startup_stm32f407xx.d 

C_DEPS += \
./stm32f4_discovery.d \
./system_stm32f4xx.d \
./tasks_FreeRTOS_qemu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\CMSIS\Core\Include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\FreeRTOS\Source\include" -I"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\FreeRTOS\Source\portable\GCC\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


