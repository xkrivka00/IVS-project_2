cmake_minimum_required(VERSION 3.16)
project(calculator VERSION 1.0.0 LANGUAGES CXX)

# Build options
option(BUILD_CALCULATOR "Build GUI calculator" ON)

# Deprecated - no need to build and install stddev but great for practice
option(BUILD_STDDEV "Build CLI stddev calculator" ON) 


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic processing of Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt
if(BUILD_CALCULATOR)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)
endif()

# ====== GUI CALCULATOR =======
if(BUILD_CALCULATOR)
    message(STATUS "Building GUI calculator")

    set(CALCULATOR_SOURCES
        src/calculator/main.cpp
        src/calculator/mainwindow.cpp
        src/calculator/mainwindow.h
        src/calculator/mainwindow.ui
        src/mathlib.h
    )

    add_executable(calculator ${CALCULATOR_SOURCES})

    target_include_directories(calculator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/calculator
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

    target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

    install(TARGETS calculator DESTINATION ${CMAKE_INSTALL_BINDIR})
    install(FILES calculator.desktop DESTINATION share/applications)
    install(FILES assets/calculator-icon.png DESTINATION share/icons/hicolor/128x128/apps RENAME calculator-icon.png)
endif()

# ======= CLI STDDEV =====
if(BUILD_STDDEV)
    message(STATUS "Building terminal stddev calculator")
    add_subdirectory(src/profiling)
endif()

# ========== CPACK CONFIG ==========
set(CPACK_GENERATOR "DEB")
set(CPACK_SOURCE_GENERATOR "")

if(BUILD_CALCULATOR AND NOT BUILD_STDDEV)
    set(CPACK_PACKAGE_NAME "calculator")
    set(CPACK_PACKAGE_VERSION "1.0.0")
    set(CPACK_PACKAGE_DESCRIPTION "Qt calculator with GUI")
    set(CPACK_PACKAGE_FILE_NAME "calculator")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27), libqt5widgets5 (>= 5.15.0)")
elseif(BUILD_STDDEV AND NOT BUILD_CALCULATOR)
    set(CPACK_PACKAGE_NAME "stddev")
    set(CPACK_PACKAGE_VERSION "1.0.0")
    set(CPACK_PACKAGE_DESCRIPTION "Standard deviation terminal calculator")
    set(CPACK_PACKAGE_FILE_NAME "stddev")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
endif()

set(CPACK_PACKAGE_CONTACT "xkrivka00@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_VENDOR "Team Nullpointers")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Team Nullpointers")

include(CPack)

# ========== TESTING ==========
enable_testing()
if(BUILD_CALCULATOR)
    add_subdirectory(src/tests)
endif()