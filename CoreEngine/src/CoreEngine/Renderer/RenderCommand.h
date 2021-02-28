#pragma once
#include "RendererAPI.h"

namespace CH {

	class Renderer;

	class RenderCommand
	{
	public:
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

	private:
		friend class Renderer;

		static RendererAPI* s_RendererAPI;
	};

}