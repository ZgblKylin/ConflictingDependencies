#ifndef WRAPPER_A_H
#define WRAPPER_A_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#ifndef SDK_USE_WRAPPER

#include "sdk_a.h"

#else  // NOT SDK_USE_WRAPPER

#ifdef WRAPPER_A_DLL_COMPILE
#define WRAPPER_A_API __attribute__((visibility("default")))
#else  // not WRAPPER_A_DLL_COMPILE
#define WRAPPER_A_API __attribute__((visibility("default")))
#endif  // WRAPPER_A_DLL_COMPILE

WRAPPER_A_API int WRAPPER_A_library_init();
WRAPPER_A_API void WRAPPER_A_library_cleanup();

// Redirect SDK_A_ to WRAPPER_A_
#ifndef WRAPPER_A_DLL_COMPILE
#define SDK_A_library_init WRAPPER_A_library_init
#define SDK_A_library_cleanup WRAPPER_A_library_cleanup
#endif  // not WRAPPER_A_DLL_COMPILE

#endif  // not SDK_USE_WRAPPER

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // WRAPPER_A_H
