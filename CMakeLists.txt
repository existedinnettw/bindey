cmake_minimum_required(VERSION 3.15)

project(bindey LANGUAGES CXX)

# Options

# Find signal lib
find_package(PalSigslot REQUIRED CONFIG)

# Library

list(APPEND FILES_source include/bindey/binding.h)
list(APPEND FILES_source include/bindey/property.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include FILES ${FILES_source})

add_library(bindey INTERFACE ${FILES_source})
target_include_directories(bindey INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(bindey INTERFACE Pal::Sigslot)

target_compile_features(bindey INTERFACE cxx_std_14)

# Tests

if(NOT BUILD_TESTING STREQUAL OFF)
  enable_testing()

  add_subdirectory(test)
endif()

# install
set_target_properties(bindey PROPERTIES PUBLIC_HEADER "include/bindey/property.h;include/bindey/binding.h")
install(TARGETS bindey
  PUBLIC_HEADER DESTINATION include/bindey/
)
