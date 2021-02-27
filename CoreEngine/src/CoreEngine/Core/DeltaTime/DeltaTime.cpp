#include "DeltaTime.h"
#include "CoreEngine/Application/Application.h"
#include "../Platform/Platform.h"

namespace CH {

	DeltaTime Time::deltaTime;
	std::chrono::steady_clock::time_point Time::last;

	void Time::Init()
	{
		last = std::chrono::steady_clock::now();
	}

    void Time::Set()
    {
		auto old = last;
		last = std::chrono::steady_clock::now();

		std::chrono::duration<float> frameTime = last - old;
		deltaTime = frameTime.count();
	}
}