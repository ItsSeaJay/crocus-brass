#include <iostream>
#include <list>
#include <mutex>
#include <vector>
#include <string>

#include "SFML/Network.hpp"

#pragma once

namespace cb
{
	class Server
	{
	public:
		Server(const unsigned short& port);
		~Server();

		void serve();

		const unsigned short mCapacity = 32;

		bool mOnline = true;

		std::mutex mMutex;

		std::vector<sf::TcpSocket*> mClients;
		sf::SocketSelector mSocketSelector;
		sf::TcpListener mListener;

	private:
		const unsigned short mPort;
	};
}
