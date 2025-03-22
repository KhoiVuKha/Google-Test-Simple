cmake_minimum_required(VERSION 3.2)
project(GTestSimple VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings and treat warnings as errors
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# Add option for building tests
option(BUILD_TESTS "Build the test suite" ON)

# Create library target for the code being tested
add_library(rectangle_lib
    function_need_to_test.cpp
    function_need_to_test.h
)

# Set up testing
if(BUILD_TESTS)
    # Locate GTest
    find_package(GTest REQUIRED)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    include_directories(${GTEST_INCLUDE_DIRS})
    
    enable_testing()
    
    # Create test executable
    add_executable(runTests test.cpp)
    target_link_libraries(runTests
        PRIVATE
            rectangle_lib
            ${GTEST_LIBRARIES}
            pthread
    )
    
    # Add test to CTest
    add_test(NAME unit_tests COMMAND runTests)
endif()
