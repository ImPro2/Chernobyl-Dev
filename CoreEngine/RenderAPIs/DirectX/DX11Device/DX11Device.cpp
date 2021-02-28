#include "DX11Device.h"
#include "CoreEngine/Core/Types.h"
#include "CoreEngine/Core/Log/Log.h"

namespace CH {

	DX11Device::DX11Device()
	{
	}

	DX11Device::~DX11Device()
	{
	}

	bool DX11Device::Init()
	{
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0
		};

		HRESULT result = 0;

		result = D3D11CreateDevice(
			NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			NULL,
			featureLevels,
			ARRAYSIZE(featureLevels),
			D3D11_SDK_VERSION,
			&m_D3D_Device,
			m_D3D_FeatureLevel,
			&m_D3D_DeviceContext);

		if (FAILED(result))
			return false;
		
		return true;
	}

	void DX11Device::Destroy()
	{
		m_D3D_Device->Release();
	}

}