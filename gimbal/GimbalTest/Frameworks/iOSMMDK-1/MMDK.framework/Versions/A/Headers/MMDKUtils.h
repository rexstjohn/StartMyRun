//
//  MMDKUtils.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MILES_PER_METER .000621371192
#define MILES_PER_KILOMETER .621371192
#define FEET_PER_METER 3.2808399
#define METERS_PER_MILE 1609.344

/**
 MMDKUtil provides class methods for data.
 */
@interface MMDKUtils : NSObject
/**
 Converts miles to meters
 @param miles is the mile amount for conversion
 */
+ (double)convertMilesToMeters:(double)miles;

/**
 Converts meters to miles
 @param meters is the meters amount for conversion
 */
+ (double)convertMetersToMiles:(double)meters;

/**
 Convert meters to feet
 @param meters is the meters amount for conversion
 */
+ (double)convertMetersToFeet:(double)meters;

/**
 Converts miles to kilometers
 @param miles is the miles amount for conversion
 */
+ (double)convertMilesToKilometers:(double)miles;

/**
 Converts kilometers to miles
 @param kilometers if the kilometers amount for conversion
 */
+ (double)convertKilometersToMiles:(double)kilometers;

/**
 Converts kilometers to meters
 @param kilometers if the kilometers amount for conversion
 */
+ (double)convertKilometersToMeters:(double)kilometers;

/**
 Converts meters to kilometers
 @param meters is the meters amount for conversion
 */
+ (double)convertMetersToKilometers:(double)meters;

/**
 Converts a pace in seconds per meter to minutes per mile
 @param secondsPerMeter is the value for conversion
 */
+ (double)convertSecondsPerMeterToMinutesPerMile:(double)secondsPerMeter;

/**
 Converts a pace in seconds per meter to minutes per kilometer
 @param secondsPerMeter is the value for conversion
 */
+ (double)convertSecondsPerMeterToMinutesPerKilometer:(double)secondsPerMeter;

/**
 Converts a pace in minutes per mile to seconds per meter
 @param minutesPerMile is the value for conversion
 */
+ (double)convertMinutesPerMileToSecondsPerMeter:(double)minutesPerMile;

/**
 Converts a speed in meters per second to miles per hour
 @param metersPerSecond is the value for conversion
 */
+ (double)convertMetersPerSecondToMilesPerHour:(double)metersPerSecond;

/**
 Converts a speed in meters per second to kilometers per hour
 @param metersPerSecond is the value for conversion
 */
+ (double)convertMetersPerSecondToKilometersPerHour:(double)metersPerSecond;

/**
 Converts a speed in miles per hour to meters per second
 @param milesPerHour is the value for conversion
 */
+ (double)convertMilesPerHourToMetersPerSecond:(double)milesPerHour;

/**
 Converts a speed in kilometers per hour to meters per second
 @param kilosPerHour is the value for conversion
 */
+ (double)convertKilometersPerHourToMetersPerSecond:(double)kilosPerHour;

/**
 Converts a pace in minutes per kilometer to seconds per meter
 @param minutesPerKilo is the value for conversion
 */
+ (double)convertMinutesPerKilometerToSecondsPerMeter:(double)minutesPerKilo;

/**
 Converts power in watts to kJ/h
 @param watts is the value for conversion
 */
+ (double)convertWattsToKilojoulesPerHour:(double)watts;

/**
 Converts power in kJ/h to watts
 @param kjPerHour is the value for conversion
 */
+ (double)convertKilojoulesPerHourToWatts:(double)kjPerHour;

/**
 Converts weight in lbs to kg
 @param lbs is the value for conversion
 */
+ (double)convertWeightInPoundsToKilograms:(double)lbs;

/**
 Converts weight in kg to lbs
 @param kg is the value for conversion
 */
+ (double)convertWeightInKilogramsToPounds:(double)kg;

/**
 Converts height in inches to cm
 @param inches is the value for conversion
 */
+ (double)convertHeightInInchesToCentimeters:(double)inches;

/**
 Converts height in cm to inches
 @param cm is the value for conversion
 */
+ (double)convertHeightInCentimetersToInches:(double)cm;

/**
 Calculate Body Mass Index
 @param heightInInches is the value for conversion
 @param weightInLbs is the value for conversion
 */
+ (double)calculateBMIFromHeightInInches:(int)heightInInches
						  andWeightInLbs:(double)weightInLbs;

/**
 Linearly interpolate between two points given as two element vectors.
 Safe to use when two points are the same, or on discontinuities, will
 return dependent value of first point given.
 @param lower is an array of element vectors
 @param upper is an array of element vectors
 @param at is the current value
 */
+ (double)linearInterpolateLowerValues:(NSArray *)lower
						   upperValues:(NSArray *)upper
							   atValue:(double)at;

/**
 Converts seconds to a time format for a label
 @param duration is the length in seconds for conversion to a time string.
 */
+ (NSString *)durationToLabel:(int)duration;

+ (double)calculateRouteDistanceMeters:(NSArray *)locationPoints;
@end
