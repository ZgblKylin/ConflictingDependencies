#ifndef SDK_USE_WRAPPER
#include "sdk_a/sdk_a.h"
#include "sdk_b/sdk_b.h"
#else  // SDK_USE_WRAPPER
#include "sdk_a/wrapper_a.h"
#include "sdk_b/wrapper_b.h"
#endif  // SDK_USE_WRAPPER

int main(int argc, char* argv[]) {
  SDK_A_library_init();
  SDK_B_library_init();

  SDK_B_library_cleanup();
  SDK_A_library_cleanup();

  return 0;
}
