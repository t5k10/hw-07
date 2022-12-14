cmake_minimum_required(VERSION 3.16.3)

project(my_container)

add_executable(
    my_container
    src/array.cpp
    src/list.cpp
    src/doubly_list.cpp
    src/main.cpp
)

add_executable(
    containers_tests 
    test/array_tests.cpp
    test/list_tests.cpp
    test/doubly_list_tests.cpp
)

target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set_target_properties(my_container PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(my_container PRIVATE
    -g -Wall -Wextra -Werror -pedantic -O0 
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(containers_tests PRIVATE 
        -g -Wall -Wextra -Werror -pedantic -O0
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(containers_tests PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
