# src/calculator/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link Qt libraries
target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

# Include directories for mainwindow.h and mathlib.h
target_include_directories(calculator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}    # For mainwindow.h (in src/calculator)
    ${CMAKE_CURRENT_SOURCE_DIR}/.. # For mathlib.h (in src/)
)

# Set properties for macOS/Windows
set_target_properties(calculator PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

find_package(Threads REQUIRED)
target_link_libraries(calculator PRIVATE Threads::Threads)