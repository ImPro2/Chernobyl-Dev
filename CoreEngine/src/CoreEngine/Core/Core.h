#pragma once

#include "Log/Log.h"
#include "Types.h"

#include <iostream>
#include <memory>

#ifdef CH_PLATFORM_WINDOWS

	#ifdef CH_DEBUG
		#define CH_ENABLE_ASSERTS
	#endif

	//TODO: add assertions, though first add logging
	#ifdef CH_ENABLE_ASSERTS
		#define CH_CORE_ASSERT(x, ...) if (!(x)) { CH_CORE_ERROR(__VA_ARGS__); __debugbreak(); }
		#define CH_ASSERT(x, ...) if (!(x)) { CH_ERROR(__VA_ARGS__); __debugbreak(); }
	#endif

#endif

struct Vec2
{
	float x, y;
};