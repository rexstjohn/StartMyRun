//
//  MMDKRecordManager.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MMDKActivityType.h"
#import "MMDKLocationManager.h"
#import "MMDKOAuthSession.h"
#import "MMDKWorkout.h"
#import "MMDKRoute.h"
#import "MMDKCommons.h"
/**
 The MMDKRecordManager is the manager used to control recording
 */
@interface MMDKRecordManager : NSObject <LocationDelegate>

- (MMDKRecordManager *)initWithSession:(MMDKOAuthSession *)session;

/**
 Start recording of data.
 @param update block will be called when route or workout data updates
 @param success block will be called on the successful start of recording
 @param fail block will be called on failure to start recording
 */
- (void)startRecordingWithUpdateCallback:(MMDKDidLoadObjectsBlock)update
							   onSuccess:(MMDKDidSucceedWithSuccessBlock)success
								  onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Pause recording of data
 @param success is called is recording is successfully paused
 @param fail is called if recording fails to pause
 */
- (void)pauseRecording:(MMDKDidSucceedWithSuccessBlock)success
				onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Resume recording of data
 @param success called on successful resume
 @param fail called on failure to resume
 */
- (void)resumeRecording:(MMDKDidSucceedWithSuccessBlock)success
				 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Stop recording of data
 @param success called on successful stop
 @param fail called on failure to stop
 */
- (void)stopRecording:(MMDKDidSucceedWithSuccessBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Save recording of data
 @param success called on successful save of any one of the components for saving, passing an array with an MMDKRoute and MMDKWorkout
 @param fail called on failure to save all items
 */
- (void)saveRecording:(MMDKDidLoadObjectsBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Save recording of the data
 @param success called on successful save of all components for saving (e.g., route and workout both saving proper)
 @param partialSuccess called when one or more components fail to save properly (e.g., the route failed to save but the workout saved)
 @param fail called with no successful saves
 */
- (void)saveRecording:(MMDKDidLoadObjectsBlock)success
	 onPartialSuccess:(MMDKDidLoadObjectsBlock)partialSuccess
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 * Sets up the workout for the specified activity type.
 * @param activityType is the activity being performed in the workout.
 */
- (void)setupWorkoutForActivity:(MMDKActivityType *)activityType;

/**
 Access to the route being recorded or the last recorded for updating, removing, etc.
 */
@property(nonatomic, strong) MMDKRoute *route;

/**
 Access to the workout being recorded or last recorded for updating, removing, etc.
 */
@property(nonatomic, strong) MMDKWorkout *workout;

/**
 Bool indicating if the workout is in progress
 */

@property(nonatomic, readonly) BOOL workoutInProgress;

/**
 Bool indicating if the workout is currently paused
 */
@property(nonatomic, readonly) BOOL workoutPaused;

@end
