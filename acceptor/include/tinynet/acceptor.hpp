#pragma once

#include <string_view>

namespace tinynet {

// Placeholder for the reusable incoming-connection layer.
//
// The Acceptor will later own the bind/listen/accept logic. It is deliberately
// NOT the full application server: it can be reused by the backend server and
// by mobile LAN-host mode. No networking is implemented yet; this type only
// exposes a short banner so the acceptor library and demo have something
// concrete to link against.
class Acceptor {
public:
    Acceptor() = default;

    // Returns a human-readable description of the acceptor component.
    std::string_view banner() const noexcept;
};

}  // namespace tinynet
