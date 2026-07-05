#include "tinynet/client.hpp"

namespace tinynet {

std::string_view Client::banner() const noexcept {
    return "TinyNet client (skeleton, no networking yet)";
}

}  // namespace tinynet
