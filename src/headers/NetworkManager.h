#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>
#include <iostream>
#include <string>

class NetworkManager {
public:
    NetworkManager();
    ~NetworkManager();

    bool connectToServer(const std::string& ip, unsigned short port);
    void disconnect();
    bool sendMessage(const std::string& message);
    bool receiveMessage(std::string& message);

private:
    sf::TcpSocket socket;
    sf::Socket::Status status;
};

#endif // NETWORKMANAGER_H