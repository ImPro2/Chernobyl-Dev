#include "chpch.h"
#include "RendererAPI.h"

#include "../Platform/Platform.h"

namespace CH {

	RenderAPI RendererAPI::s_API;

	RendererAPI::RendererAPI()
	{
		s_API = (Platform::GetCurrentPlatform() == Platforms::WINDOWS ? RenderAPI::DX11 : RenderAPI::GL4_0);
		m_ClearColor = glm::vec4(0);
	}

}