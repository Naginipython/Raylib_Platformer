#pragma once
#include <iostream>
#include <cassert>

constexpr int WORLD_WIDTH = 320;
constexpr int WORLD_HEIGHT = 180;
constexpr int TILESIZE = 8;
constexpr int ZOOM = 4;

#define println(x) std::cout << x << std::endl
#define TRACE(x) println("\x1b[32mTRACE: " << x << "\x1b[0m");
#define WARN(x) println("\x1b[33mWARNING: " << x << "\x1b[0m");
#define ERROR(x) println("\x1b[31mERROR: " << x << "\x1b[0m");
#define ASSERT(x, msg) if (!(x)) { ERROR(msg); assert(false); }