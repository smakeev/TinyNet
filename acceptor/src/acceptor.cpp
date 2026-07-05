#include "tinynet/acceptor.hpp"

namespace tinynet {

std::string_view Acceptor::banner() const noexcept {
    return "TinyNet acceptor (incoming-connection layer, no networking yet)";
}

}  // namespace tinynet
