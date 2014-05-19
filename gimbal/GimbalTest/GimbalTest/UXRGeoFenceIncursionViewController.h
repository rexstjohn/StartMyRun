//
//  UXRGeoFenceIncursionViewController.h
//  GimbalTest
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 UX-RX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ContextLocation/QLContextPlaceConnector.h>

@interface UXRGeoFenceIncursionViewController : UIViewController <QLContextPlaceConnectorDelegate>
@property (nonatomic) QLContextPlaceConnector *placeConnector;

@property(nonatomic,strong) IBOutlet UILabel *fenceLabel;

@end
