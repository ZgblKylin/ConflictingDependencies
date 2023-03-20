#ifndef WRAPPER_B_H
#define WRAPPER_B_H

#ifdef WRAPPER_B_DLL_COMPILE
#define WRAPPER_B_API __attribute__((visibility("default")))
#else  // not WRAPPER_B_DLL_COMPILE
#define WRAPPER_B_API __attribute__((visibility("default")))
#endif  // WRAPPER_B_DLL_COMPILE

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

WRAPPER_B_API int WRAPPER_B_library_init();
WRAPPER_B_API void WRAPPER_B_library_cleanup();

#ifndef WRAPPER_B_DLL_COMPILE
#define SDK_B_library_init WRAPPER_B_library_init
#define SDK_B_library_cleanup WRAPPER_B_library_cleanup
#endif  // not WRAPPER_B_DLL_COMPILE

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // WRAPPER_B_H
