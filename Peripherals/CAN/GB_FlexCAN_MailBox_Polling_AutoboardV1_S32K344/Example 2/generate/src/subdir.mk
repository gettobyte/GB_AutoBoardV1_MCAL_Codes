################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/FlexCAN_Ip_Sa_BOARD_InitPeripherals_PBcfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Port_BOARD_InitPeripherals_PBcfg.c \
../generate/src/Port_Cfg.c \
../generate/src/Siul2_Port_Ip_BOARD_InitPeripherals_PBcfg.c \
../generate/src/Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c 

OBJS += \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/FlexCAN_Ip_Sa_BOARD_InitPeripherals_PBcfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Port_BOARD_InitPeripherals_PBcfg.o \
./generate/src/Port_Cfg.o \
./generate/src/Siul2_Port_Ip_BOARD_InitPeripherals_PBcfg.o \
./generate/src/Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.o 

C_DEPS += \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/FlexCAN_Ip_Sa_BOARD_InitPeripherals_PBcfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Port_BOARD_InitPeripherals_PBcfg.d \
./generate/src/Port_Cfg.d \
./generate/src/Siul2_Port_Ip_BOARD_InitPeripherals_PBcfg.d \
./generate/src/Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/Clock_Ip_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

