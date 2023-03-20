#include "wrapper_a.h"

#ifndef SDK_USE_WRAPPER

int wrapper_a_dummy_make_compiler_happy_for_empty_source_;

#else  // SDK_USE_WRAPPER

#include <stddef.h>
#include <dlfcn.h>

void* SDK_A_dll_handle = NULL;

typedef int (*SDK_A_library_init_t)();
SDK_A_library_init_t SDK_A_library_init_ptr = NULL;

typedef void (*SDK_A_library_cleanup_t)();
SDK_A_library_cleanup_t SDK_A_library_cleanup_ptr = NULL;

int WRAPPER_A_library_init() {
  SDK_A_dll_handle = dlopen("./libsdk_a.so", RTLD_LAZY);
  if (!SDK_A_dll_handle) {
    return -1;
  }

  SDK_A_library_init_ptr =
      (SDK_A_library_init_t)dlsym(SDK_A_dll_handle, "SDK_A_library_init");
  if (!SDK_A_library_init_ptr) {
    return -1;
  }

  SDK_A_library_cleanup_ptr =
      (SDK_A_library_cleanup_t)dlsym(SDK_A_dll_handle, "SDK_A_library_cleanup");
  if (!SDK_A_library_cleanup_ptr) {
    return -1;
  }

  return SDK_A_library_init_ptr();
}

void WRAPPER_A_library_cleanup() {
  SDK_A_library_cleanup_ptr();
  dlclose(SDK_A_dll_handle);
}

#endif  // SDK_USE_WRAPPER
