cmake_minimum_required(VERSION 3.2)

project(solver_lib)

add_library(solver_lib lib.cpp)

set_target_properties(solver_lib PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)

target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                             "/usr/include/c++/8/")

if (MSVC)
    target_compile_options(solver_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(solver_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

