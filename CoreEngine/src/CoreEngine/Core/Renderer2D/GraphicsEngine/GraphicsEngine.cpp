#include "GraphicsEngine.h"
#include "../Platform/Platform.h"

// dx11
#include "../RenderAPIs/DirectX/DX11Device/DX11Device.h"
#include "../RenderAPIs/DirectX/DX11DeviceContext/DX11DeviceContext.h"

#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	void GraphicsEngine::Init()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			DX11Device::Init();
			break;
		}
		case Platforms::MACOS:
		{
			CH_ASSERT(false, "OpenGL isnt currently supported...");
			break;
		}
		}
	}

	void GraphicsEngine::Update()
	{
	}

	void GraphicsEngine::Destroy()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			DX11Device::Destroy();
			//DX11DeviceContext::Destroy();
			break;
		}
		case Platforms::MACOS:
		{
			CH_ASSERT(false, "OpenGL isnt currently supported...");
			break;
		}
		}
	}

	void* GraphicsEngine::GetD3DDevice()
	{
		return DX11Device::m_D3D_Device;
	}

	void* GraphicsEngine::GetD3DDeviceContext()
	{
		return DX11Device::m_D3D_DeviceContext;
	}

}