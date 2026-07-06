#include "tinynet/socket_factory.hpp"

#include <sys/socket.h>

namespace tinynet {

Socket SocketFactory::createTcp(const Endpoint& endpoint) noexcept {
    return Socket(::socket(endpoint.addressFamily(), SOCK_STREAM, 0));
}

Socket SocketFactory::createUdp(const Endpoint& endpoint) noexcept {
    return Socket(::socket(endpoint.addressFamily(), SOCK_DGRAM, 0));
}

}  // namespace tinynet
