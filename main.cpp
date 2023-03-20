#include "sdk_a/wrapper_a.h"
#include "sdk_b/wrapper_b.h"

int main(int argc, char* argv[]) {
  SDK_A_library_init();
  SDK_B_library_init();

  SDK_B_library_cleanup();
  SDK_A_library_cleanup();

  return 0;
}
