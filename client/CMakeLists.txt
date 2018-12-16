set(SOURCES
	src/main.cpp)

# Find SFML 2.5.1
# If the package can't be found, terminate the script
find_package(SFML 2.5 COMPONENTS network REQUIRED)

add_executable(${PROJECT_NAME}Client
               ${SOURCES})

target_link_libraries(${PROJECT_NAME}Client sfml-network)