#include "WindowCreation.h"
#include "../Platform/Platform.h"

#include "../Log/Log.h"
#include "../RenderAPIs/OpenGL/OpenGLWindow/OpenGLWindow.h"
#include "../RenderAPIs/DirectX/DX11Window.h"


namespace CH {

	void* WindowCreation::m_Window = nullptr;

	void WindowCreation::CreateWindowNativeToPlatform()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
			CreateDX11Window();
			break;
		case Platforms::MACOS:
			CreateOpenGLWindow();
			break;
		}
	}

	void WindowCreation::UpdateWindow()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
			static_cast<DX11Window*>(m_Window)->Update();
		case Platforms::MACOS:
			static_cast<OpenGLWindow*>(m_Window)->Update();
			break;
		}
	}

	void WindowCreation::DestroyWindow()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
			static_cast<DX11Window*>(m_Window)->Destroy();
			break;
			break;
		case Platforms::MACOS:
			static_cast<OpenGLWindow*>(m_Window)->Destroy();
			break;
		}
	}

	bool WindowCreation::GetWindowRunState()
	{
		bool result;
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			result = static_cast<DX11Window*>(m_Window)->IsOpen();
			return result;
		}
		case Platforms::MACOS:
		{
			result = static_cast<OpenGLWindow*>(m_Window)->IsOpen();
			return result;
		}
		}
		CH_ASSERT(false, "Invalid window");
		return false;
	}

	void* WindowCreation::GetNativeWindow()
	{
		void* wnd = nullptr;
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			wnd = static_cast<DX11Window*>(m_Window)->GetNativeWindow();
			break;
		}
		case Platforms::MACOS:
		{
			wnd = static_cast<OpenGLWindow*>(m_Window)->GetNativeWindow();
			break;
		}
		}
		return wnd;
	}

	void WindowCreation::CreateOpenGLWindow()
	{
		
		m_Window = new OpenGLWindow();

		Window::OpenGLWindowData data;
		data.Width = 800;
		data.Height = 600;
		data.Title = "Chernobyl Engine";
		data.isVsync = false;
		
		CH_ASSERT(static_cast<OpenGLWindow*>(m_Window)->Init(data), "Failed to create OpenGLWindow");
		CH_INFO("Successfully created OpenGLWindow: Width: {0}, Height: {1}, Title: {2}, VSync: {3}", data.Width, data.Height, data.Title, data.isVsync);
	}

	void WindowCreation::CreateDX11Window()
	{
		m_Window = new DX11Window();

		Window::DX11WindowData data;
		data.Width = 800;
		data.Height = 600;
		data.Title = L"Chernobyl Engine";
		data.isVsync = false;

		CH_ASSERT(static_cast<DX11Window*>(m_Window)->Init(data), "Failed to create DX11Window");
		CH_INFO("Successfully created DX11Window: Width: {0}, Height: {1}, Title: {2}, VSync: {3}", data.Width, data.Height, data.Title, data.isVsync);
	}

}