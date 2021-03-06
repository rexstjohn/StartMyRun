//
//  UXRAppDelegate.m
//  GimbalTest
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 Mashery. All rights reserved.
//

#import "UXRAppDelegate.h"
#import <ContextCore/QLContextCoreConnector.h>
#import <FYX/FYXVisitManager.h>
#import <FYX/FYXTransmitter.h>

@implementation UXRAppDelegate

#define APP_ID "XXXX"
#define APP_SECRET "XXXX"

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    
    QLContextCoreConnector *connector = [QLContextCoreConnector new];
    [connector enableFromViewController:self.window.rootViewController success:^
     {
         NSLog(@"Gimbal enabled");
     } failure:^(NSError *error) {
         NSLog(@"Failed to initialize gimbal %@", error);
     }];
    
    // Proximity service
    [FYX setAppId:@"APP_ID" appSecret:@"APP_SECRET" callbackUrl:@"test://authcode"];
     [FYX startService:self];
    
    return YES;
}

#pragma proximity services

- (void)serviceStarted
{
    // this will be invoked if the service has successfully started
    // bluetooth scanning will be started at this point.
    NSLog(@"FYX Service Successfully Started");
}

- (void)startServiceFailed:(NSError *)error
{
    // this will be called if the service has failed to start
    NSLog(@"%@", error);
}


#pragma other stuff

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
