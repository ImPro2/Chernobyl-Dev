#pragma once

#include "CoreEngine/Core/Core.h"
#include "CoreEngine/ImGuiLayer/ImGuiLayer.h"

namespace CH {

	class Application
	{
	public:
		Application() {}
		~Application() {}

		static void OnCreate();
		static void OnUpdate();
		static void OnDestroy();
		
		static bool GetRunState() { return m_Running; }
	private:
		static bool m_Running;

		static ImGuiLayer* m_ImGuiLayer;
	};

}