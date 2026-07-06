#include "tinynet/socket.hpp"

#include <unistd.h>

namespace tinynet {

Socket::Socket(int fd) noexcept : fd_(fd) {}

Socket::~Socket() {
    close();
}

Socket::Socket(Socket&& other) noexcept : fd_(other.fd_) {
    other.fd_ = kInvalidFd;
}

Socket& Socket::operator=(Socket&& other) noexcept {
    if (this != &other) {
        close();
        fd_ = other.fd_;
        other.fd_ = kInvalidFd;
    }
    return *this;
}

void Socket::close() noexcept {
    if (isValid()) {
        ::close(fd_);
        fd_ = kInvalidFd;
    }
}

int Socket::release() noexcept {
    int fd = fd_;
    fd_ = kInvalidFd;
    return fd;
}

}  // namespace tinynet
