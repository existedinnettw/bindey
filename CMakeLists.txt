cmake_minimum_required(VERSION 3.15)

project(bindey LANGUAGES CXX)

# Options
option(BINDEY_USE_BUNDLED_NODSIGNAL "Use Bundled nod::signal" ON)
set(BINDEY_NODSIGNAL_TARGET
    "nod-signal"
    CACHE
      STRING
      "If your build system supplies nod signal as a CMake Target override this with your library name"
)

# Find nod-signal
if(BINDEY_USE_BUNDLED_NODSIGNAL)
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
  find_package(nod-signal REQUIRED)
endif()

find_package(PalSigslot REQUIRED CONFIG)

# Library

list(APPEND FILES_source include/bindey/binding.h)
list(APPEND FILES_source include/bindey/property.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include FILES ${FILES_source})

add_library(bindey INTERFACE ${FILES_source})
target_include_directories(bindey INTERFACE include)

target_link_libraries(bindey INTERFACE ${BINDEY_NODSIGNAL_TARGET} Pal::Sigslot)

target_compile_features(bindey INTERFACE cxx_std_14)

# Tests

if(NOT BUILD_TESTING STREQUAL OFF)
  enable_testing()

  add_subdirectory(test)
endif()

# install
set_target_properties(bindey PROPERTIES PUBLIC_HEADER "include/bindey.h")
install(TARGETS bindey)
