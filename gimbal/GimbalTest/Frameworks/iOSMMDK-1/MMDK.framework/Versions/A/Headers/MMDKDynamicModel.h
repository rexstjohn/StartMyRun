//
// Created by MiKey on 11/11/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "MMDKManagedObjectStore.h"

@protocol MMDKManagedObjectMap <NSObject>
- (NSEntityDescription *)mapEntity;
@end

@interface MMDKDynamicModel : NSObject
- (void)registerObjectMap:(id <MMDKManagedObjectMap>)entityMap;

- (NSManagedObjectModel *)generateModel;
@end