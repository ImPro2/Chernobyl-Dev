#include "chpch.h"
#include "WindowHandler.h"
#include "../Platform/Platform.h"

#include "CoreEngine/Core/Log/Log.h"
#include "../RenderAPIs/OpenGL/OpenGLWindow/OpenGLWindow.h"
#include "../RenderAPIs/DirectX/DX11Window/DX11Window.h"

#include <locale>
#include <string>
#include <sstream>

namespace CH {

	Window* WindowHandler::m_Window = nullptr;

	void WindowHandler::CreateWindowNativeToPlatform()
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

	void WindowHandler::UpdateWindow()
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

	void WindowHandler::DestroyWindow()
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

	bool WindowHandler::GetWindowRunState()
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

	void* WindowHandler::GetNativeWindow()
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

	void WindowHandler::DisplayInfo()
	{
		CH_INFO("Window Info | Width: {0}, Height: {1}, Title: {2}, VSync: {3}", GetWidth(), GetHeight(), GetTitle(), IsVSync());
	}

	void WindowHandler::CreateOpenGLWindow()
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

	void WindowHandler::CreateDX11Window()
	{
		m_Window = new DX11Window();

		Window::DX11WindowData data;
		data.Width = 800;
		data.Height = 600;
		data.Title = L"Chernobyl Engine";
		data.isVsync = false;

		CH_ASSERT(static_cast<DX11Window*>(m_Window)->Init(data), "Failed to create DX11Window");
		CH_INFO("Successfully created DX11Window: Width: {0}, Height: {1}, Title: {2}, VSync: {3}", GetWidth(), GetHeight(), GetTitle(), IsVSync());
	}

	void* WindowHandler::GetWindowData()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			auto data = GetDX11WindowData();
			return &data;
		}
		case Platforms::MACOS:
		{
			auto data = GetOpenGLWindowData();
			return &data;
		}
		}
		CH_ASSERT(false, "Invalid platform!");
		return nullptr;
	}

	uint32_t WindowHandler::GetWidth()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData* data = (Window::DX11WindowData*)GetWindowData();

			return data->Width;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData* data = (Window::OpenGLWindowData*)GetWindowData();

			return data->Width;
		}
		}
		CH_ASSERT(false, "Invalid platform!");
		return NULL;
	}

	uint32_t WindowHandler::GetHeight()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData* data = (Window::DX11WindowData*)GetWindowData();

			return data->Height;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData* data = (Window::OpenGLWindowData*)GetWindowData();

			return data->Height;
		}
		}
		CH_ASSERT(false, "Invalid platform!");
		return NULL;
	}

	//
	//	random code from internet i dont understand that converts const wchar_t* to const char*
	//

	std::string* narrow(const std::wstring& str, std::string& incomingString)
	{
		std::ostringstream stm;
		const std::ctype<char>& ctfacet =
			std::use_facet< std::ctype<char> >(stm.getloc());

		for (size_t i = 0; i < str.size(); ++i)
			stm << ctfacet.narrow(str[i], 0);

		incomingString = stm.str();

		return &incomingString;
	}

	std::string WindowHandler::GetTitle()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData* data = (Window::DX11WindowData*)GetWindowData();

			const std::wstring wchar = data->Title;
			std::string shortStr;
			std::string* str = narrow(wchar, shortStr);
			const char* title = str->c_str();

			return *str;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData* data = (Window::OpenGLWindowData*)GetWindowData();

			return (std::string)data->Title;
		}
		}
		CH_ASSERT(false, "Invalid platform!");
		return NULL;
	}

	bool WindowHandler::IsVSync()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData* data = (Window::DX11WindowData*)GetWindowData();

			return data->isVsync;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData* data = (Window::OpenGLWindowData*)GetWindowData();

			return data->isVsync;
		}
		}
		CH_ASSERT(false, "Invalid platform!");
		return NULL;
	}

	void WindowHandler::SetWindowData(Window::DX11WindowData data)
	{
		static_cast<DX11Window*>(m_Window)->SetDX11WindowData(data);
	}

	void WindowHandler::SetWindowData(Window::OpenGLWindowData data)
	{
		static_cast<OpenGLWindow*>(m_Window)->SetOpenGLWindowData(data);
	}

	void WindowHandler::SetWidth(uint32_t width)
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData data = GetDX11WindowData();

			data.Width = width;

			SetWindowData(data);
			break;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData data = GetOpenGLWindowData();

			data.Width = width;

			SetWindowData(data);
			break;
		}
		}
	}

	void WindowHandler::SetHeight(uint32_t height)
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData data = GetDX11WindowData();

			data.Height = height;

			SetWindowData(data);
			break;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData data = GetOpenGLWindowData();

			data.Height = height;

			SetWindowData(data);
			break;
		}
		}
	}

	void WindowHandler::SetTitle(const char* title)
	{
		Window::OpenGLWindowData data = GetOpenGLWindowData();

		data.Title = title;

		SetWindowData(data);
	}

	void WindowHandler::SetTitle(const wchar_t* title)
	{
		Window::DX11WindowData data = GetDX11WindowData();

		data.Title = title;

		SetWindowData(data);
	}

	void WindowHandler::SetVSync(bool enabled)
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			Window::DX11WindowData data = GetDX11WindowData();

			data.isVsync = enabled;

			SetWindowData(data);
			break;
		}
		case Platforms::MACOS:
		{
			Window::OpenGLWindowData data = GetOpenGLWindowData();

			data.isVsync = enabled;

			SetWindowData(data);
			break;
		}
		}
	}

	Window::OpenGLWindowData WindowHandler::GetOpenGLWindowData()
	{
		return static_cast<OpenGLWindow*>(m_Window)->GetOpenGLWindowData();
	}

	Window::DX11WindowData WindowHandler::GetDX11WindowData()
	{
		DX11Window* window = static_cast<DX11Window*>(m_Window);
		
		return window->GetDX11WindowData();
	}

}