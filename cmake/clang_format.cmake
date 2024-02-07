#
# Author: Kirill Trofimov
# Email: k.trofimov@geoscan.aero
# Date: 05.12.23
# Copyright (c) 2023 Geoscan Group. All rights reserved.
#

# Additional targets to perform clang-format/clang-tidy
# Get all project files
file(GLOB_RECURSE
        ALL_CXX_SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/Source/*.cpp"
        "${CMAKE_SOURCE_DIR}/Source/*.cxx"
        "${CMAKE_SOURCE_DIR}/Source/*.cc"
        "${CMAKE_SOURCE_DIR}/Source/*.C"
        "${CMAKE_SOURCE_DIR}/tests/*.cpp"
        "${CMAKE_SOURCE_DIR}/tests/*.cxx"
        "${CMAKE_SOURCE_DIR}/tests/*.cc"
        "${CMAKE_SOURCE_DIR}/tests/*.C"
)

file(GLOB_RECURSE
        ALL_CXX_HEADER_FILES
        "${CMAKE_SOURCE_DIR}/Source/*.h"
        "${CMAKE_SOURCE_DIR}/Source/*.H"
        "${CMAKE_SOURCE_DIR}/Source/*.hh"
        "${CMAKE_SOURCE_DIR}/Source/*.hxx"
        "${CMAKE_SOURCE_DIR}/Source/*.hpp"
)


# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    add_custom_target(
            clang-format
            COMMAND clang-format
            -i
            -style=file
            ${ALL_CXX_SOURCE_FILES}
            ${ALL_CXX_HEADER_FILES}
    )
endif()

# Adding clang-tidy target if executable is found
find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
    add_custom_target(
            clang-tidy
            COMMAND clang-tidy
            ${ALL_CXX_SOURCE_FILES}
            -config=''
            --
            -std=c++11
            ${INCLUDE_DIRECTORIES}
    )
endif()