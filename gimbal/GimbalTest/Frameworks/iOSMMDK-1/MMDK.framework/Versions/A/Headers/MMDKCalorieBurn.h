//
//  CalorieBurn.h
//  iMapMy3
//
//  Created by Seth Howard on 3/10/10.
//  Copyright 2010 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKUserInfo.h"

/**
 Class to help calculate calories
 */

@interface MMDKCalorieBurn : NSObject {
}
/**
 Initialization of the CalorieBurn class
 @param gender is the user's gender
 @param heightInInches is the user's height in inches
 @param weightInPounds is the user's weight in pounds
 @param age is the user's age
 @param mets is the met or mets value for the workout
 */
- (id)initWithGender:(Gender)gender
		  withHeight:(int)heightInInches
		  withWeight:(int)weightInPounds
			 withAge:(int)age
			withMETS:(NSDictionary *)mets;

/**
 Method to calculate the calories burned for the given workout information
 @param speedMilesPerHour is the speed in miles per hour
 @param elapsedTime is the elapsed time of the workout in seconds
 @param cheatingIsOK is a bool set to determine if the user can cheat.
 */
- (NSNumber *)calculateCalories:(double)speedMilesPerHour
				withElapsedTime:(double)elapsedTime
				  allowCheating:(BOOL)cheatingIsOK;

@end
