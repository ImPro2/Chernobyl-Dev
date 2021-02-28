#include "chpch.h"
#include "DX11Device.h"
#include "../DXErr.h"

namespace CH {

	DX11Device::DX11Device()
	{
	}

	DX11Device::~DX11Device()
	{
	}

	bool DX11Device::Init()
	{
		// for error checking
		HRESULT hr = 0;
		
		// driver types ranging from best performance to lowest performance
		D3D_DRIVER_TYPE DriverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE
		};

		// DirectX11 is only needed, if the device only supports lower versions, another api like OpenGL will be used
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0
		};

		// create flags for debug and release
		uint32_t creationFlags = 0;
#ifdef CH_DEBUG
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#else
		creationFlags |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#endif

		// create the device and device context
		for (int i = 0; i < ARRAYSIZE(DriverTypes); i++)
		{
			DXCALL(hr = D3D11CreateDevice(
				NULL,
				DriverTypes[i],
				NULL,
				creationFlags,
				featureLevels,
				ARRAYSIZE(featureLevels),
				D3D11_SDK_VERSION,
				&m_D3D_Device,
				m_D3D_FeatureLevel,
				&m_D3D_DeviceContext));

			if (SUCCEEDED(hr))
				break;

			// warn the user that the driver type is low
			CH_CORE_WARN("D3D_DRIVER_TYPE < DRIVER_TYPE_HARDWARE: Please considering updating your graphics driver for better performance");
		}
		
		// Something went wrong...
		if (FAILED(hr))
			return false;
		
		// Everything succeeded
		return true;
	}

	void DX11Device::Destroy()
	{
		m_D3D_Device->Release();
	}

}