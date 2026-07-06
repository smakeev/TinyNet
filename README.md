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


# Roadmap

## Phase 1 — Foundation

- ✅ 1. Initial project skeleton
- ✅ 2. Project architecture (common / client / acceptor / server)
- ✅ 3. Socket RAII wrapper
- ✅ 4. Endpoint abstraction
- ✅ 5. SocketFactory

Next:

- ⬜ 6. Endpoint → sockaddr conversion (common)
- ⬜ 7. Client transport strategy (client + common)
- ⬜ 8. Acceptor transport strategy (acceptor + common)

---

## Phase 2 — Networking

- ⬜ 9. TCP client connect / disconnect (client + common)
- ⬜ 10. TCP bind / listen (acceptor + common)
- ⬜ 11. TCP accept (acceptor + common)
- ⬜ 12. Server accept loop (server + acceptor + common)

---

## Phase 3 — Data Transport

- ⬜ 13. Send raw bytes (client + acceptor + common)
- ⬜ 14. Receive raw bytes (client + acceptor + common)
- ⬜ 15. Packet header (common)
- ⬜ 16. Packet framing (common)
- ⬜ 17. Packet parser (common)
- ⬜ 18. Command dispatcher (common)

---

## Phase 4 — Console Chat

- ⬜ 19. Single client chat (examples)
- ⬜ 20. Multi-client chat (server + client + examples)
- ⬜ 21. Broadcast (server)
- ⬜ 22. User names (server + client)
- ⬜ 23. Join / Leave notifications (server)
- ⬜ 24. Private messages (server)

---

## Phase 5 — Reliability

- ⬜ 25. Threads (server)
- ⬜ 26. Connection manager (server)
- ⬜ 27. Graceful disconnect (client + server)
- ⬜ 28. Heartbeat / Ping (common)
- ⬜ 29. Timeouts (server)
- ⬜ 30. Logging (common)

---

## Phase 6 — UDP

- ⬜ 31. UDP client transport (client + common)
- ⬜ 32. UDP acceptor transport (acceptor + common)
- ⬜ 33. UDP client/server demo (examples)
- ⬜ 34. UDP console chat (examples)
- ⬜ 35. TCP vs UDP comparison (docs + examples)

---

## Phase 7 — Production

- ⬜ 36. Unit tests (tests)
- ⬜ 37. Docker demo (docker)
- ⬜ 38. GitHub Actions (CI)
- ⬜ 39. Documentation
- ⬜ 40. Release v0.1
