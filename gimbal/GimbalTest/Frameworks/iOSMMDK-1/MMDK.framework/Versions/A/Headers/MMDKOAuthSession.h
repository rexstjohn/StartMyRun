//
//  MMDKOAuthSession.h
//  MMDK
//
//  Created by MiKey on 10/29/13.
//  Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKManagedObjectStore.h"
#import "MMDKSyncManager.h"
#import "AFOAuth1Client.h"
#import "AFXAuthClient.h"

@interface MMDKOAuthSession : NSObject

@property(nonatomic, assign) BOOL xAuth;
@property(nonatomic, assign) BOOL loggedIn;
@property(nonatomic, assign) BOOL mockData;
@property(nonatomic, strong) MMDKManagedObjectStore *mmdkManagedObjectStore;
@property(nonatomic, strong) MMDKSyncManager *syncManager;

+ (MMDKOAuthSession *)instance;

+ (MMDKOAuthSession *)initializeWithConsumer:(NSString *)consumerKey secret:(NSString *)secret xAuth:(BOOL)xAuth;

- (AFHTTPClient *)getHttpClient;

+ (BOOL)isMetric;

- (void)loginUserWithCallbackUrl:(NSString *)callbackURL
						 success:(MMDKDidLoadObjectBlock)success
						  onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)setUserToken:(NSString *)token secret:(NSString *)secret success:(MMDKDidLoadObjectBlock)success onFail:(MMDKDidFailWithErrorBlock)fail;

- (NSError *)setUserToken:(NSString *)token secret:(NSString *) secret;

- (void)xAuthWithUsername:(NSString *)username
				 password:(NSString *)password
				onSuccess:(MMDKDidLoadObjectBlock)success
				   onFail:(MMDKDidFailWithErrorBlock)fail;

- (void)logoutUser;

@end
