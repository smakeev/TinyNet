#include "tinynet/sock_addr.hpp"

#include <cstring>

namespace tinynet {

SockAddr::SockAddr(const sockaddr_in& addr) noexcept {
    std::memcpy(&storage_, &addr, sizeof(addr));
    size_ = sizeof(addr);
}

SockAddr::SockAddr(const sockaddr_in6& addr) noexcept {
    std::memcpy(&storage_, &addr, sizeof(addr));
    size_ = sizeof(addr);
}

const sockaddr* SockAddr::data() const noexcept {
    return reinterpret_cast<const sockaddr*>(&storage_);
}

int SockAddr::addressFamily() const noexcept {
    return storage_.ss_family;
}

}  // namespace tinynet
