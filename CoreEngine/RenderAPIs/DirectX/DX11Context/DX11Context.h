#pragma once

#include "CoreEngine/Renderer/Context.h"
#include "../DX11Device/DX11Device.h"

namespace CH {

	// TODO: Create a Context interface that OpenGL and DirectX can override
	class DX11Context : public Context
	{
	public:
		bool CreateContext(void* handle) override;
		void DestroyContext() override { static_cast<DX11Device*>(m_Context)->Destroy(); }

		void* GetContext() override { return static_cast<DX11Device*>(m_Context)->GetD3DDevice(); }
		ID3D11DeviceContext* GetDeviceContext() { return static_cast<DX11Device*>(m_Context)->GetD3DDeviceContext(); }
	};

}