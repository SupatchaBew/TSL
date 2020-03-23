################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
TSL.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TSL.list \

OBJCOPY_HEX += \
TSL.hex \


# All Target
all: TSL.elf secondary-outputs

# Tool invocations
TSL.elf: $(OBJS) $(USER_OBJS) ../STM32F030R8Tx_FLASH.ld
	arm-none-eabi-gcc -o "TSL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"../STM32F030R8Tx_FLASH.ld" --specs=nosys.specs -Wl,-Map="TSL.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TSL.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TSL.list"
	@echo 'Finished building: $@'
	@echo ' '

TSL.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "TSL.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
