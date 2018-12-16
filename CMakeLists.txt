# Ensure that this script can only be run with modern versions of CMake that
# use config files
cmake_minimum_required(VERSION 3.0)

# Tell CMake what our project is called
project(CrocusBrass)

# Find version 2.5.0 of the SFML library on this computer,
# but only use the network package
# If the package can't be found, terminate the script
find_package(SFML 2.4 COMPONENTS network REQUIRED)

# Tell the compiler where the source code is, and add it to the executable
add_executable(CrocusBrass src/Main.cpp)

# Add the following SFML module to the application:
target_link_libraries(CrocusBrass sfml-network)
