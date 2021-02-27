#pragma once

namespace CH {

	class Time;
	class Application;

	class DeltaTime
	{
	public:
		DeltaTime() {}
		~DeltaTime() {}

		float asSeconds() { return m_Time * 10.0f; }
		float asMilliSeconds() { return m_Time; }

		operator float()
		{
			return m_Time;
		}

		void operator=(const float& other)
		{
			m_Time = other;
		}

	private:
		float m_Time = 0;

		friend class Time;
	};

	class Time
	{
	public:
		static DeltaTime deltaTime;
	
	private:
		static void Set();

	private:
		static float m_LastFrameTime;

		friend class Application;
	};

#define dt Time::deltaTime.asSeconds()

}