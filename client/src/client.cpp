#include "tinynet/client.hpp"

#include "tinynet/tcp_client_transport.hpp"

namespace tinynet {

Client::Client() : transport_(std::make_unique<TcpClientTransport>()) {}

std::string_view Client::banner() const noexcept {
    return "TinyNet client (skeleton, no networking yet)";
}

bool Client::connect(const Endpoint& endpoint) {
    return transport_->connect(endpoint);
}

void Client::disconnect() noexcept {
    transport_->disconnect();
}

bool Client::isConnected() const noexcept {
    return transport_->isConnected();
}

}  // namespace tinynet
