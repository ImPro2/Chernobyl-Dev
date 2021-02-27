#pragma once
#include "RenderCommand.h"

namespace CH {

	class Renderer
	{
	public:
		static void Init();
		static void Destroy();

		RenderAPI GetAPI() { return RendererAPI::GetAPI(); }
			
	private:

	};

}