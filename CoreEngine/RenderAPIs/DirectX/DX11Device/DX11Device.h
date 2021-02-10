#pragma once

#include <d3d11.h>

namespace CH {

	class GraphicsEngine;

	class DX11Device
	{
	public:
		static void Init();
		static void Destroy();

	private:
		static ID3D11Device* m_D3D_Device;
		static D3D_FEATURE_LEVEL* m_D3D_FeatureLevel;

		friend class GraphicsEngine;
	};

}