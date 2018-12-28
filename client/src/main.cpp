#include <iostream>

#include "SFML/Network.hpp"

int main(int argc, char** argv)
{
	bool online = true;

	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("localhost", 3000);
	sf::IpAddress localhost = "localhost";

	// Check that the connection attempt was successful
	if (status != sf::Socket::Done)
	{
        std::cerr << "An error has occured trying to connect to the server." << std::endl;

        return EXIT_FAILURE;
	}

	// Try to send a packet to the remote server
	std::string message = "Hello, World!";
	sf::Packet packet;

	packet << message;

	do
	{
		if (socket.send(packet) != sf::Socket::Done)
		{
			std::cerr << "Packet could not be sent to " << socket.getRemoteAddress();

			return EXIT_FAILURE;
		}
	} while (online);

	return EXIT_SUCCESS;
}
