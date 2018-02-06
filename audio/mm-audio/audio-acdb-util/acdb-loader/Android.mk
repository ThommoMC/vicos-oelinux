ifeq ($(call is-board-platform-in-list,msm8660 msm8960 msm8974 msm8610 msm8226 copper apq8084 msm8916 msm8994 msm8992 msm8909 msm8996 msm8952 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)

ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ---------------------------------------------------------------------------------
#                 Common definitons
# ---------------------------------------------------------------------------------

libacdbloader-def := -g -O3
libacdbloader-def += -D_ANDROID_
libacdbloader-def += -D_ENABLE_QC_MSG_LOG_
libacdbloader-def += -D ACDB_BIN_PATH=\"/etc/acdbdata\"
libacdbloader-def += -D ETC_ROOT_PATH=\"/etc\"
libacdbloader-def += -D DEFAULT_BOARD=\"MTP\"

libacdbloader-def += -D MIXER_CONTROL_FILE_PATH=\"/system/etc/audio_tuning_mixer.txt\"
libacdbloader-def += -D TAVIL_MIXER_CONTROL_FILE_PATH=\"/system/etc/audio_tuning_mixer_tavil.txt\"
libacdbloader-def += -D TASHA_MIXER_CONTROL_FILE_PATH=\"/system/etc/audio_tuning_mixer_tasha.txt\"
libacdbloader-def += -D_TINY_ALSA_LIB_

ifeq ($(call is-board-platform-in-list,msm8610 apq8084 msm8996 msm8952 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
libacdbloader-def += -D AUDIO_USE_SYSTEM_HEAP_ID
endif
# ---------------------------------------------------------------------------------
#             Make the Shared library (libaudcalctrl)
# ---------------------------------------------------------------------------------

libacdbloader-inc     := $(LOCAL_PATH)/inc
libacdbloader-inc     += $(LOCAL_PATH)/src
libacdbloader-inc     += $(LOCAL_PATH)/../acdb-mcs/inc
libacdbloader-inc     += $(LOCAL_PATH)/../acdb-mcs/src

LOCAL_MODULE            := libacdbloader
LOCAL_MODULE_TAGS       := optional
LOCAL_CFLAGS            := $(libacdbloader-def)
LOCAL_C_INCLUDES        := $(libacdbloader-inc)
LOCAL_C_INCLUDES        += $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES        += $(TARGET_OUT_HEADERS)/mm-audio/audcal
LOCAL_C_INCLUDES        += $(TARGET_OUT_HEADERS)/mm-audio/audio-acdb-util
LOCAL_C_INCLUDES        += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include

LOCAL_C_INCLUDES        += external/tinyalsa/include

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_PRELINK_MODULE    := false
LOCAL_SHARED_LIBRARIES  := libcutils libutils liblog libaudcal libtinyalsa
LOCAL_COPY_HEADERS_TO   := mm-audio/audio-acdb-util

ifeq ($(call is-board-platform,msm8660),true)
LOCAL_COPY_HEADERS      := inc/8660/acdb-loader.h
LOCAL_COPY_HEADERS      += inc/acdb-anc-timpani.h
LOCAL_COPY_HEADERS      += inc/8660/acdb-loader-def.h
endif

ifeq ($(call is-board-platform,msm8960),true)
LOCAL_COPY_HEADERS      := inc/8960/acdb-loader.h
LOCAL_COPY_HEADERS      += ../acdb-mapper/inc/acdb-id-mapper.h
LOCAL_COPY_HEADERS      += inc/acdb-anc-tabla.h
LOCAL_COPY_HEADERS      += inc/8960/acdb-loader-def.h
endif

ifeq ($(call is-board-platform-in-list,msm8974 msm8610 msm8226 msm8610 copper apq8084 msm8916 msm8994 msm8992 msm8909 msm8996 msm8952 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
LOCAL_SHARED_LIBRARIES  += libacdbrtac
LOCAL_SHARED_LIBRARIES  += libadiertac
LOCAL_SHARED_LIBRARIES  += libacdb-fts
LOCAL_COPY_HEADERS      := inc/8974/acdb-loader.h
LOCAL_COPY_HEADERS      += ../acdb-mapper/inc/acdb-id-mapper.h
LOCAL_COPY_HEADERS      += ../acdb-rtac/inc/acdb-rtac.h
LOCAL_COPY_HEADERS      += ../adie-rtac/inc/adie-rtac.h
LOCAL_COPY_HEADERS      += inc/acdb-anc-tabla.h
LOCAL_COPY_HEADERS      += inc/acdb-anc-taiko.h
LOCAL_COPY_HEADERS      += inc/anc_map_api.h
LOCAL_COPY_HEADERS      += inc/anc_bitmasks.h
LOCAL_COPY_HEADERS      += inc/wcd9335_anc_registers.h
LOCAL_COPY_HEADERS      += inc/vbat_map_api.h
LOCAL_COPY_HEADERS      += ../acdb-mcs/inc/acdb-mcs.h
endif

LOCAL_COPY_HEADERS      += inc/acdb-anc-general.h

ifeq ($(call is-board-platform-in-list,msm8974 msm8610 msm8226 msm8610 copper apq8084 msm8916 msm8994 msm8992 msm8909 msm8996 msm8952 msm8937 thorium msm8953 msmgold msm8998 sdm660),true)
LOCAL_SRC_FILES         := src/family-b/acdb-loader.c \
				src/family-b/anc_map.c \
				src/family-b/vbat_map.c
else
LOCAL_SRC_FILES         := src/legacy_intf/acdb-loader.c
endif

#MCS
LOCAL_SRC_FILES         += ../acdb-mcs/src/acdb-mcs.c \
				../acdb-mcs/src/mcs-route-ctrl.c

ifeq ($(call is-board-platform-in-list,msm8974 apq8084 msm8994 msm8992 msm8996 msm8998),true)
$(shell mkdir -p $(TARGET_OUT)/etc/firmware/wcd9320; \
	ln -sf /data/misc/audio/wcd9320_anc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9320/wcd9320_anc.bin;\
	ln -s /data/misc/audio/mbhc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9320/wcd9320_mbhc.bin; \
	ln -s /data/misc/audio/wcd9320_mad_audio.bin \
		$(TARGET_OUT)/etc/firmware/wcd9320/wcd9320_mad_audio.bin)
else ifeq ($(call is-board-platform-in-list,msm8226 msm8916),true)
$(shell mkdir -p $(TARGET_OUT)/etc/firmware/wcd9306; \
	ln -sf /data/misc/audio/wcd9320_anc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9306/wcd9306_anc.bin;\
	ln -s /data/misc/audio/mbhc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9306/wcd9306_mbhc.bin)
else ifeq ($(call is-board-platform,msm8960),true)
$(shell mkdir -p $(TARGET_OUT)/etc/firmware/wcd9310; \
	ln -sf /data/misc/audio/wcd9310_anc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9310/wcd9310_anc.bin;\
	ln -s /data/misc/audio/mbhc.bin \
		$(TARGET_OUT)/etc/firmware/wcd9306/wcd9306_mbhc.bin)
endif


LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

endif
endif # is-board-platform-in-list

# ---------------------------------------------------------------------------------
#                     END
# ---------------------------------------------------------------------------------
