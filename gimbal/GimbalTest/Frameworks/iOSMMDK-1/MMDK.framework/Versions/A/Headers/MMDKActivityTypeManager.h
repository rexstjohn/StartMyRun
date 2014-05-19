//
// Created by MiKey on 12/7/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKActivityType.h"
#import "MMDKWorkout.h"
#import "MMDKCommons.h"

#define kRecentActivities @"MMDKRecentActivityTypes"

@interface MMDKActivityTypeManager : NSObject

+ (MMDKActivityTypeManager *)instance;
- (MMDKActivityType *)activityTypeForID:(NSUInteger)actID;
- (NSArray *)recentActivityTypes;
- (void)cacheActivityTypeForWorkout:(MMDKWorkout *)workout;

- (void)getActivityTypes:(MMDKDidLoadObjectBlock)success
				  onFail:(MMDKDidFailWithErrorBlock)fail;
@end