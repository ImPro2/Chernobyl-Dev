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
		// update window and swap buffers and such
		WindowCreation::UpdateWindow();

		// get run state, closes if false
		m_Running = WindowCreation::GetWindowRunState();
		Event::Clear();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowCreation::DestroyWindow();
	}
}