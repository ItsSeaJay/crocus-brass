# Ensure that this script can only be run with modern versions of CMake that
# use config files
cmake_minimum_required(VERSION 3.0)

# Tell CMake what the project is called
project(CrocusBrass)

# Set the properties of the SFML dependancy
set(SFML_DIR
    /home/callum/Downloads/SFML-2.5.1/build)
set(SFML_DOC_DIR
    /home/callum/Downloads/SFML-2.5.1/doc)

# Add subdirectories for the different executables
add_subdirectory(client)
add_subdirectory(server)