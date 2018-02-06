ifeq ($(call is-board-platform-in-list,msm8952 msm8996 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

#----------------------------------------------------------------------------------
#                 Common definitons
#----------------------------------------------------------------------------------

libOmxApeDec-def := -g -O3
libOmxApeDec-def += -DQC_MODIFIED
libOmxApeDec-def += -D_ANDROID_
libOmxApeDec-def += -D_ENABLE_QC_MSG_LOG_
libOmxApeDec-def += -DAUDIOV2
libOmxApeDec-def += -Wconversion
ifeq ($(call is-board-platform-in-list,msm8952 msm8996 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
libOmxApeDec-def += -DQCOM_AUDIO_USE_SYSTEM_HEAP_ID
endif
ifeq ($(strip $(AUDIO_FEATURE_ENABLED_NT_PAUSE_TIMEOUT)),true)
libOmxApeDec-def += -DNT_PAUSE_TIMEOUT_ENABLED
endif

#----------------------------------------------------------------------------------
#             Make the Shared library (libOmxApeDec)
#----------------------------------------------------------------------------------

include $(CLEAR_VARS)

libOmxApeDec-inc        := $(LOCAL_PATH)/inc
libOmxApeDec-inc        += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
libOmxApeDec-inc        += $(TARGET_OUT_HEADERS)/mm-core/omxcore
libOmxApeDec-inc        += $(TARGET_OUT_HEADERS)/common/inc

LOCAL_ADDITIONAL_DEPENDENCIES  := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_MODULE            := libOmxApeDec
LOCAL_MODULE_TAGS       := optional
LOCAL_CFLAGS            := $(libOmxApeDec-def)
LOCAL_C_INCLUDES        := $(libOmxApeDec-inc)
LOCAL_PRELINK_MODULE    := false
LOCAL_SHARED_LIBRARIES  := libutils liblog

LOCAL_SRC_FILES         := src/adec_svr.c
LOCAL_SRC_FILES         += src/omx_ape_adec.cpp

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

endif #BUILD_TINY_ANDROID
endif #TARGET_BOARD_PLATFORM
#----------------------------------------------------------------------------------
#                     END
#----------------------------------------------------------------------------------

