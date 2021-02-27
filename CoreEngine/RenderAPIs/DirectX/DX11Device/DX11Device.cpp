#include "DX11Device.h"
#include "CoreEngine/Core/Types.h"

namespace CH {

	DX11Device::DX11Device()
	{
	}

	DX11Device::~DX11Device()
	{
	}

	bool DX11Device::Init()
	{
		D3D_DRIVER_TYPE driver_types[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE
		};
		UINT num_driver_types = ARRAYSIZE(driver_types);

		D3D_FEATURE_LEVEL feature_levels[] =
		{
			D3D_FEATURE_LEVEL_11_0
		};
		UINT num_feature_levels = ARRAYSIZE(feature_levels);

		HRESULT res = 0;

		for (UINT driver_type_index = 0; driver_type_index < num_driver_types;)
		{
			res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
				num_feature_levels, D3D11_SDK_VERSION, &m_D3D_Device, &m_D3D_FeatureLevel, &m_D3D_DeviceContext);
			if (SUCCEEDED(res))
				break;
			++driver_type_index;
		}

		if (FAILED(res))
		{
			return false;
		}

		return true;
	}

	void DX11Device::Destroy()
	{
		m_D3D_Device->Release();
	}

}