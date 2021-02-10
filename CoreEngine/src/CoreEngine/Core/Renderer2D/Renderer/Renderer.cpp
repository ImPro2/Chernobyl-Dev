#include "Renderer.h"
#include "../GraphicsEngine/GraphicsEngine.h"

namespace CH {

	void Renderer::Init()
	{
		GraphicsEngine::Init();
	}

	void Renderer::Destroy()
	{
		GraphicsEngine::Destroy();
	}

}