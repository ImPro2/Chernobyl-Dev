#include "Input.h"

#include <GLFW/glfw3.h>

// for the window
#include "CoreEngine/Window/Window.h"

namespace CH {

	bool Input::IsKeyPressed(int keycode)
	{
		int state = glfwGetKey(Window::GetWindow(), keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	int Input::GetMousePosX()
	{
		auto [x, y] = GetMousePos();
		return x;
	}

	int Input::GetMousePosY()
	{
		auto [x, y] = GetMousePos();
		return x;
	}

	std::pair<int, int> Input::GetMousePos()
	{
		double xpos, ypos;
		glfwGetCursorPos(Window::GetWindow(), &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	bool Input::IsMouseButtonPressed(int button)
	{
		int state = glfwGetMouseButton(Window::GetWindow(), button);
		return state == GLFW_PRESS;
	}

}