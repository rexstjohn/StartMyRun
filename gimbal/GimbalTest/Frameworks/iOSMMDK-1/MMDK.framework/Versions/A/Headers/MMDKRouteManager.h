//
//  MMDKRouteManager.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/12/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKRouteFilter.h"
#import "MMDKOAuthSession.h"
#import <CoreLocation/CoreLocation.h>
#import "MMDKRoute.h"
#import "MMDKCommons.h"

@class MMDKRouteDO;

/**
 MMDKROuteManger is retrieving and saving routes
 */
@interface MMDKRouteManager : NSObject

@property (nonatomic, strong, readonly) MMDKOAuthSession *session;

+ (id)initializeWithSession:(MMDKOAuthSession *)session;

/**
 Method to get a route for the specified route ID
 @param routeID is the ID of the route you want to retrieve
 @param success is block loaded with the route object
 @param fail is the block loaded on failure to retrieve the route.
*/
- (void)getRoute:(NSString *)routeID
	   onSuccess:(MMDKDidLoadObjectBlock)success
		  onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to save a route to the server
 @param route is the MMDKRoute object for saving
 @param success is the block called upon success with the save MMDKRoute object returned
 @param fail is the block called on failure to save the route
 */
- (void)saveRoute:(MMDKRoute *)route
		onSuccess:(MMDKDidLoadObjectBlock)success
		   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to update a route to the server
 @param route is the MMDKRoute object for updating
 @param success is the block called upon success with the update MMDKRoute object returned
 @param fail is the block called on failure to update the route
 */
- (void)updateRoute:(MMDKRoute *)route
		  onSuccess:(MMDKDidLoadObjectBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to delete a route from the server
 @param routeID is the ID of the route you want to delete
 @param success is the block called upon successful deletion of the route
 @param fail is the block called upon failure to delete the route
 */
- (void)deleteRoute:(NSString *)routeID
		  onSuccess:(MMDKDidSucceedWithSuccessBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;


/**
 Method to retrieve a list of routes of a certain type and amount
 @param filter is a route filter wherein criterium is specified to obtain a list of routes fiting said criterium. If null this call will default to up to the last thrity of the users's routes
 @param success is the block called on successful load of the routes. This will return an NSArray of routes.
 @param fail is the block called on failure to load the routes
 */
- (void)getRoutesWithFilter:(MMDKRouteFilter *)filter
				  onSuccess:(MMDKDidLoadObjectBlock)success
					 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to geocode a route to add locality information
 @param route is the route for updating;
 @param success if the block called on successful geocoding of the route.
 @param fail is the block called with an error geocoding the route.
 */
- (void)geocodeRoute:(MMDKRoute *)route
		   onSuccess:(MMDKDidLoadObjectBlock)success
			  onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to get a UIImage for the route
 @param size is the CGSize of the image disired. Following are the allowable image sizes:

 ('500x500', '375x280', '290x290', '250x250', '250x180', '200x200', '180x180', '165x165', '135x135', '100x100', '90x90', '75x75', '60x60', '50x50')

 @param success is the block called on the successful obtaining of an image for the route. This will return a route image
 @param fail is the block called on the failure to obtain an image for the route
 */
- (void)getRouteImageForRoute:(NSString *)routeID
						 size:(CGSize)size
				  OnSuccess:(MMDKDidLoadObjectBlock)success
					 onFail:(MMDKDidFailWithErrorBlock)fail;


/**
 Sets the route bookmark flag with MapMyFitness based on the provided BOOL
 @param bookmarked the BOOL value indicating if the route is bookmarked
 @param success the block called on the successful setting of the route bookmark
 @param fail the block called on failure to set the bookmark flag
 */
- (void)setBookmarked:(NSString *)routeID
			setBookmark:(BOOL)bookmarked
			onSuccess:(MMDKDidSucceedWithSuccessBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method returns an example MMDKRoute with mock data
 */
+ (MMDKRoute *)getMockRoute;

- (NSArray *)getLocalRoutes;

- (MMDKRouteDO *)getLocalRouteByKey:(NSNumber *)number;

+ (void)mapRoute:(MMDKRoute *)route withRouteDO:(MMDKRouteDO *)routeDO;

@end
