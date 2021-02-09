#include "Input.h"

#include <GLFW/glfw3.h>

// for the window
#include "../Platform/Platform.h"
#include "CoreEngine/Window/WindowHandler.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Core.h"

namespace CH {

	bool Input::IsKeyPressed(int keycode)
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			int state = glfwGetKey(static_cast<GLFWwindow*>(WindowHandler::GetNativeWindow()), keycode);
			return state == GLFW_PRESS || state == GLFW_REPEAT;
			break;
		}

		default:
			CH_ASSERT(false, "Invalid Window");
		}
		return false;
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

		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			glfwGetCursorPos(static_cast<GLFWwindow*>(WindowHandler::GetNativeWindow()), &xpos, &ypos);
			return { (float)xpos, (float)ypos };
			break;
		}

		default:
			CH_ASSERT(false, "Invalid Window");
		}
		return std::pair<int, int>();
	}

	bool Input::IsMouseButtonPressed(int button)
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			int state = glfwGetMouseButton(static_cast<GLFWwindow*>(WindowHandler::GetNativeWindow()), button);
			return state == GLFW_PRESS;
			break;
		}
		default:
			CH_ASSERT(false, "Invalid Window");
		}

		return false;
	}

}