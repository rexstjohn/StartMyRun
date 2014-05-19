//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
@class MMDKRouteLocationDO;

@interface MMDKRouteDO : NSManagedObject

@property(nonatomic, strong) NSString *city;
@property(nonatomic, strong) NSString *country;
@property(nonatomic, strong) NSNumber *distance;
@property(nonatomic, strong) NSNumber *gain;
@property(nonatomic, strong) NSString *routeID;
@property(nonatomic, strong) NSString *routeKey;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *state;
@property(nonatomic, strong) NSNumber *bookmarked;
@property(nonatomic, strong) NSNumber *startLatitude;
@property(nonatomic, strong) NSNumber *startLongitude;
@property(nonatomic, strong) NSNumber *syncedWithServer;
@property(nonatomic, strong) NSNumber *nearby;
@property(nonatomic, strong) NSNumber *myroute;
@property(nonatomic, strong) NSNumber *activityTypeID;
@property(nonatomic, strong) NSString *routeTypeID;
@property(nonatomic, strong) NSSet *routeLocations;
@property(nonatomic, strong) NSDate *routeDate;
@property(nonatomic, strong) NSNumber *privacy;
@property(nonatomic, strong) NSNumber *distanceAway;
@property(nonatomic, strong) NSNumber *maxElevation;
@property(nonatomic, strong) NSNumber *minElevation;
@property(nonatomic, strong) NSNumber *descent;

@end

@interface MMDKRouteDO (CoreDataGeneratedAccessors)

- (void)addRouteLocationsObject:(MMDKRouteLocationDO *)value;

- (void)removeRouteLocationsObject:(MMDKRouteLocationDO *)value;

- (void)addRouteLocations:(NSSet *)values;

- (void)removeRouteLocations:(NSSet *)values;
@end