project(sdk_b LANGUAGES C CXX)

add_library(sdk_b SHARED)

target_sources(sdk_b PRIVATE sdk_b.h sdk_b.cpp)

add_subdirectory(ssl_b)
target_link_libraries(sdk_b PUBLIC ssl_b)



add_library(wrapper_b SHARED)

target_sources(wrapper_b PRIVATE wrapper_b.h wrapper_b.cpp)

target_compile_options(wrapper_b PRIVATE -fvisibility=hidden)

target_compile_definitions(wrapper_b
  PRIVATE WRAPPER_A_DLL_COMPILE=1
)
