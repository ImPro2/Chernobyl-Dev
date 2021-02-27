#pragma once

#include <d3d11.h>
#include <Windows.h>

namespace CH {

	class DX11Device
	{
	public:
		DX11Device();
		~DX11Device();

		bool Init();
		void Destroy();

		ID3D11Device* GetD3DDevice() const { return m_D3D_Device; }
		ID3D11DeviceContext* GetD3DDeviceContext() const { return m_D3D_DeviceContext; }

	private:
		ID3D11Device* m_D3D_Device;
		ID3D11DeviceContext* m_D3D_DeviceContext;
		D3D_FEATURE_LEVEL m_D3D_FeatureLevel;
	};

}