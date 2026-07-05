# TinyNet developer convenience Makefile.
#
# This is a thin wrapper around CMake. The real build system is CMakeLists.txt.

MAC_BUILD_DIR := build/mac

.PHONY: mac
# Fully regenerate the Xcode project/workspace from scratch (no build step).
mac:
	rm -rf $(MAC_BUILD_DIR)
	cmake -S . -B $(MAC_BUILD_DIR) -G Xcode -DCMAKE_BUILD_TYPE=Debug
	@echo ""
	@echo "Xcode project generated at $(MAC_BUILD_DIR)/TinyNet.xcodeproj"
	@echo "Open it with: open $(MAC_BUILD_DIR)/TinyNet.xcodeproj"
