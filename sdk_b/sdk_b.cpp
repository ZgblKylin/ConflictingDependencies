#include "sdk_b.h"
#include "ssl_b/ssl.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned long ssl_version;

  char ssl_context[0];
} SDK_B_Context;
SDK_B_Context* sdk_b_context = NULL;

extern "C" {

int SDK_B_library_init() {
  int ret = SSL_library_init();
  if (ret) {
    return ret;
  }

  unsigned long* ssl_version =
      (unsigned long*)(SSL_context() + SSL_version() - sizeof(unsigned long));
  assert(*ssl_version == 0x010203);
  if (*ssl_version != 0x010203) {
    return -1;
  }
  printf("Initialize SDK B with ssl version %06lx\n", *ssl_version);

  sdk_b_context = (SDK_B_Context*)malloc(sizeof(SDK_B_Context) + SSL_version());
  sdk_b_context->ssl_version = SSL_version();
  memcpy(sdk_b_context->ssl_context, SSL_context(), SSL_version());

  return 0;
}

void SDK_B_library_cleanup() {
  free(sdk_b_context);
  printf("Release SDK B\n");
}

}  // extern "C"
