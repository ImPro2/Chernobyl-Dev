#pragma once

#include <glm/glm.hpp>

#include "Context.h"
#include "SwapChain.h"

#include "CoreEngine/Window/Window.h"
#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	enum class RenderAPI
	{
		DX11,
		GL4_0
	};

	// overrided in the RendererAPIs folder
	class RendererAPI
	{
	public:
		RendererAPI();
		~RendererAPI() {}

		virtual void Init(void* handle, Window::DX11WindowData Dx11Data, Window::OpenGLWindowData Gl4Data) = 0;
		virtual void Destroy() = 0;

		virtual void SetClearColor(glm::vec4 color) = 0;
		virtual void Clear() = 0;

		virtual void SwapBuffers() = 0;

		inline static RenderAPI GetAPI() { return s_API; }
		inline static void SetAPI(RenderAPI api) { s_API = api; }

	protected:
		Context* m_Context;
		SwapChain* m_SwapChain;
		glm::vec4 m_ClearColor;

	private:
		static RenderAPI s_API;
	};

}