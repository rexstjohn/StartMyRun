//
//  UXRViewController.m
//  GimbalTest
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 Mashery. All rights reserved.
//

#import "UXRBeaconSightingViewController.h"
#import <MMDK/MMDK.h>
#import <MMDK/MMDKWorkoutManager.h>
#import "UXRAppDelegate.h"
#import <MMDK/MMDKActivityType.h>

@interface UXRBeaconSightingViewController ()

// Map My Fitness exercise recorder instance.
@property (nonatomic, strong) MMDKRecordManager *recordManager;

@end

@implementation UXRBeaconSightingViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Create the visit manager;
    self.visitManager = [FYXVisitManager new];
    self.visitManager.delegate = self;
    [self.visitManager start];
}

#pragma visit manager

- (void)didArrive:(FYXVisit *)visit;
{
    // this will be invoked when an authorized transmitter is sighted for the first time
    NSLog(@"I arrived at a Gimbal Beacon!!! %@", visit.transmitter.name);
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"We have arrived at beacon named %@", visit.transmitter.name] message:@"wheee!" delegate:nil cancelButtonTitle:@"done" otherButtonTitles:nil, nil];
    [alert show];
    
    
    // Start workout.
    [self.recordManager startRecordingWithUpdateCallback:^(NSDictionary *objects) {
        
    } onSuccess:^{
        
    } onFail:^(NSError *error) {
        
    }];
}

- (void)receivedSighting:(FYXVisit *)visit updateTime:(NSDate *)updateTime RSSI:(NSNumber *)RSSI;
{
    // this will be invoked when an authorized transmitter is sighted during an on-going visit
    NSLog(@"I received a sighting!!! %@", visit.transmitter.name);
    [self.sightedLabel setText:[NSString stringWithFormat:@"Beacon sighted: %@ RSSI: %f", visit.transmitter.name,[RSSI floatValue]]];
}

- (void)didDepart:(FYXVisit *)visit;
{
    // this will be invoked when an authorized transmitter has not been sighted for some time
    NSLog(@"I left the proximity of a Gimbal Beacon!!!! %@", visit.transmitter.name);
    NSLog(@"I was around the beacon for %f seconds", visit.dwellTime);
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"We have left beacon named %@ after %f seconds", visit.transmitter.name,visit.dwellTime] message:@"wheee!" delegate:nil cancelButtonTitle:@"done" otherButtonTitles:nil, nil];
    [alert show];
    [self.sightedLabel setText:@"No beacons around"];
    
    // Stop workout.
    [self.recordManager stopRecording:^{
        
    } onFail:^(NSError *error) {
        
    }];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

@end
