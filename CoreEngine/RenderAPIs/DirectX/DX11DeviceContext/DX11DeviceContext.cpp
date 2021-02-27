#include "DX11DeviceContext.h"

namespace CH {



	DX11DeviceContext::DX11DeviceContext()
	{
	}

	DX11DeviceContext::~DX11DeviceContext()
	{
	}

	void DX11DeviceContext::ClearRenderTargetColor(DX11Context* context, DX11SwapChain* swapChain, const glm::vec4& clearColor)
	{
		float color[]
		{
			clearColor.r, clearColor.g, clearColor.b, clearColor.a
		};

		context->GetDeviceContext()->ClearRenderTargetView(swapChain->GetD3DRenderTargetView(), color);
	}

}