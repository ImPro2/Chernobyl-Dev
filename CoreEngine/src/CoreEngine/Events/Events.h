#pragma once

#include "CoreEngine/Core.h"

namespace CH {

	// when ever some sort of event like a key press or mouse moved event happens,
	// glfw will call a lambda which sets the event category and the corresponding event.
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
		// not used by client
		// each event category has an enum/struct
		enum class EventCategory
		{
			TypeEvent,
			MouseClickedEvent,
			MouseReleasedEvent,
			MouseMovedEvent,
			MouseScrolledEvent,
			WindowEvent
		};

		// typing stuff
		enum class TypeEvent
		{
			NONE,
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			N1,
			N2,
			N3,
			N4,
			N5,
			N6,
			N7,
			N8,
			N9,
			N0,
			TAB,
			LSHIFT,
			LCONTROL,
			SPACE,
			RCONTROL,
			RSHIFT,
			COMMA,
			PERIOD,
			SLASH,
			SEMICOLON,
			QUOTE,
			ENTER,
			LBRACKET,
			RBRACKET,
			MINUS,
			PLUS
		};

		// mouse clicking/released
		enum class MouseEvent
		{
			NONE,
			LEFT,
			RIGHT,
			MIDDLE
		};

	private:
		// for window events
		enum class WindowEvent
		{
			AppTick,	// Could also be None
			Close
		};

		// for mouse moved event
		static Vec2 s_MousePos;

		// for mouse scrolled event
		static float s_MouseScrollOffset;

		static EventCategory s_CurrentCategory;
		static TypeEvent s_CurrentKeyTyped;
		static TypeEvent s_CurrentKeyReleased;
		static MouseEvent s_CurrentMouseButtonClicked;
		static MouseEvent s_CurrentMouseButtonReleased;
		static WindowEvent s_CurrentWindowEvent;

	public:
		// functions
		static EventCategory GetCurrentCategory() { return s_CurrentCategory; }
		static TypeEvent GetCurrentKeyTyped() { return s_CurrentKeyTyped; }
		static TypeEvent GetCurrentKeyReleased() { return s_CurrentKeyReleased;  }
		static MouseEvent GetCurrentMouseButtonClicked() { return s_CurrentMouseButtonClicked; }
		static MouseEvent GetCurrentMouseButtonReleased() { return s_CurrentMouseButtonReleased; }
		static WindowEvent GetCurrentWindowEvent() { return s_CurrentWindowEvent; }
		static Vec2 GetMousePos() { return s_MousePos; }	
		static float GetMouseScrollOffset() { return s_MouseScrollOffset; }

	};
}