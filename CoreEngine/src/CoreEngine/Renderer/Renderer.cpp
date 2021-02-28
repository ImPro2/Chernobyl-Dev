#include "chpch.h"
#include "Renderer.h"

#include "CoreEngine/Window/WindowHandler.h"

#include "../Platform/Platform.h"
#include "../RenderAPIs/DirectX/DX11RendererAPI/DX11RendererAPI.h"

namespace CH {

	void Renderer::Init()
	{
		RenderCommand::s_RendererAPI = new DX11RendererAPI();

		switch (RendererAPI::GetAPI())
		{
		case RenderAPI::DX11:
			RenderCommand::Init(WindowHandler::GetNativeWindow(), WindowHandler::GetDX11WindowData(), Window::OpenGLWindowData());
			break;
		case RenderAPI::GL4_0:
			RenderCommand::Init(WindowHandler::GetNativeWindow(), Window::DX11WindowData(), WindowHandler::GetOpenGLWindowData());
		}
	}

	void Renderer::Destroy()
	{
		RenderCommand::Destroy();
	}

}