#include "DX11Context.h"
#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	bool DX11Context::CreateContext(void* handle)
	{
		bool status = m_DX11_Device.Init();
		m_DX11_DeviceContext.SetD3DDeviceContext(m_DX11_Device.GetD3DDeviceContext());
		return status;
	}
}