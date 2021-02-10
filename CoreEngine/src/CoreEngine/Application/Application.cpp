#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/EventHandler.h"
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
		// poll events
		WindowHandler::UpdateWindow();
		EventHandler::Update();
		
		// set the time difference between two frames
		Time::SetDeltaTime();

		// all update here
		if (EventHandler::GetKeyPressed() == CH_KEY_A)
			CH_CORE_INFO("A key is pressed");
		
		// get run state, closes if false
		m_Running = WindowHandler::GetWindowRunState();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowHandler::DestroyWindow();
	}
}