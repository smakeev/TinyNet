#include <iostream>

#include "tinynet/acceptor.hpp"
#include "tinynet/version.hpp"

int main() {
    tinynet::Acceptor acceptor;

    std::cout << "TinyNet acceptor demo v" << tinynet::version() << '\n'
              << acceptor.banner() << '\n'
              << "No sockets are bound yet -- this is the starter skeleton.\n"
              << "Planned: bind/listen/accept, reusable by server and LAN-host mode.\n";

    return 0;
}
