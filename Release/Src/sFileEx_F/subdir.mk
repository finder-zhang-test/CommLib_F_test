################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/sFileEx_F/FileFdMmap_F.cpp \
../Src/sFileEx_F/FileFd_F.cpp \
../Src/sFileEx_F/FileRecord_F.cpp \
../Src/sFileEx_F/File_F.cpp 

OBJS += \
./Src/sFileEx_F/FileFdMmap_F.o \
./Src/sFileEx_F/FileFd_F.o \
./Src/sFileEx_F/FileRecord_F.o \
./Src/sFileEx_F/File_F.o 

CPP_DEPS += \
./Src/sFileEx_F/FileFdMmap_F.d \
./Src/sFileEx_F/FileFd_F.d \
./Src/sFileEx_F/FileRecord_F.d \
./Src/sFileEx_F/File_F.d 


# Each subdirectory must supply rules for building sources it contributes
Src/sFileEx_F/%.o: ../Src/sFileEx_F/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/root/workspace/CommLib_F/Src/cJSON" -I"/root/workspace/CommLib_F/Src/sCommBase_F" -I"/root/workspace/CommLib_F/Src/sDebugEx" -I"/root/workspace/CommLib_F/Src/sFileEx_F" -I"/root/workspace/CommLib_F/Src/sMathEx_F" -I"/root/workspace/CommLib_F/Src/sMemMonitor" -I"/root/workspace/CommLib_F/Src/sNetwork" -I"/root/workspace/CommLib_F/Src/sSerial_F" -I"/root/workspace/CommLib_F/Src/sThreadEx_F" -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


