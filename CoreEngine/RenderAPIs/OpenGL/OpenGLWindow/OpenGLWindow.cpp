#include "OpenGLWindow.h"

#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Events/EventHandler.h"
#include "CoreEngine/Core/Core.h"

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
		glfwSetWindowPosCallback(m_GLFW_Window, [](GLFWwindow* window, int xpos, int ypos)
			{
				Event* e = new Event(Event::EventTypes::WindowMove);
				EventHandler::AddEvent(e);
			});

		glfwSetWindowCloseCallback(m_GLFW_Window, [](GLFWwindow* window)
			{
				Event* e = new Event(Event::EventTypes::WindowClose);
				EventHandler::AddEvent(e);
			});

		glfwSetKeyCallback(m_GLFW_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_REPEAT:
				case GLFW_PRESS:
				{
					Event* e = new Event(Event::EventTypes::KeyPressed);
					e->KeyPressed = key;
					EventHandler::AddEvent(e);
				}
				case GLFW_RELEASE:
				{
					Event* e = new Event(Event::EventTypes::KeyReleased);
					e->KeyReleased = key;
					EventHandler::AddEvent(e);
				}
				}
			});

		glfwSetCharCallback(m_GLFW_Window, [](GLFWwindow* window, unsigned int key)
			{
				Event* e = new Event(Event::EventTypes::KeyTyped);
				e->KeyTyped = key;
				EventHandler::AddEvent(e);
			});

		glfwSetMouseButtonCallback(m_GLFW_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					if (button == CH_MOUSE_BUTTON_LEFT)
					{
						Event* e = new Event(Event::EventTypes::LButtonClicked);
						EventHandler::AddEvent(e);
					}
					else if (button == CH_MOUSE_BUTTON_RIGHT)
					{
						Event* e = new Event(Event::EventTypes::RButtonClicked);
						EventHandler::AddEvent(e);
					}
					else if (button == CH_MOUSE_BUTTON_MIDDLE)
					{
						Event* e = new Event(Event::EventTypes::MButtonClicked);
						EventHandler::AddEvent(e);
					}
				}
				case GLFW_RELEASE:
				{
					if (button == CH_MOUSE_BUTTON_LEFT)
					{
						Event* e = new Event(Event::EventTypes::LButtonReleased);
						EventHandler::AddEvent(e);
					}
					else if (button == CH_MOUSE_BUTTON_RIGHT)
					{
						Event* e = new Event(Event::EventTypes::RButtonReleased);
						EventHandler::AddEvent(e);
					}
					else if (button == CH_MOUSE_BUTTON_MIDDLE)
					{
						Event* e = new Event(Event::EventTypes::MButtonReleased);
						EventHandler::AddEvent(e);
					}
				}
				}
			});
	
		glfwSetCursorPosCallback(m_GLFW_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				Event* e = new Event(Event::EventTypes::MouseMoved);
				e->MousePos.x = xpos;
				e->MousePos.y = ypos;
				EventHandler::AddEvent(e);
			});
	
		glfwSetScrollCallback(m_GLFW_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				Event* e = new Event(Event::EventTypes::MouseScrolled);
				e->MouseScrollOffset = yoffset;
				EventHandler::AddEvent(e);
			});
	
		glfwSetWindowSizeCallback(m_GLFW_Window, [](GLFWwindow* window, int width, int height)
			{
				OpenGLWindowData& wndData = *(OpenGLWindowData*)glfwGetWindowUserPointer(window);

				wndData.Width = width;
				wndData.Height = height;

				Event* e = new Event(Event::EventTypes::WindowResize);
				EventHandler::AddEvent(e);
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