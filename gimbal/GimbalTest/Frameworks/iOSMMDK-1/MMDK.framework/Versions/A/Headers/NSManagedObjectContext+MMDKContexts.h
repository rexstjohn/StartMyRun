//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface NSManagedObjectContext (MMDKContexts)

- (id)insertNewObjectForEntityForName:(NSString *)entityName;

- (BOOL)saveToStore:(NSError **)error;
@end