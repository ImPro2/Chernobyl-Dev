#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"
#include "CoreEngine/Input/Input.h"
#include "CoreEngine/Window/WindowHandler.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
		WindowHandler::CreateWindowNativeToPlatform();
	}

	void Application::OnUpdate()
	{
		// update window and swap buffers and such
		WindowHandler::UpdateWindow();

		//CH_CORE_INFO("Mouse X: {0}, Mouse Y: {1}", Event::s_MousePos.x, Event::s_MousePos.y);

		if (Event::s_CurrentKeyPressed == CH_KEY_A)
			CH_CORE_INFO("A key is pressed");
		if (Event::s_CurrentKeyReleased == CH_KEY_A)
			CH_CORE_INFO("A key is released");
		if (Event::s_CurrentKeyTyped == 'a')
			CH_CORE_INFO("a key is typed");

		// get run state, closes if false
		m_Running = WindowHandler::GetWindowRunState();
		Event::Clear();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowHandler::DestroyWindow();
	}
}