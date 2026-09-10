# Text-Based-Game

A turn-based battle game built in C++ that runs directly in the terminal. This project serves as an interactive educational tool designed to teach developers the core principles of Object-Oriented Programming (OOP) and robust class design.

---

# Template Setup Steps

## Prerequisites

You need three things: **Git**, a **C++ compiler**, and **CMake** (3.10 or newer). Steps to install below

### Windows

Open PowerShell and run:

```powershell
winget install Git.Git
winget install Kitware.CMake
winget install Microsoft.VisualStudio.Community --override "--quiet --add Microsoft.VisualStudio.Workload.NativeDesktop --includeRecommended"
```

**Close and reopen your terminal afterward** so the new tools land on your `PATH`.

### macOS

Install the Apple command-line developer tools (this provides `git` and the `clang` compiler):

```bash
xcode-select --install
```

Then install CMake — easiest via [Homebrew](https://brew.sh):

```bash
brew install cmake
```

### Linux (Debian / Ubuntu)

```bash
sudo apt update
sudo apt install git build-essential cmake
```

On Fedora, use `sudo dnf install git gcc-c++ make cmake`. On Arch, `sudo pacman -S git base-devel cmake`.

---

## Building

Verify your tools are installed first. Both commands should print a version:

```bash
git --version
cmake --version
```

Then clone and build:

```bash
git clone https://github.com/Illini-Vex-Robotics/Text-Based-Game.git
cd Text-Based-Game
cmake -S . -B build
cmake --build build --config Debug
```

## Running

The executable's location depends on your platform, because Visual Studio uses per-configuration subfolders and the Unix generators do not:

**Windows:**
```powershell
.\build\Debug\TextBasedGame.exe
```

**macOS / Linux:**
```bash
./build/TextBasedGame
```

---

## Adding new source files

**Every new `.cpp` file must be added to `CMakeLists.txt` or it will not be compiled.**

Open `CMakeLists.txt` and add the file's path to the `add_executable` list:

```cmake
add_executable(TextBasedGame
    src/main.cpp
    src/character/baseCharacter.cpp
    src/enemy/baseEnemy.cpp
    src/item/newFile.cpp        # <-- your new file
)
```

Paths are relative to `CMakeLists.txt`, so they include the `src/` prefix

### Header files and `src/include.h`

Headers don't go in `CMakeLists.txt`, CMake tracks them on its own. Instead, add each new `.h` to `src/include.h`:

```cpp
#pragma once

#include "character/baseCharacter.h"
#include "enemy/baseEnemy.h"
#include "item/newFile.h"        // <-- your new header
```

`main.cpp` includes only `include.h`, so anything listed there is available without touching `main.cpp`. Paths start from `src/`, the same as in `CMakeLists.txt`.