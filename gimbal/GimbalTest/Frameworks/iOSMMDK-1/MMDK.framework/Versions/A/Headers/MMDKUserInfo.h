//
//  MMDKUserInfo.h
//  MMDK
//
//  Created by Ryan P. Trunck on 2/11/13.
//  Copyright (c) 2013 MapMyFitness, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
	MALE,
	FEMALE
} Gender;

/**
 MMDKUserInfo contains the user's information and details.
 The system is based on SI units
 */
@interface MMDKUserInfo : NSObject

/**
 The user's first name
 */
@property(nonatomic, copy) NSString *firstName;

/**
 The user's last name
 */
@property(nonatomic, copy) NSString *lastName;

/**
 The user's original username. In case the username property
 was not changed, then this value will be the same as the username.
 The value is used to know if the username was changed meanwhile.
 */
@property NSString *originalUsername;

/**
 The user's username
 */
@property(nonatomic, copy) NSString *username;

/**
 The user's password
 */
@property(nonatomic, copy) NSString *password;

/**
 The user's original email. In case the email property
 was not changed, then this value will be the same as the email.
 The value is used to know if the email was changed meanwhile.
 */
@property NSString *originalEmail;

/**
 The user's email
 */
@property(nonatomic, copy) NSString *email;

/**
 The user's birthdate
 */
@property(nonatomic, strong) NSDate *birthdate;

/**
 The user's gender
 */
@property(nonatomic, assign) Gender gender;

/**
 The user's height in the user's units
 */
@property(nonatomic, assign) double height;

/**
 The user's weight in the user's units
 */
@property(nonatomic, assign) double weight;

/**
 The user's total distance in meters for a metric user or miles for a imperial one.
 */
@property(nonatomic, assign) double totalDistance;

/**
 The user's total time logged in seconds
 */
@property(nonatomic, assign) double totalTime;

/**
 The user's ID
 */
@property(nonatomic, strong) NSNumber *userID;

/**
 If the user uses metric
 */
@property(assign) BOOL isMetric;

/**
 * Indicates if the username was changed since the object was retrieved.
 */
- (bool)usernameChanged;

/**
 * Indicates if the email was changed since the object was retrieved.
 */
- (bool)emailChanged;

@end
