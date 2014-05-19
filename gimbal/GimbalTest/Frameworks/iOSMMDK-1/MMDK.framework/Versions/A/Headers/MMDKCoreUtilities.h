//
// Created by MiKey on 11/23/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface MMDKCoreUtilities : NSObject

void ExcludeItemFromBackupAtPath(NSString *path);

BOOL MMDKValidateDirectoryAtPath(NSString *path, NSError **error);

NSString *MMDKDataDirectory(void);
@end