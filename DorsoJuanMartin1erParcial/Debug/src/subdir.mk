################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DorsoJuanMartin1erParcial.c \
../src/cliente.c \
../src/pedidos.c \
../src/utn.c 

OBJS += \
./src/DorsoJuanMartin1erParcial.o \
./src/cliente.o \
./src/pedidos.o \
./src/utn.o 

C_DEPS += \
./src/DorsoJuanMartin1erParcial.d \
./src/cliente.d \
./src/pedidos.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


