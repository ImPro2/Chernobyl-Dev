#include "DX11DeviceContext.h"

namespace CH {

	DX11DeviceContext::DX11DeviceContext()
	{
	}

	DX11DeviceContext::~DX11DeviceContext()
	{
	}

	void DX11DeviceContext::SetD3DDeviceContext(ID3D11DeviceContext* deviceContext)
	{
		m_DeviceContext = deviceContext;
	}

	void DX11DeviceContext::ClearColor(DX11SwapChain* swapChain, const glm::vec4& clearColor)
	{
		float color[]
		{
			clearColor.r, clearColor.g, clearColor.b, clearColor.a
		};

		m_DeviceContext->ClearRenderTargetView(swapChain->GetD3DRenderTargetView(), color);
	}

}