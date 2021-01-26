#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
		Window::Init();
	}

	void Application::OnUpdate()
	{
		// sets all events to their defaults
		Event::Clear();
		
		// update window and swap buffers and such
		Window::OnUpdate();

		// get run state, closes if false
		m_Running = Window::IsOpen();
		if (m_Running == false)
			CH_CORE_INFO("Window close");

		// temporary
		if (Event::s_CurrentKeyPressed == CH_KEY_A)
			CH_CORE_INFO("A key is pressed!");
		else if (Event::s_CurrentKeyReleased == CH_KEY_A)
			CH_CORE_INFO("A key is released (KeyReleasedEvent)");
		
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		Window::OnDestroy();
	}
}