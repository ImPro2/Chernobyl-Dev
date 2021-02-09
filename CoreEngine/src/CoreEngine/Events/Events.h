#pragma once

#include "CoreEngine/Core.h"
#include "KeyCodes.h"
#include <GLFW/glfw3.h>

namespace CH {

	// class for use by the engine
	// NOTE: CHECK FOR AN EVENT AFTER WINDOW IS UPDATED
	// 
	// Check a mouse event:
	////
	////	if (CH::Event::s_CurrentMouseButtonClicked == CH::Event::MouseEvent::LEFT)
	////		CH_CORE_INFO("Left mouse button is clicked");
	//

	// Check a KeyPressed and KeyReleased event
	////
	////	if (CH::Event::s_CurrentKeyPressed == CH_KEY_A)
	////		CH_CORE_INFO("A key is pressed");
	////
	////	if (CH::Event::s_CurrentKeyReleased == CH_KEY_A)
	////		CH_CORE_INFO("A key is released");
	//

	// Check a KeyTyped event
	////	if (CH::Event::s_CurrentKeyTyped == 'a')
	////		CH_CORE_INFO("a key is pressed");
	////	if (CH::Event::s_CurrentKeyTyped == 'A')
	////		CH_CORE_INFO("A key is pressed");		// note that this is different
	//

	// Get mouse position
	////	Vec2 mousePos = CH::Event::s_MousePos;
	////	CH_CORE_INFO("X: {0}, Y: {1}", mousePos.x, mousePos.y);
	//

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
		static int s_CurrentSysKeyDown;
		static int s_CurrentSysKeyUp;
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