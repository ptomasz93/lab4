################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/clasa.cpp \
../src/funkcje.cpp \
../src/generator.cpp \
../src/heap.cpp \
../src/main.cpp \
../src/merge.cpp \
../src/quick.cpp 

OBJS += \
./src/clasa.o \
./src/funkcje.o \
./src/generator.o \
./src/heap.o \
./src/main.o \
./src/merge.o \
./src/quick.o 

CPP_DEPS += \
./src/clasa.d \
./src/funkcje.d \
./src/generator.d \
./src/heap.d \
./src/main.d \
./src/merge.d \
./src/quick.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


