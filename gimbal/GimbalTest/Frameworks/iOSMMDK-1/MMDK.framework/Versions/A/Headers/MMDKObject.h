//
// Created by MiKey on 11/24/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface MMDKObject : NSObject

typedef enum {
	PRIVATE = 0,
	FRIENDS_ONLY = 1,
	PUBLIC = 3
} PrivacyType;

@end