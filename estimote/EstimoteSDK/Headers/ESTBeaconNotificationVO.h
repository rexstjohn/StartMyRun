//
//  ESTBeaconNotificationVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 13/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconBaseVO.h"

@interface ESTBeaconNotificationVO : ESTBeaconBaseVO

@property (nonatomic, strong)   NSString*           text;
@property (nonatomic, strong)   NSNumber*           enabled;

@end
