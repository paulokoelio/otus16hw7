cmake_minimum_required(VERSION 3.2)

find_package(GTest REQUIRED)

add_executable(testall 
                testall.cpp
                ${APP_BULK_DIR}/version.cpp 
                ${APP_BULK_DIR}/bulk.cpp
                ${APP_BULK_DIR}/Reader.cpp
                ${APP_BULK_DIR}/iPublisher.cpp
                ${APP_BULK_DIR}/Speaker.cpp
                ${APP_BULK_DIR}/Writer.cpp
                )

set_target_properties(testall PROPERTIES     
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(testall PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${GTEST_INCLUDE_DIRS}
    "${CMAKE_BINARY_DIR}/include"
    ${LIB_DIR}
)

target_link_libraries( testall 
                        ${GTEST_LIBRARIES} 
                        Threads::Threads
                        stdc++fs 
                        solver_lib
                        )


if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(testall PRIVATE
        /W4
    )
else ()
    target_compile_options(testall PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

