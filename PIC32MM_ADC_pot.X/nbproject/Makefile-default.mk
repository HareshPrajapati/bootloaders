#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=bsp/adc.c bsp/buttons.c bsp/leds.c bsp/leds_rgb.c bsp/timer_1ms.c usb/usb_device.c usb/usb_device_generic.c usb/usb_hal_32bit.c usb/usb_descriptors.c usb/usb_events.c main.c system.c app_device_vendor_basic.c app_led_usb_status.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/bsp/adc.o ${OBJECTDIR}/bsp/buttons.o ${OBJECTDIR}/bsp/leds.o ${OBJECTDIR}/bsp/leds_rgb.o ${OBJECTDIR}/bsp/timer_1ms.o ${OBJECTDIR}/usb/usb_device.o ${OBJECTDIR}/usb/usb_device_generic.o ${OBJECTDIR}/usb/usb_hal_32bit.o ${OBJECTDIR}/usb/usb_descriptors.o ${OBJECTDIR}/usb/usb_events.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/app_device_vendor_basic.o ${OBJECTDIR}/app_led_usb_status.o
POSSIBLE_DEPFILES=${OBJECTDIR}/bsp/adc.o.d ${OBJECTDIR}/bsp/buttons.o.d ${OBJECTDIR}/bsp/leds.o.d ${OBJECTDIR}/bsp/leds_rgb.o.d ${OBJECTDIR}/bsp/timer_1ms.o.d ${OBJECTDIR}/usb/usb_device.o.d ${OBJECTDIR}/usb/usb_device_generic.o.d ${OBJECTDIR}/usb/usb_hal_32bit.o.d ${OBJECTDIR}/usb/usb_descriptors.o.d ${OBJECTDIR}/usb/usb_events.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/app_device_vendor_basic.o.d ${OBJECTDIR}/app_led_usb_status.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/bsp/adc.o ${OBJECTDIR}/bsp/buttons.o ${OBJECTDIR}/bsp/leds.o ${OBJECTDIR}/bsp/leds_rgb.o ${OBJECTDIR}/bsp/timer_1ms.o ${OBJECTDIR}/usb/usb_device.o ${OBJECTDIR}/usb/usb_device_generic.o ${OBJECTDIR}/usb/usb_hal_32bit.o ${OBJECTDIR}/usb/usb_descriptors.o ${OBJECTDIR}/usb/usb_events.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/app_device_vendor_basic.o ${OBJECTDIR}/app_led_usb_status.o

