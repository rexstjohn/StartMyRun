//
// Created by MiKey on 11/1/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "lcl_MMDK.h"

/**
* MMDK logging servicese are based on LibComponentLogging. LCL is configured as an embedded component to avoid clashing
* with any application that may also choose to use LCL. If you wish to use the MMDK logger in your application as is,
* see the supporting LCL configurtation files.
*
* @see lcl_config_components_MMDK.h
* @see lcl_config_logger_MMDK.h
*/

/**
* This defines the logging component to use. By default this sets the entire library to log using the base MMDK log
* component. All other components defined are nested below this level, so this essentially sets the log level across
* all components.
*
* The log component can be redefined based on what component may we may be logging to. The component is defined by LCL
* through a data structure prefixed like: MMDKlcl_c<Component>.
*
* The macros definined herein will log to the active component, which may be redefined by that particular component.
* For example:
*
* 		#undef MMDKLogComponent
* 		#define MMDKLogComponent MMDKlcl_MMDKManager
*
*   	MMDKLogInfo(@"Hello Chalupa Batman")
*
* Would log something like:
*
*       I MMDK.Manager:MMDKLog.h:20 Hello Chalupa Batman
*
*/
#define MMDKLogComponent MMDKlcl_cMMDK

@interface MMDKLog : NSObject
#define MMDKLogCritical(...)                                                              \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vCritical, @"" __VA_ARGS__)

#define MMDKLogError(...)                                                                 \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vError, @"" __VA_ARGS__)

#define MMDKLogWarning(...)                                                               \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vWarning, @"" __VA_ARGS__)

#define MMDKLogInfo(...)                                                                  \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vInfo, @"" __VA_ARGS__)

#define MMDKLogDebug(...)                                                                 \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vDebug, @"" __VA_ARGS__)

#define MMDKLogTrace(...)                                                                 \
MMDKlcl_log(MMDKLogComponent, MMDKlcl_vTrace, @"" __VA_ARGS__)

/**
* These levels simply map to LCL log levels but provide a more user friendly format
*/
typedef enum {
	mmOFF = 0,
	mmCRITICAL,              // critical situation
	mmERROR,                 // error situation
	mmWARNING,               // warning
	mmINFO,                  // informational message
	mmDEBUG,                 // coarse-grained debugging information
	mmTRACE                  // fine-grained debugging information
} MMDKLogLevel;

/**
*  Sets the default log level for the MMDK. You can override this setting by configuring a macro for MMDKDefaultLogLevel
*  and setting it to a specific MMDKLogLevel.
*/
#ifndef MMDKDefaultLogLevel
#ifdef DEBUG
#define MMDKDefaultLogLevel mmDEBUG
#else
        #define MMDKDefaultLogLevel mmWARNING
	#endif
#endif

@end