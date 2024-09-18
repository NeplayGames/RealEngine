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

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			//glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}