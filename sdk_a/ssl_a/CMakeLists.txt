project(ssl_a LANGUAGES C)

add_library(ssl_a SHARED)

target_sources(ssl_a PRIVATE ssl.h ssl.c)

# target_compile_options(ssl_a PUBLIC -fPIC)
