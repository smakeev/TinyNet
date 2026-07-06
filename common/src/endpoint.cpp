#include "tinynet/endpoint.hpp"

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

}  // namespace tinynet
