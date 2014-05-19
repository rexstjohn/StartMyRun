//
//  LocationManager.h
//  MMDK
//
//  Created by Ryan P. Trunck on 3/26/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <mach/mach_time.h>
#import "CoreLocationService.h"

/**
 The protocol used for specifing what method a delegate of the LocationManager should implement
 */
@protocol LocationDelegate <NSObject>

/**
 Updated location message
 @param manager is the current location manager (actual CLLocationManager or mock)
 @param locations contain one or more of the current and past locations
 */
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;

@optional
/**
 Location update error
 @param manager is the location manager (actual CLLocationManager or mock)
 @param error is the error containing details on why location update failed
 */
- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error;

@end

/**
 This is a singleton class that manages the MMDK's interaction with location services
 */
@interface LocationManager : NSObject <CoreLocationService>

/**
 The shared instance is the class method to obtain the singleton instance for LocationManager
 */
+ (LocationManager *)sharedInstance;

/**
 The serivce used to provide location information, either real GPS or mock
 */
@property(nonatomic, strong) id <CoreLocationService> coreLocationService;

/**
 The current mock or actual GPS location
 */
@property(nonatomic, strong) CLLocation *location;

/**
 Bool if the location services are running
 */
@property(nonatomic, assign) BOOL locationServicesOn;

/**
 Delegate of the location service
 */
@property(nonatomic, strong) id delegate;


/**
 Method to defer location updates until the application resumes or the specified distance or time occurs.
 Use of this method is recomended to optimal battery life
 @param distance - The distance (in meters) from the current location that must be travelled before event delivery resumes. To specify an unlimited distance, pass the CLLocationDistanceMax constant.
 @param timeout - The amount of time (in seconds) from the current time that must pass before event delivery resumes. To specify an unlimited amount of time, pass the CLTimeIntervalMax constant.
 @param success - The callback for when defering location updates is successful
 @param fail - The callback for when defering location updates fails. E.g., the current device doesn't support location update deferment

- (void)deferLocationUpdatesUntilDistance:(CLLocationDirection)distance
                                  timeout:(NSTimeInterval)timeout
                                OnSuccess:(MMDKDidSucceedWithSuccessBlock)success
                                   onFail:(MMDKDidFailWithErrorBlock)fail;

*/
/**
 Notification posted when one or more locations were updated
 */
#define kUpdatedLocation @"receivedALocationUpdate"

/**
 Notification posted when there is an error receiving location updateds
 */
#define kLocationServicesFailed @"failedToReceiveLocation"

/**
 Notification posted when location services is stopped
 */
#define kLocationServiceDidStop @"stoppedLocationServices"

@end
