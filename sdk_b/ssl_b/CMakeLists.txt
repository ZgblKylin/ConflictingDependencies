project(ssl_b LANGUAGES C)

add_library(ssl_b SHARED)

target_sources(ssl_b PRIVATE ssl.h ssl.c)

set_target_properties(ssl_b PROPERTIES
  VERSION 1.2.3
  SOVERSION 1
)
