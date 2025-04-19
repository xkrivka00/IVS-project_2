cmake_minimum_required(VERSION 3.10)
project(IVSMathLib)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stddev src/profiling/stddev.cpp)
install(TARGETS stddev DESTINATION ${CMAKE_INSTALL_BINDIR})

# Desktop entry + icon
install(FILES stddev.desktop DESTINATION share/applications)
install(FILES assets/stddev-icon.png DESTINATION share/icons/hicolor/128x128/apps RENAME stddev-icon.png)

include(InstallRequiredSystemLibraries)

# CPack
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "stddev")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Team Nullpointers")
set(CPACK_PACKAGE_DESCRIPTION "A program that calculates stddev from input")
set(CPACK_PACKAGE_VENDOR "Team Nullpointers")
set(CPACK_PACKAGE_CONTACT "xkrivka00@stud.fit.vutbr.cz")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")

include(CPack)

enable_testing()
add_subdirectory(src/tests)
add_subdirectory(src/calculator)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)