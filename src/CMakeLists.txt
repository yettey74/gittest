cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(gittest LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target with source files
add_executable(main
                ../src/main.cpp 
                ../src/OptionsScreen.cpp
                ../headers/OptionsScreen.h
                ../version.rc
            )

# Set the path to SFML
set(SFML_DIR "C:/SFML4VC17/lib/cmake/SFML")

# Find the SFML package
find_package(SFML 2.6.1 REQUIRED COMPONENTS graphics window system )

# Link SFML libraries to the executable
target_link_libraries(main sfml-graphics sfml-window sfml-system)

# Include SFML headers
target_include_directories(main PUBLIC "C:/SFML4GCC/include")