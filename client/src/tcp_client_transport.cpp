#include "tinynet/tcp_client_transport.hpp"

namespace tinynet {

bool TcpClientTransport::connect(const Endpoint& /*endpoint*/) {
    // Placeholder: no networking yet. The socket is intentionally not created
    // until the real POSIX connect() is implemented (roadmap item 9), so the
    // transport does not hold a socket it cannot yet use.
    return false;
}

void TcpClientTransport::disconnect() noexcept {
    socket_.close();
}

bool TcpClientTransport::isConnected() const noexcept {
    // Always false for now: a valid socket fd does not imply a completed TCP
    // connection. Real connection state is tracked once POSIX connect() is
    // implemented in roadmap item 9.
    return false;
}

}  // namespace tinynet
