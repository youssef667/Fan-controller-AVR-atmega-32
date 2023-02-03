################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_DRIVER_YOUSSEF.c \
../DC_MOTOR_DRIVER.c \
../GPIO_YOUSSEF.c \
../MINIPROJECT3.c \
../PWM_DC_MOTOR.c \
../lcd.c \
../lm35_sensor.c 

OBJS += \
./ADC_DRIVER_YOUSSEF.o \
./DC_MOTOR_DRIVER.o \
./GPIO_YOUSSEF.o \
./MINIPROJECT3.o \
./PWM_DC_MOTOR.o \
./lcd.o \
./lm35_sensor.o 

C_DEPS += \
./ADC_DRIVER_YOUSSEF.d \
./DC_MOTOR_DRIVER.d \
./GPIO_YOUSSEF.d \
./MINIPROJECT3.d \
./PWM_DC_MOTOR.d \
./lcd.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


