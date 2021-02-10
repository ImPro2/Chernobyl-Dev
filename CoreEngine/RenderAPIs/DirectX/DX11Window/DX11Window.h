#pragma once

#include "CoreEngine/Window/Window.h"

namespace CH {

	class DX11Window : public Window
	{
	public:
		// initialize and destroy the window
		virtual bool Init(DX11WindowData wndData) override;
		virtual void Destroy() override;

		// update the window
		virtual void Update() override;

		// check if the window is open
		virtual bool IsOpen() override;

		// accessors
		virtual DX11WindowData GetDX11WindowData() override;
		virtual void* GetNativeWindow() override;
		
	private:
		DX11WindowData m_WindowData;
		HWND m_hWnd;
		bool m_IsOpen = true;

	public:
		void SetHWND(HWND hWnd) { m_hWnd = hWnd; }
		void SetOpen(bool open) { m_IsOpen = open; }
		
	private:
		// not needed at all
		virtual bool Init(OpenGLWindowData wndData) override;
		virtual OpenGLWindowData GetOpenGLWindowData() override;
	};

}