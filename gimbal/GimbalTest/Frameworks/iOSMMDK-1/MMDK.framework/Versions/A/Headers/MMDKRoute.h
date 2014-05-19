//
//  MMDKRoute.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "MMDKObject.h"

/**
 MMDKRoute is the object that represents a route
 */
@interface MMDKRoute : MMDKObject

/**
 Location Points is an array that contains CLLocations that make up a given route
 */
@property(nonatomic, strong) NSMutableArray *locationPoints;

/**
 Name of the route
 */
@property(nonatomic, strong) NSString *routeName;

/**
 A description of the route
 */
@property(nonatomic, strong) NSString *routeDescription;

/**
 City where the route was started in
 */
@property(nonatomic, strong) NSString *city;

/**
 State where the route was started in
 */
@property(nonatomic, strong) NSString *state;

/**
 Country where the route was started in
 */
@property(nonatomic, strong) NSString *country;

/**
 ID of the route
 */
@property(nonatomic, strong) NSNumber *routeID;

/**
 Key of the route
 */
@property(nonatomic, strong) NSNumber *routeKey;

/**
 The route's activity type
 */
@property(nonatomic, assign) NSUInteger activityTypeID;

/**
 Privacy type of the route
 */
@property(nonatomic, assign) PrivacyType privacy;

/**
 Date in which the route was created on
 */
@property(nonatomic, strong) NSDate *routeDate;

/**
 Starting location of the route
 */
@property(nonatomic, assign) CLLocationCoordinate2D startLocation;

/**
 Maximum elevation of the route, in meters
 */
@property(nonatomic, assign) double maximumElevation;

/**
 Minimum elevation of the route, in meters
 */
@property(nonatomic, assign) double minimumElevation;

/**
 Total gain of the route, in meters
 */
@property(nonatomic, assign) double gain;

/**
 Total descent of the route, in meters
 */
@property(nonatomic, assign) double descent;

/**
 Total distance of the route in meters
 */
@property(nonatomic, assign) double distance;

/**
 Distance of the route from the current location in meters
 */
@property(nonatomic, assign) double distanceAway;

/**
 Information about the user who created this route
 */
@property(nonatomic, strong) NSDictionary *routeUserInfo;

/**
 An array containing route points with elevation.
 These are a summary of the route and it does not contain every route point.
 */
@property(nonatomic, strong) NSArray *elevationSummary;

/**
 A Bool indicated wether or not this route belongs to the logged in user
 */
@property(nonatomic, assign) BOOL usersRoute;

/**
 Sets the route bookmark flag with MapMyFitness based on the provided BOOL
 @param bookmarked the BOOL value indicating if the route is bookmarked
 @param success the block called on the successful setting of the route bookmark
 @param fail the block called on failure to set the bookmark flag
 */
//- (void)setBookmarked:(BOOL)bookmarked
//			onSuccess:(MMDKDidSucceedWithSuccessBlock)success
//			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Bool value indicating whether or not the route is bookmarked
 */
@property(assign) BOOL bookmarked;


/**
 Method to get a UIImage for the route
 @param size is the CGSize of the image disired. Following are the allowable image sizes:

 ('500x500', '375x280', '290x290', '250x250', '250x180', '200x200', '180x180', '165x165', '135x135', '100x100', '90x90', '75x75', '60x60', '50x50')

 @param success is the block called on the successful obtaining of an image for the route. This will return a route image
 @param fail is the block called on the failure to obtain an image for the route
 */
//- (void)getRouteImageOfSize:(CGSize)size
//				  OnSuccess:(MMDKDidLoadObjectBlock)success
//					 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Retrieves the distance in meters covered by
 the location points stored in the route
 */
- (double)calculateRouteDistanceMeters;

/**
 Adds the locations that are not present in the route already.
 @param locations list of locations to add to the route.
 */
- (void)addUniqueLocations:(NSArray *)locations;

@end
