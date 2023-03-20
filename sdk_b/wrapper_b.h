#ifndef WRAPPER_B_H
#define WRAPPER_B_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#ifndef SDK_USE_WRAPPER

#include "sdk_b.h"

#else  // NOT SDK_USE_WRAPPER

#ifdef WRAPPER_B_DLL_COMPILE
#define WRAPPER_B_API __attribute__((visibility("default")))
#else  // not WRAPPER_B_DLL_COMPILE
#define WRAPPER_B_API __attribute__((visibility("default")))
#endif  // WRAPPER_B_DLL_COMPILE

WRAPPER_B_API int WRAPPER_B_library_init();
WRAPPER_B_API void WRAPPER_B_library_cleanup();

// Redirect SDK_B_ to WRAPPER_B_
#ifndef WRAPPER_B_DLL_COMPILE
#define SDK_B_library_init WRAPPER_B_library_init
#define SDK_B_library_cleanup WRAPPER_B_library_cleanup
#endif  // not WRAPPER_B_DLL_COMPILE

#endif  // SDK_USE_WRAPPER

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // WRAPPER_B_H
