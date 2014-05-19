//
//  CoreLocationMock.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/26/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreLocationService.h"

#define LAT_START_POINT  39.75164434698163
#define LNG_START_POINT  -104.99582290649414

/**
 Mock implementation of CoreLocationServices to provide mock GPS data
 */

@interface MMDKCoreLocationMock : NSObject <CoreLocationService>

/**
 The delegate is the object getting the location updates
 */
@property(nonatomic, strong) id <CLLocationManagerDelegate> delegate;

/**
 The location is the current location of the location manager implemented, mock or real
 */
@property(nonatomic, retain) CLLocation *location;

/**
 No idea what the line array thing is
 */
@property(nonatomic, strong) NSArray *lineArray;

/**
 All the locations?
 */
@property(nonatomic, strong) NSMutableArray *locations;

/**
 This is a timer
 */
@property(nonatomic, strong) NSTimer *updateTimer;

@end