#pragma once

#include <string_view>

namespace tinynet {

// Placeholder for the upcoming TinyNet TCP server.
//
// No networking is implemented yet; this type only exposes a short banner so
// the server library and demos have something concrete to link against.
class Server {
public:
    Server() = default;

    // Returns a human-readable description of the server component.
    std::string_view banner() const noexcept;
};

}  // namespace tinynet
