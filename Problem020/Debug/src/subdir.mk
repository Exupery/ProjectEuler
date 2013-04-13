################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Problem020.cpp 

OBJS += \
./src/Problem020.o 

CPP_DEPS += \
./src/Problem020.d 


# Each subdirectory must supply rules for building sources it contributes
src/Problem020.o: ../src/Problem020.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/frost/euler/bigint -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/Problem020.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


