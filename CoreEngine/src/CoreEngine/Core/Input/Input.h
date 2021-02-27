#pragma once

#include "CoreEngine/Core/Core.h"

namespace CH {

	class Input
	{
	public:
		static bool IsKeyPressed(int keycode);
		static int GetMousePosX();
		static int GetMousePosY();
		static std::pair<int, int> GetMousePos();
		static bool IsMouseButtonPressed(int button);
	};

}