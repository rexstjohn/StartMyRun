//
//  UXRAppDelegate.h
//  GimbalTest
//
//  Simple example of using Gimbal with the MapMyRun API
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 Mashery. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FYX/FYX.h>
#import <MMDK/MMDK.h>

@interface UXRAppDelegate : UIResponder <UIApplicationDelegate,FYXServiceDelegate>

@property (strong, nonatomic) UIWindow *window;

/**
 MapMyRun object for using the MapMyFitness SDK (MMDK)
 */
@property (strong) MMDK *mmdk;

/**
 MapMyRun user manager for getting user information, among other things
 */
@property (strong) MMDKUserManager *userManager;

/**
 MapMyRun route manager
 */
@property (strong) MMDKRouteManager *routeManager;


@end
