cmake_minimum_required(VERSION 3.10)
project(TextBasedGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TextBasedGame
    src/main.cpp
    src/character/baseCharacter.cpp
    src/enemy/baseEnemy.cpp
    src/enemy/grunt.cpp
    src/enemy/gambler.cpp
    src/enemy/Joker.cpp
    src/enemy/darthVader.cpp
)

target_include_directories(TextBasedGame PRIVATE src)

if(MSVC)
    target_compile_options(TextBasedGame PRIVATE /utf-8)
endif()
