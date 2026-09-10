cmake_minimum_required(VERSION 3.10)
project(TextBasedGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add every new .cpp file to this list, or it will not be compiled.
# Header (.h) files do not belong here - CMake tracks them automatically.
# See "Adding new source files" in README.md.
add_executable(TextBasedGame
    src/main.cpp
    src/character/baseCharacter.cpp
    src/enemy/baseEnemy.cpp
)

# Lets any file include headers as paths from src/,
# e.g. #include "enemy/baseEnemy.h" instead of "../enemy/baseEnemy.h"
target_include_directories(TextBasedGame PRIVATE src)
