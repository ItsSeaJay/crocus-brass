#include <iostream>

#include "SFML/Network.hpp"

int main(int argc, char** argv)
{
	bool online = true;

	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("localhost", 3000);

	// Check that the connection attempt was successful
	if (status != sf::Socket::Done)
	{
        std::cerr << "An error has occured trying to connect to the server." << std::endl;

        return EXIT_FAILURE;
	}

	// Create a container for client messages
	std::string message;

	do
	{
		// Regenerate the packet container
		sf::Packet packet;

		// Prompt the user to type something
		std::cout << '['
			<< socket.getRemoteAddress()
			<< ':'
			<< socket.getRemotePort()
			<< "]: ";
		
		// Capture their input
		std::cin >> message;

		// Serialize that input into a packet
		packet << message;

		// Attempt to send that packet to the server
		if (socket.send(packet) != sf::Socket::Done)
		{
			std::cerr << "Packet could not be sent to " << socket.getRemoteAddress();

			return EXIT_FAILURE;
		}
	} while (online);

	return EXIT_SUCCESS;
}
