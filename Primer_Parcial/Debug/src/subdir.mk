################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Primer_Parcial.c \
../src/UTN.c \
../src/contribuyente.c \
../src/recaudacion.c 

OBJS += \
./src/Primer_Parcial.o \
./src/UTN.o \
./src/contribuyente.o \
./src/recaudacion.o 

C_DEPS += \
./src/Primer_Parcial.d \
./src/UTN.d \
./src/contribuyente.d \
./src/recaudacion.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


