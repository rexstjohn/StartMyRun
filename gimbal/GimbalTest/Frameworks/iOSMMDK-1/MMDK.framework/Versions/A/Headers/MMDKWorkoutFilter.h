//
//  MMDKWorkoutFilter.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/21/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The filter for searching routes
 */
@interface MMDKWorkoutFilter : NSObject

/**
 The start record of routes to search
 */
@property(nonatomic, assign) NSUInteger startIndex;

/**
 The end record of routes to search
 */
@property(nonatomic, assign) NSUInteger endIndex;

/**
 The basis of the workout filter is to obtain workouts that meet specific criterium desired by the user of the application.
 @param startIndex is the record start index for workouts, defaulted to zero
 @param endIndex is the record end index for workouts, defaulted to 25
 */
+ (MMDKWorkoutFilter *)workoutFilterStartIndex:(NSUInteger)startIndex
									  endIndex:(NSUInteger)endIndex;

@end
