#pragma once

#include <string_view>

namespace tinynet {

// Placeholder for the upcoming TinyNet TCP client.
//
// No networking is implemented yet; this type only exposes a short banner so
// the client library and demos have something concrete to link against.
// Client-specific connect/disconnect logic will be added later, on top of the
// sockets produced by common's SocketFactory.
class Client {
public:
    Client() = default;

    // Returns a human-readable description of the client component.
    std::string_view banner() const noexcept;
};

}  // namespace tinynet
