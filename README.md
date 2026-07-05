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

## Developer setup

After cloning, enable the shared git hooks once:

```sh
make hooks
```

This points `core.hooksPath` at the tracked `.githooks/` directory. The
`prepare-commit-msg` hook then prepends area tags to each commit message based
on which top-level folders are staged: `[Common]`, `[Client]`, `[Acceptor]`,
`[Server]`, and `[Base]` (root and everything outside the lib folders). For
example, staging a change under `common/` and a root file yields
`[Common] [Base] your message`.

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


PLAN:
TinyNet Roadmap

* ✅ 1. Initial project skeleton
* ✅ 2. Split architecture: common / client / acceptor / server
* ✅ 3. Socket RAII wrapper

⸻

* ⬜ 4. Endpoint
* ⬜ 5. TCP Transport Strategy
* ⬜ 6. Transport Factory
* ⬜ 7. Client: TCP connect / disconnect
* ⬜ 8. Acceptor: bind / listen
* ⬜ 9. Acceptor: accept one client
* ⬜ 10. Server skeleton: accept loop

⸻

* ⬜ 11. Send raw bytes
* ⬜ 12. Receive raw bytes
* ⬜ 13. Packet header
* ⬜ 14. Packet framing
* ⬜ 15. Packet parser
* ⬜ 16. Command enum
* ⬜ 17. Command dispatcher

⸻

* ⬜ 18. Console chat: single client
* ⬜ 19. Console chat: multiple clients
* ⬜ 20. Broadcast
* ⬜ 21. User names
* ⬜ 22. Join / Leave notifications
* ⬜ 23. Private messages

⸻

* ⬜ 24. Threads
* ⬜ 25. Connection manager
* ⬜ 26. Graceful disconnect
* ⬜ 27. Heartbeat / Ping
* ⬜ 28. Timeouts
* ⬜ 29. Logging

⸻

* ⬜ 30. UDP Transport Strategy
* ⬜ 31. UDP client demo
* ⬜ 32. UDP acceptor/server demo
* ⬜ 33. UDP console chat
* ⬜ 34. TCP vs UDP comparison

⸻

* ⬜ 35. Unit tests
* ⬜ 36. Docker demo
* ⬜ 37. GitHub Actions CI
* ⬜ 38. README polish for C++ vacancies
* ⬜ 39. Architecture docs
* ⬜ 40. Final cleanup / tags / release
