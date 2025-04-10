################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/target/m7/src/subdir.mk
-include src/Flash/subdir.mk
-include src/subdir.mk
-include services/src/standard/subdir.mk
-include services/src/shecommandapp/subdir.mk
-include services/src/monotonic_cnt/subdir.mk
-include services/src/fw_crypto/subdir.mk
-include services/src/common/subdir.mk
-include services/src/subdir.mk
-include generate/src/subdir.mk
-include framework/host_keymgmt/subdir.mk
-include framework/host_hse/subdir.mk
-include framework/host_crypto_helper/subdir.mk
-include drivers/stm/subdir.mk
-include drivers/mu/subdir.mk
-include drivers/flash/subdir.mk
-include drivers/dcm_register/subdir.mk
-include board/subdir.mk
-include S&M_Driv/src/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
G2B_CAN_S32K344.siz \


# All Target
all: G2B_CAN_S32K344.elf secondary-outputs

# Tool invocations
G2B_CAN_S32K344.elf: $(OBJS) C:/Users/gettobyte_kunal/Documents/GB_AutoBoardV1_MCAL_Codes/Peripherals/CAN/G2B_CAN_S32K344/Project_Settings/Linker_Files/linker_flash_s32k344.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "G2B_CAN_S32K344.elf" "@G2B_CAN_S32K344.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

G2B_CAN_S32K344.siz: G2B_CAN_S32K344.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley G2B_CAN_S32K344.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
