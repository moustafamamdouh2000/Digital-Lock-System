################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HKPD_Program.c \
../MDIO_program.c \
../MSPI_Program.c \
../MUART_Program.c \
../Master_main.c 

OBJS += \
./HKPD_Program.o \
./MDIO_program.o \
./MSPI_Program.o \
./MUART_Program.o \
./Master_main.o 

C_DEPS += \
./HKPD_Program.d \
./MDIO_program.d \
./MSPI_Program.d \
./MUART_Program.d \
./Master_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


