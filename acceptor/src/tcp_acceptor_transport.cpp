#include "tinynet/tcp_acceptor_transport.hpp"

namespace tinynet {

bool TcpAcceptorTransport::bind(const Endpoint& /*endpoint*/) {
    // Placeholder: no networking yet. The listening socket is intentionally not
    // created until the real POSIX bind()/listen() is implemented, so the
    // transport does not hold a socket it cannot yet use.
    return false;
}

bool TcpAcceptorTransport::listen(int /*backlog*/) {
    // Placeholder: no networking yet.
    return false;
}

Socket TcpAcceptorTransport::accept() {
    // Placeholder: no networking yet, so no client connection is produced.
    return Socket{};
}

void TcpAcceptorTransport::close() noexcept {
    socket_.close();
}

bool TcpAcceptorTransport::isListening() const noexcept {
    // Always false for now: a valid socket fd does not imply a bound, listening
    // socket. Real listening state is tracked once POSIX bind()/listen() is
    // implemented.
    return false;
}

}  // namespace tinynet
