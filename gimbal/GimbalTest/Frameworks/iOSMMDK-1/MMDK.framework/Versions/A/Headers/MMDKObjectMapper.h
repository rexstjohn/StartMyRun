//
// Created by MiKey on 11/12/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <objc/runtime.h>

@interface MMDKObjectMapper : NSObject
@property(nonatomic, strong) NSString *objectName;

+ (const char *)getPropertyType:(objc_property_t *)property;

+ (NSDictionary *)getObjectPropertiesForClass:(Class)clazz;

+ (NSAttributeType)getAttributeType:(NSString *)stringType;

+ (NSEntityDescription *)buildEntityFromClass:(NSString *)entityName;
@end