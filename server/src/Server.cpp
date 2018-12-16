#include "Server.h"

cb::Server::Server
(
	const int& port
)
: mPort(port)
{
	listener.listen(mPort);
}

cb::Server::~Server()
{
    //dtor
}

void cb::Server::listen()
{
	listener.accept(mSocket);

	std::cout << "New client @" << mSocket.getRemoteAddress() << std::endl;
}

void cb::Server::serve()
{
	std::cout << "Test" << std::endl;
}