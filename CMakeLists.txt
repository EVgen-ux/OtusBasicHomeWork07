cmake_minimum_required(VERSION 3.5)

project(07.homework)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

add_executable(Container src/HW06.cpp)

# Test target
add_executable(
    test_container
    test/test_main.cpp
    test/test_container.cpp
    test/test_OneListContainer.cpp
    test/test_TwoListContainer.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_container PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    test_container PRIVATE
    gtest gtest_main
)

set_target_properties(Container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        Container PRIVATE
        /W4
    )
    target_compile_options(
        test_container PRIVATE
        /W4
    )
else ()
    target_compile_options(
        Container PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_container PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()