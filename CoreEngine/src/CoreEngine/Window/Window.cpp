#include "Window.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"

namespace CH {

	Window::WindowData Window::s_Data;
	GLFWwindow* Window::s_Window;
	int Window::s_IsOpen = 1;

	void Window::Init(const char* title, int width, int height)
	{
		s_Data.Height = 900;
		s_Data.Width = 600;
		s_Data.Title = title;

		CH_CORE_ASSERT(glfwInit(), "Unable to initialize glfw!");

		Create();
		SetVSync();
		SetEventCallbacks();
	}

	void Window::Create()
	{
		s_Window = glfwCreateWindow(s_Data.Height, s_Data.Width, s_Data.Title, nullptr, nullptr);
		glfwSetWindowUserPointer(s_Window, &s_Data);
		glfwMakeContextCurrent(s_Window);
	}

	void Window::SetVSync()
	{
		
	}

	void Window::SetEventCallbacks()
	{
		glfwSetWindowSizeCallback(s_Window, [](GLFWwindow* window, int width, int height)
			{
				s_Data.Width = width;
				s_Data.Height = height;
			});
		glfwSetKeyCallback(s_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				case GLFW_REPEAT:
				{
					Event::s_CurrentCategory = Event::EventCategory::KeyPressedEvent;
					Event::s_CurrentKeyPressed = key;
					break;
				}
				case GLFW_RELEASE:
				{	
					Event::s_CurrentCategory = Event::EventCategory::KeyReleasedEvent;
					Event::s_CurrentKeyReleased = key;
					break;
				}
				}
			});
		glfwSetCharCallback(s_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				Event::s_CurrentCategory = Event::EventCategory::TypeEvent;
				Event::s_CurrentKeyTyped = keycode;
			});

		glfwSetMouseButtonCallback(s_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					Event::s_CurrentCategory = Event::EventCategory::MouseClickedEvent;
					if (button == GLFW_MOUSE_BUTTON_LEFT)
						Event::s_CurrentMouseButtonClicked = Event::MouseEvent::LEFT;
					else if (button == GLFW_MOUSE_BUTTON_RIGHT)
						Event::s_CurrentMouseButtonClicked = Event::MouseEvent::RIGHT;
					else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
						Event::s_CurrentMouseButtonClicked = Event::MouseEvent::MIDDLE;
					break;
				}
				case GLFW_RELEASE:
				{
					Event::s_CurrentCategory = Event::EventCategory::MouseReleasedEvent;
					if (button == GLFW_MOUSE_BUTTON_LEFT)
						Event::s_CurrentMouseButtonReleased = Event::MouseEvent::LEFT;
					else if (button == GLFW_MOUSE_BUTTON_RIGHT)
						Event::s_CurrentMouseButtonReleased = Event::MouseEvent::RIGHT;
					else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
						Event::s_CurrentMouseButtonReleased = Event::MouseEvent::MIDDLE;
					break;
				}
				}
			});

		glfwSetScrollCallback(s_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				Event::s_CurrentCategory = Event::EventCategory::MouseScrolledEvent;
				Event::s_MouseScrollOffset.x = xOffset;
				Event::s_MouseScrollOffset.y = yOffset;
			});

		glfwSetCursorPosCallback(s_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				Event::s_CurrentCategory = Event::EventCategory::MouseMovedEvent;
				Event::s_MousePos.x = xPos;
				Event::s_MousePos.y = yPos;
			});
		glfwSetWindowCloseCallback(s_Window, [](GLFWwindow* window)
			{
				Event::s_CurrentCategory = Event::EventCategory::WindowEvent;
				Event::s_CurrentWindowEvent = Event::WindowEvent::Close;
			});
	}

	void Window::OnUpdate()
	{
		// check if the window is open
		if (Event::s_CurrentWindowEvent == Event::WindowEvent::Close)
			s_IsOpen = 1;
		else
			s_IsOpen = 0;
		
		//TODO: create vulkan swapchain and stuff
		glfwSwapBuffers(s_Window);
		glfwPollEvents();
	}

	void Window::OnDestroy()
	{
		glfwDestroyWindow(s_Window);
		glfwTerminate();
	}

}