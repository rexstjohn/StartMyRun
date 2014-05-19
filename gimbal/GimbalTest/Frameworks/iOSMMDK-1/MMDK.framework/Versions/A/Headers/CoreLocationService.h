//
//  CoreLocationService.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/26/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 Protocol for wrapping the Core Location Services.  This provides a means for swapping out interfaces for testing purposes
 */
@protocol CoreLocationService <NSObject, CLLocationManagerDelegate>

/**
 Called to start updating the location service
 */
- (void)startLocationService;

/**
 Called to stop the location service from updating
 */
- (void)stopLocationService;

/**
 The delegate is the object getting the location updates
 */
@property(nonatomic, strong) id <CLLocationManagerDelegate> delegate;

/**
 The location is the current location of the location manager implemented, mock or real
 */
@property(nonatomic, retain) CLLocation *location;

@end