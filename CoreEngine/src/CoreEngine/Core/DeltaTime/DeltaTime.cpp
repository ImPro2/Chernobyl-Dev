#include "DeltaTime.h"

#include "../Platform/Platform.h"
#include "CoreEngine/Core/Log/Log.h"

#include <GLFW/glfw3.h>
#include <Windows.h>

namespace CH {

	float Time::m_DeltaTime = 0.0f;
	float Time::m_FramesPerSecond = 0.0f;
	float Time::m_LastFrameTime = 0.0f;

	float Time::GetFrameTimeDifference(DeltaTimes time)
	{
		switch (time)
		{
			case Milliseconds:
			{
				return m_DeltaTime;
			}
			case Nanoseconds:
			{

				return m_DeltaTime / 1000.0f;
			}
			case Seconds:
			{
				return m_DeltaTime * 100.0f;
			}
			default:
				CH_ASSERT(false, "Invalid time");
				break;
		}
		return  0.0f;
	}

	float Time::GetFramesPerSecond()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			float time = GetTickCount();
			m_FramesPerSecond = 1.0f / (time - m_LastFrameTime);
			m_LastFrameTime = time;
			break;
		}
		case Platforms::MACOS:
		{
			float time = (float)glfwGetTime();
			m_FramesPerSecond = 1.0f / (time - m_LastFrameTime);
			m_LastFrameTime = time;
			break;
		}
		}

		return m_FramesPerSecond;
	}

	void Time::SetDeltaTime()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			float time = (float)glfwGetTime();
			m_DeltaTime = time - m_LastFrameTime;
			m_LastFrameTime = time;

			break;
		}
		case Platforms::WINDOWS:
		{
			float time = GetTickCount();
			m_DeltaTime = time - m_LastFrameTime;
			m_LastFrameTime = time;

			break;
		}
		}
	}

}