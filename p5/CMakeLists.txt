cmake_minimum_required(VERSION 3.10)
project(p5)  # Name deines Projekts

# Setze C++-Standard (z. B. C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Füge die ausführbare Datei hinzu (alle .cpp-Dateien auflisten!)
add_executable(p5_oop
    p5_oop.cpp
    taschenrechner.cpp
)

# Aktiviere Debugging-Symbole
target_compile_options(p5_oop PRIVATE -g)