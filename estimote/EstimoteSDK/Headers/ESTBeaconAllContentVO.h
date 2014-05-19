//
//  ESTBeaconAllContentVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 13/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconContentVO.h"
#import "ESTBeaconNotificationVO.h"

@interface ESTBeaconAllContentVO : NSObject

// proximity zones content
@property (nonatomic, strong) ESTBeaconContentVO*       immediateContent;
@property (nonatomic, strong) ESTBeaconContentVO*       nearContent;
@property (nonatomic, strong) ESTBeaconContentVO*       farContent;

// enter event notification and content
@property (nonatomic, strong) ESTBeaconNotificationVO*  enterNote;
@property (nonatomic, strong) ESTBeaconContentVO*       enterContent;

// exit event notification and content
@property (nonatomic, strong) ESTBeaconNotificationVO*  exitNote;
@property (nonatomic, strong) ESTBeaconContentVO*       exitContent;




@end
