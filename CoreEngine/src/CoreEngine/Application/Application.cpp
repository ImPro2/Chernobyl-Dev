#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"			// temporary
#include "CoreEngine/Input/Input.h"				// temporary
#include "CoreEngine/Window/WindowHandler.h"
#include "CoreEngine/DeltaTime/DeltaTime.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
		WindowHandler::CreateWindowNativeToPlatform();
	}

	void Application::OnUpdate()
	{
		// set the time difference between two frames
		Time::SetDeltaTime();

		// update window and swap buffers and such
		WindowHandler::UpdateWindow();

		CH_CORE_INFO("DeltaTime: {0}", DeltaTime);

		// clear events to be used next time
		Event::Clear();
		
		// get run state, closes if false
		m_Running = WindowHandler::GetWindowRunState();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowHandler::DestroyWindow();
	}
}