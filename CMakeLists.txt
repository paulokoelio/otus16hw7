cmake_minimum_required(VERSION 3.2)

set(BUILD_VER 1)
set(BUILD_SUBVER 0)
set(BUILD_PATCH 0)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set (BUILD_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(bulk VERSION ${BUILD_VER}.${BUILD_SUBVER}.${BUILD_PATCH})

set(APP_BULK_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/other/solver)
add_subdirectory(${LIB_DIR})

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(testfull "test/testall")