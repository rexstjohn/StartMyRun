//
//  ESTBeacon.h
//  EstimoteSDK
//
//  Version : 1.4.0
//  Created by Marcin Klimek on 9/19/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"
#import "ESTBeaconAllContentVO.h"

@class ESTBeacon;

////////////////////////////////////////////////////////////////////
// Estimote beacon delegate protocol


/**
 
 ESTBeaconDelegate defines beacon connection delegate mathods. Connection is asynchronous operation so you need to be prepared that eg. beaconDidDisconnectWith: method can be invoked without previous action.
 
 */

@protocol ESTBeaconDelegate <NSObject>

@optional

/**
 * Delegate method that indicates error in beacon authorization.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconAuthorizationDidFail:(ESTBeacon*)beacon withError:(NSError*)error;

/**
 * Delegate method that indicates success in beacon authorization.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconAuthorizationDidSucceeded:(ESTBeacon*)beacon;

/**
 * Delegate method that indicates error in beacon connection.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconConnectionDidFail:(ESTBeacon*)beacon withError:(NSError*)error;

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconConnectionDidSucceeded:(ESTBeacon*)beacon;

/**
 * Delegate method that beacon did disconnect with device.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beacon:(ESTBeacon*)beacon didDisconnectWithError:(NSError*)error;

@end


////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 The ESTBeacon class represents a beacon that was encountered during region monitoring. You do not create instances of this class directly. The ESTBeaconManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
 
 
ESTBeacon class contains basic Apple CLBeacon object reference as well as some additional functionality. It allows to  connect with Estimote beacon to read / write its characteristics.
 
 */

@interface ESTBeacon : NSObject

@property (readonly, nonatomic) ESTBeaconFirmwareState  firmwareState;
@property (nonatomic, weak)     id <ESTBeaconDelegate>  delegate;

/////////////////////////////////////////////////////
// bluetooth beacon available when used with
// startEstimoteBeaconsDiscoveryForRegion:


/// @name Publicly available properties

/**
 *  macAddress
 *
 *  Discussion:
 *    Hardware MAC address of the beacon.
 */
@property (readonly, nonatomic)   NSString*               macAddress;

/**
 *  proximityUUID
 *
 *    Proximity identifier associated with the beacon.
 *
 */
@property (readonly, nonatomic)   NSUUID*                 proximityUUID;

/**
 *  major
 *
 *    Most significant value associated with the region. If a major value wasn't specified, this will be nil.
 *
 */
@property (readonly, nonatomic)   NSNumber*               major;

/**
 *  minor
 *
 *    Least significant value associated with the region. If a minor value wasn't specified, this will be nil.
 *
 */
@property (readonly, nonatomic)   NSNumber*               minor;



/**
 *  rssi
 *
 *    Received signal strength in decibels of the specified beacon.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (readonly, nonatomic)   NSInteger               rssi;

/**
 *  distance
 *
 *    Distance between phone and beacon calculated based on rssi and measured power.
 *
 */
@property (readonly, nonatomic)   NSNumber*               distance;

/**
 *  proximity
 *
 *    The value in this property gives a general sense of the relative distance to the beacon. Use it to quickly identify beacons that are nearer to the user rather than farther away.
 */
@property (readonly, nonatomic)   CLProximity             proximity;

/**
 *  measuredPower
 *
 *    rssi value measured from 1m. This value is used for device calibration.
 */
@property (readonly, nonatomic)   NSNumber*               measuredPower;

/**
 *  hardwareVersion
 *
 *    Reference of the device peripheral object.
 */
@property (readonly, nonatomic)   CBPeripheral*           peripheral;

/////////////////////////////////////////////////////
// properties filled when read characteristic

/// @name Properties available after connection


/**
 *  firmwareUpdateInfo
 *
 *    Flag indicating connection status.
 */
@property (readonly, nonatomic)   BOOL                    isConnected;

/**
 *  power
 *
 *    Power of signal in dBm. Value available after connection with the beacon. It takes one of the values represented by ESTBeaconPower .
 */
@property (readonly, nonatomic)   NSNumber*               power;

