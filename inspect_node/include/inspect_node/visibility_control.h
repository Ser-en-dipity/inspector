#ifndef INSPECT_NODE__VISIBILITY_CONTROL_H_
#define INSPECT_NODE__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define INSPECT_NODE_EXPORT __attribute__ ((dllexport))
    #define INSPECT_NODE_IMPORT __attribute__ ((dllimport))
  #else
    #define INSPECT_NODE_EXPORT __declspec(dllexport)
    #define INSPECT_NODE_IMPORT __declspec(dllimport)
  #endif
  #ifdef INSPECT_NODE_BUILDING_LIBRARY
    #define INSPECT_NODE_PUBLIC INSPECT_NODE_EXPORT
  #else
    #define INSPECT_NODE_PUBLIC INSPECT_NODE_IMPORT
  #endif
  #define INSPECT_NODE_PUBLIC_TYPE INSPECT_NODE_PUBLIC
  #define INSPECT_NODE_LOCAL
#else
  #define INSPECT_NODE_EXPORT __attribute__ ((visibility("default")))
  #define INSPECT_NODE_IMPORT
  #if __GNUC__ >= 4
    #define INSPECT_NODE_PUBLIC __attribute__ ((visibility("default")))
    #define INSPECT_NODE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define INSPECT_NODE_PUBLIC
    #define INSPECT_NODE_LOCAL
  #endif
  #define INSPECT_NODE_PUBLIC_TYPE
#endif

#endif  // INSPECT_NODE__VISIBILITY_CONTROL_H_
