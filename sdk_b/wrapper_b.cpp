#include "wrapper_b.h"

#include <stddef.h>
#include <dlfcn.h>

void* SDK_B_dll_handle = NULL;

typedef int (*SDK_B_library_init_t)();
SDK_B_library_init_t SDK_B_library_init_ptr = NULL;

typedef void (*SDK_B_library_cleanup_t)();
SDK_B_library_cleanup_t SDK_B_library_cleanup_ptr = NULL;

int WRAPPER_B_library_init() {
  SDK_B_dll_handle = dlopen("./libsdk_b.so", RTLD_LAZY);
  if (!SDK_B_dll_handle) {
    return -1;
  }

  SDK_B_library_init_ptr =
      (SDK_B_library_init_t)dlsym(SDK_B_dll_handle, "SDK_B_library_init");
  if (!SDK_B_library_init_ptr) {
    return -1;
  }

  SDK_B_library_cleanup_ptr =
      (SDK_B_library_cleanup_t)dlsym(SDK_B_dll_handle, "SDK_B_library_cleanup");
  if (!SDK_B_library_cleanup_ptr) {
    return -1;
  }

  return SDK_B_library_init_ptr();
}

void WRAPPER_B_library_cleanup() {
  SDK_B_library_cleanup_ptr();
  dlclose(SDK_B_dll_handle);
}
