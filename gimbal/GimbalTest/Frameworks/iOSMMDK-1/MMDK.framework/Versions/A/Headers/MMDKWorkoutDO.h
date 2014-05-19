//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKObject.h"
#import <CoreData/CoreData.h>

@class MMDKWorkout;

/**
* Internal representation of a workout. Used for core data interactions because MMDKWorkout does not adhere to
* CoreData restrictions.
*/
@interface MMDKWorkoutDO : NSManagedObject
/**
 The activityTypeID is the activity type of the workout
 */
@property(nonatomic, strong) NSNumber *activityTypeID;

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
@property(nonatomic, strong) NSNumber *distance;

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
 Calories burned for the workout NSUInteger
 */
@property(nonatomic, strong) NSNumber *caloriesBurned;

/**
 The privacy of the workout
 */
@property(nonatomic, strong) NSNumber *privacy;

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
 double
 */
@property(nonatomic, strong) NSNumber *avgHR;

/**
 Current pace of the workout (calculated from the last two points)
 double
 */
@property(nonatomic, strong) NSNumber *currentPace;

/**
 Average pace of the workout
 double
 */
@property(nonatomic, strong) NSNumber *avgPace;

/**
 Average cadence of the workout
 double
 */
@property(nonatomic, strong) NSNumber *avgCadence;

/**
 Average power of the workout
 double
 */
@property(nonatomic, strong) NSNumber *avgPower;

/**
 Current speed of the workout (calculated from the last two points)
 double
 */
@property(nonatomic, strong) NSNumber *currentSpeed;

/**
 Average speed of the workout
 double
 */
@property(nonatomic, strong) NSNumber *avgSpeed;

/**
 Maximum speed of the workout
 */
@property(nonatomic, strong) NSNumber *maxSpeed;

/**
 Maximum pace of the workout
 */
@property(nonatomic, strong) NSNumber *maxPace;

/**
 Maximum power of the workout
 */
@property(nonatomic, strong) NSNumber *maxPower;

/**
 Maximum cadence of the workout
 */
@property(nonatomic, strong) NSNumber *maxCadence;

/**
 Maximum heart rate of the workout
 */
@property(nonatomic, strong) NSNumber *maxHeartRate;

/**
 Mets value for this workout
 */
@property(nonatomic, strong) NSNumber *mets;

/**
 Quality level for the workout
 */
@property(nonatomic, strong) NSNumber *qualityLevel;

/**
 The activity type ID for the parent workout, if any
 */
@property(nonatomic, strong) NSNumber *parentWorkoutActivityTypeID;

/**
 The number of repetitions done for a workout
 */
@property(nonatomic, strong) NSNumber *numberOfRepetitions;

/**
 Length of the workout in seconds
 */
@property(nonatomic, strong) NSNumber *timeTaken;

/**
 Number of steps for the workout
 */
@property(nonatomic, strong) NSNumber *numberOfSteps;

/**
 Bool value if the workout has routes
 */
@property(nonatomic, strong) NSNumber *hasRoutes;

/**
 Bool value if the workout is "verified"
 */
@property(nonatomic, strong) NSNumber *verified;

/**
 Bool value indicating wether the workout belongs to the logged in user
 */
@property(nonatomic, strong) NSNumber *usersWorkout;

@property(nonatomic, retain) NSNumber *syncedWithServer;

@end