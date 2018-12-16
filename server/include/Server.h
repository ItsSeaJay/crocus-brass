#include <iostream>

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

		bool mOnline { true };

		sf::TcpSocket mSocket;

	private:
		const int mPort;
	};
}
