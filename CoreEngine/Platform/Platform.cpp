#include "chpch.h"
#include "Platform.h"

namespace CH {

	// if it is Windows, it uses DX11 as the Rendering API
	// if it is Mac, it uses OpenGL as the Rendering API
	// Linux will be vulkan... though that would be implemented in something like 2022 idk
	Platforms Platform::s_CurrentPlatform = Platforms::WINDOWS;

}