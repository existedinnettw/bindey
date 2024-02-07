list(APPEND SOURCE_tests binding.test.cpp)
list(APPEND SOURCE_tests property.test.cpp)

find_package(Catch2 REQUIRED CONFIG)

add_executable(bindey-test ${SOURCE_tests})
target_link_libraries(bindey-test PRIVATE bindey Catch2::Catch2WithMain)

# add tests to CTest
include(CTest)
include(Catch)
catch_discover_tests(bindey-test)
