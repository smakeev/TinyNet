# TinyNet

TinyNet is a lightweight C++20 POSIX socket starter for building reusable
client/server networking foundations.

It is a clean starter/template repository for experimenting with a minimal
POSIX-based C++ server/client foundation. Real projects are expected to copy
the parts they need out of TinyNet rather than depend on it directly.

## Current status

**Initial project skeleton.** The repository provides the directory layout,
the CMake/Xcode build setup, placeholder libraries, and two console demos.
There is no real networking implementation yet.

## Planned starter features

- TCP server
- TCP client
- Packet framing
- Command dispatcher
- Connection state machine
- Console demos
- Docker demo

## Project layout

```
TinyNet/
├── common/     # shared low-level primitives
├── client/     # outgoing connections
├── acceptor/   # reusable incoming connection layer (backend + LAN-host mode)
├── server/     # full server layer built on acceptor
├── examples/   # console demos (client + acceptor + server)
├── tests/      # unit / integration tests
├── docker/     # Docker demo assets
├── docs/       # documentation
└── .github/    # CI workflows
```

## Planned architecture

- **common** — shared low-level primitives.
- **client** — outgoing connections.
- **acceptor** — reusable incoming connection layer for backend and LAN-host
  mode. It owns bind/listen/accept and is intentionally not the full server, so
  it can be reused wherever incoming connections are needed.
- **server** — full server layer built on top of `acceptor`.

## Building

TinyNet uses CMake (C++20). The `Makefile` is a thin convenience wrapper.

### Generate an Xcode project (macOS)

```sh
make mac
```

This removes any previous `build/mac` output and regenerates the Xcode project
with the CMake Xcode generator. It does not build the project. Open it with:

```sh
open build/mac/TinyNet.xcodeproj
```

### Build manually

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

This produces three demo executables:

- `tinynet_client_demo` (from `examples/client/main.cpp`)
- `tinynet_acceptor_demo` (from `examples/acceptor/main.cpp`)
- `tinynet_server_demo` (from `examples/server/main.cpp`)

## License

[MIT](LICENSE)
