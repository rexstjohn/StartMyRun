//
//  MMDKWorkout.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/20/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKObject.h"

/**
 The MMDKWorkout object is the object that makes up a workout
 */
@interface MMDKWorkout : MMDKObject

/**
 The activityTypeID is the activity type of the workout
 */
@property(nonatomic, assign) NSUInteger activityTypeID;

/**
 The activityTypeName is the activity type name for the workout
 */
@property(nonatomic, strong) NSString *activityTypeName;

/**
 The workout name
 */
@property(nonatomic, strong) NSString *name;

/**
 The workout distance in miles
 */
@property(nonatomic, assign) double distance;

/**
 The date the workout occurred on
 */
@property(nonatomic, strong) NSDate *workoutDate;

/**
 The date the workout was created on
 */
@property(nonatomic, strong) NSDate *creationDate;

/**
 The date the workout started
 */
@property(nonatomic, strong) NSDate *workoutStartTime;

/**
 The time the workout ended
 */
@property(nonatomic, strong) NSDate *workoutEndTime;

/**
 Calories burned for the workout
 */
@property(nonatomic, assign) NSUInteger caloriesBurned;

/**
 The privacy of the workout
 */
@property(nonatomic, assign) PrivacyType privacy;

/**
 The workout ID
 */
@property(nonatomic, strong) NSNumber *workoutID;

/**
 The workout key
 */
@property(nonatomic, strong) NSNumber *workoutKey;

/**
 The related route ID, if any
 */
@property(nonatomic, strong) NSNumber *routeID;

/**
 The related route key, if any
 */
@property(nonatomic, strong) NSNumber *routeKey;

/**
 Average heart rate of the workout
 */
@property(nonatomic, assign) double avgHR;

/**
 Current pace of the workout (calculated from the last two points)
 */
@property(nonatomic, assign) double currentPace;

/**
 Average pace of the workout
 */
@property(nonatomic, assign) double avgPace;

/**
 Average cadence of the workout
 */
@property(nonatomic, assign) double avgCadence;

/**
 Average power of the workout
 */
@property(nonatomic, assign) double avgPower;

/**
 Current speed of the workout (calculated from the last two points)
 */
@property(nonatomic, assign) double currentSpeed;

/**
 Average speed of the workout
 */
@property(nonatomic, assign) double avgSpeed;

/**
 Maximum speed of the workout
 */
@property(nonatomic, assign) double maxSpeed;

/**
 Maximum pace of the workout
 */
@property(nonatomic, assign) double maxPace;

/**
 Maximum power of the workout
 */
@property(nonatomic, assign) double maxPower;

/**
 Maximum cadence of the workout
 */
@property(nonatomic, assign) double maxCadence;

/**
 Maximum heart rate of the workout
 */
@property(nonatomic, assign) NSUInteger maxHeartRate;

/**
 Mets value for this workout
 */
@property(nonatomic, assign) double mets;

/**
 Quality level for the workout
 */
@property(nonatomic, assign) NSUInteger qualityLevel;

/**
 The activity type ID for the parent workout, if any
 */
@property(nonatomic, assign) NSUInteger parentWorkoutActivityTypeID;

/**
 The number of repetitions done for a workout
 */
@property(nonatomic, assign) NSUInteger numberOfRepetitions;

/**
 Length of the workout in seconds
 */
@property(nonatomic, assign) unsigned long timeTaken;

/**
 Number of steps for the workout
 */
@property(nonatomic, assign) NSUInteger numberOfSteps;

/**
 Bool value if the workout has routes
 */
@property(nonatomic, assign) BOOL hasRoutes;

/**
 Bool value if the workout is "verified"
 */
@property(nonatomic, assign) BOOL verified;

/**
 Bool value indicating wether the workout belongs to the logged in user
 */
@property(nonatomic, assign) BOOL usersWorkout;

@end
