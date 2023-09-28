#pragma once
#include <spdlog/spdlog.h>
#define DEBUG_MODE 1

#define INFO(...) spdlog::info(__VA_ARGS__)
#define DEBUG(...) if (DEBUG_MODE) {spdlog::info(__VA_ARGS__);} else {}
#define ERROR(...) spdlog::error(__VA_ARGS__)
#define CRIT(...) spdlog::critical(__VA_ARGS__)


#if DEBUG_MODE 
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define ASSERT(a) if (!(a)) {spdlog::critical("Assertion failed: {}.  {}:{}", #a, __FILENAME__, __LINE__);}
#else
#define ASSERT(a) // None-debug mode does not check for assertion.
#endif

#define NOT_REACHEABLE() ASSERT("This line shouldn't be reacheable." == NULL)