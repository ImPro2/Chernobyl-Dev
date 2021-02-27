#pragma once

#include "CoreEngine/Core/Types.h"

namespace CH {

	class SwapChain
	{
	public:
		virtual bool Init(void* context, void* handle, uint32_t width, uint32_t height) = 0;
		virtual void Destroy() = 0;

		virtual void SetVSync(bool enabled) = 0;

		virtual bool Present() = 0;

	protected:
		bool m_IsVSync = false;
	};

}