//
//  ActivityType.h
//  MMDK
//
//  Created by Ryan P. Trunck on 7/22/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 MMDKActivityType is the class that represents an activity type.
 */
@interface MMDKActivityType : NSObject

/**
 The activityTypeID is the unique ID for a given activity type
 */
@property(nonatomic, assign) NSUInteger activityTypeID;

/**
 The activityTypeName is the name of the activity type
 */
@property(nonatomic, copy) NSString *activityTypeName;

/**
 hasRoutes is the bool that indicates if the activity type includes routes (and corresponding GPS data).
 */
@property(nonatomic, assign) BOOL hasRoutes;

/**
 mets is the specific mets value for an activity type where the mets value doesn't correspond to a speed.
 */
@property(nonatomic, assign) float mets;

/**
 metsSpeeds is a dictionary containing mets values corresponding to a given speed.
 */
@property(nonatomic, strong) NSDictionary *metsSpeeds;

/**
 parentActivityID is the id of the parent activity type, if any.
 */
@property(nonatomic, assign) NSUInteger parentActivityID;

/**
 parentActivityName is the name of the parent activity type, if any.
 */
@property(nonatomic, copy) NSString *parentActivityName;

/**
 shortName is the an abbreviated name for the activity type.
 */
@property(nonatomic, copy) NSString *shortName;

/**
 This method converts a passed NSDictionary to a MMDKActivityType
 @param dictionary is the NSDicationary containing data representing the activity type
 */
+ (MMDKActivityType *)activityTypeForDictionary:(NSDictionary *)dictionary;

/**
 This method converts a MMDKActivityType to a NSDictionary
 @param activity is the MMDKActivityType for conversion.
 */
+ (NSDictionary *)dictionaryForActivityType:(MMDKActivityType *)activity;

@end
