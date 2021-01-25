#pragma once

#include "CoreEngine/Core.h"

#include <GLFW/glfw3.h>

namespace CH {

	class Window
	{
	public:
		static void Init(const char* title = "Chernobyl Engine", int width = 900, int height = 600);
		static void OnUpdate();

	private:
		static void Create();
		static void SetVSync();
		static void SetEventCallbacks();

	private:
		struct WindowData
		{
			const char* Title;
			int Width;
			int Height;
		};

		static WindowData s_Data;
		static GLFWwindow* s_Window;
		static int s_IsOpen;

	public:
		static int GetWidth() { return s_Data.Width; }
		static int GetHeight() { return s_Data.Height; }
		static GLFWwindow* GetWindow() { return s_Window; }
		static bool IsOpen() 
		{
			if (s_IsOpen == 0)
				return true;
			else
				return false;
		}
	};

}