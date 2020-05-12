#include "ocpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Oculum
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%H:%M:%S:%e] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("OCULUM");
		coreLogger->set_level(spdlog::level::trace);
		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
		OC_CORE_INFO("Logger Initialised");
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return coreLogger;
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return clientLogger;
	}
}