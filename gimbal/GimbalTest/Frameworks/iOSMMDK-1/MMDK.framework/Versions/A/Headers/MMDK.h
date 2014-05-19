//
//  MMDK.h
//  MMDK
//
//  Created by Ryan P. Trunck on 12/13/12.
//  Copyright (c) 2012 MapMyFitness, Inc. All rights reserved.
//

/**
 * Import this class to activate the use of the MMDK in your application. This
 * header is required in order to access all public API's provided.
 */


@class AFOAuth1Client;


#import <CoreGraphics/CoreGraphics.h>
#import <CoreData/CoreData.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import "MMDKLog.h"

#import "MMDKUserManager.h"
#import "MMDKRouteManager.h"
#import "MMDKWorkoutManager.h"
#import "MMDKRecordManager.h"
#import "MMDKCommons.h"

#define kAFApplicationLaunchedWithURLNotification @"kAFApplicationLaunchedWithURLNotification"
#define kAFApplicationLaunchOptionsURLKey @"UIApplicationLaunchOptionsURLKey"

/**
* Defines the privacy level of a given workout.
* TODO: Define defaults and meaning
*/


@interface MMDK : NSObject

/**
 MMDK should be used *after* the mmdk has been initialized with the consumer key and secret.
 If it hasn't been initialized, this will return a nil object.
 */
+ (MMDK *)mmdk;

/**
 Initialization of the Mmdk library.  The end developer will not be able to do much until
 the mmdkWithConsumerKey is called to go through the OAuth experience OR the end users OAuth
 credentials are passed in via setUserToken.

 Note: This initializer will toggle logging based on the preprocessor directive DEBUG. Default log levels
 for DEBUG set to ON will be mmDEBUG. For DEBUG off logging will be set to mmWARNING.

 @param appConsumer is your application consumer key obtained from the MapMyFitness developer portal
 @param appSecret is the application secret obtained from the MapMyFitness developer portal
 */
+ (MMDK *)initializeWithApplicationConsumer:(NSString *)appConsumer
						  applicationSecret:(NSString *)appSecret;

/**
 * Initialize the MMDK with given consumer key and secret, explicitly sets logging level to the provided duration
 * of the MMDK instance.
 *
 * @param appConsumer is your application consumer key obtained from the MapMyFitness developer portal
 * @param appSecret is the application secret obtained from the MapMyFitness developer portal
 * @param mmdkLogLevel is one of the provided log levels in MMDKLogLevel
*/
+ (MMDK *)initializeWithApplicationConsumer:(NSString *)appConsumer applicationSecret:(NSString *)appSecret mmdkLogLevel:(MMDKLogLevel)mmdkLogLevel;

/**
 An extention of the base initialize interface adding the ability to set to use xAuth
 @param appConsumer is the consumer token of the OAuth credentials
 @param appSecret is the secret for OAuth credentials
 @param xAuth is the BOOL to set for xAuth
 */
+ (MMDK *)initializeWithApplicationConsumer:(NSString *)appConsumer
						  applicationSecret:(NSString *)appSecret
									  xAuth:(BOOL)xAuth;

/**
 Initialize the app with the the Oauth credentials. This is the standard login and authentication call
 MMF uses Oauth and requests should be signed with the proper items.
 @param callbackURL is the URL scheme your application registers for
 @param success is the block called on successful authentication
 @param fail is the block called on failure to authenticate
 */
- (void)loginUserWithCallbackUrl:(NSString *)callbackURL
						 success:(MMDKDidLoadObjectBlock)success
						  onFail:(MMDKDidFailWithErrorBlock)fail;


/**
 Method to use xAuth. To use xAuth you must be approved seperately.
 @param username is the username of the user. You can also use email address to log in
 @param password is the password of the user
 @param success is the block called upon successful authentication of the user
 @param fail is the block called on failure to authenticate
 */
- (void)xAuthWithUsername:(NSString *)username
				 password:(NSString *)password
				onSuccess:(MMDKDidLoadObjectBlock)success
				   onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 * Method that allows the developer to pass the end users token and secret key rather
 * than using the manual loginUser() process.  If any user is logged in (including the
 * one whose token and secret keys are passed in to) when this method is called,
 * logoutUser will be called on that user.  If initialize() has not been called this method
 * will return false and the userToken and userSecret will not be saved.
 * @param userToken the end users token
 * @param userSecret the end users secret key.
 * @param success is the block called on successful authentication
 * @param fail is the block called on failure to authenticate
 */
- (void)setUserToken:(NSString *)userToken
			  secret:(NSString *)userSecret
			 success:(MMDKDidLoadObjectBlock)success
			  onFail:(MMDKDidFailWithErrorBlock)fail;

/**
 Retrive a user manage.
 @param loadBlock The block to invoke if the call successfully loads an instance of MMDKProfile.
 @param failBlock The block to invoke if there is an issue with the request.
 */
- (MMDKUserManager *)getUserManager;

/**
 Retrive a route manager.
 @param loadBlock The block to invoke if the call successfully loads an instance of MMDKRouteManager.
 @param failBlock The block to invoke if there is an issue with the request.
 */
- (MMDKRouteManager *)getRouteManager;

/**
 Retrive a record manager.
 @param loadBlock The block to invoke if the call successfully loads an instance of MMDKRecordManager.
 @param failBlock The block to invoke if there is an issue with the request.
 */
- (MMDKRecordManager *)getRecordManager;

/**
 Retrive a workout manager.
 @param loadBlock The block to invoke if the call successfully loads an instance of MMDKRouteManager.
 @param failBlock The block to invoke if there is an issue with the request.
 */
- (MMDKWorkoutManager *)getWorkoutManager;

/**
 The mmfClient is an AFOAuth1Client that is used for any requests; especially ones not provided by this SDK.
 For more information on how to use this client, see AFOAuth1Client.h and/or AFNetworking.h
 */
@property(nonatomic, strong) AFOAuth1Client *mmfClient DEPRECATED_ATTRIBUTE;


/**
 Set GPS to mock, defaults to NO
/ */
@property(nonatomic, assign) BOOL mockGPS;

/**
 Set Data requests to mock, defaults to NO
 */
@property(nonatomic, assign) BOOL mockData;

/**
 Property to determine if xAuth is used. The use of xAuth must seperately and specifically be approved.
 */
@property(readonly) BOOL xAuth;

/**
 Check to see if the user has authenticated
*/
- (BOOL)isUserLoggedIn;

/**
 Alternative to get if a user is metric
 */
+ (BOOL)isMetric;

/**
 Method to log the user out.
 */
- (void)logoutUser;

/**
 Class method to obtain the current version of the MMDK
 */
+ (NSString *)version;
@end

