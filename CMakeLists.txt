project(test LANGUAGES C CXX)

option(CONFLICT_RESOLVE "Set ON to resolve ssl conflict" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)


add_executable(test)

target_sources(test PRIVATE main.cpp)

add_subdirectory(sdk_a)
target_link_libraries(test PRIVATE wrapper_a)

add_subdirectory(sdk_b)
target_link_libraries(test PRIVATE wrapper_b)
