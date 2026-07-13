#pragma once

namespace tinynet {

class Endpoint;

// Abstract client transport interface.
//
// IClientTransport is the strategy that a Client uses to reach a remote
// Endpoint. Concrete transports (TCP first, UDP later) own the underlying
// Socket and implement the actual connect/disconnect behaviour on top of the
// sockets produced by common's SocketFactory. Client itself stays a thin
// facade and never touches sockets directly.
class IClientTransport {
public:
    virtual ~IClientTransport() = default;

    // Establishes the transport-level connection to the endpoint. Returns true
    // on success. Concrete implementations own and manage the Socket.
    virtual bool connect(const Endpoint& endpoint) = 0;

    // Tears down the connection and releases any owned resources.
    virtual void disconnect() noexcept = 0;

    // Returns true if the transport considers the connection established.
    virtual bool isConnected() const noexcept = 0;
};

}  // namespace tinynet
