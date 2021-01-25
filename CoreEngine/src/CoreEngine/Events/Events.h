#pragma once

#include "CoreEngine/Core.h"
#include <GLFW/glfw3.h>

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
			A = GLFW_KEY_A,
			B = GLFW_KEY_B,
			C = GLFW_KEY_C,
			D = GLFW_KEY_D,
			E = GLFW_KEY_E,
			F = GLFW_KEY_F,
			G = GLFW_KEY_G,
			H = GLFW_KEY_H,
			I = GLFW_KEY_I,
			J = GLFW_KEY_J,
			K = GLFW_KEY_K,
			L = GLFW_KEY_L,
			M = GLFW_KEY_M,
			N = GLFW_KEY_N,
			O = GLFW_KEY_O,
			P = GLFW_KEY_P,
			Q = GLFW_KEY_Q,
			R = GLFW_KEY_R,
			S = GLFW_KEY_S,
			T = GLFW_KEY_T,
			U = GLFW_KEY_U,
			V = GLFW_KEY_V,
			W = GLFW_KEY_W,
			X = GLFW_KEY_X,
			Y = GLFW_KEY_Y,
			Z = GLFW_KEY_Z,
			N1 = GLFW_KEY_1,
			N2 = GLFW_KEY_2,
			N3 = GLFW_KEY_3,
			N4 = GLFW_KEY_4,
			N5 = GLFW_KEY_5,
			N6 = GLFW_KEY_6,
			N7 = GLFW_KEY_7,
			N8 = GLFW_KEY_8,
			N9 = GLFW_KEY_9,
			N0 = GLFW_KEY_0,
			TAB = GLFW_KEY_TAB,
			LSHIFT = GLFW_KEY_LEFT_SHIFT,
			LCONTROL = GLFW_KEY_LEFT_CONTROL,
			SPACE = GLFW_KEY_SPACE,
			RCONTROL = GLFW_KEY_RIGHT_CONTROL,
			RSHIFT = GLFW_KEY_RIGHT_SHIFT,
			COMMA = GLFW_KEY_COMMA,
			PERIOD = GLFW_KEY_PERIOD,
			SLASH = GLFW_KEY_SLASH,
			SEMICOLON = GLFW_KEY_SEMICOLON,
			ENTER = GLFW_KEY_ENTER,
			LBRACKET = GLFW_KEY_LEFT_BRACKET,
			RBRACKET = GLFW_KEY_RIGHT_BRACKET,
			MINUS = GLFW_KEY_MINUS,
			EQUAL = GLFW_KEY_EQUAL,
			BACKSPACE = GLFW_KEY_BACKSPACE,
			BACKSLASH = GLFW_KEY_BACKSLASH
		};

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
			AppTick,	// Could also be None
			Close
		};

		// for mouse moved event
		static Vec2 s_MousePos;

		// for mouse scrolled event
		static Vec2 s_MouseScrollOffset;

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
		static Vec2 GetMouseScrollOffset() { return s_MouseScrollOffset; }

	};
}