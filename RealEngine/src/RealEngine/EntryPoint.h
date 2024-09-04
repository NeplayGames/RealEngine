#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RealEngine::Application* RealEngine::CreateApplication();

int main(int argc, char** argv) {
	RealEngine::Log::Init();
	RealEngine::Log::GetCoreLogger()->warn("Welcome some warnings");
	RealEngine::Log::GetClientLogger()->info("Welcome some warnings");
	auto app = RealEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // RE_PLATFORM_WINDOWS
