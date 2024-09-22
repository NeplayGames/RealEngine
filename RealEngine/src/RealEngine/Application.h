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
			void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}
