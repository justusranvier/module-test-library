cmake_minimum_required(VERSION 3.25)

project(myexample LANGUAGES CXX)
include(gcc_modules.cmake)

add_library(myexample SHARED)

target_sources(myexample PRIVATE "src/test.cpp")

# NOTE cmake and/or gcc apparently refuse to believe that a file with an .hpp
# extension can be a module interface unit.
configure_file("include/test.hpp" "${CMAKE_CURRENT_BINARY_DIR}/test.cpp" @ONLY)

target_sources(
  myexample
  PUBLIC FILE_SET
         public_headers
         BASE_DIRS
         "${CMAKE_CURRENT_SOURCE_DIR}/include"
         TYPE
         HEADERS
         FILES
         "include/test.hpp"
  PRIVATE FILE_SET modules TYPE CXX_MODULES FILES
          "${CMAKE_CURRENT_BINARY_DIR}/test.cpp")

set_target_properties(myexample PROPERTIES CXX_STANDARD 20)
target_compile_options(myexample PUBLIC "-fmodules-ts")

install(
  TARGETS myexample
  EXPORT myexampleExport
  FILE_SET public_headers
  DESTINATION include/myexample)
install(
  EXPORT myexampleExport
  NAMESPACE myexample::
  DESTINATION lib/cmake/myexample)
