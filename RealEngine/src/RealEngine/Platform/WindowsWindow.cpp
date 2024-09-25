#include "Repch.h"
#include "RealEngine/Platform/WindowsWindow.h"
#include <RealEngine/Events/KeyEvent.h>
#include "../../../WIndowsEvent.h"


namespace RealEngine {

	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		RE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		RE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (s_GLFWWindowCount == 0)
		{
			int success = glfwInit();
			RE_CORE_INFO(success);
			s_GLFWWindowCount = 1;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
		SetGLFWCallBacks(m_Window);
	}

	void WindowsWindow::SetGLFWCallBacks(GLFWwindow* window) {
			glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
				WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*) glfwGetWindowUserPointer(window);
				WindowResizedEvent windowResizedEvent(width, height);
				data.EventCallback(windowResizedEvent);
			});
	}
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props); 
	}
}