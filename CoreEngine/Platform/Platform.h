#pragma once

namespace CH {

	enum class Platforms
	{
		WINDOWS,
		MACOS,
		LINUX,
		IOS,
		ANDROID
	};

	// singleton to get and set the current platform to build on
	class Platform
	{
	public:
		static Platforms GetCurrentPlatform()
		{
			return s_CurrentPlatform;
		}

	private:
		static Platforms s_CurrentPlatform;
	};

}