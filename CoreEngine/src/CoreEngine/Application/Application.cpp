#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"
#include "CoreEngine/Input/Input.h"
#include "../Window/WindowCreation.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
		WindowCreation::CreateWindowNativeToPlatform();
	}

	void Application::OnUpdate()
	{
		// sets all events to their defaults
		Event::Clear();
		
		// update window and swap buffers and such
		WindowCreation::UpdateWindow();

		// get run state, closes if false
		m_Running = WindowCreation::GetWindowRunState();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowCreation::DestroyWindow();
	}
}