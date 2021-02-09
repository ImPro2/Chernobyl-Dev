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

		if (Event::s_CurrentMouseButtonClicked == Event::MouseEvent::LEFT)
			CH_CORE_INFO("Left mouse button is pressed");
		if (Event::s_CurrentMouseButtonClicked == Event::MouseEvent::RIGHT)
			CH_CORE_INFO("Right mouse button is pressed");
		if (Event::s_CurrentMouseButtonClicked == Event::MouseEvent::MIDDLE)
			CH_CORE_INFO("Middle mouse button is pressed");

		if (Event::s_CurrentMouseButtonReleased == Event::MouseEvent::LEFT)
			CH_CORE_INFO("Left mouse button is released");
		if (Event::s_CurrentMouseButtonReleased == Event::MouseEvent::RIGHT)
			CH_CORE_INFO("Right mouse button is released");
		if (Event::s_CurrentMouseButtonReleased == Event::MouseEvent::MIDDLE)
			CH_CORE_INFO("Middle mouse button is released");

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