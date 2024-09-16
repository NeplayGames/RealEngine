#include "Repch.h"
#include "Application.h"
namespace RealEngine {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(WindowsWindow::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run() {
		while (true) {
			m_Window->OnUpdate();
		}
	}
}