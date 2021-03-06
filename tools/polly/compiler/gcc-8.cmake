# Copyright (c) 2013-2017, Ruslan Baratov
# Copyright (c) 2017, David Hirvonen
# All rights reserved.

if(DEFINED POLLY_COMPILER_GCC_8_CMAKE_)
  return()
else()
  set(POLLY_COMPILER_GCC_8_CMAKE_ 1)
endif()

find_program(CMAKE_C_COMPILER gcc-8)
find_program(CMAKE_CXX_COMPILER g++-8)

if(NOT CMAKE_C_COMPILER)
  polly_fatal_error("gcc not found")
endif()

if(NOT CMAKE_CXX_COMPILER)
  polly_fatal_error("g++ not found")
endif()

set(
    CMAKE_C_COMPILER
    "${CMAKE_C_COMPILER}"
    CACHE
    STRING
    "C compiler"
    FORCE
)

set(
    CMAKE_CXX_COMPILER
    "${CMAKE_CXX_COMPILER}"
    CACHE
    STRING
    "C++ compiler"
    FORCE
)
