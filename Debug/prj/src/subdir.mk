################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../prj/src/clasa.cpp \
../prj/src/funkcje.cpp \
../prj/src/generator.cpp \
../prj/src/heap.cpp \
../prj/src/main.cpp \
../prj/src/merge.cpp \
../prj/src/quick.cpp 

OBJS += \
./prj/src/clasa.o \
./prj/src/funkcje.o \
./prj/src/generator.o \
./prj/src/heap.o \
./prj/src/main.o \
./prj/src/merge.o \
./prj/src/quick.o 

CPP_DEPS += \
./prj/src/clasa.d \
./prj/src/funkcje.d \
./prj/src/generator.d \
./prj/src/heap.d \
./prj/src/main.d \
./prj/src/merge.d \
./prj/src/quick.d 


# Each subdirectory must supply rules for building sources it contributes
prj/src/%.o: ../prj/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


