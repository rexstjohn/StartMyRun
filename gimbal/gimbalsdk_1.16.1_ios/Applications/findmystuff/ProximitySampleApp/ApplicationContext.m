/**
 * Copyright (C) 2013 Qualcomm Retail Solutions, Inc. All rights reserved.
 *
 * This software is the confidential and proprietary information of Qualcomm
 * Retail Solutions, Inc.
 *
 * The following sample code illustrates various aspects of the FYX iOS SDK.
 *
 * The sample code herein is provided for your convenience, and has not been
 * tested or designed to work on any particular system configuration. It is
 * provided pursuant to the License Agreement for FYX Software and Developer
 * Portal AS IS, and your use of this sample code, whether as provided or with
 * any modification, is at your own risk. Neither Qualcomm Retail Solutions,
 * Inc. nor any affiliate takes any liability nor responsibility with respect
 * to the sample code, and disclaims all warranties, express and implied,
 * including without limitation warranties on merchantability, fitness for a
 * specified purpose, and against infringement.
 */
#import "ApplicationContext.h"
#import <FYX/FYXLogging.h>


@implementation ApplicationContext

static ApplicationContext *sharedInstance = nil;

+ (ApplicationContext *)sharedInstance {
    if (sharedInstance == nil) {
        sharedInstance = [[super allocWithZone:NULL] init];
        sharedInstance.userSettingRepository = [[UserSettingsRepository alloc] init];
    }

    return sharedInstance;
}

- (id)copyWithZone:(NSZone *)zone {
    return self;
}

- (void) initializeFyxService {
    //Replace with your own Application-ID and Application-Secret to see your
    //activated beacons
    [FYX setAppId:@"dcb127099ef4492467dd66d83bede1850c1edf65e8bb89d3c9e2d2deebca7569"
         appSecret:@"a8261e45490b46b9a803e86901ef1c6cf87d9cc56dad9e3e261c65e18cb668c2"
         callbackUrl:@"your-callback-url"];
    [FYXLogging setLogLevel:FYX_LOG_LEVEL_INFO];
}

@end