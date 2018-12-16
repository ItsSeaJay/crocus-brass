#include <iostream>
#include <thread>
#include <functional>

#include "SFML/Network.hpp"
#include "Server.h"

int main(int argc, char** argv)
{
	bool running { true };
	cb::Server* server { new cb::Server(3000) };
	std::thread listeningThread(&cb::Server::listen, &server);

	while (running)
	{

	}

	delete server;
	server = nullptr;

	return EXIT_SUCCESS;
}