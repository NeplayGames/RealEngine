#pragma once 
#include "Core.h"
#include "Window.h"
#include "Platform/WindowsWindow.h"


namespace RealEngine {
	class REALENGINE_API Application
	{
		public: 
			Application();
			~Application();
			void Run();
	private:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}
