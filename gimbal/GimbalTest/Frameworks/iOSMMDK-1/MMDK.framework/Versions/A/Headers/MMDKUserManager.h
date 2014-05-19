//
//  MMDKUserManager.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/11/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMDKOAuthSession.h"
#import "MMDKUserInfo.h"
#import <UIKit/UIKit.h>
/**
 The MMDKUserManager provides access to the user's data, and the ability to update the user's data
 */
@interface MMDKUserManager : NSObject



+ (id)initializeWithSession:(MMDKOAuthSession *)session;

/**
 Method to obtain user's data
 @param success is the block called with the MMDKUserInfo object
 @param fail is the block called upon the failure to obtain the user object
 */
- (void)getUserInfo:(MMDKDidLoadObjectBlock)success
			 onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to obtain the user's avatar
 @param userID is the userID to retrieve the avatar for
 @param success is the block called on the successful retrieval of the avatar. This block will return the UIImage of the user
 @param fail is the block called on the failure to retrieve they user's avatar. This block will return a NSError received.
 */
- (void)getUserAvatarForUserID:(NSString *)userID
					 onSuccess:(MMDKDidLoadObjectBlock)success
						onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to upload an avatar for a user. This method auto-reduces the size of the passed UIImage to under 1 mb and uploads the image as a JPEG.
 @param image is the UIImage to upload for the user
 @param userID is the userID of the user for uploading the UIImage as the avatar
 @param success is the block called on successful uploading of the user's avatar. This block returns the response object from the server.
 @param fail is the block called on failure to upload the user's avatar. This block will return a NSError received.
 */
- (void)updateUserAvatarWithImage:(UIImage *)image
						forUserID:(NSString *)userID
						onSuccess:(MMDKDidLoadObjectBlock)success
						   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to update the user's data
 @param userInfo is the MMDKUSerInfo object to update on the MapMyFitness server
 @param success is the block called upon successful update of the user's info
 @param fail is the block called on failure to update the user's info
 */
- (void)updateUserInfo:(MMDKUserInfo *)userInfo
			 onSuccess:(MMDKDidSucceedWithSuccessBlock)success
				onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Method to create a user
 @param user is the MMDKUserInfo object passed to create the object
 @param success is the block called on successful creation of the user, passing the user object with the new userID
 @param fail is the block called on failure to create the user
 */

- (void)createUserWithMMDKUserInfo:(MMDKUserInfo *)user
						 onSuccess:(MMDKDidLoadObjectBlock)success
							onFail:(MMDKDidFailWithErrorBlock)fail;

@end
