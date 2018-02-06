/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

GENERAL DESCRIPTION
  LocationProviderGlue implementation

  Copyright (c) 2015 - 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#define LOG_TAG "LocationProviderGlue"
#define LOG_NDEBUG 0

#include <platform_lib_includes.h>
#include <comdef.h>
#include <IzatTypes.h>
#include <IzatRequest.h>
#include <IzatLocation.h>
#include <LocationProviderGlue.h>
#include <IzatProviderEngine_jni.h>
#include <IIzatManager.h>
#include "IzatDefines.h"

using namespace izat_manager;

// ctor
LocationProviderGlue :: LocationProviderGlue (IzatStreamType streamType)
: mIzatManager (NULL),
  mLocationStreamType (streamType),
  mStatus (IZAT_PROVIDER_AVAILABLE) {

  int result = -1;

  do {
      mIzatManager = getIzatManager(NULL);
      BREAK_IF_ZERO(1, mIzatManager);
      result = 0;
  } while (0);

  EXIT_LOG_WITH_ERROR("%d", result);
}

// dtor
LocationProviderGlue :: ~LocationProviderGlue () {}

void LocationProviderGlue :: onEnable () {
    if (mIzatManager == NULL) return;
    mIzatManager->enableProvider (mLocationStreamType);
    mIzatManager->subscribeListener (this);
}

void LocationProviderGlue :: onDisable () {
    if (mIzatManager == NULL) return;
    mIzatManager->disableProvider (mLocationStreamType);
    mIzatManager->unsubscribeListener (this);
}

void LocationProviderGlue :: onAddRequest (IzatRequest * request) {
    if (mIzatManager == NULL) return;
    mIzatManager->addRequest (request);
}

void LocationProviderGlue :: onRemoveRequest (IzatRequest * request) {
    if (mIzatManager == NULL) return;
    mIzatManager->removeRequest (request);
}

IzatProviderStatus LocationProviderGlue :: getStatus () {
    return mStatus;
}

int64 LocationProviderGlue :: getStatusUpdateTime () {
    return 0;
}

IzatListenerMask LocationProviderGlue :: listensTo () const {
  return (IzatListenerMask)mLocationStreamType;
}

void LocationProviderGlue :: onLocationChanged
(
    const IzatLocation * location,
    const IzatLocationStatus status
)
{
#ifdef __ANDROID__
  onLocationChangedJNI (location, mLocationStreamType);
#endif
}

void LocationProviderGlue :: onStatusChanged
(
    const IzatProviderStatus status
)
{
    mStatus = status;
#ifdef __ANDROID__
    onStatusChangedJNI (status, mLocationStreamType);
#endif
}

