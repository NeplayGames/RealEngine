#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RealEngine::Application* RealEngine::CreateApplication();

int main(int argc, char** argv) {
	RealEngine::Log::Init();
	RE_CORE_WARN("Welcome some warnings");
	RE_CORE_INFO("Welcome some warnings");
	auto app = RealEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // RE_PLATFORM_WINDOWS
