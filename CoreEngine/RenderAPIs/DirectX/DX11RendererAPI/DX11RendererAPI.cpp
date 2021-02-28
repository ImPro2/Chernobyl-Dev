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
	
	void DX11RendererAPI::Init(void* handle, Window::DX11WindowData Dx11Data, Window::OpenGLWindowData Gl4Data)
	{
		m_Context = new DX11Context();
		CH_CORE_ASSERT(m_Context->CreateContext(handle), "Failed to initialize Context");

#ifdef CH_DEBUG
		CH_CORE_INFO("Successfully initialized DX11Context");
#endif

		m_SwapChain = new DX11SwapChain();
		CH_CORE_ASSERT(m_SwapChain->Init(static_cast<DX11Context*>(m_Context)->GetDX11Device().GetD3DDevice(), handle, Dx11Data.Width, Dx11Data.Height), "Failed to initialize Swap Chain");
		m_SwapChain->SetVSync(Dx11Data.isVsync);

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
		m_ClearColor = color;
	}

	void DX11RendererAPI::Clear()
	{
		static_cast<DX11Context*>(m_Context)->GetDX11DeviceContext().ClearColor((DX11SwapChain*)m_SwapChain, m_ClearColor);
	}

	void DX11RendererAPI::SwapBuffers()
	{
		m_SwapChain->Present();
	}
}