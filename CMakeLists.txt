# Copyright Moses Turner, 2021.
# SPDX-License-Identifier: BSL-1.0
cmake_minimum_required(VERSION 3.10)

# You probably want C++17 for now
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# So that Intellisense/clangd know how your project is compiled
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
# march=native makes it use *all* optimizations/fancy instructions specific to your machine. Turn it off if you're distributing - people will get a lot of Illegal instruction (core dumped) if you don't
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -march=native -O3 -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -march=native -O3  -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(CMAKE_VERBOSE_MAKEFILE ON)

project(sk-example VERSION "0.0.1" LANGUAGES CXX C)

find_package(StereoKitC REQUIRED)


message("Found StereoKitC " ${StereoKitC_Found})

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)

if ("${FORCE_COLORED_OUTPUT}")
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		add_compile_options (-fdiagnostics-color=always)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		add_compile_options (-fcolor-diagnostics)
	endif ()
endif ()

add_executable(
  sk-example
  src/main.cpp
)

target_link_libraries(
  sk-example
  -L/usr/local/lib
  StereoKitC
)