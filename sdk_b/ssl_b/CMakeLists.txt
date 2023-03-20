project(ssl_b LANGUAGES C)

add_library(ssl_b SHARED)

target_sources(ssl_b PRIVATE ssl.h ssl.c)

# target_compile_options(ssl_b PUBLIC -fPIC)
