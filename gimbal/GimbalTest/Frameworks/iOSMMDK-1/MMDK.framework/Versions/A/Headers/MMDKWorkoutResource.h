//
//  Created by Ryan P. Trunck on 2/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKOAuthSession.h"
#import "MMDKWorkout.h"
#import "MMDKWorkoutFilter.h"
#import "MMDKActivityType.h"
#import "MMDKCommons.h"

@interface MMDKWorkoutResource : NSObject
- (id)initWithSession:(MMDKOAuthSession *)session;

/**
 Method to get a workout for the specified workout ID
 @param workoutID is the ID of the workout you want to retrieve
 @param success is block loaded with the workout object
 @param fail is the block loaded on failure to retrieve the workout.
 */
- (void)getWorkout:(NSString *)workoutID
		 onSuccess:(MMDKDidLoadObjectBlock)success
			onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to save a workout to the server
 @param workout is the MMDKWorkout object for saving
 @param success is the block called upon success
 @param fail is the block called on failure to save the workout
 */
- (void)saveWorkout:(MMDKWorkout *)workout
		  onSuccess:(MMDKDidLoadObjectBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to update a workout on the server
 @param workout is the MMDKWorkout object for updating
 @param success is the block called upon success with the updated workout
 @param fail is the block called on failure to save the workout
 */
- (void)updateWorkout:(MMDKWorkout *)workout
			onSuccess:(MMDKDidLoadObjectBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to delete a workout from the server
 @param workoutID is the ID of the workout you want to delete
 @param success is the block called upon successful deletion of the workout
 @param fail is the block called upon failure to delete the workout
 */
- (void)deleteWorkout:(NSString *)workoutID
			onSuccess:(MMDKDidSucceedWithSuccessBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to retrieve a list of workouts of a certain type and amount
 @param filter is the route filter used to search workouts
 @param success is the block called on successful load of the routes. This will return an NSArray of workouts.
 @param fail is the block called on failure to load the workouts
 */
- (void)getWorkoutsWithFilter:(MMDKWorkoutFilter *)filter
					onSuccess:(MMDKDidLoadObjectBlock)success
					   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to retrieve a list of workout activity types
 @param success is the block called on successful load of the workout activity types. This will return an NSArray of activities
 @param fail is the block called on the failure of load the activity type list
 */
//- (void)getActivityTypesOnSuccess:(MMDKDidLoadObjectBlock)success
//						   onFail:(MMDKDidFailWithErrorBlock)fail;


@end