cmake_minimum_required(VERSION 3.16)

project(calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt (try Qt6, fall back to Qt5)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

# Define project sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Add mathlib.h explicitly (since it's in the parent directory)
set(ADDITIONAL_HEADERS
    ../mathlib.h
)

# Add executable (simplified for desktop)
add_executable(calculator
    ${PROJECT_SOURCES}
    ${ADDITIONAL_HEADERS}
)

# Link Qt libraries
target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

# Include directories for mainwindow.h and mathlib.h
target_include_directories(calculator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}    # For mainwindow.h (in src/calculator)
    ${CMAKE_CURRENT_SOURCE_DIR}/.. # For mathlib.h (in src/)
)

# Set properties for macOS/Windows bundles
set_target_properties(calculator PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install rules (optional, keep if you need to install)
include(GNUInstallDirs)
install(TARGETS calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize for Qt 6 (if needed)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calculator)
endif()
