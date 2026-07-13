#pragma once

#include "tinynet/socket.hpp"

namespace tinynet {

class Endpoint;

// Abstract acceptor transport interface.
//
// IAcceptorTransport is the strategy an Acceptor uses to receive incoming
// connections. Concrete transports (TCP first) own the underlying listening
// Socket and will later implement bind()/listen()/accept() on top of the
// sockets produced by common's SocketFactory. The Acceptor facade stays thin
// and never touches sockets directly.
//
// This interface belongs to the acceptor module, not common: it represents the
// incoming-connection side and is shared by the backend server and mobile
// LAN-host mode.
class IAcceptorTransport {
public:
    virtual ~IAcceptorTransport() = default;

    // Binds the listening socket to the given local endpoint. Returns true on
    // success. Concrete implementations own and manage the Socket.
    virtual bool bind(const Endpoint& endpoint) = 0;

    // Marks the bound socket as passive with the given connection backlog.
    // Returns true on success.
    virtual bool listen(int backlog) = 0;

    // Accepts the next pending incoming connection and returns it as a new
    // Socket. Returns an invalid Socket if no connection is accepted.
    virtual Socket accept() = 0;

    // Closes the listening socket and releases any owned resources.
    virtual void close() noexcept = 0;

    // Returns whether the transport is currently listening.
    virtual bool isListening() const noexcept = 0;
};

}  // namespace tinynet
