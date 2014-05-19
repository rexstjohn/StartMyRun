//
// Created by MiKey on 11/24/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKObjectMapper.h"

@class MMDKRoute;


@interface MMDKRouteMapper : MMDKObjectMapper

+ (NSEntityDescription *)buildEntityFromClass:(NSString *)entityName;

+ (MMDKRoute *)mmdkRouteFromJsonDictionary:(NSDictionary *)dict;

+ (NSDictionary *)dictionaryFromRoute:(MMDKRoute *)route;
@end