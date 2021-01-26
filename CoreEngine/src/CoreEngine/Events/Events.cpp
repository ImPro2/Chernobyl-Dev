#include "Events.h"

namespace CH {

	Vec2				 Event::s_MousePos = { 0.0f, 0.0f };
	Vec2				 Event::s_MouseScrollOffset = { 0.0f, 0.0f };
	Event::EventCategory Event::s_CurrentCategory = Event::EventCategory::WindowEvent;
	int					 Event::s_CurrentKeyTyped = CH_KEY_UNKNOWN;
	int					 Event::s_CurrentKeyReleased = CH_KEY_UNKNOWN;
	int					 Event::s_CurrentKeyPressed = CH_KEY_UNKNOWN;
	Event::MouseEvent    Event::s_CurrentMouseButtonClicked = Event::MouseEvent::NONE;
	Event::MouseEvent	 Event::s_CurrentMouseButtonReleased = Event::MouseEvent::NONE;
	Event::WindowEvent   Event::s_CurrentWindowEvent = Event::WindowEvent::AppTick;

	void Event::Clear()
	{
		s_CurrentCategory = EventCategory::WindowEvent;
		s_CurrentKeyPressed = CH_KEY_UNKNOWN;
		s_CurrentKeyReleased = CH_KEY_UNKNOWN;
		s_CurrentKeyTyped = CH_KEY_UNKNOWN;
		s_CurrentMouseButtonClicked = MouseEvent::NONE;
		s_CurrentMouseButtonReleased = MouseEvent::NONE;
		s_CurrentWindowEvent = WindowEvent::AppTick;
		s_MouseScrollOffset = { 0.0f, 0.0f };
	}

}