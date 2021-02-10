#pragma once

#include "CoreEngine/Core/Core.h"
#include "KeyCodes.h"

namespace CH {

	class Event
	{
	public:
		enum class EventTypes
		{
			// window events
			AppTick,
			WindowCreate,
			WindowClose,
			WindowResize,
			WindowMove,

			// keyboard events
			KeyPressed,
			KeyReleased,
			KeyTyped,
			SysKeyPressed,

			/// mouse button events
			LButtonClicked,
			LButtonReleased,
			RButtonClicked,
			RButtonReleased,
			MButtonClicked,
			MButtonReleased,

			// other mouse events
			MouseMoved,
			MouseScrolled
		};

		Event(EventTypes e) { m_EventType = e; }

		int  KeyPressed		 = CH_KEY_UNKNOWN;
		int  KeyReleased	 = CH_KEY_UNKNOWN;
		int  KeyTyped		 = CH_KEY_UNKNOWN;
		int  SysKeyPressed	 = CH_KEY_UNKNOWN;
		Vec2 MousePos		 = { 0.0f, 0.0f };
		float MouseScrollOffset = 0.0f;

		EventTypes GetType() { return m_EventType; }

	private:
		EventTypes m_EventType;
	};

}