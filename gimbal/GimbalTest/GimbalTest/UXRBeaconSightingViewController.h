//
//  UXRViewController.h
//  GimbalTest
//
//  Created by Rex St. John on 4/16/14.
//  Copyright (c) 2014 UX-RX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FYX/FYXVisitManager.h>

@interface UXRBeaconSightingViewController : UIViewController <FYXVisitDelegate>
@property (nonatomic) FYXVisitManager *visitManager;
@property(nonatomic,strong) IBOutlet UILabel *sightedLabel;

@end
