#include "DX11DeviceContext.h"

namespace CH {

	ID3D11DeviceContext* DX11DeviceContext::m_D3D_DeviceContext;

	void DX11DeviceContext::Destroy()
	{
		m_D3D_DeviceContext->Release();
	}

}