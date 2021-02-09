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

		glfwSetWindowUserPointer(m_GLFW_Window, &m_WindowData);

		SetEventCallbacks();

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

	void OpenGLWindow::SetEventCallbacks()
	{
		glfwSetKeyCallback(m_GLFW_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_REPEAT:
				case GLFW_PRESS:
				{
					Event::s_CurrentKeyPressed = key;
					break;
				}
				case GLFW_RELEASE:
				{
					Event::s_CurrentKeyReleased = key;
					break;
				}
				}
			});

		glfwSetCharCallback(m_GLFW_Window, [](GLFWwindow* window, unsigned int key)
			{
				Event::s_CurrentKeyTyped = key;
			});

		glfwSetMouseButtonCallback(m_GLFW_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					if (button == CH_MOUSE_BUTTON_LEFT)	Event::s_CurrentMouseButtonClicked = Event::MouseEvent::LEFT;
					else if (button == CH_MOUSE_BUTTON_RIGHT) Event::s_CurrentMouseButtonClicked = Event::MouseEvent::RIGHT;
					else if (button == CH_MOUSE_BUTTON_MIDDLE) Event::s_CurrentMouseButtonClicked = Event::MouseEvent::MIDDLE;
					break;
				}
				case GLFW_RELEASE:
				{
					if (button == CH_MOUSE_BUTTON_LEFT)	Event::s_CurrentMouseButtonReleased = Event::MouseEvent::LEFT;
					else if (button == CH_MOUSE_BUTTON_RIGHT) Event::s_CurrentMouseButtonReleased = Event::MouseEvent::RIGHT;
					else if (button == CH_MOUSE_BUTTON_MIDDLE) Event::s_CurrentMouseButtonReleased = Event::MouseEvent::MIDDLE;
					break;				
				}
				}
			});
	
		glfwSetCursorPosCallback(m_GLFW_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				Event::s_MousePos.x = static_cast<float>(xpos);
				Event::s_MousePos.y = static_cast<float>(ypos);
			});
	
		glfwSetScrollCallback(m_GLFW_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				Event::s_MouseScrollOffset.x = xoffset;
				Event::s_MouseScrollOffset.y = yoffset;
			});
	
		glfwSetWindowSizeCallback(m_GLFW_Window, [](GLFWwindow* window, int width, int height)
			{
				OpenGLWindowData& wndData = *(OpenGLWindowData*)glfwGetWindowUserPointer(window);

				wndData.Width = width;
				wndData.Height = height;
			});
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