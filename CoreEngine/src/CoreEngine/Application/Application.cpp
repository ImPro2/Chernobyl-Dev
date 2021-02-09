#include "Application.h"

#include "CoreEngine/Log/Log.h"
#include "CoreEngine/Events/Events.h"			// temporary
#include "CoreEngine/Input/Input.h"				// temporary
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

		if (Input::IsKeyPressed(CH_KEY_A))
			CH_CORE_INFO("A key is pressed");
		else if (Input::IsKeyPressed(CH_KEY_W))
			CH_CORE_INFO("W key is presseed");

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