#pragma once

namespace CH {

	class Time
	{
	public:
		enum DeltaTimes
		{
			Nanoseconds,
			Milliseconds,
			Seconds
		};

		static float GetFrameTimeDifference(DeltaTimes time);
		static float GetFramesPerSecond();
		static void SetDeltaTime();

	private:
		static float m_DeltaTime;
		static float m_LastFrameTime;

		static float m_FramesPerSecond;
	};

}

#define DeltaTimeAsSec CH::Time::GetFrameTimeDifference(CH::Time::Seconds)
#define DeltaTimeAsMilSec CH::Time::GetFrameTimeDifference(CH::Time::Milliseconds)
#define DeltaTimeAsNanSec CH::Time::GetFrameTimeDifference(CH::Time::Nanoseconds)

#define GetFramesPerSec CH::Time::GetFramesPerSecond()

#define FPS GetFramesPerSec
#define DeltaTime DeltaTimeAsSec