#include "Application.h"

#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Events/EventHandler.h"
#include "CoreEngine/Input/Input.h"				// temporary
#include "CoreEngine/Window/WindowHandler.h"
#include "CoreEngine/Core/DeltaTime/DeltaTime.h"
#include "CoreEngine/Core/Layer/LayerHandler.h"
#include "CoreEngine/Core/Renderer2D/Renderer/Renderer.h"
#include "CoreEngine/ImGuiLayer/ImGuiLayer.h"

namespace CH {

	bool Application::m_Running = true;

	void Application::OnCreate()
	{
		Log::Init();
		WindowHandler::CreateWindowNativeToPlatform();
		LayerHandler::Init();
		Renderer::Init();

		LayerHandler::AddFront(new ImGuiLayer());
	}

	void Application::OnUpdate()
	{
		// poll events
		WindowHandler::UpdateWindow();
		EventHandler::Update();
		
		// set the time difference between two frames
		Time::SetDeltaTime();

		// all update here
		for (Layer* layer : LayerHandler::GetLayerStack())
			layer->OnUpdate();

		for (Layer* layer : LayerHandler::GetLayerStack())
			layer->OnEvent();

		for (Layer* layer : LayerHandler::GetLayerStack())
			layer->OnImGuiRender();

		// get run state, closes if false
		m_Running = WindowHandler::GetWindowRunState();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		WindowHandler::DestroyWindow();
		LayerHandler::Destroy();
		Renderer::Destroy();
	}
}