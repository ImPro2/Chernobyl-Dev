#include "Renderer.h"

#include "CoreEngine/Window/WindowHandler.h"

#include "../Platform/Platform.h"
#include "../RenderAPIs/DirectX/DX11RendererAPI/DX11RendererAPI.h"

namespace CH {

	void Renderer::Init()
	{
		RenderCommand::s_RendererAPI = new DX11RendererAPI();

		RenderCommand::s_RendererAPI->Init(WindowHandler::GetNativeWindow(), WindowHandler::GetDX11WindowData(), WindowHandler::GetOpenGLWindowData());
	}

	void Renderer::Destroy()
	{
		RenderCommand::s_RendererAPI->Destroy();
	}

}