# Ensure that this script can only be run with modern versions of CMake that
# use config files
cmake_minimum_required(VERSION 3.0)

# Tell CMake what the project is called
project(CrocusBrass)

# Add the different subdirectories for the different executables
add_subdirectory(src/Client)