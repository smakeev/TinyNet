#pragma once

#include "tinynet/i_acceptor_transport.hpp"
#include "tinynet/socket.hpp"

namespace tinynet {

class Endpoint;

// TCP acceptor transport.
//
// Future home of the TinyNet incoming TCP connection logic (bind/listen/
// accept). It owns a listening Socket that will be obtained from SocketFactory.
// No POSIX networking is performed yet -- the methods are placeholders that
// define the class structure only.
class TcpAcceptorTransport : public IAcceptorTransport {
public:
    TcpAcceptorTransport() = default;

    // Move-only: it owns a Socket.
    TcpAcceptorTransport(const TcpAcceptorTransport&) = delete;
    TcpAcceptorTransport& operator=(const TcpAcceptorTransport&) = delete;

    TcpAcceptorTransport(TcpAcceptorTransport&&) noexcept = default;
    TcpAcceptorTransport& operator=(TcpAcceptorTransport&&) noexcept = default;

    // Placeholder: performs no networking and returns false. Real POSIX bind()
    // will be added in a later roadmap item.
    bool bind(const Endpoint& endpoint) override;

    // Placeholder: performs no networking and returns false. Real POSIX
    // listen() will be added in a later roadmap item.
    bool listen(int backlog) override;

    // Placeholder: performs no networking and returns an invalid Socket. Real
    // POSIX accept() will be added in a later roadmap item.
    Socket accept() override;

    // Closes the current listening socket.
    void close() noexcept override;

    // Returns whether the transport is currently listening.
    bool isListening() const noexcept override;

private:
    Socket socket_;
};

}  // namespace tinynet
