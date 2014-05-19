//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MMDKRouteLocationDO;
@class MMDKWorkoutSequenceDO;


@interface MMDKSequenceDataDO : NSManagedObject
@property(nonatomic, strong) NSNumber *speed;
@property(nonatomic, strong) NSNumber *pace;
@property(nonatomic, strong) NSNumber *power;
@property(nonatomic, strong) NSNumber *td;
@property(nonatomic, strong) NSNumber *lng;
@property(nonatomic, strong) NSNumber *lat;
@property(nonatomic, strong) NSNumber *hr;
@property(nonatomic, strong) NSNumber *cadence;
@property(nonatomic, strong) NSNumber *timestamp;
@property(nonatomic, strong) NSNumber *steps;

//Dev High Frequency Work
@property(nonatomic, strong) NSNumber *accelX;
@property(nonatomic, strong) NSNumber *accelY;
@property(nonatomic, strong) NSNumber *accelZ;
@property(nonatomic, strong) NSNumber *altitude;
@property(nonatomic, strong) NSNumber *attitudePitch;
@property(nonatomic, strong) NSNumber *attitudeRoll;
@property(nonatomic, strong) NSNumber *attitudeYaw;
@property(nonatomic, strong) NSNumber *gravX;
@property(nonatomic, strong) NSNumber *gravY;
@property(nonatomic, strong) NSNumber *gravZ;
@property(nonatomic, strong) NSNumber *rotationRateX;
@property(nonatomic, strong) NSNumber *rotationRateY;
@property(nonatomic, strong) NSNumber *rotationRateZ;


@property(nonatomic, strong) MMDKWorkoutSequenceDO *WorkoutSequence;
@property(nonatomic, strong) MMDKRouteLocationDO *routeLocationDO;
@end