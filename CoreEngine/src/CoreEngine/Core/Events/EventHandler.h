#pragma once

#include <queue>

#include "Event.h"

/*
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
SysKeyTyped,

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
*/

namespace CH {

	class EventHandler
	{
	public:
		// set the events
		static void AddEvent(Event* e);
		static void Update();

		// accessors
		static int GetKeyPressed();
		static int GetKeyReleased();
		static char GetKeyTyped();
		static int GetSysKeyPressed();
		static int GetMouseButtonClicked();
		static int GetMouseButtonReleased();
		static Vec2 GetMousePos();
		static float GetMouseScrollOffset();

	private:
		static void HandleEvent(Event* e);

	private:
		static std::queue<Event*> s_EventQueue;

		static int s_CurrentKeyPressed;
		static int s_CurrentKeyReleased;
		static int s_CurrentKeyTyped;
		static int s_CurrentSysKeyPressed;
		static bool s_LButtonClicked;
		static bool s_LButtonReleased;
		static bool s_RButtonClicked;
		static bool s_RButtonReleased;
		static bool s_MButtonClicked;
		static bool s_MButtonReleased;
		static Vec2 s_MousePos;
		static float s_MouseScrollOffset;
	};

}