# Source Files
SOURCEFILES=bsp/adc.c bsp/buttons.c bsp/leds.c bsp/leds_rgb.c bsp/timer_1ms.c usb/usb_device.c usb/usb_device_generic.c usb/usb_hal_32bit.c usb/usb_descriptors.c usb/usb_events.c main.c system.c app_device_vendor_basic.c app_led_usb_status.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MM0256GPM064
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/bsp/adc.o: bsp/adc.c  .generated_files/flags/default/55d2ab3b3d3fe6471130f219c186d826183953da .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/adc.o.d 
	@${RM} ${OBJECTDIR}/bsp/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/adc.o.d" -o ${OBJECTDIR}/bsp/adc.o bsp/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/buttons.o: bsp/buttons.c  .generated_files/flags/default/761d9f06a446417bdfeb42a87aff8a0a62882b79 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/buttons.o.d 
	@${RM} ${OBJECTDIR}/bsp/buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/buttons.o.d" -o ${OBJECTDIR}/bsp/buttons.o bsp/buttons.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/leds.o: bsp/leds.c  .generated_files/flags/default/1acc24df17f97c99d74b02bfc79b2ea28f21cf5e .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/leds.o.d" -o ${OBJECTDIR}/bsp/leds.o bsp/leds.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/leds_rgb.o: bsp/leds_rgb.c  .generated_files/flags/default/5fecec2b7c3d71a101c7aa834e855548c6392193 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds_rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/leds_rgb.o.d" -o ${OBJECTDIR}/bsp/leds_rgb.o bsp/leds_rgb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/timer_1ms.o: bsp/timer_1ms.c  .generated_files/flags/default/8d6cb08a5f2c2326e3d14847a2dd99eb6ecfed20 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/timer_1ms.o.d" -o ${OBJECTDIR}/bsp/timer_1ms.o bsp/timer_1ms.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_device.o: usb/usb_device.c  .generated_files/flags/default/3b7e9f7dc7ab33e4797f1a74f190b29d9b0295b6 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_device.o.d" -o ${OBJECTDIR}/usb/usb_device.o usb/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_device_generic.o: usb/usb_device_generic.c  .generated_files/flags/default/c3df03daa4982e188d091a33cca0670b59929d03 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_device_generic.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_device_generic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_device_generic.o.d" -o ${OBJECTDIR}/usb/usb_device_generic.o usb/usb_device_generic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_hal_32bit.o: usb/usb_hal_32bit.c  .generated_files/flags/default/9f69cc670b4e23e68211e8c5493d682169ba9b3d .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_hal_32bit.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_hal_32bit.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_hal_32bit.o.d" -o ${OBJECTDIR}/usb/usb_hal_32bit.o usb/usb_hal_32bit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_descriptors.o: usb/usb_descriptors.c  .generated_files/flags/default/27f7d143dbc62cce73433d1931276226246c883a .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/usb/usb_descriptors.o usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_events.o: usb/usb_events.c  .generated_files/flags/default/3d4b7e2ecfe3496f725cc94c23350eebe383235a .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_events.o.d" -o ${OBJECTDIR}/usb/usb_events.o usb/usb_events.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/e84adb0491a982f809ff810695647e0e63aed7ee .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/9b94701cb910a37ef8f5d6c4937b5ff34c3f56b2 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/app_device_vendor_basic.o: app_device_vendor_basic.c  .generated_files/flags/default/305e5be2247f2c4df76456d181d3563f68260d08 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_vendor_basic.o.d 
	@${RM} ${OBJECTDIR}/app_device_vendor_basic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/app_device_vendor_basic.o.d" -o ${OBJECTDIR}/app_device_vendor_basic.o app_device_vendor_basic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/app_led_usb_status.o: app_led_usb_status.c  .generated_files/flags/default/43d24c70bc303dea59f130c3e22d3a4d69a4d000 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_led_usb_status.o.d 
	@${RM} ${OBJECTDIR}/app_led_usb_status.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/app_led_usb_status.o.d" -o ${OBJECTDIR}/app_led_usb_status.o app_led_usb_status.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/bsp/adc.o: bsp/adc.c  .generated_files/flags/default/a16e4fbf726ce7ded883bffaea6cab467154c736 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/adc.o.d 
	@${RM} ${OBJECTDIR}/bsp/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/adc.o.d" -o ${OBJECTDIR}/bsp/adc.o bsp/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/buttons.o: bsp/buttons.c  .generated_files/flags/default/58c8b99c92f896542b5b661264134289bcf8c4f2 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/buttons.o.d 
	@${RM} ${OBJECTDIR}/bsp/buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/buttons.o.d" -o ${OBJECTDIR}/bsp/buttons.o bsp/buttons.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/leds.o: bsp/leds.c  .generated_files/flags/default/278dce191318f91c330e4d22cb51642b5f7df9bb .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/leds.o.d" -o ${OBJECTDIR}/bsp/leds.o bsp/leds.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/leds_rgb.o: bsp/leds_rgb.c  .generated_files/flags/default/5c7041a6682f0d0f091c81fb9d93f52ddd28678d .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds_rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/leds_rgb.o.d" -o ${OBJECTDIR}/bsp/leds_rgb.o bsp/leds_rgb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/bsp/timer_1ms.o: bsp/timer_1ms.c  .generated_files/flags/default/20af5a29e58652bd37b29bc80f05798036bf8c0c .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/bsp/timer_1ms.o.d" -o ${OBJECTDIR}/bsp/timer_1ms.o bsp/timer_1ms.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_device.o: usb/usb_device.c  .generated_files/flags/default/b3b79ff006629f65acd69069fc7ebf7755be938d .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_device.o.d" -o ${OBJECTDIR}/usb/usb_device.o usb/usb_device.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_device_generic.o: usb/usb_device_generic.c  .generated_files/flags/default/c440e52fef98bb79ce09e6c16568306e508a1422 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_device_generic.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_device_generic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_device_generic.o.d" -o ${OBJECTDIR}/usb/usb_device_generic.o usb/usb_device_generic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_hal_32bit.o: usb/usb_hal_32bit.c  .generated_files/flags/default/47824a612c017287c7d3a7450e0a5139a90b6731 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_hal_32bit.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_hal_32bit.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_hal_32bit.o.d" -o ${OBJECTDIR}/usb/usb_hal_32bit.o usb/usb_hal_32bit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_descriptors.o: usb/usb_descriptors.c  .generated_files/flags/default/1cbcfcac6530c75298dc8861abe3125bdc9e702 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/usb/usb_descriptors.o usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/usb/usb_events.o: usb/usb_events.c  .generated_files/flags/default/b049a1a5b5f576c921220b7373f4abcfa6c6d6a4 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}/usb" 
	@${RM} ${OBJECTDIR}/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/usb/usb_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/usb/usb_events.o.d" -o ${OBJECTDIR}/usb/usb_events.o usb/usb_events.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/b710144f68283fa40aadd6a9e93f458016e2296d .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/a9aadf8dd623d61e0baf2ee7c594ea60ce9dd8be .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/app_device_vendor_basic.o: app_device_vendor_basic.c  .generated_files/flags/default/b7e06d8e88896b1af996e2113aa1a2c1a1e4b197 .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_vendor_basic.o.d 
	@${RM} ${OBJECTDIR}/app_device_vendor_basic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/app_device_vendor_basic.o.d" -o ${OBJECTDIR}/app_device_vendor_basic.o app_device_vendor_basic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/app_led_usb_status.o: app_led_usb_status.c  .generated_files/flags/default/72b5d52e2782e7c4f08227c0c4ec2ae3b149d8bd .generated_files/flags/default/1b27e8024f347cd20cd5d49b5982ea3e478da71
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_led_usb_status.o.d 
	@${RM} ${OBJECTDIR}/app_led_usb_status.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSYSTEM_PERIPHERAL_CLOCK=32000000 -I"bsp" -I"usb" -I".." -I"." -MP -MMD -MF "${OBJECTDIR}/app_led_usb_status.o.d" -o ${OBJECTDIR}/app_led_usb_status.o app_led_usb_status.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC32MM_ADC_pot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
