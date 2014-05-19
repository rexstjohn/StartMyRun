//
// Created by MiKey on 12/6/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

typedef void (^MMDKDidFailWithErrorBlock)(NSError *error);

typedef void (^MMDKDidSucceedWithSuccessBlock)();

typedef void (^MMDKDidLoadObjectsBlock)(NSDictionary *objects);

typedef void (^MMDKDidLoadObjectBlock)(id object);

typedef int (^MMDKDidFindRoute)(void);

@interface MMDKCommons : NSObject
@end