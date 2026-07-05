#include "tinynet/server.hpp"

namespace tinynet {

std::string_view Server::banner() const noexcept {
    return "TinyNet server (skeleton, no networking yet)";
}

}  // namespace tinynet
