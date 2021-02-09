#pragma once

#include "Window.h"

namespace CH {

	// wrapper class for the window class that handles different types of window creations etc. like OpenGLWindow, DX11Window, etc.
	class WindowHandler
	{
	public:
		static void CreateWindowNativeToPlatform();
		static void UpdateWindow();
		static void DestroyWindow();
		static bool GetWindowRunState();
		static void* GetNativeWindow();

	private:
		// functions creating windows to dedicated platforms
		static void CreateOpenGLWindow();
		static void CreateDX11Window();

	private:
		static Window* m_Window;
	};

}