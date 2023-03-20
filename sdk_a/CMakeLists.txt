project(sdk_a LANGUAGES C CXX)

add_library(sdk_a SHARED)

target_sources(sdk_a PRIVATE sdk_a.h sdk_a.cpp)

add_subdirectory(ssl_a)
target_link_libraries(sdk_a PUBLIC ssl_a)



add_library(wrapper_a SHARED)

target_sources(wrapper_a PRIVATE wrapper_a.h wrapper_a.cpp)

target_compile_options(wrapper_a PRIVATE -fvisibility=hidden)

target_compile_definitions(wrapper_a
  PRIVATE WRAPPER_A_DLL_COMPILE=1
)
