#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>

#ifndef OC_DIST

#define OC_CORE_TRACE(...) ::Oculum::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OC_CORE_WARN(...) ::Oculum::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OC_CORE_INFO(...) ::Oculum::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OC_CORE_ERROR(...) ::Oculum::Log::GetCoreLogger()->error(__VA_ARGS__)

#define OC_TRACE(...) ::Oculum::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OC_WARN(...) ::Oculum::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OC_INFO(...) ::Oculum::Log::GetClientLogger()->info(__VA_ARGS__)
#define OC_ERROR(...) ::Oculum::Log::GetClientLogger()->error(__VA_ARGS__)

#else

#define OC_CORE_TRACE
#define OC_CORE_WARN
#define OC_CORE_INFO
#define OC_CORE_ERROR

#define OC_TRACE
#define OC_WARN
#define OC_INFO
#define OC_ERROR

#endif

namespace Oculum
{
	class OC_API Log
	{
	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger();
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}