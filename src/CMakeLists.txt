cmake_minimum_required(VERSION 3.2)

add_executable(bulk 
                main.cpp 
                version.cpp 
                bulk.cpp
                Reader.cpp
                iPublisher.cpp
                Speaker.cpp
                Writer.cpp
                )

set_target_properties(bulk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulk PRIVATE 
                            ${PROJECT_SOURCE_DIR}/include
                            ${PROJECT_SOURCE_DIR}/other/solver
                            "${CMAKE_BINARY_DIR}/include"
                            "/usr/include/c++/8/"
                            ${LIB_DIR}
)

target_link_libraries( bulk PRIVATE stdc++fs solver_lib)

if (MSVC)
    target_compile_options(bulk PRIVATE
        /W4
    )
else ()
    target_compile_options(bulk PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT solverdce@gmail.com)

include(CPack)

