//
// Created by MiKey on 11/02/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKWorkout.h"
#import "MMDKActivityType.h"
#import "MMDKObjectMapper.h"
#import "MMDKWorkoutDO.h"

#define kMappedWorkoutId @"workout_id"
#define kMappedWorkoutKey @"workout_key"
#define kMappedWorkoutDate @"workout_date"
#define kMappedWorkoutEndTime @"workout_end_time"
#define kMappedWorkoutEndTimeCST @"workout_end_time_cst"
#define kMappedWorkoutCreateDateRaw @"created_date_raw"
#define kMappedWorkoutDateRaw @"raw_workout_date"
#define kMappedWorkoutCreateDate @"created_date"
#define kMappedWorkoutStartTime @"workout_start_time"
#define kMappedWorkoutStartTimeCST @"workout_start_time_cst"
#define kMappedWorkoutTimeTaken @"time_taken"
#define kMappedRouteId @"route_id"
#define kMappedRouteKey @"route_key"
#define kMappedActivityTypeId @"activity_type_id"
#define kMappedAvgCadence @"avg_cadence"
#define kMappedAvgHeartRate @"avg_hr"
#define kMappedAvgPace @"avg_pace"
#define kMappedAvgPower @"avg_power"
#define kMappedAvgSpeed @"avg_speed"
#define kMappedCaloriesBurned @"calories_burned"
#define kMappedDistance @"distance"
#define kMappedVerified @"is_verified"
#define kMappedMaxHeartRate @"max_hr"
#define kMappedMaxPace @"max_pace"
#define kMappedMaxSpeed @"max_speed"
#define kMappedMaxPower @"max_power"
#define kMappedMets @"mets"
#define kMappedNumberOfRepititions @"number_of_repetitions"
#define kMappedNumberOfSteps @"number_of_steps"
#define kMappedParentWorkoutTypeId @"parent_workout_type_id"
#define kMappedQualityLevel @"quality_level"
#define kMappedWorkoutPrivacySetting @"workout_privacy_setting"
#define kMappedWorkoutDescription @"workout_description"
#define kMappedWorkoutUserId @"user_id"

#define kMMDKUserId @"MMDKUserID"

#define kWorkoutRawDateFormat @"yyyy'-'MM'-'dd' 'HH':'mm':'ss'"
#define kWorkoutEndDateFormat @"yyyy-MM-dd HH:mm:ss"
#define kWorkoutDateFormat @"yyyy-MM-dd"
#define kSecondaryDateFormat @"MM/dd/yyyy"
#define kWorkoutDefaultTimeZone @"CST"
#define kTimeOnlyFormat @"HH:mm:ss"

@interface MMDKWorkoutMapper : MMDKObjectMapper

+ (MMDKWorkout *)mmdkWorkoutFromDictionary:(NSDictionary *)result;

+ (NSDictionary *)dictionaryFromWorkout:(MMDKWorkout *)workout;

+ (void)cleanSaveDataForWorkout:(MMDKWorkout *)workout;

+ (void)mapWorkoutDO:(MMDKWorkoutDO *)workoutDO fromWorkout:(MMDKWorkout *)workout;

+ (void)mapWorkout:(MMDKWorkout *)workout fromWorkoutDO:(MMDKWorkoutDO *)workoutDO;
@end