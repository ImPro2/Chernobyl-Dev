#include "Application.h"

// TEMPORARY FOR LOGGING:
#include <iostream>

namespace CH {

	void Application::OnUpdate()
	{
		std::cout << "OnUpdate()";
	}

	void Application::OnDestroy()
	{
		m_Running = false;
	}
}