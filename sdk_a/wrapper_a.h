#ifndef WRAPPER_A_H
#define WRAPPER_A_H

#ifdef WRAPPER_A_DLL_COMPILE
#define WRAPPER_A_API __attribute__((visibility("default")))
#else  // not WRAPPER_A_DLL_COMPILE
#define WRAPPER_A_API __attribute__((visibility("default")))
#endif  // WRAPPER_A_DLL_COMPILE

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

WRAPPER_A_API int WRAPPER_A_library_init();
WRAPPER_A_API void WRAPPER_A_library_cleanup();

#ifndef WRAPPER_A_DLL_COMPILE
#define SDK_A_library_init WRAPPER_A_library_init
#define SDK_A_library_cleanup WRAPPER_A_library_cleanup
#endif  // not WRAPPER_A_DLL_COMPILE

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // WRAPPER_A_H
