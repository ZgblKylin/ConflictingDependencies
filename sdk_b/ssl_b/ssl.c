#include "ssl.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define SSL_VERSION 0x010203

typedef struct {
  unsigned int version;
} SSL_Context;
SSL_Context* ssl_context = NULL;

int SSL_library_init() {
  assert(NULL == ssl_context);
  if (NULL != ssl_context) {
    abort();
  }

  ssl_context = (SSL_Context*)malloc(SSL_VERSION);
  memset(ssl_context, 0, SSL_VERSION);

  ssl_context->version = SSL_VERSION;
  memcpy((char*)ssl_context + SSL_version() - sizeof(unsigned long),
         &ssl_context->version, sizeof(unsigned long));

  return 0;
}

unsigned long SSL_version() { return ssl_context->version; }

const char* SSL_context() { return (const char*)ssl_context; }

void SSL_library_cleanup() { free(ssl_context); }
