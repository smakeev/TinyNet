#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include <sys/socket.h>

#include "tinynet/sock_addr.hpp"

namespace tinynet {

// Immutable value type describing a network endpoint: *where* to connect or
// bind. It carries an address string, a port and an address family, and can
// produce the matching POSIX SockAddr on demand. It performs no networking
// itself (no socket/connect/bind/listen/accept) -- it only encapsulates the
// address + port + family triple so networking code never has to pass raw
// strings and AF_INET/AF_INET6 constants (or bare sockaddr structs) around.
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

    // Builds the POSIX SockAddr for this endpoint. Parses the address string
    // with inet_pton and converts the port to network byte order. Returns
    // std::nullopt if the address string fails to parse or the family is
    // unsupported. Never throws.
    std::optional<SockAddr> toSockAddr() const noexcept;

private:
    // Private: endpoints are created through the static factory methods.
    Endpoint(std::string address, uint16_t port, int addressFamily);

    std::string address_;
    uint16_t port_;
    int addressFamily_;
};

}  // namespace tinynet
