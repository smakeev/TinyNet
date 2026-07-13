#pragma once

#include <memory>
#include <string_view>

#include "tinynet/i_client_transport.hpp"

namespace tinynet {

class Endpoint;

// Thin facade over a client transport strategy.
//
// Client owns an IClientTransport (a TcpClientTransport by default) and simply
// delegates connect/disconnect/isConnected to it. All socket handling lives in
// the transport; Client stays a stable, transport-agnostic entry point. No
// networking is performed yet -- the transport methods are still placeholders.
class Client {
public:
    // Constructs a Client backed by a TCP transport.
    Client();

    // Returns a human-readable description of the client component.
    std::string_view banner() const noexcept;

    // Connects to the endpoint through the underlying transport.
    bool connect(const Endpoint& endpoint);

    // Disconnects the underlying transport.
    void disconnect() noexcept;

    // Returns true if the underlying transport is connected.
    bool isConnected() const noexcept;

private:
    std::unique_ptr<IClientTransport> transport_;
};

}  // namespace tinynet
