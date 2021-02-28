#pragma once

#include "CoreEngine/Renderer/RendererAPI.h"

#include "../DX11Context/DX11Context.h"
#include "../DX11SwapChain/DX11SwapChain.h"
#include "../DX11DeviceContext/DX11DeviceContext.h"

namespace CH {

	class DX11RendererAPI : public RendererAPI
	{
	public:
		DX11RendererAPI();
		~DX11RendererAPI();

		void Init(void* handle, Window::DX11WindowData Dx11Data, Window::OpenGLWindowData Gl4Data) override;
		void Destroy() override;

		// rendering commands
		virtual void SetClearColor(glm::vec4 color) override;
		virtual void Clear() override;

		virtual void SetVSync(bool enabled) override;

		void SwapBuffers() override;
	};

}