#pragma once

#include "../DX11Context/DX11Context.h"
#include "../DX11SwapChain/DX11SwapChain.h"

#include <glm/glm.hpp>

namespace CH {

	class DX11DeviceContext
	{
	public:
		DX11DeviceContext();
		~DX11DeviceContext();

		void ClearRenderTargetColor(DX11Context* context, DX11SwapChain* swapChain, const glm::vec4& clearColor);
	};

}