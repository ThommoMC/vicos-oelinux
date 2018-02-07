#ifndef MVVSLAM_H
#define MVVSLAM_H

/**=============================================================================
@file
    mvSLAM.h

@brief
    Machine Vision SDK public API, Visual Simultaneous Localization And 
    Mapping (VSLAM)

Copyright 2014-2016 Qualcomm Technologies, Inc.  All rights reserved.

Confidential & Proprietary - Qualcomm Technologies, Inc. ("QTI")
 
This software may be subject to U.S. and international export, re-export 
or transfer laws. Diversion contrary to U.S. and international law is 
strictly prohibited.
 
The party receiving this software directly from QTI (the "Recipient") 
may use this software solely as set forth in the agreement between the 
Recipient and QTI (the "Agreement"). The software may be used in source 
code form solely by the Recipient's employees (if any) authorized by the 
Agreement. Unless expressly authorized in the Agreement, the Recipient 
may not sublicense, assign, transfer or otherwise provide the source 
code to any third party. Qualcomm Technologies, Inc. retains all 
ownership rights in and to the software. Except as may be expressly 
granted by the Agreement, this file provides no license to any patents, 
trademarks, copyrights, or other intellectual property of Qualcomm Technologies 
Incorporated or its affiliates.
 
This notice supersedes any other QTI notices contained within the 
software except copyright notices indicating different years of 
publication for different portions of the software. This notice does not 
supersede the application of any third party copyright notice to that 
third party's code. 
=============================================================================**/


//==============================================================================
// Defines
//==============================================================================

#define mvVSLAM_Initialize                      mv60_D
#define mvVSLAM_Deinitialize                    mv61_D
#define mvVSLAM_AddImage                        mv62_D
#define mvVSLAM_GetPose                         mv63_D
#define mvVSLAM_AddTarget                       mv64_D
#define mvVSLAM_GetPointCloud                   mv65_D
#define mvVSLAM_HasUpdatedPointCloud            mv66_D
#define mvVSLAM_GetMapSize                      mv67_D
#define mvVSLAM_GetKeyframes                    mv68_D
#define mvVSLAM_SaveMap                         mv69_D
#define mvVSLAM_SetMapPath                      mv6A_D
#define mvVSLAM_IncrementallyLoadMap            mv6B_D
#define mvVSLAM_DeepReset                       mv6C_D
#define mvVSLAM_SetKfPatchSizeToProtect         mv6D_D
#define mvVSLAM_EnableDescriptorSaveLoad        mv6E_D
#define mvVSLAM_SetKeyframeSelectorParameters   mv6F_D
#define mvVSLAM_EnableScaleFreeTracking         mv6G_D
#define mvVSLAM_EnableLoopClosure               mv6H_D
#define mvVSLAM_HasTrackedObservation           mv6I_D
#define mvVSLAM_GetObservation                  mv6J_D
#define mvVSLAM_TransformMap                    mv6K_D
#define mvVSLAM_SetWorkingDirectory             mv6L_D
#define mvVSLAM_EnableMapperSynchronousMode     mv6M_D
#define mvVSLAM_LoadDefaultMapAndMerge          mv6N_D
#define mvVSLAM_SaveDefaultMap                  mv6O_D
#define mvVSLAM_AddImageWithWheel               mv6P_D
#define mvVSLAM_EnableWheelInitialization       mv6Q_D

//==============================================================================
// Includes
//==============================================================================

#include <mv.h>

//==============================================================================
// Declarations
//==============================================================================

