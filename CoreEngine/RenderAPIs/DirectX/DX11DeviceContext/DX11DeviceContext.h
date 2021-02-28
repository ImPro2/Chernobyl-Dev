#pragma once


#include <glm/glm.hpp>
#include <d3d11.h>

#include "../DX11SwapChain/DX11SwapChain.h"

namespace CH {

	// class responsible for using the device context created by the DX11Device class to execute render commands
	class DX11DeviceContext
	{
	public:
		DX11DeviceContext();
		~DX11DeviceContext();

		void ClearColor(DX11SwapChain* swapChain, const glm::vec4& clearColor);

		// set and get the device context
		void SetD3DDeviceContext(ID3D11DeviceContext* deviceContext);
		ID3D11DeviceContext* GetD3DDeviceContext() { return m_DeviceContext; }
	
	private:
		ID3D11DeviceContext* m_DeviceContext;
	};

}