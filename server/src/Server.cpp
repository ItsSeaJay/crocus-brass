#include "Server.h"

cb::Server::Server(const unsigned short& port)
: mPort(port)
{
	// Notify the user of a new server
	std::cout << "Created a server on port "
		<< port
		<< std::endl;
}

cb::Server::~Server() {}

void cb::Server::serve()
{
	mListener.listen(mPort);	
	mSocketSelector.add(mListener);

	std::cout << "Beginning service..." << std::endl;

	do
	{
		// Make the selector wait for data on any socket
		if (mSocketSelector.wait())
		{
			if (mSocketSelector.isReady(mListener))
			{
				// The listener is ready
				// This indicates a pending connection
				sf::TcpSocket* client = new sf::TcpSocket();

				if (mListener.accept(*client) == sf::Socket::Done)
				{
					if (mClients.size() < mCapacity)
					{
						std::cout << "New connection from "
							<< client->getRemoteAddress()
							<< ':'
							<< client->getRemotePort()
							<< std::endl;

						// Add the new client to the clients list
						mClients.push_back(client);

						// Also add them to the selector so we'll be notified when
						// they give us something
						mSocketSelector.add(*client);
					}
					else
					{
						std::cerr << "Server is full!";
					}
				}
				else
				{
					// We didn't get a new connection
					delete client;
				}
			}
			else
			{
				// The listener socket isn't ready yet
				// test all other live TCP sockets for incoming data
				for (std::list<sf::TcpSocket*>::iterator iterator = mClients.begin();
					iterator != mClients.end();
					++iterator)
				{
					// Dereference the client pointer
					sf::TcpSocket& client = **iterator;

					if (mSocketSelector.isReady(client))
					{
						// The client has sent some data
						sf::Packet packet;

						if (client.receive(packet) == sf::Socket::Done)
						{
							std::string message;

							// Deserialize the message from the packet
							if (packet >> message)
							{
								// Output that message
								std::cout << '['
									<< client.getRemoteAddress()
									<< ':'
									<< client.getRemotePort()
									<< "]: "
									<< message
									<< std::endl;
							}
						}
					}
				}
			}
		}
	} while (mOnline);
}