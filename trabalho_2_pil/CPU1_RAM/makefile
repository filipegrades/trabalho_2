################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2050/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tasks.obj" \
"./syscfg/board.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./device/F2837xD_CodeStartBranch.obj" \
"./device/device.obj" \
"./src/scicomm.obj" \
"../2837xD_RAM_lnk_cpu1.cmd" \
"C:/ti/C2000Ware_26_00_00_00/driverlib/f2837xd/driverlib/ccs/Debug/driverlib.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/lib/cla1_math_library_fpu32_eabi.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include device/subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include device/subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
trabalho_2_PIL.out 

EXE_OUTPUTS__QUOTED += \
"trabalho_2_PIL.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "trabalho_2_PIL.out"

# Tool invocations
trabalho_2_PIL.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'C2000 Linker - building target: "$@"'
	"C:/ti/ccs2050/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --define=_LAUNCHXL_F28379D --define=DEBUG --define=CPU1 --define=RAM --c99 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"trabalho_2_PIL.map" --heap_size=0x100 --stack_size=0x200 --warn_sections -i"G:/Meu Drive/UFJF/Doutorado/2026.1/Codigos_TSeISEpEP/trabalho_2/trabalho_2_pil/src" -i"C:/ti/ccs2050/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/lib" -i"C:/ti/C2000Ware_26_00_00_00" -i"G:/Meu Drive/UFJF/Doutorado/2026.1/Codigos_TSeISEpEP/trabalho_2/trabalho_2_pil/CPU1_RAM/syscfg" -i"C:/ti/ccs2050/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" -i"C:/ti/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/lib" --reread_libs --define=RAM --diag_wrap=off --display_error_number --xml_link_info="trabalho_2_PIL_linkInfo.xml" --entry_point=code_start --rom_model -o "trabalho_2_PIL.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tasks.obj" "syscfg\board.obj" "syscfg\c2000ware_libraries.obj" "device\F2837xD_CodeStartBranch.obj" "device\device.obj" "src\scicomm.obj" 
	-$(RM) "main.d" "syscfg\board.d" "syscfg\c2000ware_libraries.d" "device\device.d" "src\scicomm.d" 
	-$(RM) "tasks.d" 
	-$(RM) "device\F2837xD_CodeStartBranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

