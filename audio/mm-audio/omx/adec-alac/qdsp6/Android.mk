ifeq ($(call is-board-platform-in-list,msm8952 msm8996 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ---------------------------------------------------------------------------------
#                 Common definitons
# ---------------------------------------------------------------------------------

libOmxAlacDec-def := -g -O3
libOmxAlacDec-def += -DQC_MODIFIED
libOmxAlacDec-def += -D_ANDROID_
libOmxAlacDec-def += -D_ENABLE_QC_MSG_LOG_
libOmxAlacDec-def += -DAUDIOV2
libOmxAlacDec-def += -Wconversion
ifeq ($(call is-board-platform-in-list,msm8952 msm8996 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
libOmxAlacDec-def += -DQCOM_AUDIO_USE_SYSTEM_HEAP_ID
endif
ifeq ($(strip $(AUDIO_FEATURE_ENABLED_NT_PAUSE_TIMEOUT)),true)
libOmxAlacDec-def += -DNT_PAUSE_TIMEOUT_ENABLED
endif

# ---------------------------------------------------------------------------------
#             Make the Shared library (libOmxAlacDec)
# ---------------------------------------------------------------------------------

include $(CLEAR_VARS)

libOmxAlacDec-inc        := $(LOCAL_PATH)/inc
libOmxAlacDec-inc        += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
libOmxAlacDec-inc        += $(TARGET_OUT_HEADERS)/mm-core/omxcore
libOmxAlacDec-inc        += $(TARGET_OUT_HEADERS)/common/inc

LOCAL_ADDITIONAL_DEPENDENCIES  := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_MODULE            := libOmxAlacDec
LOCAL_MODULE_TAGS       := optional
LOCAL_CFLAGS            := $(libOmxAlacDec-def)
LOCAL_C_INCLUDES        := $(libOmxAlacDec-inc)
LOCAL_PRELINK_MODULE    := false
LOCAL_SHARED_LIBRARIES  := libutils liblog

LOCAL_SRC_FILES         := src/adec_svr.c
LOCAL_SRC_FILES         += src/omx_alac_adec.cpp

LOCAL_MODULE_OWNER := qcom
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

endif #BUILD_TINY_ANDROID
endif #TARGET_BOARD_PLATFORM
# ---------------------------------------------------------------------------------
#                     END
# ---------------------------------------------------------------------------------

