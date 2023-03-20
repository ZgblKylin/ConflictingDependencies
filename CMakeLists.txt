project(test LANGUAGES C CXX)

option(CONFLICT_RESOLVE "Set ON to resolve ssl conflict" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)


add_executable(test)

target_sources(test PRIVATE main.cpp)

add_subdirectory(sdk_a)
add_subdirectory(sdk_b)

if(NOT CONFLICT_RESOLVE)
  target_link_libraries(test PRIVATE sdk_a)
  target_link_libraries(test PRIVATE sdk_b)
else()
  target_link_libraries(test PRIVATE wrapper_a)
  target_link_libraries(test PRIVATE wrapper_b)
  target_compile_definitions(test PUBLIC SDK_USE_WRAPPER=1)
endif()
