//
// Created by MiKey on 12/5/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SyncManagerContext.h"

#define kNewWorkoutAdded @"kNewWorkoutAdded"
#define kWorkoutSyncInProgress @"kWorkoutSyncInProgress"
#define kWorkoutSyncSucceeded @"kWorkoutSyncSucceeded"
#define kWorkoutSyncFailed @"kWorkoutSyncFailed"
#define kSaveManagerFinished @"kSaveManagerFinished"
#define kAppHasFinishedBackgroundTasks @"kAppHasFinishedBackgroundTasks"

@interface MMDKSyncManager : NSObject

+ (MMDKSyncManager *)sharedInstance;

- (void)startSaveService;
- (void)resumeSaveService;
- (void)pauseSaveService;

- (void)forceStart;
- (void)addToQueue:(SyncManagerContext *)syncContext;
- (void)save;

- (BOOL)isActive;
- (BOOL)isSaving;
- (int)numberOfItemsInQueue;
- (void)flushQueue;

- (void)prioritize:(SyncManagerContext *)workout;

@end