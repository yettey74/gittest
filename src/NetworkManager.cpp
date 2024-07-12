#include "headers/NetworkManager.h"

NetworkManager::NetworkManager() {
    // Initialize network manager
}

NetworkManager::~NetworkManager() {
    disconnect();
}

bool NetworkManager::connectToServer(const std::string& ip, unsigned short port) {
    status = socket.connect(ip, port);
    if (status != sf::Socket::Done) {
        std::cerr << "Error connecting to server: " << ip << ":" << port << std::endl;
        return false;
    }
    std::cout << "Connected to server: " << ip << ":" << port << std::endl;
    return true;
}

void NetworkManager::disconnect() {
    socket.disconnect();
    std::cout << "Disconnected from server." << std::endl;
}

bool NetworkManager::sendMessage(const std::string& message) {
    if (socket.send(message.c_str(), message.size()) != sf::Socket::Done) {
        std::cerr << "Error sending message: " << message << std::endl;
        return false;
    }
    return true;
}

bool NetworkManager::receiveMessage(std::string& message) {
    char buffer[2000];
    std::size_t received;
    if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
        std::cerr << "Error receiving message" << std::endl;
        return false;
    }
    message.assign(buffer, received);
    return true;
}
