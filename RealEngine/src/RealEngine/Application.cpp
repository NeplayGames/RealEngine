#include "Repch.h"
#include "Application.h"
namespace RealEngine {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(WindowsWindow::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}
	Application::~Application()
	{
	}
	void Application::Run() {

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		RE_CORE_INFO("{0}", e.ToString());
	}
}