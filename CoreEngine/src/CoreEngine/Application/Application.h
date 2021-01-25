#pragma once

#include "CoreEngine/Core.h"

namespace CH {

	class Application
	{
	public:
		Application() {}
		~Application() {}

		void OnUpdate();

		void OnDestroy();
		
		bool GetRunState() { return m_Running; }
	private:
		bool m_Running = true;
	};

}