//
//  ESTBeaconBaseVO.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 17/12/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ESTContentType)
{
    ESTContentTypeExit,
    ESTContentTypeEnter,
    ESTContentTypeImmediate,
    ESTContentTypeNear,
    ESTContentTypeFar
};

@interface ESTBeaconBaseVO : NSObject

@end
