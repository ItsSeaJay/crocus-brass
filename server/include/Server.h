#include <iostream>
#include <list>
#include <mutex>
#include "SFML/Network.hpp"

#pragma once

namespace cb
{
	class Server
	{
	public:
		Server(const int& port);
		~Server();

		void listen();
		void serve();
		void dumpClients();

		bool mOnline { true };

		std::mutex mMutex;

		std::list<sf::TcpSocket*> mClients;
		sf::SocketSelector mSocketSelector;
		sf::TcpListener mListener;

	private:
		const int mPort;
	};
}
