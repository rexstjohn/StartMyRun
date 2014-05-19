//
//  MMDKRouteFilter.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef enum {
	MINE,
	NEARBY,
	BOOKMARKED
} ROUTE_TYPE;

/**
 The filter to provide to search for routes
 */
@interface MMDKRouteFilter : NSObject

/**
 The type of route desired.
 */
@property(nonatomic, assign) ROUTE_TYPE routeType;

/**
 The start record of routes to search
 */
@property(nonatomic, assign) NSUInteger startIndex;

/**
 The end record of routes to search
 */
@property(nonatomic, assign) NSUInteger endIndex;

/**
 The minimum route distance to search
 */
@property(nonatomic, assign) double minimumDistance;

/**
 The maximum route distance to search
 */
@property(nonatomic, assign) double maximumDistance;

/**
 The current location to search from
 */
@property(nonatomic, strong) CLLocation *currentLocation;

/**
 The maximum distance to search for routes from your current location
 */
@property(nonatomic, assign) double distanceFromLocation;

/**
 The basis of the route filter is to obtain routes that meet specific criterium desired by the user of the application.

 @param routeType is the ROUTE_TYPE desired, defaults to zero
 @param startIndex is the record start index for routes, defaulted to zero
 @param endIndex is the record end index for routes, defaulted to 25
 @param minimumDistance is the minimum distance for routes desired, in meters
 @param maximumDistance is the maximum distance for routes desired, in meters
 @param currentLocation is the user's current location, for use with nearby routes
 @param distanceFromLocation is the maximum distance from the provided location to search for routes
 */
+ (MMDKRouteFilter *)routeFilterForRoutesOfType:(ROUTE_TYPE)routeType
									 startIndex:(NSUInteger)startIndex
									   endIndex:(NSUInteger)endIndex
								minimumDistance:(double)minimumDistance
								maximumDistance:(double)maximumDistance
								currentLocation:(CLLocation *)currentLocation
						   distanceFromLocation:(double)distanceFromLocation;
@end
