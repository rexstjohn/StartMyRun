//
//
// lcl_MMDK.h -- LibComponentLogging, embedded, MMDK/MMDK
//
//
// Copyright (c) 2008-2013 Arne Harren <ah@0xc0.de>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef __MMDKLCL_H__
#define __MMDKLCL_H__

#define _MMDKLCL_VERSION_MAJOR  1
#define _MMDKLCL_VERSION_MINOR  3
#define _MMDKLCL_VERSION_BUILD  2
#define _MMDKLCL_VERSION_SUFFIX ""

//
// lcl -- LibComponentLogging, embedded, MMDK/MMDK
//
// LibComponentLogging is a logging library for Objective-C applications
// with the following characteristics:
//
// - Log levels
//   The library provides log levels for distinguishing between error messages,
//   informational messages, and fine-grained trace messages for debugging.
//
// - Log components
//   The library provides log components for identifying different parts of an
//   application. A log component contains a unique identifier, a short name
//   which is used as a header in a log message, and a full name which can be
//   used in a user interface.
//
// - Active log level per log component
//   At runtime, the library provides an active log level for each log
//   component in order to enable/disable logging for certain parts of an
//   application.
//
// - Grouping of log components
//   Log components which have the same name prefix form a group of log
//   components and logging can be enabled/disabled for the whole group with
//   a single command.
//
// - Low runtime-overhead when logging is disabled
//   Logging is based on a log macro which checks the active log level before
//   constructing the log message and before evaluating log message arguments.
//
// - Code completion support
//   The library provides symbols for log components and log levels which work
//   with Xcode's code completion. All symbols, e.g. values or functions, which
//   are relevant when using the logging library in an application, are prefixed
//   with 'MMDKlcl_'. Internal symbols, which are needed when working with meta
//   data, when defining log components, or when writing a logging back-end, are
//   prefixed with '_MMDKlcl_'. Internal symbols, which are only used by the logging
//   library itself, are prefixed with '__MMDKlcl_'.
//
// - Meta data
//   The library provides public data structures which contain information about
//   log levels and log components, e.g. headers and names.
//
// - Pluggable loggers
//   The library does not contain a concrete logger, but provides a simple
//   delegation mechanism for plugging-in a concrete logger based on the
//   application's requirements, e.g. a logger which writes to the system log,
//   or a logger which writes to a log file. The concrete logger is configured
//   at build-time.
//
// Note: If the preprocessor symbol _MMDKLCL_NO_LOGGING is defined, the log macro
// will be defined to an empty effect.
//


#import <Foundation/Foundation.h>


