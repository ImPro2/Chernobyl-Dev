#pragma once

#include "CoreEngine/Core/Core.h"

#ifdef CH_PLATFORM_WINDOWS
#include <Windows.h>
#endif

namespace CH {

	// interface representing a window on a desktop system
	class Window
	{
	public:
		struct OpenGLWindowData
		{
			const char* Title;
			int Width;
			int Height;
			bool isVsync;
		};

		struct DX11WindowData
		{
			const wchar_t* Title;
			UINT Width;
			UINT Height;
			bool isVsync;
		};

		enum class WindowType
		{
			OPENGL_WINDOW,
			DX11_WINDOW
		};

	protected:
		virtual bool Init(OpenGLWindowData wndData) = 0;
		virtual bool Init(DX11WindowData wndData) = 0;
		virtual void Destroy() = 0;
		virtual void Update() = 0;
		virtual bool IsOpen() = 0;
		virtual OpenGLWindowData GetOpenGLWindowData() = 0;
		virtual DX11WindowData GetDX11WindowData() = 0;
		virtual void SetOpenGLWindowData(OpenGLWindowData data) = 0;
		virtual void SetDX11WindowData(DX11WindowData data) = 0;
		virtual void* GetNativeWindow() = 0;
	};
}