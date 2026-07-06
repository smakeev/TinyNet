#pragma once

#include <cstdint>
#include <string>

#include <sys/socket.h>

namespace tinynet {

// Immutable value type describing a network endpoint: *where* to connect or
// bind. It carries an address string, a port and an address family, but never
// performs any networking (no socket/connect/bind/listen/accept and no
// sockaddr conversion). Those responsibilities belong to future networking
// code, which can rely on Endpoint to encapsulate the address + port + family
// triple instead of passing raw strings and AF_INET/AF_INET6 constants around.
class Endpoint {
public:
    // Constructs an IPv4 endpoint (address family AF_INET).
    static Endpoint ipv4(std::string address, uint16_t port);

    // Constructs an IPv6 endpoint (address family AF_INET6).
    static Endpoint ipv6(std::string address, uint16_t port);

    // Wildcard IPv4 endpoint ("0.0.0.0"): bind on every local interface.
    static Endpoint anyIpv4(uint16_t port);

    // Wildcard IPv6 endpoint ("::"): bind on every local interface.
    static Endpoint anyIpv6(uint16_t port);

    // Loopback IPv4 endpoint ("127.0.0.1").
    static Endpoint localhostIpv4(uint16_t port);

    // Loopback IPv6 endpoint ("::1").
    static Endpoint localhostIpv6(uint16_t port);

    // Returns the address string (e.g. "127.0.0.1" or "::1").
    const std::string& address() const noexcept { return address_; }

    // Returns the port in host byte order.
    uint16_t port() const noexcept { return port_; }

    // Returns the address family, either AF_INET or AF_INET6.
    int addressFamily() const noexcept { return addressFamily_; }

private:
    // Private: endpoints are created through the static factory methods.
    Endpoint(std::string address, uint16_t port, int addressFamily);

    std::string address_;
    uint16_t port_;
    int addressFamily_;
};

}  // namespace tinynet
