#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
	}

	void Application::OnUpdate()
	{
		
	}

	void Application::OnDestroy()
	{
		m_Running = false;
	}
}