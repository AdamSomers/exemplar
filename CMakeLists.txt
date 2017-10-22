cmake_minimum_required(VERSION 3.7)
project(exemplar)

set (CMAKE_CXX_STANDARD 11)

# force static runtime libraries for msvc builds
if(MSVC)
set(variables 
  CMAKE_CXX_FLAGS_DEBUG
  CMAKE_CXX_FLAGS_RELEASE
  CMAKE_CXX_FLAGS_RELWITHDEBINFO
  CMAKE_CXX_FLAGS_MINSIZEREL
)
foreach(variable ${variables})
  if(${variable} MATCHES "/MD")
    string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
  endif()
endforeach()
endif()

FILE(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(exemplarapp app/main.cpp)

include_directories(src)

add_library(exemplarlib ${sources})

if (WIN32)
    target_compile_definitions(exemplarapp PUBLIC WINDOWS=1)
    target_compile_definitions(exemplarlib PUBLIC WINDOWS=1)
endif (WIN32)

## Unit tests ##
# downloaded from https://github.com/google/googletest/releases
add_subdirectory(external/googletest-release-1.8.0)
enable_testing()
include(GoogleTest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FILE(GLOB_RECURSE test_sources test/*.cpp)
add_executable(runUnitTests ${test_sources})
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests exemplarlib)
gtest_add_tests(TARGET runUnitTests)
