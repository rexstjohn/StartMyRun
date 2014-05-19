//
// Created by MiKey on 11/24/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKUserInfo.h"

@interface MMDKUserMapper : NSObject
+ (MMDKUserInfo *)objectFromDictionary:(NSDictionary *)userDictionary;

+ (NSDictionary *)dictionaryFromObject:(MMDKUserInfo *)userInfo;

@end