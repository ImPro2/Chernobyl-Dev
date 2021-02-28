#include "chpch.h"
#include "DX11RendererAPI.h"

#include "../DX11Device/DX11Device.h"

namespace CH {

	DX11RendererAPI::DX11RendererAPI()
		: RendererAPI()
	{
	}

	DX11RendererAPI::~DX11RendererAPI()
	{
	}
	
	void DX11RendererAPI::Init(void* handle, Window::DX11WindowData Dx11Data = Window::DX11WindowData(), Window::OpenGLWindowData Gl4Data = Window::OpenGLWindowData())
	{
		// create the context
		m_Context = new DX11Context();
		CH_CORE_ASSERT(m_Context->CreateContext(handle), "Failed to initialize Context");

		// display info about successful creation
#ifdef CH_DEBUG
		CH_CORE_INFO("Successfully initialized DX11Context");
#endif

		// create the swap chain
		m_SwapChain = new DX11SwapChain();
		CH_CORE_ASSERT(m_SwapChain->Init(static_cast<DX11Context*>(m_Context)->GetDX11Device().GetD3DDevice(), handle, Dx11Data.Width, Dx11Data.Height), "Failed to initialize Swap Chain");

		// display info about successful creation
#ifdef CH_DEBUG
		CH_CORE_INFO("Successfully initialized SwapChain");
#endif
	}

	void DX11RendererAPI::Destroy()
	{
		m_SwapChain->Destroy();
		m_Context->DestroyContext();
	}

	void DX11RendererAPI::SetClearColor(glm::vec4 color)
	{
		// just set the clear color here
		m_ClearColor = color;
	}

	void DX11RendererAPI::Clear()
	{
		// clear the screen with the clear color
		// if the clear color is not set, use a default clear color
		if (m_ClearColor == glm::vec4(0.0f, 0.0f, 0.0f, 0.0f))
			static_cast<DX11Context*>(m_Context)->GetDX11DeviceContext().ClearColor((DX11SwapChain*)m_SwapChain, { 0.1f, 0.1f, 0.1f, 1.0f });
		else
			static_cast<DX11Context*>(m_Context)->GetDX11DeviceContext().ClearColor((DX11SwapChain*)m_SwapChain, m_ClearColor);
	}

	void DX11RendererAPI::SetVSync(bool enabled)
	{
		m_IsVSync = enabled;
	}

	void DX11RendererAPI::SwapBuffers()
	{
		m_SwapChain->SetVSync(m_IsVSync);
		m_SwapChain->Present();
	}
}