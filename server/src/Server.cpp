#include "Server.h"

cb::Server::Server(const unsigned short& port)
: mPort(port)
{}

cb::Server::~Server() {}

void cb::Server::serve()
{
	mListener.listen(mPort);	
	mSocketSelector.add(mListener);

	do
	{
		// Make the selector wait for data on any socket
		if (mSocketSelector.wait())
		{
			if (mSocketSelector.isReady(mListener))
			{
				// There is a pending connection
				sf::TcpSocket* client = new sf::TcpSocket();

				if (mListener.accept(*client) == sf::Socket::Done &&
					mClients.size() < mCapacity)
				{
					// Add the new client to the clients list
					mClients.push_back(client);

					// Also add them to the selector so we'll be notified when
					// they give us something
					mSocketSelector.add(*client);
				}
				else
				{
					// We didn't get a new connection
					delete client;
				}
			}
			else
			{
				// The listener socket is not ready
				// test all other sockets
				for (auto* client : mClients)
				{
					if (mSocketSelector.isReady(*client))
					{
						sf::Packet packet;

						if (client->receive(packet) == sf::Socket::Done)
						{
							std::cout << "Received a packet!" << std::endl;
						}
					}
				}
			}
		}
	} while (mOnline);
}