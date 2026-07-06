cmake_minimum_required(VERSION 3.20)

project(TinyNet
    VERSION 0.1.0
    DESCRIPTION "Lightweight C++20 POSIX socket starter for reusable client/server networking foundations"
    LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Global settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# ---------------------------------------------------------------------------
# Libraries: common + client + acceptor + server
# ---------------------------------------------------------------------------
add_library(tinynet_common
    common/src/version.cpp
    common/src/socket.cpp
    common/src/endpoint.cpp)
target_include_directories(tinynet_common PUBLIC common/include)
add_library(tinynet::common ALIAS tinynet_common)

add_library(tinynet_client
    client/src/client.cpp)
target_include_directories(tinynet_client PUBLIC client/include)
target_link_libraries(tinynet_client PUBLIC tinynet_common)
add_library(tinynet::client ALIAS tinynet_client)

# Reusable incoming-connection layer (bind/listen/accept), shared by the
# backend server and mobile LAN-host mode.
add_library(tinynet_acceptor
    acceptor/src/acceptor.cpp)
target_include_directories(tinynet_acceptor PUBLIC acceptor/include)
target_link_libraries(tinynet_acceptor PUBLIC tinynet_common)
add_library(tinynet::acceptor ALIAS tinynet_acceptor)

# Full server layer, built on top of the acceptor.
add_library(tinynet_server
    server/src/server.cpp)
target_include_directories(tinynet_server PUBLIC server/include)
target_link_libraries(tinynet_server PUBLIC tinynet_common tinynet_acceptor)
add_library(tinynet::server ALIAS tinynet_server)

# ---------------------------------------------------------------------------
# Demo executables
# ---------------------------------------------------------------------------
add_executable(tinynet_client_demo examples/client/main.cpp)
target_link_libraries(tinynet_client_demo PRIVATE tinynet::client)

add_executable(tinynet_acceptor_demo examples/acceptor/main.cpp)
target_link_libraries(tinynet_acceptor_demo PRIVATE tinynet::acceptor)

add_executable(tinynet_server_demo examples/server/main.cpp)
target_link_libraries(tinynet_server_demo PRIVATE tinynet::server)
