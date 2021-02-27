#include "DX11Context.h"
#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Core.h"

namespace CH {

	bool DX11Context::CreateContext(void* handle)
	{
		return static_cast<DX11Device*>(m_Context)->Init();
	}

}