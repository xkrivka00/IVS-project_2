#!/bin/bash

# Cesta kde máš Qt pro Windows (Qt5 MinGW)
QT_WIN_PATH="../cmake/Toolchain-mingw64.cmake"

# Build složka
BUILD_DIR=../build-windows

# Smažeme starý build
rm -rf $BUILD_DIR
mkdir $BUILD_DIR
cd $BUILD_DIR

# Spustíme cmake
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain-mingw64.cmake \
    -DCMAKE_PREFIX_PATH="$QT_WIN_PATH" \
    -DBUILD_CALCULATOR=ON \
    -DBUILD_STDDEV=OFF

# Build
cmake --build .

# Package (.exe installer přes NSIS)
cpack