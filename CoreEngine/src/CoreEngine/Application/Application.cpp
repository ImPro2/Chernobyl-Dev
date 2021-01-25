#include "Application.h"

#include "CoreEngine/Log/Log.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
	}

	void Application::OnUpdate()
	{
		CH_CORE_INFO("OnUpdate()");
	}

	void Application::OnDestroy()
	{
		m_Running = false;
	}
}