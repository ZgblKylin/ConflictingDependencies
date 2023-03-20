#include "sdk_a.h"
#include "ssl_a/ssl.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned long ssl_version;

  char ssl_context[0];
} SDK_A_Context;
SDK_A_Context* sdk_a_context = NULL;

extern "C" {

int SDK_A_library_init() {
  int ret = SSL_library_init();
  if (ret) {
    return ret;
  }

  unsigned long* ssl_version =
      (unsigned long*)(SSL_context() + SSL_version() - sizeof(unsigned long));
  assert(*ssl_version == 0x010101);
  if (*ssl_version != 0x010101) {
    return -1;
  }
  printf("Initialize SDK A with ssl version %06lx\n", *ssl_version);

  sdk_a_context = (SDK_A_Context*)malloc(sizeof(SDK_A_Context) + SSL_version());
  sdk_a_context->ssl_version = SSL_version();
  memcpy(sdk_a_context->ssl_context, SSL_context(), SSL_version());

  return 0;
}

void SDK_A_library_cleanup() {
  free(sdk_a_context);
  printf("Release SDK A\n");
}

}  // extern "C"
