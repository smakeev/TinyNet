#include <iostream>

#include "tinynet/client.hpp"
#include "tinynet/version.hpp"

int main() {
    tinynet::Client client;

    std::cout << "TinyNet client demo v" << tinynet::version() << '\n'
              << client.banner() << '\n'
              << "No connection is established yet -- this is the starter skeleton.\n"
              << "Planned: TCP connect, packet framing, connection state machine.\n";

    return 0;
}
