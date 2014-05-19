//
// Created by MiKey on 11/23/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

@class MMDKWorkout;
@class MMDKRoute;


@interface MMDKMockData : NSObject
- (MMDKRoute *)getMockRoute;

- (MMDKWorkout *)getMockWorkout;

- (NSArray *)getMockActivityList;
@end