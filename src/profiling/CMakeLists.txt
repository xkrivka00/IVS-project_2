# src/profiling/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(stddev VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stddev stddev.cpp)
target_include_directories(stddev PRIVATE ${CMAKE_SOURCE_DIR}/src)

install(TARGETS stddev DESTINATION ${CMAKE_INSTALL_BINDIR})

# .desktop + icon for terminal app
install(FILES ${CMAKE_SOURCE_DIR}/stddev.desktop DESTINATION share/applications)
install(FILES ${CMAKE_SOURCE_DIR}/assets/stddev-icon.png DESTINATION share/icons/hicolor/128x128/apps RENAME stddev-icon.png)



