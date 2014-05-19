//
//  CoreLocationImplementation.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/26/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
#import <UIKit/UIKit.h>
#import "CoreLocationService.h"

/**
 The actual implementation of the location manager
 */
@interface MMDKCoreLocationImplementation : NSObject <CoreLocationService, CLLocationManagerDelegate>

/**
 The actual Apple CLLocationManager
 */
@property(nonatomic, strong) CLLocationManager *locationManager;

/**
 The delegate is the object getting the location updates
 */
@property(nonatomic, strong) id <CLLocationManagerDelegate> delegate;

/**
 The location is the current location of the location manager implemented, mock or real
 */
@property(nonatomic, retain) CLLocation *location;

@end
