#include "Server.h"

cb::Server::Server
(
	const int& port
)
: mPort(port)
{
    //ctor
}

cb::Server::~Server()
{
    //dtor
}

void cb::Server::listen()
{
	sf::TcpListener listener;

	// Listen for incoming connections on the server port
	listener.listen(mPort);
	listener.accept(mSocket);

	// Show who just connected
	std::cout << "New client connected: "
	          << mSocket.getRemoteAddress()
	          << std::endl;
}