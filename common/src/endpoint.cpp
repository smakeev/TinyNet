#include "tinynet/endpoint.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>

#include <utility>

namespace tinynet {

Endpoint::Endpoint(std::string address, uint16_t port, int addressFamily)
    : address_(std::move(address)), port_(port), addressFamily_(addressFamily) {}

Endpoint Endpoint::ipv4(std::string address, uint16_t port) {
    return Endpoint(std::move(address), port, AF_INET);
}

Endpoint Endpoint::ipv6(std::string address, uint16_t port) {
    return Endpoint(std::move(address), port, AF_INET6);
}

Endpoint Endpoint::anyIpv4(uint16_t port) {
    return ipv4("0.0.0.0", port);
}

Endpoint Endpoint::anyIpv6(uint16_t port) {
    return ipv6("::", port);
}

Endpoint Endpoint::localhostIpv4(uint16_t port) {
    return ipv4("127.0.0.1", port);
}

Endpoint Endpoint::localhostIpv6(uint16_t port) {
    return ipv6("::1", port);
}

std::optional<SockAddr> Endpoint::toSockAddr() const noexcept {
    switch (addressFamily_) {
        case AF_INET: {
            sockaddr_in addr{};
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port_);
            if (::inet_pton(AF_INET, address_.c_str(), &addr.sin_addr) != 1) {
                return std::nullopt;
            }
            return SockAddr(addr);
        }
        case AF_INET6: {
            sockaddr_in6 addr{};
            addr.sin6_family = AF_INET6;
            addr.sin6_port = htons(port_);
            if (::inet_pton(AF_INET6, address_.c_str(), &addr.sin6_addr) != 1) {
                return std::nullopt;
            }
            return SockAddr(addr);
        }
        default:
            return std::nullopt;
    }
}

}  // namespace tinynet
