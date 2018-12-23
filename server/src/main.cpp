#include <iostream>
#include <thread>
#include <functional>

#include "SFML/Network.hpp"
#include "Server.h"

int main(int argc, char** argv)
{
	cb::Server* server = new cb::Server(3000);

	// Start the server
	server->serve();

	// Deallocate the memory used by the server
	delete server;
	server = nullptr;

	return EXIT_SUCCESS;
}