################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_Driver/src/ST7789_low_level.c \
../LCD_Driver/src/fonts.c 

OBJS += \
./LCD_Driver/src/ST7789_low_level.o \
./LCD_Driver/src/fonts.o 

C_DEPS += \
./LCD_Driver/src/ST7789_low_level.d \
./LCD_Driver/src/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_Driver/src/%.o: ../LCD_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@LCD_Driver/src/ST7789_low_level.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


