#pragma once

namespace CH {

	enum class SupportedAPIs
	{
		DX11,
		OPENGL4_0
	};

	class Renderer
	{
	public:
		static void Init();
		static void Destroy();
	};

}