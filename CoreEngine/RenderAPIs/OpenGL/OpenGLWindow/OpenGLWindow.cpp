#include "OpenGLWindow.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"
#include "CoreEngine/Core.h"

namespace CH {

	bool OpenGLWindow::Init(OpenGLWindowData wndData)
	{
		m_WindowData = wndData;

		if (!glfwInit())
			return false;

		m_GLFW_Window = glfwCreateWindow(m_WindowData.Width, m_WindowData.Height, m_WindowData.Title, nullptr, nullptr);

		if (!m_GLFW_Window)
			return false;

		glfwMakeContextCurrent(m_GLFW_Window);

		return true;
	}

	void OpenGLWindow::Destroy()
	{
		glfwDestroyWindow(m_GLFW_Window);
		glfwTerminate();
	}

	void OpenGLWindow::Update()
	{
		glfwSwapBuffers(m_GLFW_Window);
		glfwPollEvents();
	}

	bool OpenGLWindow::IsOpen()
	{
		return !glfwWindowShouldClose(m_GLFW_Window);
	}

	OpenGLWindow::OpenGLWindowData OpenGLWindow::GetOpenGLWindowData()
	{
		return m_WindowData;
	}

	bool OpenGLWindow::Init(DX11WindowData wndData)
	{
		return false;
	}

	Window::DX11WindowData OpenGLWindow::GetDX11WindowData()
	{
		return DX11WindowData();
	}

}