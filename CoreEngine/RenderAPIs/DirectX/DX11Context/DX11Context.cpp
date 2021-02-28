#include "chpch.h"
#include "DX11Context.h"
#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	bool DX11Context::CreateContext(void* handle)
	{
		// create the device and device context
		bool status = m_DX11_Device.Init();

		// set the device context
		m_DX11_DeviceContext.SetD3DDeviceContext(m_DX11_Device.GetD3DDeviceContext());

		// return the status for error checking in the DX11RendererAPI class.
		return status;
	}
}