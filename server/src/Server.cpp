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
	do
	{
		mMutex.lock();
			listener.accept(mSocket);
		mMutex.unlock();

		std::cout << "New client @" << mSocket.getRemoteAddress() << std::endl;
	} while (mOnline)
}

void cb::Server::serve()
{
	while(mOnline)
	{
		std::cout << "Test" << std::endl;
	}
}