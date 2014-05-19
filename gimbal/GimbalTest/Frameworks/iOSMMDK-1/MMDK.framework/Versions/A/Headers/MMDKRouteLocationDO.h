//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class MMDKRouteDO;
@class MMDKSequenceDataDO;


@interface MMDKRouteLocationDO : NSManagedObject
@property(nonatomic, strong) NSNumber *lat;
@property(nonatomic, strong) NSNumber *lng;
@property(nonatomic, strong) NSNumber *vAccuracy;
@property(nonatomic, strong) NSNumber *hAccuracy;
@property(nonatomic, strong) NSNumber *course;
@property(nonatomic, strong) NSNumber *altitude;
@property(nonatomic, strong) NSDate *timestamp;
@property(nonatomic, strong) MMDKRouteDO *route;
@property(nonatomic, strong) MMDKSequenceDataDO *sequenceData;
@end