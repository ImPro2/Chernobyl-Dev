#pragma once
#include "RendererAPI.h"

namespace CH {

	class Renderer;

	class RenderCommand
	{
	public:
		// init and destroy
		inline static void Init(void* handle, Window::DX11WindowData Dx11Data = Window::DX11WindowData(), Window::OpenGLWindowData Gl4Data = Window::OpenGLWindowData())
		{
			s_RendererAPI->Init(handle, Dx11Data, Gl4Data);
		}

		inline static void Destroy()
		{
			s_RendererAPI->Destroy();
		}

		inline static void SetClearColor(glm::vec4 color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static RendererAPI* GetRendererAPI()
		{
			return s_RendererAPI;
		}

		inline static void SetAPI(RenderAPI api)
		{
			s_RendererAPI->SetAPI(api);
		}

		inline static void SwapBufers()
		{
			s_RendererAPI->SwapBuffers();
		}

		inline static void SetVSync(bool enabled)
		{
			s_RendererAPI->SetVSync(enabled);
		}

	private:
		friend class Renderer;

		static RendererAPI* s_RendererAPI;
	};

}