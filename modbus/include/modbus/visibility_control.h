#ifndef MODBUS__VISIBILITY_CONTROL_H_
#define MODBUS__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MODBUS_EXPORT __attribute__ ((dllexport))
    #define MODBUS_IMPORT __attribute__ ((dllimport))
  #else
    #define MODBUS_EXPORT __declspec(dllexport)
    #define MODBUS_IMPORT __declspec(dllimport)
  #endif
  #ifdef MODBUS_BUILDING_LIBRARY
    #define MODBUS_PUBLIC MODBUS_EXPORT
  #else
    #define MODBUS_PUBLIC MODBUS_IMPORT
  #endif
  #define MODBUS_PUBLIC_TYPE MODBUS_PUBLIC
  #define MODBUS_LOCAL
#else
  #define MODBUS_EXPORT __attribute__ ((visibility("default")))
  #define MODBUS_IMPORT
  #if __GNUC__ >= 4
    #define MODBUS_PUBLIC __attribute__ ((visibility("default")))
    #define MODBUS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MODBUS_PUBLIC
    #define MODBUS_LOCAL
  #endif
  #define MODBUS_PUBLIC_TYPE
#endif

#endif  // MODBUS__VISIBILITY_CONTROL_H_
