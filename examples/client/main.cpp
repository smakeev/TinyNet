#include <iostream>

#include "tinynet/client.hpp"
#include "tinynet/endpoint.hpp"
#include "tinynet/socket_factory.hpp"
#include "tinynet/version.hpp"

int main() {
    std::cout << "TinyNet client demo v" << tinynet::version() << '\n'
              << tinynet::Client{}.banner() << '\n';

    // Describe where we would eventually connect, then create the matching
    // POSIX socket through the shared SocketFactory. No connect happens yet --
    // client connect/disconnect logic is added in a later commit.
    const auto endpoint = tinynet::Endpoint::localhostIpv4(8080);
    auto socket = tinynet::SocketFactory::createTcp(endpoint);

    std::cout << "Endpoint: " << endpoint.address() << ':' << endpoint.port()
              << '\n'
              << "Created TCP socket via SocketFactory: "
              << (socket.isValid() ? "valid" : "invalid") << " (fd "
              << socket.nativeHandle() << ")\n";

    // Convert the endpoint into a POSIX sockaddr. Future connect() will pass
    // addr->data() / addr->size() to ::connect; here we only build it.
    if (const auto addr = endpoint.toSockAddr()) {
        std::cout << "Built SockAddr: family=" << addr->addressFamily()
                  << ", size=" << addr->size() << " bytes\n";
    } else {
        std::cout << "Failed to build SockAddr for endpoint.\n";
    }

    return 0;
}
