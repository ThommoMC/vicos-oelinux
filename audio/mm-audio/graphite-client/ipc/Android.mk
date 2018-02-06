ifeq ($(call is-board-platform-in-list, msm8998 sdm660),true)

ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ---------------------------------------------------------------------------------
#                 Common definitons
# ---------------------------------------------------------------------------------

ipc-def := -D_ANDROID_

# ---------------------------------------------------------------------------------
#             Make the Shared library (libgcs-ipc)
# ---------------------------------------------------------------------------------

LOCAL_CFLAGS            := $(ipc-def)
LOCAL_C_INCLUDES        := $(LOCAL_PATH)/inc
LOCAL_C_INCLUDES        += $(TARGET_OUT_HEADERS)/mm-audio/graphite-client/osal/
LOCAL_C_INCLUDES        += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES        += external/expat/lib

LOCAL_SHARED_LIBRARIES  := liblog libexpat libgcs-osal
LOCAL_COPY_HEADERS_TO   := mm-audio/graphite-client/ipc
LOCAL_COPY_HEADERS      := inc/packetizer.h

LOCAL_SRC_FILES         := src/packetizer.c \
                           src/ipc.c \
                           src/platform_info.c

LOCAL_MODULE             := libgcs-ipc
LOCAL_MODULE_TAGS        := optional
LOCAL_MODULE_OWNER       := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

endif # BUILD_TINY_ANDROID
endif # is-board-platform-in-list
