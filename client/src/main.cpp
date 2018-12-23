#include <iostream>

#include "SFML/Network.hpp"

int main(int argc, char** argv)
{
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("localhost", 3000);

	if (status != sf::Socket::Done)
	{
        std::cerr << "An error has occured trying to connect to the server." << std::endl;

        return EXIT_FAILURE;
	}

	std::string message = "Hello, World!";

	socket.send(message.c_str(), message.size() + 1);

	return EXIT_SUCCESS;
}
