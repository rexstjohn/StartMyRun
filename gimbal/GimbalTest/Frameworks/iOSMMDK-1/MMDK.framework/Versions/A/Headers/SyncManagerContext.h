//
// Created by MiKey on 12/5/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKCommons.h"
#import "MMDKRoute.h"
#import "MMDKWorkout.h"
#import "MMDKRouteDO.h"
#import "MMDKWorkoutDO.h"


@interface SyncManagerContext : NSObject

@property (nonatomic, strong) MMDKWorkoutDO *workoutDO;
@property (nonatomic, strong) MMDKRouteDO *routeDO;
@property (nonatomic, strong) MMDKWorkout *workout;
@property (nonatomic, strong) MMDKRoute *route;
@property (nonatomic, strong) MMDKDidLoadObjectBlock successBlock;
@property (nonatomic, strong) MMDKDidFailWithErrorBlock failBlock;

- (void)generateTemporaryKeys;

@end