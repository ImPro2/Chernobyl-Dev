#pragma once

#include "CoreEngine/Renderer/Context.h"
#include "../DX11Device/DX11Device.h"

#include "../DX11DeviceContext/DX11DeviceContext.h"

namespace CH {

	// class that has a DX11Device and DX11DeviceContext that is accessed through this class.
	// OpenGL would just be glfwMakeContextCurrent((GLFWwindow*)handle); for this
	class DX11Context : public Context
	{
	public:
		bool CreateContext(void* handle) override;
		void DestroyContext() override { m_DX11_Device.Destroy(); }

		DX11Device GetDX11Device() { return m_DX11_Device; }
		DX11DeviceContext GetDX11DeviceContext() { return m_DX11_DeviceContext; }

	private:
		DX11Device m_DX11_Device;
		DX11DeviceContext m_DX11_DeviceContext;
	};

}