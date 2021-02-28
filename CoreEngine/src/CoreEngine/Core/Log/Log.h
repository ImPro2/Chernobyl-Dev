#pragma once

#include "CoreEngine/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace CH {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define CH_CORE_INFO(...) CH::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CH_CORE_WARN(...) CH::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CH_CORE_ERROR(...) CH::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CH_CORE_FATAL(...) CH::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CH_INFO(...) CH::Log::GetClientLogger()->info(__VA_ARGS__)
#define CH_WARN(...) CH::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CH_ERROR(...) CH::Log::GetClientLogger()->error(__VA_ARGS__)
#define CH_FATAL(...) CH::Log::GetClientLogger()->fatal(__VA_ARGS__)