# src/tests/CMakeLists.txt
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)

gtest_discover_tests(tests)