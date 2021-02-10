#pragma once

#include <d3d11.h>

namespace CH {

	class GraphicsEngine;

	class DX11DeviceContext
	{
	public:
		static void Destroy();

		// accessors
		static ID3D11DeviceContext* GetD3DDeviceContext() { return m_D3D_DeviceContext; }
	private:
		static ID3D11DeviceContext* m_D3D_DeviceContext;

		friend class GraphicsEngine;
	};

}