################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/Gmac_Ip_Cfg.c \
../generate/src/Gmac_Ip_Sa_PBcfg.c \
../generate/src/IntCtrl_Ip_Cfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Pit_Ip_PBcfg.c \
../generate/src/netifcfg.c 

OBJS += \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/Gmac_Ip_Cfg.o \
./generate/src/Gmac_Ip_Sa_PBcfg.o \
./generate/src/IntCtrl_Ip_Cfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Pit_Ip_PBcfg.o \
./generate/src/netifcfg.o 

C_DEPS += \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/Gmac_Ip_Cfg.d \
./generate/src/Gmac_Ip_Sa_PBcfg.d \
./generate/src/IntCtrl_Ip_Cfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Pit_Ip_PBcfg.d \
./generate/src/netifcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/Clock_Ip_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


