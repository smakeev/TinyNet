#pragma once

#include <netinet/in.h>
#include <sys/socket.h>

namespace tinynet {

// Owns an already-built POSIX socket address (IPv4 or IPv6).
//
// SockAddr keeps the raw sockaddr in a safely-sized buffer and exposes only
// the pointer and length that POSIX calls such as ::connect and ::bind need.
// This lets higher-level code work with a single opaque address type instead
// of juggling sockaddr_in / sockaddr_in6 directly. It is a plain value type:
// copyable and movable, and it performs no networking.
class SockAddr {
public:
    // Builds a SockAddr from a filled-in IPv4 sockaddr_in.
    explicit SockAddr(const sockaddr_in& addr) noexcept;

    // Builds a SockAddr from a filled-in IPv6 sockaddr_in6.
    explicit SockAddr(const sockaddr_in6& addr) noexcept;

    // Raw pointer to the stored sockaddr, suitable for POSIX socket calls.
    const sockaddr* data() const noexcept;

    // Length in bytes of the stored sockaddr.
    socklen_t size() const noexcept { return size_; }

    // Address family of the stored sockaddr (AF_INET or AF_INET6).
    int addressFamily() const noexcept;

private:
    // Large enough for any supported family; zero-initialised.
    sockaddr_storage storage_{};
    socklen_t size_ = 0;
};

}  // namespace tinynet
