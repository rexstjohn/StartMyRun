//
//  ESTBeaconContentVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 10/4/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconBaseVO.h"


@interface ESTBeaconContentVO : ESTBeaconBaseVO

@property (nonatomic, strong) NSString*         title;
@property (nonatomic, strong) NSString*         subtitle;
@property (nonatomic, strong) NSString*         image;
@property (nonatomic, strong) NSString*         sticker;

@end
