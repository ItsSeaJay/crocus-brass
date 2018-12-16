#include <iostream>
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

		bool mOnline { true };

		std::mutex mMutex;

		sf::TcpSocket mSocket;
		sf::TcpListener listener;

	private:
		const int mPort;
	};
}
