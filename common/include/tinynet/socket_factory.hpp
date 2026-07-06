#pragma once

#include "tinynet/endpoint.hpp"
#include "tinynet/socket.hpp"

namespace tinynet {

// Low-level factory for POSIX sockets.
//
// SocketFactory is the single place that turns an Endpoint's address family
// into a freshly created file descriptor wrapped in a Socket. It performs no
// bind/connect/listen and no sockaddr conversion -- it only calls ::socket().
// Client connect logic and acceptor bind/listen/accept logic live in their
// own modules and build on top of the sockets produced here.
class SocketFactory {
public:
    // Creates a TCP (SOCK_STREAM) socket for the endpoint's address family.
    // Returns an invalid Socket if ::socket() fails.
    static Socket createTcp(const Endpoint& endpoint) noexcept;

    // Creates a UDP (SOCK_DGRAM) socket for the endpoint's address family.
    // Returns an invalid Socket if ::socket() fails.
    static Socket createUdp(const Endpoint& endpoint) noexcept;
};

}  // namespace tinynet
