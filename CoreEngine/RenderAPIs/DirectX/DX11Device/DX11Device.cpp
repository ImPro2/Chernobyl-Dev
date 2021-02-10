#include "DX11Device.h"
#include "../DX11DeviceContext/DX11DeviceContext.h"

#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	ID3D11Device*			DX11Device::DX11Device::m_D3D_Device;
	ID3D11DeviceContext*	DX11Device::m_D3D_DeviceContext;
	D3D_FEATURE_LEVEL*		DX11Device::DX11Device::m_D3D_FeatureLevel;

	void DX11Device::Init()
	{
		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE
		};
		UINT numDriverTypes = ARRAYSIZE(driverTypes);

		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0
		};
		UINT numFeatureLevels = ARRAYSIZE(featureLevels);

		HRESULT result = 0;

		for (int i = 0; i < numDriverTypes; i++)
		{
			result = D3D11CreateDevice(
				NULL,
				driverTypes[i],
				NULL,
				NULL,
				featureLevels,
				numFeatureLevels,
				D3D11_SDK_VERSION,
				&m_D3D_Device,
				m_D3D_FeatureLevel,
				&m_D3D_DeviceContext);

			if (SUCCEEDED(result))
				break;

			CH_CORE_WARN("D3D Driver Type is lower than D3D_DRIVER_TYPE_HARDWARE. Please considering updating your graphics driver.");
		}

		CH_ASSERT(SUCCEEDED(result), "Failed to create D3D11Device :(");

		CH_CORE_INFO("Successfully initialized DX11Device");
	}

	void DX11Device::Destroy()
	{
		m_D3D_Device->Release();
	}

}