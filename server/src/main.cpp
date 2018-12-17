#include <iostream>
#include <thread>
#include <functional>

#include "SFML/Network.hpp"
#include "Server.h"

int main(int argc, char** argv)
{
	cb::Server* server { new cb::Server(3000) };
	std::thread listeningThread(&cb::Server::listen, server);
	std::thread servingThread(&cb::Server::serve, server);

	// Start seperate threads for new connections and packets
	listeningThread.join();
	servingThread.join();

	delete server;
	server = nullptr;

	return EXIT_SUCCESS;
}