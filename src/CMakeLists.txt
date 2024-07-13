cmake_minimum_required(VERSION 3.14)

# Set the project name and language
project(gittest LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target with source files
add_executable(main
                ../src/main.cpp 
                ../src/GameScreen.cpp
                ../src/OptionsScreen.cpp
                ../src/NetworkManager.cpp
                ../src/AudioManager.cpp
                ../version.rc                
            )

# Add include directories
target_include_directories(
    main 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src/headers
    ${CMAKE_SOURCE_DIR}/src/audio
    ${CMAKE_SOURCE_DIR}/src/network
    #PRIVATE
    "C:/SFML4GCC/include"
)

# Set the path to SFML
set(SFML_DIR "C:/SFML4VC17/lib/cmake/SFML")

# Find the SFML package
find_package(
    SFML 2.6.1 
    REQUIRED COMPONENTS 
    graphics 
    system 
    window 
    audio 
    network 
)

# Link SFML libraries to the executable
target_link_libraries(
    main 
    PRIVATE 
    sfml-graphics 
    sfml-system 
    sfml-window 
    sfml-audio 
    sfml-network 
)

# Ensure orchestral.mp3 is copied to the output directory
# add_custom_command(
#     TARGET gittest POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy
#     ${CMAKE_SOURCE_DIR}/audio/orchestral.mp3
#     ${CMAKE_BINARY_DIR}/orchestral.mp3
#     COMMENT "Copying orchestral.mp3 to build directory"
# )