//
// Created by MiKey on 12/6/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SyncManagerContext.h"
#import "MMDKCommons.h"


@interface MMDKSyncHandler : NSObject
- (id)init;
- (void)handleContext:(SyncManagerContext *)context
		  withSuccess:(MMDKDidLoadObjectBlock) success
		withFailure:(MMDKDidFailWithErrorBlock)failure;

- (NSArray *)getPendingSaveData;
@end