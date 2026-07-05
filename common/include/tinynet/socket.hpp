#pragma once

namespace tinynet {

class Socket {
public:
    // Sentinel value for an invalid (unowned) file descriptor.
    static constexpr int kInvalidFd = -1;

    // Constructs an invalid socket (no fd owned).
    Socket() noexcept = default;

    // Takes ownership of an existing file descriptor.
    explicit Socket(int fd) noexcept;

    // Closes the owned fd, if any.
    ~Socket();

    // Move-only.
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    Socket(Socket&& other) noexcept;
    Socket& operator=(Socket&& other) noexcept;

    // Returns the owned file descriptor (or kInvalidFd if none).
    int nativeHandle() const noexcept { return fd_; }

    // Returns true if this Socket owns a valid fd.
    bool isValid() const noexcept { return fd_ >= 0; }

    // Closes the owned fd (if valid) and resets to invalid.
    void close() noexcept;

    // Relinquishes ownership without closing; returns the fd.
    int release() noexcept;

    // Creates an AF_INET / SOCK_STREAM (TCP) socket.
    // Returns an invalid Socket on failure.
    static Socket createTcp() noexcept;

    // Creates an AF_INET / SOCK_DGRAM (UDP) socket.
    // Returns an invalid Socket on failure.
    static Socket createUdp() noexcept;

private:
    int fd_ = kInvalidFd;
};

}  // namespace tinynet
