#include <iostream>

#include "tinynet/server.hpp"
#include "tinynet/version.hpp"

int main() {
    tinynet::Server server;

    std::cout << "TinyNet server demo v" << tinynet::version() << '\n'
              << server.banner() << '\n'
              << "No sockets are opened yet -- this is the starter skeleton.\n"
              << "Planned: TCP accept loop, packet framing, command dispatch.\n";

    return 0;
}
