//
// Created by MiKey on 11/24/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

#import "MMDKOAuthSession.h"
#import "MMDKRoute.h"
#import "MMDKRouteFilter.h"

@interface MMDKRouteResource : NSObject

- (id)initWithSession:(MMDKOAuthSession *)session;

- (void)getRoute:(NSString *)routeID
	   onSuccess:(MMDKDidLoadObjectBlock)success
		  onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)saveRoute:(MMDKRoute *)route
		onSuccess:(MMDKDidLoadObjectBlock)success
		   onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)updateRoute:(MMDKRoute *)route
		  onSuccess:(MMDKDidLoadObjectBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)deleteRoute:(NSString *)routeID
		  onSuccess:(MMDKDidSucceedWithSuccessBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)getRoutesWithFilter:(MMDKRouteFilter *)filter
				  onSuccess:(MMDKDidLoadObjectBlock)success
					 onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)getRouteImageForRoute:(NSString *)routeID
						 size:(CGSize)size
					OnSuccess:(MMDKDidLoadObjectBlock)success
					   onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)setBookmarked:(NSString *)routeID
		  setBookmark:(BOOL)bookmarked
			onSuccess:(MMDKDidSucceedWithSuccessBlock)success
			   onFail:(MMDKDidFailWithErrorBlock)fail;


@end