################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/sMathEx_F/Fraction_F.cpp \
../Src/sMathEx_F/Random_F.cpp 

OBJS += \
./Src/sMathEx_F/Fraction_F.o \
./Src/sMathEx_F/Random_F.o 

CPP_DEPS += \
./Src/sMathEx_F/Fraction_F.d \
./Src/sMathEx_F/Random_F.d 


# Each subdirectory must supply rules for building sources it contributes
Src/sMathEx_F/%.o: ../Src/sMathEx_F/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/root/workspace/CommLib_F/Src/cJSON" -I"/root/workspace/CommLib_F/Src/sCommBase_F" -I"/root/workspace/CommLib_F/Src/sDebugEx" -I"/root/workspace/CommLib_F/Src/sFileEx_F" -I"/root/workspace/CommLib_F/Src/sMathEx_F" -I"/root/workspace/CommLib_F/Src/sMemMonitor" -I"/root/workspace/CommLib_F/Src/sNetwork" -I"/root/workspace/CommLib_F/Src/sSerial_F" -I"/root/workspace/CommLib_F/Src/sThreadEx_F" -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