/**
 *  advInterval
 *
 *    Advertising interval of the beacon. Value change from 50ms to 2000ms. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSNumber*               advInterval;

/**
 *  batteryLevel
 *
 *    Battery strength in %. Battery level change from 100% - 0%. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSNumber*               batteryLevel;


/**
 *  hardwareVersion
 *
 *    Version of device hardware. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSString*               hardwareVersion;

/**
 *  firmwareVersion
 *
 *    Version of device firmware. Value available after connection with the beacon
 */
@property (readonly, nonatomic)   NSString*               firmwareVersion;


/**
 *  firmwareUpdateInfo
 *
 *    Firmware update availability status. Value available after connection with the beacon and firmware version check.
 */
@property (readonly, nonatomic)  ESTBeaconFirmwareUpdate firmwareUpdateInfo;


/// @name Cloud related properties

/**
 *  name
 *
 *    Name of the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   NSString*     name;

/**
 *  color
 *
 *    Color of the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   ESTBeaconColor          color;

/**
 *  content
 *
 *    Content assigned to the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   ESTBeaconAllContentVO*  content;

/**
 *  content
 *
 *    Content assigned to the beacon. Filled with value after successful cloud request.
 */
@property (readonly, nonatomic)   BOOL  isAuthorized;


/// @name Connection handling methods
#pragma mark - Connection handling methods

/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * Major, Minor, Power and Advertising interval.
 *
 * @return void
 */
-(void)connectToBeacon;

/**
 * Disconnect device with particular beacon
 *
 * @return void
 */
-(void)disconnectBeacon;

/// @name Methods for writing beacon configuration
#pragma mark - Methods for writing beacon configuration

/**
 * Sets Name to the bluetooth connected beacon.
 *
 * @param name new name of the beacon
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconName:(NSString*)name withCompletion:(ESTStringCompletionBlock)completion;

/**
 * Writes Proximity UUID param to bluetooth connected beacon.
 *
 * @param pUUID new Proximity UUID value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconProximityUUID:(NSString*)pUUID withCompletion:(ESTStringCompletionBlock)completion;

/**
 * Writes major param to bluetooth connected beacon.
 *
 * @param major major beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMajor:(unsigned short)major withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMinor:(unsigned short)minor withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes advertising interval (in milisec) of connected beacon.
 *
 * @param advertising interval of beacon (50 - 2000 ms)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconAdvInterval:(unsigned short)interval withCompletion:(ESTUnsignedShortCompletionBlock)completion;


/**
 * Writes power of bluetooth connected beacon.
 *
 * @param power advertising beacon power
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconPower:(ESTBeaconPower)power withCompletion:(ESTPowerCompletionBlock)completion;


/**
 * Resets beacon to factory settings. It changes Major, Minor, UUID, 
 * Power and Adv Inteval to original values.
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)resetToFactorySettingsWithCompletion:(ESTCompletionBlock)completion;


/// @name Firmware update handling methods
#pragma mark - Firmware update handling methods



/**
 * Verifies if new firmware version is available for download
 * without any additional action. Internet connection
 * is required to pass this process.
 *
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)checkFirmwareUpdateWithCompletion:(ESTFirmwareUpdateCompletionBlock)completion;

/**
 * Verifies if new firmware version is available for download
 * and updates firmware of connected beacon. Internet connection 
 * is required to pass this process.
 *
 * @param progress Block handling operation progress
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)updateBeaconFirmwareWithProgress:(ESTProgressBlock)progress
                          andCompletion:(ESTCompletionBlock)completion;


/// @name Estimote Cloud integration
#pragma mark - Estimote Cloud integration

/**
 * Allows to get content for current beacon zone.
 * Method works only after successful authentication.
 *
 * @return void
 */
-(ESTBeaconContentVO*)getContentForCurrentZone;

/**
 * Allows to get content for the beacon.
 * Method works only after successful authentication.
 *
 * @return void
 */
-(void)getContentForBeaconWithCompletion:(ESTContentCompletionBlock)completion;

/// @name utility methods
#pragma mark - utility methods

/**
 * Allows comparison between two ESTBeacon objects
 *
 * @return YES or NO
 */
- (BOOL)isEqualToBeacon:(ESTBeacon *)beacon;

@end
