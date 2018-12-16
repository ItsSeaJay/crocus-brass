set(SOURCES
	src/main.cpp
	src/Server.cpp)
set(INCLUDES
    include/Server.h)

# Find SFML
# If the package can't be found, terminate the script
find_package(SFML 2.5 COMPONENTS network REQUIRED)

include_directories(include)

add_executable(${PROJECT_NAME}Server
               ${SOURCES}
               ${INCLUDES})

target_link_libraries(${PROJECT_NAME}Server sfml-network)

if(UNIX)
	target_link_libraries(${PROJECT_NAME}Server pthread)
endif(UNIX)