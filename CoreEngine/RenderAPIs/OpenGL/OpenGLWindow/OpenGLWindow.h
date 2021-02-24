#pragma once
#include "CoreEngine/Window/Window.h"

#include <GLFW/glfw3.h>

namespace CH {

	class OpenGLWindow : public Window
	{
	public:
		
		bool Init(OpenGLWindowData wndData) override;
		void Destroy() override;
		void Update() override;
		bool IsOpen() override;

		// accesors
		void* GetNativeWindow() override { return m_GLFW_Window; }
		OpenGLWindowData GetOpenGLWindowData() override;

		void SetOpenGLWindowData(OpenGLWindowData data) override { m_WindowData = data; }

	private:
		void SetEventCallbacks();

		GLFWwindow* m_GLFW_Window;
		OpenGLWindowData m_WindowData;

		// needs to inherit or else doesnt work
		virtual bool Init(DX11WindowData wndData) override;
		virtual DX11WindowData GetDX11WindowData() override;
		virtual void SetDX11WindowData(DX11WindowData data) override {}
	};

}