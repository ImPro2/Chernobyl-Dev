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

		static void DisplayInfo();

	private:
		// functions creating windows to dedicated platforms
		static void CreateOpenGLWindow();
		static void CreateDX11Window();

	public:
		// accessors
		static void* GetWindowData();
		static uint32_t GetWidth();
		static uint32_t GetHeight();
		static std::string GetTitle();
		static bool IsVSync();

		// setters
		static void SetWindowData(Window::DX11WindowData data);
		static void SetWindowData(Window::OpenGLWindowData data);
		static void SetWidth(uint32_t width);
		static void SetHeight(uint32_t height);
		static void SetTitle(const char* title);
		static void SetTitle(const wchar_t* title);
		static void SetVSync(bool enabled);
		static Window::OpenGLWindowData GetOpenGLWindowData();
		static Window::DX11WindowData GetDX11WindowData();

	private:
		static Window* m_Window;
	};

}