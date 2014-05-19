//
// Created by MiKey on 11/4/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class AFOAuth1Client;
@class MMDKWorkoutMapper;


@interface MMDKManagedObjectStore : NSObject

@property(nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property(nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property(nonatomic, strong, readonly) NSManagedObjectContext *privateConcurrentMOC;
@property(nonatomic, strong, readonly) NSManagedObjectContext *mainQueueMOC;

+ (instancetype)defaultStore;

+ (void)setDefaultStore:(MMDKManagedObjectStore *)managedObjectStore;

- (id)init;

- (id)initWithManagedObjectModel:(NSManagedObjectModel *)managedObjectModel;

- (void)createPersistentStoreCoordinator;

- (NSPersistentStore *)addSQLitePersistentStoreAtPath:(NSString *)storePath
							   fromSeedDatabaseAtPath:(NSString *)seedPath
									withConfiguration:(NSString *)nilOrConfigurationName
											  options:(NSDictionary *)nilOrOptions
												error:(NSError **)error;


- (void)createManagedObjectContexts;

//- (void)createRKObjectStoreWithClient:(AFOAuth1Client *)client;
//
//- (void)buildEntityMapping;
@end