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
		Window::OnUpdate();
		m_Running = Window::IsOpen();

		if (Event::s_CurrentCategory == Event::EventCategory::MouseClickedEvent && Event::s_CurrentMouseButtonClicked == Event::MouseEvent::LEFT)
			CH_CORE_INFO("Mouse button is clicked!");
		if (Event::s_CurrentCategory == Event::EventCategory::TypeEvent && Event::s_CurrentKeyTyped == Event::TypeEvent::W)
			CH_CORE_INFO("W key is presesd!");
	}

	void Application::OnDestroy()
	{
		m_Running = false;
	}
}