#ifdef __cplusplus
extern "C"
{
#endif


//==============================================================================
/// @brief
///     Visual Simultaneous Localization And Mapping (VSLAM)
//==============================================================================
typedef struct mvVSLAM mvVSLAM;



//------------------------------------------------------------------------------
/// @brief
///     Tracking observation
//------------------------------------------------------------------------------
typedef struct
{
   typedef enum
   {
      MATCHING_OK,                        ///< Matching succeeded
      MATCHING_FAILED                     ///< Matching failed
   } MV_OBSERVATION_STATE;

   float x; //In pixel
   float y; //in pixle
   MV_OBSERVATION_STATE s;
} MV_TrackedObservation;


//------------------------------------------------------------------------------
/// @brief
///     Active keyframe
//------------------------------------------------------------------------------
typedef struct
{
	mvPose6DRT pose;
	int id;
} MV_ActiveKeyframe;


//------------------------------------------------------------------------------
/// @brief
///     Tracking state quality for VSLAM
//------------------------------------------------------------------------------
typedef enum
{
   MV_VSLAM_TRACKING_STATE_FAILED = -2,
   MV_VSLAM_TRACKING_STATE_INITIALIZING = -1,
   MV_VSLAM_TRACKING_STATE_GREAT = 0,
   MV_VSLAM_TRACKING_STATE_GOOD = 1,
   MV_VSLAM_TRACKING_STATE_OK = 2,
   MV_VSLAM_TRACKING_STATE_BAD = 3,
   MV_VSLAM_TRACKING_STATE_APPROX = 4,
   MV_VSLAM_TRACKING_STATE_RELOCATED = 5,
} MV_VSLAM_TRACKING_STATE;


//------------------------------------------------------------------------------
/// @brief
///     Pose information along with a quality indicator for VSLAM.
//------------------------------------------------------------------------------
typedef struct
{
   mvPose6DRT pose;                      // Pose                
   MV_VSLAM_TRACKING_STATE poseQuality;  // Quality of the pose
} mvVSLAMTrackingPose;


//------------------------------------------------------------------------------
/// @brief
///     Initialize VSLAM object
/// @param pnConfig
///     Pointer to VSLAM configuration
/// @return
///     Pointer to VSLAM object; returns NULL if failed
//------------------------------------------------------------------------------
MV_API mvVSLAM* mvVSLAM_Initialize( const mvCameraConfiguration *pnConfig );


//------------------------------------------------------------------------------
/// @brief
///     Deinitialize VSLAM object
/// @param pObj
///     Pointer to VSLAM object
//------------------------------------------------------------------------------
void MV_API mvVSLAM_Deinitialize( mvVSLAM* pObj );


//------------------------------------------------------------------------------
/// @brief
///     Pass camera frame to the VSLAM object
/// @param pObj
///     Pointer to VSLAM object
/// @param t
///     Timestamp of camera frame
/// @param pxls
///     Pointer to camera frame data
//------------------------------------------------------------------------------
void MV_API mvVSLAM_AddImage( mvVSLAM* pObj, int64_t t, const uint8_t* pxls );


//------------------------------------------------------------------------------
/// @brief
///     Compute and return pose
/// @param pObj
///     Pointer to VSLAM object
/// @return
///     Computed pose from previous frame and IMU data
//------------------------------------------------------------------------------
const mvVSLAMTrackingPose MV_API mvVSLAM_GetPose( mvVSLAM* pObj );

//------------------------------------------------------------------------------
/// @brief
///     Add target to VSLAM internal target database
/// @param pObj
///     VSLAM object
/// @param name
///     Target name
/// @param pxls
///     Pointer to image
/// @param pxlWidth
///     Image width in pixels
/// @param pxlHeight
///     Image height in pixels
/// @pxlStride
///     Image memory stride
/// @param targetWidth
///     Physical width of target
/// @param targetHeight
///     Physical height of target
/// @param targetPose
///     6DOF pose of target ( center and rotation )
/// @return
///     On success target ID >= 0
///     -1 on failure
//------------------------------------------------------------------------------
int MV_API mvVSLAM_AddTarget( mvVSLAM* pObj, const char* name, 
                              const uint8_t* pxls, uint32_t pxlWidth, 
                              uint32_t pxlHeight, uint32_t pxlStride, 
                              float32_t targetWidth, float32_t targetHeight, 
                              mvPose6DRT targetPose );


//------------------------------------------------------------------------------
/// @brief
///     Inquire if VSLAM has new map points
/// @param pObj
///     Pointer to VSLAM object
/// @return
///     Number of current map points
//------------------------------------------------------------------------------
int MV_API mvVSLAM_HasUpdatedPointCloud( mvVSLAM *pObj );


//------------------------------------------------------------------------------
/// @brief
///     Grab point cloud
/// @param pObj
///     Pointer to VSLAM object
/// @param pPoints
///     Pre-allocated array of 3 floats per map point queried
/// @param maxPoints
///     Max number of points requested. Should match allocated number of points
/// @return
///     Number of points filled into the pPoints array (number of tripples). 
///     This can be smaller then number returned by mvVSLAM_HasUpdatedPointCloud
//------------------------------------------------------------------------------
int MV_API mvVSLAM_GetPointCloud( mvVSLAM* pObj, float* pPoints, 
                                  uint32_t maxPoints );


//------------------------------------------------------------------------------
/// @brief
///     Get the number of keyframes in the maps
/// @param pObj
///     Pointer to SVSLAM object
/// @return
///     Number of keyframes in the first source map (there might be multiple 
///     sourcemaps in SLAM)
//------------------------------------------------------------------------------
int MV_API mvVSLAM_GetMapSize( mvVSLAM* pObj );


//------------------------------------------------------------------------------
/// @brief
///     Get positions of keyframes in the maps
/// @param pObj
///     Pointer to SVSLAM object
/// @param pKeyframes
///     Pre-allocated array of keyframes queried
/// @param maxKeyframes
///     Max number of keyframes requested. Should match allocated number of keyframes
/// @return
///     Number of keyframes in the first source map (there might be multiple 
///     sourcemaps in SLAM)
//------------------------------------------------------------------------------
int MV_API mvVSLAM_GetKeyframes(mvVSLAM* pObj, MV_ActiveKeyframe* pKeyframes, uint32_t maxKeyframes);


//------------------------------------------------------------------------------
/// @brief
///     Save a map to the given path
/// @param pObj
///     Pointer to SVSLAM object
/// @param mapFolder
///     The folder for saving map
/// @param mapName
///     Name of Map
/// @return
///     True if the map is successfully saved. False otherwise
//------------------------------------------------------------------------------
bool MV_API mvVSLAM_SaveMap( mvVSLAM* pObj, const char* mapFolder, const char* mapName );


//------------------------------------------------------------------------------
/// @brief
///     Preset the path to load a startup map for SLAM
/// @param pObj
///     Pointer to SVSLAM object
/// @param mapPath
///     The map path
/// @param addingKeyframesEnabled
///     Whether to enable to add new keyframes to the initial map
//------------------------------------------------------------------------------
void MV_API mvVSLAM_SetMapPath( mvVSLAM* pObj, const char *mapPath, 
                                bool addingKeyframesEnabled );


//------------------------------------------------------------------------------
/// @brief
///     Incrementally loading the keyframe content for the map
/// @param pObj
///     Pointer to SVSLAM object
/// @param mapFolder
///     Map path for loading
//------------------------------------------------------------------------------
void MV_API mvVSLAM_IncrementallyLoadMap( mvVSLAM* pObj, const char* mapFolder );


//------------------------------------------------------------------------------
/// @brief
///     Reset all map and pose, then start from zero state
/// @param pObj
///     Pointer to SVSLAM object
//------------------------------------------------------------------------------
void MV_API mvVSLAM_DeepReset( mvVSLAM* pObj, bool saveMap );


//------------------------------------------------------------------------------
/// @brief
///     Set the number of keyframes around robot to be protected from release
/// @param pObj
///     Pointer to SVSLAM object
/// @param patchSize
///     The patch size (number of keyframes)
//------------------------------------------------------------------------------
void MV_API mvVSLAM_SetKfPatchSizeToProtect( mvVSLAM* pObj, int patchSize );


//------------------------------------------------------------------------------
/// @brief
///     Set whether to enable descriptor save/load for relocator
/// @param pObj
///     Pointer to SVSLAM object
/// @param enable
///     The flag to set
//------------------------------------------------------------------------------
void MV_API mvVSLAM_EnableDescriptorSaveLoad( mvVSLAM* pObj, bool enable );


//------------------------------------------------------------------------------
/// @brief
///     Set rules for keyframe selector
/// @param pObj
///     Pointer to VSLAM object
/// @param minDistance
///     Minimum relative distance (meters) for taking a new keyframe without any
///     additional triggers. Default: 0.1
/// @param minDistanceAngle
///     Minimum relative distance for taking a new keyframe when the viewing 
///     angle to the closest keyframe is large. Default: 0.1
/// @param minAngleAngle
///     The relative angle (radians w.r.t. FOC) for the angle criteria. Takes 
///     effect together with "minDistanceAngle". Default: 0.2
/// @param framesDelayForCriteriaTrigger
///     Minimum number of frames since last keyframe to allow taking a new 
///     keyframe. Default: 8
/// @param maxKeyframe
///     Maximum number of keyframes in current map. Default: indefinite
//------------------------------------------------------------------------------
void MV_API mvVSLAM_SetKeyframeSelectorParameters( mvVSLAM* pObj,
                                                   float minDistance,
                                                   float minDistanceAngle,
                                                   float minAngleAngle,
                                                   size_t framesDelayForCriteriaTrigger,
	                                               int maxKeyframe );


//------------------------------------------------------------------------------
/// @brief
///     Override target initialization from mvVSLAM_AddTarget() with scale-free
///     tracking instead.
/// @param pObj
///     Pointer to VSLAM object
/// @param enable
///     TRUE = turn on scale-free tracking and ignores initialization target.
///     FALSE = turn off scale-free tracking and return to target initialization
//------------------------------------------------------------------------------
void MV_API mvVSLAM_EnableScaleFreeTracking( mvVSLAM* pObj, bool enable );


//------------------------------------------------------------------------------
/// @brief
///     Enable loop closure detection and subsequent bundle adjustment.
/// @param pObj
///     Pointer to VSLAM object
/// @param enable
///     TRUE = turn on loop closure operation.
///     FALSE = turn off loop closure operation
//------------------------------------------------------------------------------
void MV_API mvVSLAM_EnableLoopClosure(mvVSLAM* pObj, bool enable);


//------------------------------------------------------------------------------
/// @brief
///     Enable wheel motion model in initialization without external target image
/// @param pObj
///     Pointer to VSLAM object
/// @param enable
///     TRUE = turn on wheel motion model
///     FALSE = turn off wheel motion model
//------------------------------------------------------------------------------
void MV_API mvVSLAM_EnableWheelInitialization( mvVSLAM* pObj, bool enable );


//------------------------------------------------------------------------------
/// @brief
///     Inquire if VSLAM has tracked observations in current frane
/// @param pObj
///     Pointer to VSLAM object
/// @return
///     Number of current observations
//------------------------------------------------------------------------------
int MV_API mvVSLAM_HasTrackedObservation( mvVSLAM *pObj );



//------------------------------------------------------------------------------
/// @brief
///     Grab observation
/// @param pObj
///     Pointer to VSLAM object
/// @param pObservation
///     Pre-allocated array of observation queried
/// @param maxPoints
///     Max number of observations requested. Should match allocated number of points
/// @return
///     Number of points filled into the array. 
//------------------------------------------------------------------------------
int MV_API mvVSLAM_GetObservation( mvVSLAM* pObj, MV_TrackedObservation* pObservation, uint32_t maxPoints );



//------------------------------------------------------------------------------
/// @brief
///     transform the map
/// @param pObj
///     Pointer to VSLAM object
/// @param scale
///     scaler for the whole map
/// @param poseMatrix
///     3x4 matrix as 6 DOF pose
/// @return
///     True if the transformation is successful; false otherwise
//------------------------------------------------------------------------------
bool MV_API mvVSLAM_TransformMap( mvVSLAM* pObj, float scale, float poseMatrix[3][4]);


//------------------------------------------------------------------------------
/// @brief
///     Set working directory for map management
/// @param pObj
///     Pointer to VSLAM object
/// @param folder
///     Target directory
/// @return
///     True if the operation is successful; false otherwise
//------------------------------------------------------------------------------
bool MV_API mvVSLAM_SetWorkingDirectory( mvVSLAM* pObj, const char *folder );


//------------------------------------------------------------------------------
/// @brief
///     Set working directory for map management
/// @param pObj
///     Pointer to VSLAM object
/// @param enable
///     TRUE = turn on synchromous mode.
///     FALSE = turn off synchromous mode.
//------------------------------------------------------------------------------
void MV_API mvVSLAM_EnableMapperSynchronousMode( mvVSLAM* pObj, bool enable );


//------------------------------------------------------------------------------
/// @brief
///     Load the default map from disk and merge to current map
/// @param pObj
///     Pointer to VSLAM object
//------------------------------------------------------------------------------
bool MV_API mvVSLAM_LoadDefaultMapAndMerge( mvVSLAM* pObj );


//------------------------------------------------------------------------------
/// @brief
///     Save the default map to disk
/// @param pObj
///     Pointer to VSLAM object
//------------------------------------------------------------------------------
bool MV_API mvVSLAM_SaveDefaultMap( mvVSLAM* pObj );


//------------------------------------------------------------------------------
/// @brief
///     Pass camera frame together with wheel odometry to the VSLAM object
/// @param pObj
///     Pointer to VSLAM object
/// @param t
///     Timestamp of camera frame
/// @param pxls
///     Pointer to camera frame data
/// @param poseMatrix
///     3x4 matrix as 6DOF pose
/// @param linearVelocity3D
///     3x1 vector as 3DOF linear velocity, represented in camera frame
/// @param angularVelocity3D
///     3x1 vecotr as 3DOF angular velocity, represented in camera frame
//------------------------------------------------------------------------------
void MV_API mvVSLAM_AddImageWithWheel( mvVSLAM* pObj, int64_t t, const uint8_t* pxls, float poseMatrix[3][4], const float* linearVelocity3D, const float* angularVelocity3D );


#ifdef __cplusplus
}
#endif


#if defined _WIN32 && !defined MV_EXPORTS
#include "win/mvVSLAM_DLLGlue.h"
#endif


#endif