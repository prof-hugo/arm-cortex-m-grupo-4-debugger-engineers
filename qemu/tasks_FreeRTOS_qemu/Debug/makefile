################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/STM32F4xx_HAL_Driver/Src/subdir.mk
-include FreeRTOS/Source/portable/GCC/MemMang/subdir.mk
-include FreeRTOS/Source/portable/GCC/ARM_CM3/subdir.mk
-include FreeRTOS/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
tasks_FreeRTOS_qemu.hex \

SECONDARY_SIZE += \
tasks_FreeRTOS_qemu.siz \


# All Target
all: tasks_FreeRTOS_qemu.elf secondary-outputs

# Tool invocations
tasks_FreeRTOS_qemu.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\ldscripts\STM32F407VGTx_FLASH.ld" -Xlinker --gc-sections -L"C:\Users\hviei\eclipse-workspace\tasks_FreeRTOS_qemu\ldscripts" -Wl,-Map,"tasks_FreeRTOS_qemu.map" --specs=nano.specs -o "tasks_FreeRTOS_qemu.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

tasks_FreeRTOS_qemu.hex: tasks_FreeRTOS_qemu.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "tasks_FreeRTOS_qemu.elf"  "tasks_FreeRTOS_qemu.hex"
	@echo 'Finished building: $@'
	@echo ' '

tasks_FreeRTOS_qemu.siz: tasks_FreeRTOS_qemu.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-none-eabi-size --format=berkeley "tasks_FreeRTOS_qemu.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) tasks_FreeRTOS_qemu.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
