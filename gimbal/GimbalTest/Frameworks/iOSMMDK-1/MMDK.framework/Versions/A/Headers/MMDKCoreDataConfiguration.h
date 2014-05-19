//
// Created by MiKey on 11/28/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

@class MMDKManagedObjectStore;


@interface MMDKCoreDataConfiguration : NSObject

@property(nonatomic, strong) NSString *persistentStorePath;
@property(nonatomic, strong) NSString *persistentStoreName;
@property(nonatomic, strong, readonly) NSArray *entityDescriptions;

- (MMDKManagedObjectStore *)configureWithDefaults;

- (MMDKManagedObjectStore *)configureWithEntityList:(NSArray *)entities;

@end