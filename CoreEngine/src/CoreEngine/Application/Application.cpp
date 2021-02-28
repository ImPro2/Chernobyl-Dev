#include "chpch.h"
#include "Application.h"

#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Core/Events/EventHandler.h"
#include "CoreEngine/Core/Input/Input.h"				// temporary
#include "CoreEngine/Window/WindowHandler.h"
#include "CoreEngine/Core/DeltaTime/DeltaTime.h"
#include "CoreEngine/Core/Layer/LayerHandler.h"
#include "CoreEngine/Renderer/Renderer.h"

#include <GLFW/glfw3.h>

namespace CH {

	bool Application::m_Running = true;
	ImGuiLayer* Application::m_ImGuiLayer;

	void Application::OnCreate()
	{
		Log::Init();
		WindowHandler::CreateWindowNativeToPlatform();
		Renderer::Init();
		LayerHandler::Init();

		//m_ImGuiLayer = new ImGuiLayer();
		//LayerHandler::AddFront(m_ImGuiLayer);
		Time::Init();

		WindowHandler::SetVSync(false);
	}

	void Application::OnUpdate()
	{
		// poll events
		WindowHandler::UpdateWindow();
		EventHandler::Update();

		Time::Set();

		// all update here
		for (Layer* layer : LayerHandler::GetLayerStack())
			layer->OnUpdate();

		for (Layer* layer : LayerHandler::GetLayerStack())
			layer->OnEvent();

		//m_ImGuiLayer->Begin();
		//for (Layer* layer : LayerHandler::GetLayerStack())
		//	layer->OnImGuiRender();
		//m_ImGuiLayer->End();

		RenderCommand::Clear();
		RenderCommand::SwapBufers();

		// get run state, closes if false
		m_Running = WindowHandler::GetWindowRunState();
	}

	void Application::OnDestroy()
	{
		m_Running = false;
		Renderer::Destroy();
		WindowHandler::DestroyWindow();
		LayerHandler::Destroy();
	}
}