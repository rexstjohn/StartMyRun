//
//  UXRGeoFenceIncursionViewController.m
//  GimbalTest
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 Mashery. All rights reserved.
//

#import <ContextLocation/QLPlaceEvent.h>
#import <ContextLocation/QLPlace.h>
#import "UXRGeoFenceIncursionViewController.h"

@interface UXRGeoFenceIncursionViewController ()

@end

@implementation UXRGeoFenceIncursionViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // Geofence detector
    self.placeConnector = [[QLContextPlaceConnector alloc] init];
    self.placeConnector.delegate = self;
}


#pragma place detector

- (void)didGetPlaceEvent:(QLPlaceEvent *)placeEvent
{
    NSLog(@"did get place event %@", [placeEvent place].name);
    [self.fenceLabel setText:[NSString stringWithFormat:@"%@ detected", [placeEvent place].name]];
    
}

@end
