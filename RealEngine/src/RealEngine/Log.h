#include "Core.h"
#include "spdlog/spdlog.h"
#pragma once
namespace RealEngine {
	class REALENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core log macros 
#define RE_CORE_TRACE(...) :: RealEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_CORE_INFO(...) :: RealEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...) :: RealEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...) :: RealEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_FATAL(...) :: RealEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Cline log macros 
#define RE_TRACE(...) :: RealEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_INFO(...) :: RealEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_WARN(...) :: RealEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...) :: RealEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_FATAL(...) :: RealEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)