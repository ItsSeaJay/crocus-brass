#include <iostream>
#include <stdexcept>
#include <string>

#include "SFML/Network.hpp"
#include "Server.h"

int main(int argc, char** argv)
{
	bool running { true };

	sf::Thread* thread = 0;
	cb::Server* server { new cb::Server(3000) };

	thread = new sf::Thread(server->serve);
	thread->launch();

	while (running)
	{
		server->listen();
	}

	delete server;
	server = nullptr;

	return EXIT_SUCCESS;
}