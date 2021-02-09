#pragma once

#include "CoreEngine/Core.h"
#include "KeyCodes.h"
#include <GLFW/glfw3.h>

namespace CH {

	// when ever some sort of event like a key press or mouse moved event happens,
	// a window api will call some sort of callback and sets the event category and the corresponding event.
	// like when the a key is pressed, the lambda will do something like this:
	//
	// Event::s_CurrentCategory = Event::EventCategory::TypeEvent;
	// Event::s_CurrentKey = Event::TypeEvent::code; // code is the keycode which key is pressed
	//
	// and each frame the HandleEvents() function gets called which calls the function 
	// correspondent to the event category, which sets a value.

	class Event
	{
	public:

		// mouse clicking/released
		enum class MouseEvent
		{
			NONE,
			LEFT,
			RIGHT,
			MIDDLE
		};

		// for window events
		enum class WindowEvent
		{
			Create,
			AppTick,	// Could also be None
			Close
		};

		// for mouse moved event
		static Vec2 s_MousePos;

		// for mouse scrolled event
		static Vec2 s_MouseScrollOffset;

		static int s_CurrentKeyTyped;
		static int s_CurrentKeyPressed;
		static int s_CurrentKeyReleased;
		static MouseEvent s_CurrentMouseButtonClicked;
		static MouseEvent s_CurrentMouseButtonReleased;
		static WindowEvent s_CurrentWindowEvent;

	public:
		// functions
		static int GetCurrentKeyTyped() { return s_CurrentKeyTyped; }
		static int GetCurrentKeyReleased() { return s_CurrentKeyReleased;  }
		static MouseEvent GetCurrentMouseButtonClicked() { return s_CurrentMouseButtonClicked; }
		static MouseEvent GetCurrentMouseButtonReleased() { return s_CurrentMouseButtonReleased; }
		static WindowEvent GetCurrentWindowEvent() { return s_CurrentWindowEvent; }
		static Vec2 GetMousePos() { return s_MousePos; }	
		static Vec2 GetMouseScrollOffset() { return s_MouseScrollOffset; }

		// called first thing each frame (before other function calls)
		static void Clear();

	};
}