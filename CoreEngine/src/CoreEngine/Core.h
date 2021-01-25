#pragma once

#include <iostream>
#include <memory>

#ifdef CH_PLATFORM_WINDOWS

	#ifdef CH_DEBUG
		#define CH_ENABLE_ASSERTS
	#endif

	//TODO: add assertions, though first add logging
	#ifdef CH_ENABLE_ASSERTS
	//	#define CH_ASSERT(x, ...) if (!(x)) { CH_LOG_INFO(__VA_ARGS__); }
	//	#define CH_CORE_ASSERT(x, ...) if (!(x)) { CH_CORE_LOG_INFO(__VA_ARGS__); }
	#endif

#endif