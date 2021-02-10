#pragma once

namespace CH {

	class GraphicsEngine
	{
	public:
		static void Init();
		static void Update();
		static void Destroy();

		// accessors
		static void* GetD3DDevice();
		static void* GetD3DDeviceContext();
	};

}