// Use C linkage.
#ifdef __cplusplus
extern "C" {
#endif


//
// Log levels.
//


// Log levels, prefixed with 'MMDKlcl_v'.
enum _MMDKlcl_enum_level_t {
	MMDKlcl_vOff = 0,

	MMDKlcl_vCritical,              // critical situation
	MMDKlcl_vError,                 // error situation
	MMDKlcl_vWarning,               // warning
	MMDKlcl_vInfo,                  // informational message
	MMDKlcl_vDebug,                 // coarse-grained debugging information
	MMDKlcl_vTrace,                 // fine-grained debugging information

	_MMDKlcl_level_t_count,
	_MMDKlcl_level_t_first = 0,
	_MMDKlcl_level_t_last = _MMDKlcl_level_t_count - 1
};

// Log level type.
typedef uint32_t _MMDKlcl_level_t;
typedef uint8_t _MMDKlcl_level_narrow_t;


//
// Log components.
//


// Log components, prefixed with 'MMDKlcl_c'.
enum _MMDKlcl_enum_component_t {
#   define  _MMDKlcl_component(_identifier, _header, _name)                        \
    MMDKlcl_c##_identifier,                                                        \
  __MMDKlcl_log_symbol_MMDKlcl_c##_identifier = MMDKlcl_c##_identifier,

#include "lcl_config_components_MMDK.h"
#   undef   _MMDKlcl_component

	_MMDKlcl_component_t_count,
	_MMDKlcl_component_t_first = 0,
	_MMDKlcl_component_t_last = _MMDKlcl_component_t_count - 1
};

// Log component type.
typedef uint32_t _MMDKlcl_component_t;


//
// Functions and macros.
//

#ifndef _MMDKLCL_NO_IGNORE_WARNINGS
#   ifdef __clang__
// Ignore some warnings about variadic macros when using '-Weverything'.
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wunknown-pragmas"
#   pragma clang diagnostic ignored "-Wvariadic-macros"
#   pragma clang diagnostic ignored "-Wpedantic"
#   endif
#endif

// MMDKlcl_log(<component>, <level>, <format>[, <arg1>[, <arg2>[, ...]]])
//
// <component>: a log component with prefix 'MMDKlcl_c'
// <level>    : a log level with prefix 'MMDKlcl_v'
// <format>   : a format string of type NSString (may include %@)
// <arg..>    : optional arguments required by the format string
//
// Logs a message for the given log component at the given log level if the
// log level is active for the log component.
//
// The actual logging is done by _MMDKlcl_logger which must be defined by a concrete
// logging back-end. _MMDKlcl_logger has the same signature as MMDKlcl_log.
//
#ifdef _MMDKLCL_NO_LOGGING
#   define MMDKlcl_log(_component, _level, _format, ...)                           \
        do {                                                                   \
        } while (0)
#else
#   define MMDKlcl_log(_component, _level, _format, ...)                           \
        do {                                                                   \
            if (((_MMDKlcl_component_level[(__MMDKlcl_log_symbol(_component))]) >=     \
                  (__MMDKlcl_log_symbol(_level)))                                  \
               ) {                                                             \
                    _MMDKlcl_logger(_component,                                    \
                                _level,                                        \
                                _format,                                       \
                                ##__VA_ARGS__);                                \
            }                                                                  \
        } while (0)
#endif

// MMDKlcl_log_if(<component>, <level>, <predicate>, <format>[, <arg1>[, ...]])
//
// <component>: a log component with prefix 'MMDKlcl_c'
// <level>    : a log level with prefix 'MMDKlcl_v'
// <predicate>: a predicate for conditional logging
// <format>   : a format string of type NSString (may include %@)
// <arg..>    : optional arguments required by the format string
//
// Logs a message for the given log component at the given log level if the
// log level is active for the log component and if the predicate evaluates
// to true.
//
// The predicate is only evaluated if the given log level is active.
//
// The actual logging is done by _MMDKlcl_logger which must be defined by a concrete
// logging back-end. _MMDKlcl_logger has the same signature as MMDKlcl_log.
//
#ifdef _MMDKLCL_NO_LOGGING
#   define MMDKlcl_log_if(_component, _level, _predicate, _format, ...)            \
        do {                                                                   \
        } while (0)
#else
#   define MMDKlcl_log_if(_component, _level, _predicate, _format, ...)            \
        do {                                                                   \
            if (((_MMDKlcl_component_level[(__MMDKlcl_log_symbol(_component))]) >=     \
                  (__MMDKlcl_log_symbol(_level)))                                  \
                &&                                                             \
                (_predicate)                                                   \
               ) {                                                             \
                    _MMDKlcl_logger(_component,                                    \
                                _level,                                        \
                                _format,                                       \
                                ##__VA_ARGS__);                                \
            }                                                                  \
        } while (0)
#endif

#ifndef _MMDKLCL_NO_IGNORE_WARNINGS
#   ifdef __clang__
#   pragma clang diagnostic pop
#   endif
#endif

// MMDKlcl_configure_by_component(<component>, <level>)
//
// <component>: a log component with prefix 'MMDKlcl_c'
// <level>    : a log level with prefix 'MMDKlcl_v'
//
// Configures the given log level for the given log component.
// Returns the number of configured log components, or 0 on failure.
//
uint32_t MMDKlcl_configure_by_component(_MMDKlcl_component_t component, _MMDKlcl_level_t level);

// MMDKlcl_configure_by_identifier(<identifier>, <level>)
//
// <identifier>: a log component's identifier with optional '*' wildcard suffix
// <level>     : a log level with prefix 'MMDKlcl_v'
//
// Configures the given log level for the given log component(s).
// Returns the number of configured log components, or 0 on failure.
//
uint32_t MMDKlcl_configure_by_identifier(const char *identifier, _MMDKlcl_level_t level);

// MMDKlcl_configure_by_header(<header>, <level>)
//
// <header>    : a log component's header with optional '*' wildcard suffix
// <level>     : a log level with prefix 'MMDKlcl_v'
//
// Configures the given log level for the given log component(s).
// Returns the number of configured log components, or 0 on failure.
//
uint32_t MMDKlcl_configure_by_header(const char *header, _MMDKlcl_level_t level);

// MMDKlcl_configure_by_name(<name>, <level>)
//
// <name>     : a log component's name with optional '*' wildcard suffix
// <level>    : a log level with prefix 'MMDKlcl_v'
//
// Configures the given log level for the given log component(s).
// Returns the number of configured log components, or 0 on failure.
//
uint32_t MMDKlcl_configure_by_name(const char *name, _MMDKlcl_level_t level);


//
// Internals.
//


// Active log levels, indexed by log component.
extern _MMDKlcl_level_narrow_t _MMDKlcl_component_level[_MMDKlcl_component_t_count];

// Log component identifiers, indexed by log component.
extern const char *const _MMDKlcl_component_identifier[_MMDKlcl_component_t_count];

// Log component headers, indexed by log component.
extern const char *const _MMDKlcl_component_header[_MMDKlcl_component_t_count];

// Log component names, indexed by log component.
extern const char *const _MMDKlcl_component_name[_MMDKlcl_component_t_count];

// Log level headers, indexed by log level.
extern const char *const _MMDKlcl_level_header[_MMDKlcl_level_t_count];   // full header
extern const char *const _MMDKlcl_level_header_1[_MMDKlcl_level_t_count]; // header with 1 character
extern const char *const _MMDKlcl_level_header_3[_MMDKlcl_level_t_count]; // header with 3 characters

// Log level names, indexed by log level.
extern const char *const _MMDKlcl_level_name[_MMDKlcl_level_t_count];

// Version.
extern const char *const _MMDKlcl_version;

// Log level symbols used by MMDKlcl_log, prefixed with '__MMDKlcl_log_symbol_MMDKlcl_v'.
enum {
	__MMDKlcl_log_symbol_MMDKlcl_vCritical = MMDKlcl_vCritical,
	__MMDKlcl_log_symbol_MMDKlcl_vError = MMDKlcl_vError,
	__MMDKlcl_log_symbol_MMDKlcl_vWarning = MMDKlcl_vWarning,
	__MMDKlcl_log_symbol_MMDKlcl_vInfo = MMDKlcl_vInfo,
	__MMDKlcl_log_symbol_MMDKlcl_vDebug = MMDKlcl_vDebug,
	__MMDKlcl_log_symbol_MMDKlcl_vTrace = MMDKlcl_vTrace
};

// Macro for appending the '__MMDKlcl_log_symbol_' prefix to a given symbol.
#define __MMDKlcl_log_symbol(_symbol)                                              \
    __MMDKlcl_log_symbol_##_symbol


// End C linkage.
#ifdef __cplusplus
}
#endif


// Include logging back-end and definition of _MMDKlcl_logger.
#import "lcl_config_logger_MMDK.h"


// For simple configurations where 'lcl_config_logger_MMDK.h' is empty, define a
// default NSLog()-based _MMDKlcl_logger here.
#ifndef _MMDKlcl_logger

// ARC/non-ARC autorelease pool
#define _MMDKlcl_logger_autoreleasepool_arc 0
#if defined(__has_feature)
#   if __has_feature(objc_arc)
#   undef  _MMDKlcl_logger_autoreleasepool_arc
#   define _MMDKlcl_logger_autoreleasepool_arc 1
#   endif
#endif
#if _MMDKlcl_logger_autoreleasepool_arc
#   define _MMDKlcl_logger_autoreleasepool_begin                                   \
        @autoreleasepool {
#   define _MMDKlcl_logger_autoreleasepool_end                                     \
        }
#else
#   define _MMDKlcl_logger_autoreleasepool_begin                                   \
        NSAutoreleasePool *_MMDKlcl_logger_autoreleasepool = [[NSAutoreleasePool alloc] init];
#   define _MMDKlcl_logger_autoreleasepool_end                                     \
        [_MMDKlcl_logger_autoreleasepool release];
#endif

#ifndef _MMDKLCL_NO_IGNORE_WARNINGS
#   ifdef __clang__
// Ignore some warnings about variadic macros when using '-Weverything'.
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wunknown-pragmas"
#   pragma clang diagnostic ignored "-Wvariadic-macros"
#   pragma clang diagnostic ignored "-Wpedantic"
#   endif
#endif

// A simple default logger, which redirects to NSLog().
#define _MMDKlcl_logger(_component, _level, _format, ...) {                        \
    _MMDKlcl_logger_autoreleasepool_begin                                          \
    NSLog(@"%s %s:%@:%d " _format,                                             \
          _MMDKlcl_level_header_1[_level],                                         \
          _MMDKlcl_component_header[_component],                                   \
          [@__FILE__ lastPathComponent],                                       \
          __LINE__,                                                            \
          ## __VA_ARGS__);                                                     \
    _MMDKlcl_logger_autoreleasepool_end                                            \
}

#ifndef _MMDKLCL_NO_IGNORE_WARNINGS
#   ifdef __clang__
#   pragma clang diagnostic pop
#   endif
#endif

#endif


// Include extensions.
#import "lcl_config_extensions_MMDK.h"


#endif // __MMDKLCL_H__

