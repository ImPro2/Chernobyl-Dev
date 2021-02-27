#include "DeltaTime.h"
#include "CoreEngine/Application/Application.h"
#include "../Platform/Platform.h"

#include <GLFW/glfw3.h>

#ifdef CH_PLATFORM_WINDOWS
#include <Windows.h>
#endif

namespace CH {

	DeltaTime Time::deltaTime;
	float Time::m_LastFrameTime = 0;

    void Time::Set()
    {
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			float time = (float)glfwGetTime();
			deltaTime = time - m_LastFrameTime;
			m_LastFrameTime = time;
			break;
		}
		case Platforms::WINDOWS:
		{
			float time = GetTickCount();
			deltaTime = time - m_LastFrameTime;
			m_LastFrameTime = time;
			break;
		}
		default:
			CH_CORE_ASSERT(false, "Unknown platform!");
		}
    }
}