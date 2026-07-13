#pragma once

#include "tinynet/i_client_transport.hpp"
#include "tinynet/socket.hpp"

namespace tinynet {

class Endpoint;

// TCP client transport.
//
// Future home of the TinyNet outgoing TCP connection logic. It owns a Socket,
// obtains it from SocketFactory and converts the target Endpoint via
// Endpoint::toSockAddr(). No POSIX connect() is performed yet -- the methods
// are placeholders that define the class structure only.
class TcpClientTransport : public IClientTransport {
public:
    TcpClientTransport() = default;

    // Move-only: it owns a Socket.
    TcpClientTransport(const TcpClientTransport&) = delete;
    TcpClientTransport& operator=(const TcpClientTransport&) = delete;

    TcpClientTransport(TcpClientTransport&&) noexcept = default;
    TcpClientTransport& operator=(TcpClientTransport&&) noexcept = default;

    // Placeholder: performs no networking and returns false. Real POSIX
    // connect() will be added in roadmap item 9.
    bool connect(const Endpoint& endpoint) override;

    // Closes the current socket.
    void disconnect() noexcept override;

    // Returns whether the transport is connected.
    bool isConnected() const noexcept override;

private:
    Socket socket_;
};

}  // namespace tinynet
