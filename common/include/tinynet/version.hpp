#pragma once

#include <string_view>

namespace tinynet {

// Semantic version of the TinyNet starter foundation.
inline constexpr int kVersionMajor = 0;
inline constexpr int kVersionMinor = 1;
inline constexpr int kVersionPatch = 0;

// Returns the TinyNet version as a "MAJOR.MINOR.PATCH" string.
std::string_view version() noexcept;

}  // namespace tinynet
