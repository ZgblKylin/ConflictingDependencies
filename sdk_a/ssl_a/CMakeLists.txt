project(ssl_a LANGUAGES C)

add_library(ssl_a SHARED)

target_sources(ssl_a PRIVATE ssl.h ssl.c)

set_target_properties(ssl_a PROPERTIES
  VERSION 1.1.1
  SOVERSION 1
)
