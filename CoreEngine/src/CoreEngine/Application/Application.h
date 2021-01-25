#pragma once

#include "CoreEngine/Core.h"
#include "CoreEngine/Window/Window.h"

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
	};

}